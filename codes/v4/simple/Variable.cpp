#include <stdexcept>
#include <sstream>
#include "Variable.h"

Variable::Variable(const string & name): name_(name){}

double Variable::eval(const map<string, double> &variables)
{
		const map<string, double>::const_iterator i= variables.find(name_);
		if(i == variables.end())
    {
    		throw runtime_error("Undefined variable: " + name_);
    }
    return i->second;
}

int Variable::precedence()
{
    return 55;
}

string Variable::to_string()
{
    return name_;
}
