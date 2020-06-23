#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Tokenizer.h"

using namespace std;

class Expression
{
    public:
        virtual double eval(const map<string, double> &variables) = 0;
        virtual ~Expression(){}
        virtual string to_string() = 0;
        virtual int precedence()=0;
};

#endif // EXPRESSION_H
