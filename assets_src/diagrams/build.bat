:: "build.bat" v1.0.0 | 2019/09/30 | Dia v0.97.2
:: -----------------------------------------------------------------------------
:: Written by Tristano Ajmone, released into the public domain via Unlicense:
::    http://unlicense.org/
:: -----------------------------------------------------------------------------
:: In order to run this script you'll need to install Dia Diagram Editor:
::    http://dia-installer.de/
:: -----------------------------------------------------------------------------
@ECHO OFF
ECHO.
ECHO ======================================
ECHO Building SVG Diagrams from Dia Sources
ECHO ======================================

FOR %%i IN (*.dia) DO (
  CALL :BuildSVG %%i
  ECHO --------------------------------------
)
ECHO /// Finish ///
EXIT /B

:: =============================================================================
::                                  Functions
:: =============================================================================
:BuildSVG
ECHO - Converting: %1
CALL dia.exe -n -t svg %1
rem ECHO - Optimizing: %~n1.svg
rem CALL SVGO --disable=cleanupAttrs -i %~n1.svg -o %~n1.svg
EXIT /B


