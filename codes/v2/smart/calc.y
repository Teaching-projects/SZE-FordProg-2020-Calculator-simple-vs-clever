%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

%type<ival> expression

%start calculation

%%

calculation:
	   | calculation line
;

line: T_NEWLINE
    | expression T_NEWLINE { printf("\tresult: %i\n", $1); }
    | T_QUIT T_NEWLINE { printf("new line!\n"); exit(0); }
;

expression: 
		T_INT								{ $$ = $1; }
		| T_FLOAT             			    { $$ = $1; }
	  	| expression T_PLUS expression		{ $$ = $1 + $3; }
	  	| expression T_MINUS expression		{ $$ = $1 - $3; }
	  	| expression T_MULTIPLY expression	{ $$ = $1 * $3; }
		| expression T_DIVIDE expression	{ $$ = $1 / (float)$3; }
;

%%

int main() 
{

	yyin = stdin;

	while(!feof(yyin)){
		yyparse();
	}

	return 0;
}

void yyerror(const char* s) 
{
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}
