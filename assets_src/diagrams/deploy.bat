:: "deploy.bat" v1.0.0 | 2019/09/30
:: -----------------------------------------------------------------------------
:: Written by Tristano Ajmone, released into the public domain via Unlicense:
::    http://unlicense.org/
:: -----------------------------------------------------------------------------
@ECHO OFF
SET _DESTFOLDER=..\..\docs_src\
ECHO.
ECHO =====================================================
ECHO Copying Built SVG diagrams to Hugo Book Source Folder
ECHO =====================================================
ECHO Destination Path: "%_DESTFOLDER%"
ECHO -----------------------------------------------------
COPY /Y *.svg %_DESTFOLDER%
ECHO -----------------------------------------------------
ECHO /// Finish ///
EXIT /B
