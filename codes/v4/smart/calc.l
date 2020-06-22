

%{
#include <stdio.h>
#include <math.h>

#define YY_DECL int yylex()

#include "szamol.tab.h"

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
"^"		            {return T_POW;}
"("		            {return T_LEFT;}
")"		            {return T_RIGHT;}
"exit"		        {return T_QUIT;}
"quit"		        {return T_QUIT;}

%%
