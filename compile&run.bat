cd src
flex lexical.l
bison -d syntax.y
gcc lex.yy.c syntax.tab.c -o../dist/compiler.exe
cd..
cls
dist\compiler.exe dist\script.brahim
pause();