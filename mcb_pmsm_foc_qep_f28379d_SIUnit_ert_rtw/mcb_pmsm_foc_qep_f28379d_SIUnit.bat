
cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2025b\bin\win64\gmake"  DEPRULES=1 -j7  -f mcb_pmsm_foc_qep_f28379d_SIUnit.mk all) else ("C:\PROGRA~1\MATLAB\R2025b\bin\win64\gmake"  DEPRULES=1 -j7  -f mcb_pmsm_foc_qep_f28379d_SIUnit.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1