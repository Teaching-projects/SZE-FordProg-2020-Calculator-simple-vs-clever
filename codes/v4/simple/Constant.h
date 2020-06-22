#ifndef CONSTANT_H
#define CONSTANT_H

#include <iostream>
#include <string>
#include <map>

#include "Expression.h"

using namespace std;

class Constant: public Expression
{
    public:
		Constant(double value);

        virtual double eval(const map<string, double> &variables);
        virtual string to_string();
        virtual int precedence();
    private:
		double value_;
};



#endif // CONSTANT_H
