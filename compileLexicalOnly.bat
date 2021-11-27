cd src
flex lexicalOnly.l
gcc lex.yy.c -o ../dist/compiler.exe
pause();
