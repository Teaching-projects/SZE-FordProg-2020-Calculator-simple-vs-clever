#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Tokenizer.h"

using namespace std;

class Expression
{
    public:
        virtual double eval() = 0;
        virtual ~Expression(){}
        virtual string to_string() = 0;
};

#endif // EXPRESSION_H
