#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <stack>
#include <cstdlib>

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

void inputpostfixevaluator(string inp){

    vector<Token> postfix = postfixExpr(inp);
    stack<Expression*> s;

    for(vector<Token>::iterator i = postfix.begin(); i != postfix.end(); ++i)
    {
        if(i->type == Operat)
        {
        Expression *right = s.top();
        s.pop();
        Expression *left = s.top();
        s.pop();
        s.push(new Operator(i->value, left, right));
        }
        else if(i->type == Const)
        {
            s.push(new Constant(strtod(i->value.c_str(), NULL)));
        }
    }
    Expression *root = s.top();

    //    variables["x"] = 12345.0;
    cout << root->to_string() << '=' << root->eval() << endl << endl;
    delete root;
}

int main()
{
    string inp;
    string inp2;
 

    while(true)
    {
        cout << "Adj meg egy meg kifejezest!"<< endl ;
        getline (cin,inp);

        if(inp.empty()){break;}
        inputpostfixevaluator(inp);

        cout << "Szeretnel tovabbi kifejezest megadni? (y/n)"<< endl ;
        getline (cin,inp2);

        if(inp2.compare("y")!=0){
            return 0;
        }

    }


    return 0;
}
