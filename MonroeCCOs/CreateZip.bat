@echo off
echo **
echo ** Create a folder in this directory named CommonCO to
echo **   contain the OPOS .ocx and .dll files. Copy the files
echo **   from the build folders to the appropriate subfolder in CommonCO.
echo **   Then create a .zip file from that folder using powershell.
echo **
echo --} Press Control-Break to exit, or
pause

@echo on

md OPOSCOs\CommonCO
md OPOSCOs\Include

xcopy OCX\Release\*.dll OPOSCOs\CommonCO\
xcopy OCX\Release\*.ocx OPOSCOs\CommonCO\

xcopy Common\Opos\*.* OPOSCOs\Include

xcopy Register.bat OPOSCOs\
xcopy OPOS_CCO_ReadMe*.* OPOSCOs\

powershell compress-archive OPOSCOs\ OPOSCOs.zip

pause