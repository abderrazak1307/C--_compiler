cd src
flex lexical.l
bison -d syntax.y
gcc lex.yy.c syntax.tab.c -o../dist/compiler.exe
cd..\dist
cls
compiler.exe script.bra
pause();