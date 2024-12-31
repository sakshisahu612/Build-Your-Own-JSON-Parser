@echo off
echo Testing valid.json:
step1_parser.exe < tests\step1\valid.json
echo Testing invalid.json:
step1_parser.exe < tests\step1\invalid.json
pause
