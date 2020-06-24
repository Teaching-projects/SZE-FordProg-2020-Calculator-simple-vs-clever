%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

%}

%token<ival> T_INT
%token<fval> T_FLOAT
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE
%token T_NEWLINE T_QUIT

%union {
	int ival;
	float fval;
}

%type<ival> expression

%start calculation

%%

calculation:
	   | calculation line
;

line: T_NEWLINE
    | expression T_NEWLINE { printf("new line!\n"); }
    | T_QUIT T_NEWLINE { printf("new line! EXIT! \n"); exit(0); }
;

expression: 
		T_INT								{ printf(" integer: %d \n", $1); }
		| T_FLOAT             			    { printf(" float: %f \n", $1); }
	  	| expression T_PLUS expression		{ printf(" plus \n"); }
	  	| expression T_MINUS expression		{ printf(" minus \n"); }
	  	| expression T_MULTIPLY expression	{ printf(" multiply \n"); }
		| expression T_DIVIDE expression	{ printf(" divide \n"); }
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
