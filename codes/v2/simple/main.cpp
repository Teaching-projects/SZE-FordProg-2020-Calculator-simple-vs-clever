#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <stack>

#include "Tokenizer.h"
#include "Expression.h"
#include "Constant.h"
#include "Operator.h"

using namespace std;

int precedence(const Token &t)
{
	if(t.value == "+" || t.value == "-") return 1;
    if(t.value == "*" || t.value == "/") return 2;
}

vector<Token> postfixExpr(const string &input)
{
      Tokenizer tz(input);
      Token t;
      stack<Token> s;
      vector<Token> result;
      while(tz.getNext(t))
      {
        if(t.type == Operat)
        {
          while(not s.empty() && precedence(s.top()) >= precedence(t))
          {
            result.push_back(s.top());
            s.pop();
          }
          s.push(t);
        }
        else if(t.type == Openp)
        {
            s.push(t);
        }
        else if(t.type == Closep)
        {
          while(not s.empty() && s.top().type != Openp)
          {
            result.push_back(s.top());
            s.pop();
          }
          s.pop();
        }
        else
        {
            result.push_back(t);
        }
      }
      while(not s.empty())
      {
        result.push_back(s.top());
        s.pop();
      }
      return result;
}

int main()
{

    // vector<Token> postfix = postfixExpr("2+3*4+5");
    // for(vector<Token>::iterator i = postfix.begin(); i != postfix.end(); ++i)
    // {
    //     cout << i->value << endl;
    // }


    Constant *c = new Constant(2.0);
    Constant *c2 = new Constant(5.0);

    Expression *root = new Operator("*", c, c2);

    //asd
    map<string, double> variables;
    variables["x"] = 3.0;
    
    cout << root->to_string() << endl;
    cout << "=" << root->eval(variables) << endl;

	cout << "-------" << endl;
    return 0;
}