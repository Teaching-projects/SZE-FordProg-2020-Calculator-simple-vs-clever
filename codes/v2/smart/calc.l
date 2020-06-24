

%{
#include <stdio.h>
#include <math.h>

#define YY_DECL int yylex()

#include "calc.tab.h"

%}

%option noyywrap

%%

[ \t]	; // ignore all whitespace
[0-9]+\.[0-9]+ 	    {yylval.fval = atof(yytext); return T_FLOAT;}
[0-9]+		        {yylval.ival = atoi(yytext); return T_INT;}
\n	            	{return T_NEWLINE;}
"+"		            {return T_PLUS;}
"-"		            {return T_MINUS;}
"*"		            {return T_MULTIPLY;}
"/"		            {return T_DIVIDE;}
"exit"		        {return T_QUIT;}
"quit"		        {return T_QUIT;}

%%
