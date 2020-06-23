#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>
#include <map>

#include "Expression.h"

using namespace std;

class Operator: public Expression
{
  public:
		Operator(const string & name,
             Expression *left,
             Expression *right);
      virtual ~Operator();
      virtual double eval();
      virtual string to_string();
    
  private:
		string name_;
    Expression *left_;
    Expression *right_;
};



#endif // OPERATOR_H
