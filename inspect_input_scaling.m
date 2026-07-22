%% inspect_input_scaling.m  — writes results to inspect_output.txt

mdl = 'testing';
ss  = [mdl '/Input Scaling1'];

if ~bdIsLoaded(mdl), load_system(mdl); end

fid = fopen('F:\Project\energy_optimization\inspect_output.txt','w');

blks = find_system(ss, 'MatchFilter', @Simulink.match.allVariants, ...
    'SearchDepth', 1, 'Type', 'Block');

fprintf(fid, '=== BLOCKS inside "%s" ===\n\n', ss);

for k = 1:numel(blks)
    blk = blks{k};
    if strcmp(blk, ss), continue; end
    name = get_param(blk,'Name');
    bt   = get_param(blk,'BlockType');
    fprintf(fid, '[%d] %-35s  Type: %s\n', k, name, bt);

    switch bt
        case 'Gain'
            fprintf(fid,'    Gain value : %s\n', get_param(blk,'Gain'));
        case 'Inport'
            fprintf(fid,'    Port #     : %s\n', get_param(blk,'Port'));
        case 'Outport'
            fprintf(fid,'    Port #     : %s\n', get_param(blk,'Port'));
        case 'Constant'
            fprintf(fid,'    Value      : %s\n', get_param(blk,'Value'));
        case 'DataTypeConversion'
            fprintf(fid,'    Output DT  : %s\n', get_param(blk,'OutDataTypeStr'));
        case 'Sum'
            fprintf(fid,'    Inputs     : %s\n', get_param(blk,'Inputs'));
        case 'Product'
            fprintf(fid,'    Inputs     : %s\n', get_param(blk,'Inputs'));
        case 'Fcn'
            fprintf(fid,'    Expression : %s\n', get_param(blk,'Expr'));
        case 'SubSystem'
            fprintf(fid,'    (subsystem)\n');
        case 'Switch'
            fprintf(fid,'    Threshold  : %s\n', get_param(blk,'Threshold'));
        case 'Trigonometry'
            fprintf(fid,'    Operator   : %s\n', get_param(blk,'Operator'));
        case 'Math'
            fprintf(fid,'    Operator   : %s\n', get_param(blk,'Operator'));
    end

    % Input connections
    ph = get_param(blk,'PortHandles');
    for p = 1:numel(ph.Inport)
        lh = get_param(ph.Inport(p),'Line');
        if lh > 0
            try
                src_blk = get_param(get_param(lh,'SrcPortHandle'),'Parent');
                sig     = get_param(lh,'Name');
                fprintf(fid,'    IN[%d] <- "%s"  sig="%s"\n', p, ...
                    get_param(src_blk,'Name'), sig);
            catch; end
        else
            fprintf(fid,'    IN[%d] <- (unconnected)\n', p);
        end
    end
    % Output connections
    for p = 1:numel(ph.Outport)
        lh = get_param(ph.Outport(p),'Line');
        if lh > 0
            try
                sig  = get_param(lh,'Name');
                dphs = get_param(lh,'DstPortHandles');
                dstr = '';
                for d = dphs'
                    dstr = [dstr '"' get_param(get_param(d,'Parent'),'Name') '" ']; %#ok
                end
                fprintf(fid,'    OUT[%d]-> %s  sig="%s"\n', p, dstr, sig);
            catch; end
        else
            fprintf(fid,'    OUT[%d]-> (unconnected)\n', p);
        end
    end
    fprintf(fid,'\n');
end

fclose(fid);
disp('Done — see inspect_output.txt');
