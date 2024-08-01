%option noyywrap
%option yylineno
%option c++

%{
#include <iostream>
%}

%x NAME OST
%%
<INITIAL>{
^(?i:mailto\:) BEGIN(NAME);
\n return 0;
. return 0;
}
<NAME>{
(?i:[a-z0-9]{1,20}) {
    BEGIN(OST); return 1;}
\n {
    BEGIN(INITIAL); return 0;}
. {
    BEGIN(INITIAL); return 0;}
}
<OST>{
(?i:@[a-z0-9]{1,20}\.[a-z]{1,5},) BEGIN(NAME);
(?i:@[a-z0-9]{1,20}\.[a-z]{1,5}\n) {
    BEGIN(INITIAL); return 2;}
\n {
    BEGIN(INITIAL); return 0;
    }
. {
    BEGIN(INITIAL); return 0;}
}



<<EOF>> {return 3;}
%%

