# Contributing Guidelines

Thank you for your interest in contributing to the **PMSM Adaptive Control & Energy Optimization** project!

## Development Workflow

1. **Fork & Branch**:
   - Create a topic branch from `main`:
     ```bash
     git checkout -b feature/your-feature-name
     ```

2. **MATLAB & Simulink Best Practices**:
   - Save models in standard versions (R2022b / R2024a recommended).
   - Ensure all parameters are defined in initialization scripts (`*_param.m` or `*_data.m`) rather than hardcoded into blocks.
   - Run the parameter scripts to verify there are no missing workspace variables before opening or running any `.slx` model.
   - Avoid committing temporary files (`.asv`, `slprj/`, `*.slxc`, autosave backups).

3. **Hardware Deployment Testing**:
   - Always verify simulations in software (MIL / SIL) before flashing to the TI Delfino TMS320F28379D target.
   - Verify ADC current offsets and encoder alignments before running at high current or speed.

4. **Pull Requests**:
   - Describe changes clearly, including which motor parameters (`MOTOR_SELECT`), Simulink models, or control scripts were modified or tested.
   - Include validation plots or metrics if submitting new control strategies or estimators.

## Code of Conduct
Please maintain respectful, constructive, and collaborative discussions across issues and pull requests.
