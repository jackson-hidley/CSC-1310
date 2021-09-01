@echo off
cls

mingw32-make -f Makefile

Program1 < TEST_CASE.txt > RESULT_OF_TEST_CASE.txt

REM Program1.exe