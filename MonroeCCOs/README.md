The Monroe Consulting Services Common Control Objects for OPOS are available with both installers and source code.

Website: http://monroecs.com/index.htm

This is a clone of the source code of the Common Control Objects as provided by Monroe Consulting Services.

### Version

This is the source code for version 1.14.001 downloaded from the Monroe Consulting Services website Oct-09-2021.

See the documentation in the file OPOS_CCO_ReadMe_1_14_001.txt

#### Note - zElectronicValueRW-Gen folder

There is an additional folder zElectronicValueRW-Gen which appears to be similar to the folder zElectronicValueRW.
It is in the source code .zip file downloaded from the Monroe web site however it is not listed in the CleanFiles.bat
file which performs the generated file clean up. There is a file, _EVRW_1.14.100_BuildSteps.txt, in the zElectronicValueRW
folder that is not in the zElectronicValueRW-Gen folder which appears to be notes about changes made by hand after using
the source code generation tool. So it may be that zElectronicValueRW-Gen is the original generated source code using
the generation tool using the data file zElectronicValueRW.txt in folder DataFiles. That file does have a note about
needing to make manual changes to the generated source.

#### Changes needed

I've found several issues with using this source code with a newer compiler, Visual Studio 2017 at the moment, Oct-2021.
 - use of the deprecated ATL::CComVariant method ClearToZero() which I've changed to Clear() in my working copy
 - use of the deprecated ATL::CComVariant::GetSize: GetSize has been replaced by GetSizeMax
 - MIDL compiler options that conflict, use of -no_robust for argument checks and targeting NT60, I removed the target in my working copy. See https://stackoverflow.com/questions/47803621/upgrading-vs2017-from-15-4-1-to-15-5-1-resulted-in-build-error
 - use of RCSTrace, a proprietary product of NCR Corporation, for debug tracing logs (missing UseRCSTrace.h when compiled with Debug)

 For the problem with the missing UseRCSTrace.h file, which is proprietary anyway, I modified the header files where it is enabled
 with a Preprocessor check for `#ifdef _DEBUG` so that instead of just a check for `_DEBUG` I've added a check for a define of WRITETRACEERROR
 using the directive `#if defined(_DEBUG) && defined(WRITETRACEERROR)` which allows someone to enable the trace functionality by
 defining `WRITETRACEERROR` on the compiler command line.

 There is provisions for using a log file rather than the RCS Trace functionality by defining `_FILETRACE` on the compiler command line.

 So if you want to enable tracing add defined constant `WRITETRACEERROR` to the compiler command line and if you don't have RCS Trace from NCR then
 also define `_FILETRACE` to enable logging trace data to a file.

## Folder structure

Each of the different OPOS controls has their source in a folder which starts with the letter z. So the POSPrinter OPOS control
source is located in the folder zPOSPrinter. These source files are used to generate each of the .ocx files that are part of
the installation package.

The folder OposConstants contains the source code for the Opos_Constants.dll file which is also part of the installation package.

The folder OCX is the destination folder for the compiler output files with subfolders of Release and Debug. The results of
compiling the source code is put into the appropriate subfolder, Release or Debug. These folder will contain .lib, .ocx,
.dll, .exp, and .map files after a compile of the source. The only files needed for installation are the .ocx and .dll files.

The folder Common contains source files that all of the OPOS controls use. In this folder is a folder ATL with a modified
version of the file atlcom.h with those changes briefly explained in the file _ATLChanges_.txt also in that folder.

Also in the folder Common is a folder Opos which contains the OPOS include files needed by an application. The files in this
folder are included in the .zip file Monroe uses to provide the .ocx files with the Register.bat OPOS control registration script.

The folder DataFiles contains text files with directives used by a generator to generate the initial source code for the OPOS
controls. This would seem to be something done rarely. The generator tool has not yet been located.

### .bat files

There are a couple of .bat files that are in the MonroeCOs root folder containing all the subfolders with the source code.

The files CleanFiles.bat and CleanFiles2.bat are used to perform a complete clean of all intermediary and final build
products. This results in all the files generated during a build to be removed including the generated .h files from the
MIDL compiler. The CleanFiles.bat script is more complete than doing a Build -> Clean Solution menu choice in the
Visual Studio IDE.

The file Register.bat is from the .zip file containing the OPOS .ocx controls and is used as a script to register the
controls as well as the Opos_Constants.dll file. It uses an application, regcomsvr.exe, which seems to be similar in
functionality to the application regsvr32.exe. The application regcomsvr.exe is included in the .zip file along with
the .ocx controls and .dll file.

The file CreateZip.bat will create a .zip file containing the OPOS controls and the OPOS include files along with
the Register.bat script file. This script does require powershell as it uses the Compress-Archive command.

## Legal

From URL: http://monroecs.com/oposccos_legal.htm

> These control objects are delivered as a reference implementation, believed to be correct and suitable for direct use by applications, but not warranted to be correct or to work with any vendor's Service Objects.
> 
> We intend to make a good faith effort to correct problems that are found and reported within these control objects, but are not obligated to do so.
> 
> The CCOs are published under the terms of the Apache 2.0 license.  Most of the source modules and CCO binaries contain the following notice:
> 
> 
>    Copyright 2015 Monroe Consulting Services, Inc.
>    
>    Licensed under the Apache License, Version 2.0 (the "License");
>    you may not use this file except in compliance with the License.
>    You may obtain a copy of the License at
>    
>    http://www.apache.org/licenses/LICENSE-2.0
>
>    Unless required by applicable law or agreed to in writing, software
>    distributed under the License is distributed on an "AS IS" BASIS,
>    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
>    See the License for the specific language governing permissions and
>    limitations under the License.
