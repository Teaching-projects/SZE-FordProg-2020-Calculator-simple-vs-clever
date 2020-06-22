#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>
#include <map>

#include "Expression.h"

using namespace std;

class Variable: public Expression
{
public:
    Variable(const string & name);

    virtual double eval(const map<string, double> &variables);
    virtual string to_string();
    virtual int precedence();
private:
    string name_;
};



#endif // VARIABLE_H
