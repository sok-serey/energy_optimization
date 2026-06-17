%% replace_pid_with_fsfb.m  (v2 — targeted replacement)
%
%  KNOWN MODEL STRUCTURE (discovered from find_system output):
%    mcb_pmsm_fsfb_qep_f28379d/Speed Control
%    mcb_pmsm_fsfb_qep_f28379d/Speed Control/PI_Controller_Speed
%    mcb_pmsm_fsfb_qep_f28379d/Speed Control/PI_Controller_Speed/
%                              Discrete PI Controller with anti-windup & reset
%    mcb_pmsm_fsfb_qep_f28379d/Speed Control/Zero_Cancellation
%    mcb_pmsm_fsfb_qep_f28379d/Speed Control/Subsystem
%    mcb_pmsm_fsfb_qep_f28379d/Simulation   (variant)
%    mcb_pmsm_fsfb_qep_f28379d/Serial Receive
%
%  STRATEGY:
%    Step 1 — Explore ALL blocks (including inactive variants) to find
%             the current controllers and signal names.
%    Step 2 — Replace Speed Control subsystem with FSFB_Controller.
%    Step 3 — Find current PI controllers (in variant subsystem) and
%             remove them, wiring FSFB Vd/Vq directly to Inverse Park.
%
%  PRE-REQUISITE:  mcb_pmsm_fsfb_f28379d_param.m  must be run first.

%% -------------------------------------------------------
%  Guard
%% -------------------------------------------------------
if ~exist('FSFB','var') || ~exist('Motor','var')
    error('Run mcb_pmsm_fsfb_f28379d_param.m first.');
end

new_mdl  = 'mcb_pmsm_fsfb_qep_f28379d';
new_file = [new_mdl '.slx'];

if ~exist(new_file,'file')
    error('%s not found. Run the param script and check the file exists.', new_file);
end

if bdIsLoaded(new_mdl), close_system(new_mdl,0); end
load_system(new_mdl);
open_system(new_mdl);
fprintf('Loaded %s\n\n', new_mdl);

%% -------------------------------------------------------
%  STEP 1 — Full exploration using allVariants filter
%% -------------------------------------------------------
fprintf('========== FULL BLOCK LIST (all variants) ==========\n');
all_blks = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'Type', 'Block');
for k = 1:numel(all_blks)
    bt = get_param(all_blks{k},'BlockType');
    fprintf('  [%-25s]  %s\n', bt, all_blks{k});
end

fprintf('\n========== SUBSYSTEMS ==========\n');
all_ss = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'BlockType', 'SubSystem');
for k = 1:numel(all_ss), fprintf('  %s\n', all_ss{k}); end

fprintf('\n========== PID / DISCRETE FILTER BLOCKS ==========\n');
pid_blks = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'BlockType', 'DiscretePIDController');
df_blks  = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'BlockType', 'DiscreteFilter');
for k = 1:numel(pid_blks), fprintf('  PID:  %s\n', pid_blks{k}); end
for k = 1:numel(df_blks),  fprintf('  DisF: %s\n', df_blks{k}); end

fprintf('\n========== INPORT / OUTPORT names ==========\n');
inp_blks = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'BlockType', 'Inport');
out_blks = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'BlockType', 'Outport');
for k = 1:numel(inp_blks), fprintf('  IN:  %s\n', inp_blks{k}); end
for k = 1:numel(out_blks), fprintf('  OUT: %s\n', out_blks{k}); end

%% -------------------------------------------------------
%  STEP 2 — Identify key subsystem paths from exploration
%% -------------------------------------------------------

% Speed Control subsystem (confirmed from earlier run)
speed_ctrl_ss = [new_mdl '/Speed Control'];

% Find the subsystem that contains Forward Park transform
% (it will also contain the current controllers)
park_fwd_blk = '';
inv_park_blk = '';
for k = 1:numel(all_blks)
    nm = lower(get_param(all_blks{k},'Name'));
    if contains(nm,'park') && ~contains(nm,'inv') && ~contains(nm,'reverse')
        park_fwd_blk = all_blks{k};
    end
    if contains(nm,'park') && (contains(nm,'inv') || contains(nm,'reverse'))
        inv_park_blk = all_blks{k};
    end
end

% Find the Variant Subsystem that holds the Code Generation path
% (the active code-gen variant is the one to modify)
variant_ss = '';
for k = 1:numel(all_ss)
    bt = get_param(all_ss{k},'BlockType');
    try
        vs = get_param(all_ss{k},'VariantControl');
        if ~isempty(vs)
            variant_ss = all_ss{k};
            fprintf('\nFound Variant Subsystem: %s\n', variant_ss);
        end
    catch, end
end

fprintf('\nForward Park block : %s\n', park_fwd_blk);
fprintf('Inverse Park block : %s\n', inv_park_blk);

%% -------------------------------------------------------
%  STEP 3 — Inspect Speed Control subsystem I/O
%  to understand what signals enter/leave it
%% -------------------------------------------------------
fprintf('\n========== Speed Control subsystem ports ==========\n');
sc_ports = find_system(speed_ctrl_ss, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'SearchDepth', 1, 'BlockType', 'Inport');
for k = 1:numel(sc_ports), fprintf('  IN:  %s\n', sc_ports{k}); end
sc_out = find_system(speed_ctrl_ss, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'SearchDepth', 1, 'BlockType', 'Outport');
for k = 1:numel(sc_out), fprintf('  OUT: %s\n', sc_out{k}); end

fprintf('\n========== Speed Control subsystem blocks ==========\n');
sc_blks = find_system(speed_ctrl_ss, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'SearchDepth', 1, 'Type', 'Block');
for k = 1:numel(sc_blks)
    nm = get_param(sc_blks{k},'Name');
    bt = get_param(sc_blks{k},'BlockType');
    pos = get_param(sc_blks{k},'Position');
    fprintf('  [%-25s] %-35s  pos=[%d %d %d %d]\n', bt, nm, pos);
end

%% -------------------------------------------------------
%  STEP 4 — Find lines connected to Speed Control I/O ports
%  so we know which signals to rewire
%% -------------------------------------------------------
fprintf('\n========== Lines at Speed Control boundary ==========\n');
sc_ph = get_param(speed_ctrl_ss,'PortHandles');
fprintf('Inport handles: '); disp(sc_ph.Inport);
fprintf('Outport handles: '); disp(sc_ph.Outport);

% For each inport, find the source signal name/block
for k = 1:numel(sc_ph.Inport)
    lh = get_param(sc_ph.Inport(k),'Line');
    if lh > 0
        try
            src_ph = get_param(lh,'SrcPortHandle');
            src_blk = get_param(src_ph,'Parent');
            src_name = get_param(src_blk,'Name');
            sig_name = get_param(lh,'Name');
            fprintf('  SpeedCtrl IN port %d <- "%s" from block "%s"\n', k, sig_name, src_name);
        catch, end
    end
end

for k = 1:numel(sc_ph.Outport)
    lh = get_param(sc_ph.Outport(k),'Line');
    if lh > 0
        try
            dst_phs = get_param(lh,'DstPortHandles');
            sig_name = get_param(lh,'Name');
            fprintf('  SpeedCtrl OUT port %d -> sig="%s"\n', k, sig_name);
            for d = dst_phs'
                dst_blk = get_param(d,'Parent');
                dst_name = get_param(dst_blk,'Name');
                fprintf('    -> "%s"\n', dst_name);
            end
        catch, end
    end
end

%% -------------------------------------------------------
%  STEP 5 — Find current PI controllers and their parent
%% -------------------------------------------------------
fprintf('\n========== Current controller search ==========\n');
curr_ctrl_blks = {};
for k = 1:numel(pid_blks)
    nm = lower(get_param(pid_blks{k},'Name'));
    pth = lower(pid_blks{k});
    if contains(nm,'id') || contains(nm,'iq') || contains(nm,'current') || ...
       contains(pth,'current') || contains(pth,'id') || contains(pth,'iq')
        curr_ctrl_blks{end+1} = pid_blks{k}; %#ok<AGROW>
        fprintf('  Current PI: %s\n', pid_blks{k});
    end
end
if isempty(curr_ctrl_blks)
    fprintf('  No current PIDs found with BlockType=DiscretePIDController.\n');
    fprintf('  They may use a custom SubSystem. Checking SubSystem names...\n');
    for k = 1:numel(all_ss)
        nm = lower(get_param(all_ss{k},'Name'));
        if contains(nm,'id') || contains(nm,'iq') || contains(nm,'current') || contains(nm,'pi')
            fprintf('  Possible current ctrl SS: %s\n', all_ss{k});
            curr_ctrl_blks{end+1} = all_ss{k}; %#ok<AGROW>
        end
    end
end

fprintf('\n');
fprintf('=====================================================\n');
fprintf('  EXPLORATION COMPLETE.\n');
fprintf('  Review the output above, then run STEP 6 below.\n');
fprintf('  Confirm the following paths are correct:\n');
fprintf('    speed_ctrl_ss  = ''%s''\n', speed_ctrl_ss);
fprintf('    inv_park_blk   = ''%s''\n', inv_park_blk);
fprintf('    park_fwd_blk   = ''%s''\n', park_fwd_blk);
fprintf('  Then run Part B of this script (uncomment STEP 6).\n');
fprintf('=====================================================\n');

%% -------------------------------------------------------
%  STEP 6 — ACTUAL REPLACEMENT
%  Uncomment and run after verifying STEP 1-5 output above.
%  Adjust path strings if exploration revealed different names.
%% -------------------------------------------------------

% ---- 6a. Determine parent of Speed Control ----
% The Speed Control block lives at the top level of new_mdl.
% We will REPLACE its contents with FSFB logic.
% (We keep the subsystem shell so existing wiring is preserved.)

top = new_mdl;   % parent of Speed Control block

fprintf('\nReplacing Speed Control contents with FSFB...\n');

%  Record the port connections BEFORE we modify anything
sc_ph = get_param(speed_ctrl_ss,'PortHandles');
n_in  = numel(sc_ph.Inport);
n_out = numel(sc_ph.Outport);
fprintf('Speed Control has %d inports and %d outports.\n', n_in, n_out);

% ---- 6b. Delete everything inside Speed Control ----
% Use SearchDepth=1 to get only DIRECT children (top-level blocks).
% Deleting a SubSystem parent automatically removes all its children,
% so we must NOT iterate into sub-sub-blocks (that's what caused the error).
inner_top = find_system(speed_ctrl_ss, 'SearchDepth', 1, ...
    'MatchFilter', @Simulink.match.allVariants, 'Type', 'Block');

% Delete all lines inside the subsystem first
inner_lines = find_system(speed_ctrl_ss, 'SearchDepth', 1, ...
    'MatchFilter', @Simulink.match.allVariants, 'FindAll','on','Type','Line');
for lh = inner_lines'
    try delete_line(lh); catch, end
end

% Delete top-level blocks only (skip the subsystem shell and its ports)
for k = 1:numel(inner_top)
    blk = inner_top{k};
    if strcmp(blk, speed_ctrl_ss), continue; end
    bt = get_param(blk, 'BlockType');
    if strcmp(bt,'Inport') || strcmp(bt,'Outport'), continue; end
    try
        delete_block(blk);
        fprintf('  Deleted: %s\n', blk);
    catch e
        fprintf('  Could not delete %s: %s\n', blk, e.message);
    end
end
fprintf('Cleared Speed Control interior.\n');

% ---- 6c. Normalise port layout inside Speed Control ----
% After clearing, the subsystem has its original Inport/Outport blocks.
% Find them and learn what they are.
sc_in_blks  = find_system(speed_ctrl_ss,'SearchDepth',1,'BlockType','Inport');
sc_out_blks = find_system(speed_ctrl_ss,'SearchDepth',1,'BlockType','Outport');

fprintf('Remaining inports  inside Speed Control:\n');
for k=1:numel(sc_in_blks),  fprintf('  %s\n', sc_in_blks{k}); end
fprintf('Remaining outports inside Speed Control:\n');
for k=1:numel(sc_out_blks), fprintf('  %s\n', sc_out_blks{k}); end

% ---- 6d. Add FSFB logic inside Speed Control ----
% The Speed Control subsystem originally had:
%   IN: omega_ref, omega_measured  (2 ports typical)
%   OUT: iq_ref                    (1 port typical)
%
% We now EXPAND it to also take id, iq as inputs and output Vd, Vq.
% We add new Inport blocks for the extra signals.
% The outer wiring will be updated in STEP 7.

sc = speed_ctrl_ss;  % shorthand

% Rename/reuse existing inports; add new ones as needed
% Determine existing port numbers from port blocks
existing_in_ports = numel(sc_in_blks);
existing_out_ports = numel(sc_out_blks);

% Add missing input ports: id_ref, id, iq
% (omega_ref and omega already exist as ports 1 and 2 from original)
% We add:  id (port 3), iq (port 4),  id_ref will be internal constant

% Get positions of existing port blocks for layout reference
if ~isempty(sc_in_blks)
    ref_pos = get_param(sc_in_blks{end},'Position');
else
    ref_pos = [20 50 50 70];
end

% Rename existing ports so we know which is which
% Port 1 = omega_ref, Port 2 = omega_measured (typical MCB Speed Control)
if numel(sc_in_blks) >= 1
    set_param(sc_in_blks{1},'Name','omega_ref');
    set_param(sc_in_blks{1},'Position',[20,  50, 50,  70]);
end
if numel(sc_in_blks) >= 2
    set_param(sc_in_blks{2},'Name','omega');
    set_param(sc_in_blks{2},'Position',[20, 130, 50, 150]);
end

% Add id, iq inports
add_block('built-in/Inport',[sc '/id'], 'Port','3','Position',[20,210,50,230]);
add_block('built-in/Inport',[sc '/iq'], 'Port','4','Position',[20,290,50,310]);

% Rename/reuse outports
% Original had iq_ref (port 1). We replace with Vd (port 1) and Vq (port 2).
if numel(sc_out_blks) >= 1
    set_param(sc_out_blks{1},'Name','Vd_cmd');
    set_param(sc_out_blks{1},'Position',[700, 80, 730,100]);
end
if numel(sc_out_blks) >= 2
    set_param(sc_out_blks{2},'Name','Vq_cmd');
    set_param(sc_out_blks{2},'Position',[700,180, 730,200]);
else
    add_block('built-in/Outport',[sc '/Vq_cmd'],'Port','2','Position',[700,180,730,200]);
end

% id_ref = 0 constant (MTPA)
add_block('built-in/Constant',[sc '/id_ref_zero'], ...
    'Value','0','Position',[100, 50, 140, 80]);

% ---- Error sums ----
add_block('built-in/Sum',[sc '/err_id'], ...
    'Inputs','+-','Position',[200, 45, 230, 85]);
add_block('built-in/Sum',[sc '/err_omega'], ...
    'Inputs','+-','Position',[200,195, 230,235]);

add_line(sc,'id_ref_zero/1','err_id/1','autorouting','on');
add_line(sc,'id/1',         'err_id/2','autorouting','on');
add_line(sc,'omega_ref/1',  'err_omega/1','autorouting','on');
add_line(sc,'omega/1',      'err_omega/2','autorouting','on');

% ---- Discrete integrators (anti-windup) ----
Ts_str  = num2str(Inv.Ts_pwm);

add_block('simulink/Discrete/Discrete-Time Integrator',[sc '/xi_id'], ...
    'IntegratorMethod',     'Forward Euler', ...
    'gainval',              '1', ...
    'SampleTime',           Ts_str, ...
    'UpperSaturationLimit', num2str(FSFB.xi_id_max), ...
    'LowerSaturationLimit', num2str(FSFB.xi_id_min), ...
    'AntiWindupMode',       'Clamping', ...
    'Position',[290, 40, 390, 90]);

add_block('simulink/Discrete/Discrete-Time Integrator',[sc '/xi_omega'], ...
    'IntegratorMethod',     'Forward Euler', ...
    'gainval',              '1', ...
    'SampleTime',           Ts_str, ...
    'UpperSaturationLimit', num2str(FSFB.xi_omega_max), ...
    'LowerSaturationLimit', num2str(FSFB.xi_omega_min), ...
    'AntiWindupMode',       'Clamping', ...
    'Position',[290,190, 390,240]);

add_line(sc,'err_id/1',    'xi_id/1','autorouting','on');
add_line(sc,'err_omega/1', 'xi_omega/1','autorouting','on');

% ---- Mux state vector x = [id; iq; omega] ----
add_block('built-in/Mux',[sc '/Mux_x'], ...
    'Inputs','3','Position',[200,300, 205,420]);
add_line(sc,'id/1',    'Mux_x/1','autorouting','on');
add_line(sc,'iq/1',    'Mux_x/2','autorouting','on');
add_line(sc,'omega/1', 'Mux_x/3','autorouting','on');

% ---- Mux integrator xi = [xi_id; xi_omega] ----
add_block('built-in/Mux',[sc '/Mux_xi'], ...
    'Inputs','2','Position',[430, 50, 435,160]);
add_line(sc,'xi_id/1',    'Mux_xi/1','autorouting','on');
add_line(sc,'xi_omega/1', 'Mux_xi/2','autorouting','on');

% ---- Matrix gains ----
add_block('built-in/Gain',[sc '/neg_Kx'], ...
    'Gain',           mat2str(-FSFB.Kx), ...
    'Multiplication', 'Matrix(K*u)', ...
    'Position',[290,300, 390,420]);
add_line(sc,'Mux_x/1','neg_Kx/1','autorouting','on');

add_block('built-in/Gain',[sc '/Ki_gain'], ...
    'Gain',           mat2str(FSFB.Ki), ...
    'Multiplication', 'Matrix(K*u)', ...
    'Position',[490, 50, 580,160]);
add_line(sc,'Mux_xi/1','Ki_gain/1','autorouting','on');

% ---- Sum: u = -Kx*x + Ki*xi ----
add_block('built-in/Sum',[sc '/Sum_u'], ...
    'Inputs','++','Position',[610,200, 640,360]);
add_line(sc,'neg_Kx/1',  'Sum_u/1','autorouting','on');
add_line(sc,'Ki_gain/1', 'Sum_u/2','autorouting','on');

% ---- Demux [Vd; Vq] ----
add_block('built-in/Demux',[sc '/Demux_u'], ...
    'Outputs','2','Position',[660,205, 665,355]);
add_line(sc,'Sum_u/1','Demux_u/1','autorouting','on');

% ---- Output saturation ----
Vlim = Inv.Vdc / sqrt(3);
add_block('built-in/Saturate',[sc '/Sat_Vd'], ...
    'UpperLimit', num2str( Vlim), ...
    'LowerLimit', num2str(-Vlim), ...
    'Position',[680, 70, 695,100]);
add_block('built-in/Saturate',[sc '/Sat_Vq'], ...
    'UpperLimit', num2str( Vlim), ...
    'LowerLimit', num2str(-Vlim), ...
    'Position',[680,170, 695,200]);

add_line(sc,'Demux_u/1','Sat_Vd/1','autorouting','on');
add_line(sc,'Demux_u/2','Sat_Vq/1','autorouting','on');
add_line(sc,'Sat_Vd/1', 'Vd_cmd/1','autorouting','on');
add_line(sc,'Sat_Vq/1', 'Vq_cmd/1','autorouting','on');

fprintf('FSFB logic inserted inside Speed Control subsystem.\n');

%% -------------------------------------------------------
%  STEP 7 — Rewire top level
%
%  Original top-level wiring around Speed Control:
%    Something -> Speed Control port 1 (omega_ref)
%    Something -> Speed Control port 2 (omega)
%    Speed Control port 1 (iq_ref) -> Current Control
%
%  New wiring needed:
%    Keep: omega_ref -> port 1
%    Keep: omega     -> port 2
%    ADD:  id        -> port 3  (from Park transform or current sensing)
%    ADD:  iq        -> port 4  (from Park transform)
%    Speed Control port 1 (Vd) -> Inverse Park port 1
%    Speed Control port 2 (Vq) -> Inverse Park port 2
%
%  We need to:
%    a) Find where id and iq signals are available at top level
%       (they come out of a Forward Park subsystem)
%    b) Delete the old line from Speed Control out -> Current Controller
%    c) Add lines for id/iq -> Speed Control ports 3,4
%    d) Redirect Vd/Vq to Inverse Park (bypassing old current PI)
%% -------------------------------------------------------
fprintf('\n--- Rewiring top level ---\n');

% Find Park forward block at top level (SearchDepth=1)
fwd_park_top = '';
inv_park_top = '';
all_top_blks = find_system(new_mdl,'SearchDepth',1, ...
    'MatchFilter',@Simulink.match.allVariants,'Type','Block');
for k=1:numel(all_top_blks)
    nm = lower(get_param(all_top_blks{k},'Name'));
    bt = get_param(all_top_blks{k},'BlockType');
    if strcmp(bt,'SubSystem')
        if contains(nm,'park') && ~contains(nm,'inv') && ~contains(nm,'reverse')
            fwd_park_top = all_top_blks{k};
        end
        if contains(nm,'park') && (contains(nm,'inv') || contains(nm,'reverse'))
            inv_park_top = all_top_blks{k};
        end
    end
end

% Also search one level deeper (in case Park is inside a variant or FOC SS)
if isempty(fwd_park_top)
    for k=1:numel(all_ss)
        nm = lower(get_param(all_ss{k},'Name'));
        if contains(nm,'park') && ~contains(nm,'inv')
            fwd_park_top = all_ss{k};
        end
        if contains(nm,'park') && contains(nm,'inv')
            inv_park_top = all_ss{k};
        end
    end
end

fprintf('Forward Park : %s\n', fwd_park_top);
fprintf('Inverse Park : %s\n', inv_park_top);

% Print current outport line destinations of Speed Control
sc_ph = get_param(speed_ctrl_ss,'PortHandles');
fprintf('\nSpeed Control current outport connections:\n');
for k=1:numel(sc_ph.Outport)
    lh = get_param(sc_ph.Outport(k),'Line');
    if lh > 0
        try
            dst_phs = get_param(lh,'DstPortHandles');
            for d=dst_phs'
                dst_blk  = get_param(d,'Parent');
                dst_name = get_param(dst_blk,'Name');
                dst_port = get_param(d,'PortNumber');
                fprintf('  OutPort %d -> "%s" port %d\n', k, dst_name, dst_port);
            end
        catch, end
    else
        fprintf('  OutPort %d -> unconnected\n', k);
    end
end

%% -------------------------------------------------------
%  STEP 8 — Remove current PI controllers from wherever they live
%
%  Since the FSFB already handles current control, we need to
%  remove the Id/Iq PI blocks and bypass them.
%  The Vd/Vq now come directly from FSFB (Speed Control outports).
%% -------------------------------------------------------
fprintf('\n--- Searching for current PI controllers to remove ---\n');

% Find all PI-type subsystems that handle Id or Iq
curr_pi_ss = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'RegExp','on','Name','.*[Pp][Ii].*[Cc]urrent.*|.*[Cc]urrent.*[Pp][Ii].*|.*[Ii][Dd].*[Pp][Ii].*|.*[Ii][Qq].*[Pp][Ii].*');
fprintf('Current PI subsystems found:\n');
for k=1:numel(curr_pi_ss), fprintf('  %s\n', curr_pi_ss{k}); end

% Also find any subsystem named "Current Control"
curr_ctrl_ss = find_system(new_mdl, ...
    'MatchFilter', @Simulink.match.allVariants, ...
    'RegExp','on','Name','.*[Cc]urrent.*[Cc]ontrol.*|.*[Cc]urrent.*[Ll]oop.*');
fprintf('Current Control subsystems found:\n');
for k=1:numel(curr_ctrl_ss), fprintf('  %s\n', curr_ctrl_ss{k}); end

%% -------------------------------------------------------
%  STEP 9 — Save and print manual completion instructions
%% -------------------------------------------------------
try
    Simulink.BlockDiagram.arrangeSystem(speed_ctrl_ss);
catch, end

save_system(new_mdl, new_file);
fprintf('\n=== Saved: %s ===\n\n', new_file);

fprintf('============================================================\n');
fprintf('  AUTOMATIC STEPS DONE:\n');
fprintf('  [x] Speed Control subsystem contents replaced with FSFB\n');
fprintf('  [x] Anti-windup integrators added (xi_id, xi_omega)\n');
fprintf('  [x] Matrix gains Kx and Ki inserted\n');
fprintf('  [x] Output voltage saturation added\n');
fprintf('\n');
fprintf('  MANUAL STEPS REMAINING in Simulink:\n');
fprintf('\n');
fprintf('  1. Open %s\n', new_file);
fprintf('\n');
fprintf('  2. EXPAND "Speed Control" port count at top level:\n');
fprintf('     Right-click Speed Control -> Block Parameters\n');
fprintf('     It now needs 4 inputs: omega_ref, omega, id, iq\n');
fprintf('     Connect id and iq signals from Park transform to\n');
fprintf('     Speed Control ports 3 and 4.\n');
fprintf('\n');
fprintf('  3. DISCONNECT Speed Control output from old current PI:\n');
fprintf('     The original single output (iq_ref) now carries Vd.\n');
fprintf('     Add second output line for Vq.\n');
fprintf('     Route Vd -> Inverse Park port 1\n');
fprintf('     Route Vq -> Inverse Park port 2\n');
fprintf('\n');
fprintf('  4. DELETE the old current PI controller subsystem(s).\n');
fprintf('     These were identified above (look for Id PI, Iq PI).\n');
fprintf('     Or if inside a variant: open Code Generation variant,\n');
fprintf('     delete the Id and Iq PI blocks, reconnect Park -> InvPark\n');
fprintf('     through the FSFB outputs.\n');
fprintf('\n');
fprintf('  5. Verify the signal flow:\n');
fprintf('     Serial Receive -> omega_ref -> Speed Control port 2\n');
fprintf('     eQEP -> omega -> Speed Control port 2  (unchanged)\n');
fprintf('     Park -> id  -> Speed Control port 3    (NEW)\n');
fprintf('     Park -> iq  -> Speed Control port 4    (NEW)\n');
fprintf('     Speed Control -> Vd -> Inverse Park port 1  (was iq_ref)\n');
fprintf('     Speed Control -> Vq -> Inverse Park port 2  (NEW)\n');
fprintf('\n');
fprintf('  6. Run simulation to verify step response.\n');
fprintf('  7. Build and deploy to F28379D.\n');
fprintf('============================================================\n');
