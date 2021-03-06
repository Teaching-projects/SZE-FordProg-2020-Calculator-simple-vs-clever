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

string Operator::to_string()
{
    stringstream s;

    s<<left_->to_string() << name_ << right_->to_string();

    return s.str();
}

Operator::~Operator()
{
    delete left_;
    delete right_;
}
