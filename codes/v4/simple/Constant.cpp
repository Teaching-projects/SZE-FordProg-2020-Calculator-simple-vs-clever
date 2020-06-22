#include "Constant.h"
#include <sstream>


Constant::Constant(double value): value_(value){}

double Constant::eval(const map<string, double> &variables)
{
    return value_;
}

int Constant::precedence()
{
    return 55;
}

string Constant::to_string()
{
    stringstream s;
    s<<value_;
    return s.str();
}
