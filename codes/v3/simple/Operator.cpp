#include "Operator.h"
#include <sstream>
#include <cmath>

Operator::Operator(const string & name,
                    Expression *left,
                    Expression *right): name_(name), left_(left), right_(right) {}

double Operator::eval()
{
    if(name_ == "+")
    {
        return left_->eval() + right_->eval();
    }
    else if(name_ == "-")
    {
        return left_->eval() - right_->eval();
    }
    else if(name_ == "*")
    {
  		return left_->eval() * right_->eval();
    }
    else if(name_ == "/")
    {
  		return left_->eval() / right_->eval();
    }

}

int Operator::precedence()
{
    if(name_ == "+" || name_ == "-") return 1;
    if(name_ == "*" || name_ == "/") return 2;
}

string Operator::to_string()
{
    stringstream s;
    if(left_->precedence() < precedence())
    {
        s << '(' << left_->to_string() << ')';
    }
    else
    {
        s << left_->to_string();
    }

    s << name_ ;

    if(right_->precedence() < precedence())
    {
        s << '(' << right_->to_string() << ')';
    }
    else
    {
        s << right_->to_string();
    }

    return s.str();
}

Operator::~Operator()
{
    delete left_;
    delete right_;
}
