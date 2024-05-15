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
