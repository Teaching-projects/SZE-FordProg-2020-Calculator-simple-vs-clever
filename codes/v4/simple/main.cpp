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
#include "Variable.h"
#include "Operator.h"


using namespace std;

int precedence(const Token &t)
{
    if(t.value == "+" || t.value == "-") return 1;
    if(t.value == "*" || t.value == "/") return 2;
    if(t.value == "^" ) return 3;
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

void inputpostfixevaluator(string inp, const map<string, double> &variables){

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
        else if(i->type == Var)
        {
            s.push(new Variable(i->value));
        }
    }
    Expression *root = s.top();

    //    variables["x"] = 12345.0;
    cout << root->to_string() << '=' << root->eval(variables) << endl << endl;
    delete root;
}

void inpVariable(map<string, double> &variables)
{
    string inpvar;
    string value;

    cout << "Adj meg egy valtozot."<< endl;
    getline (cin,inpvar);

    while(not inpvar.empty())
    {
        cout << "Adj meg a valtozo ereteket."<< endl;
        getline (cin,value);
        variables[inpvar]=strtod(value.c_str(), NULL);

        cout << "Adj meg egy valtozot."<< endl;
        getline (cin,inpvar);
    }

}

void printVariables(map<string, double> &variables)
{
    system("cls");          //WINDOWS
    //system("clear");      //LINUX

    cout <<"------------------------------------------"<< endl;
    cout <<"A felhasznalhato valtozok a kovetkezok:"<< endl;
    for (map<string, double>::iterator it=variables.begin(); it!=variables.end(); ++it)
    {
            cout << it->first << " = " << it->second << endl;
    }
    cout <<"------------------------------------------"<< endl;
    cout << endl;
}

int main()
{
    string inp;
    string inp2;
    map<string, double> variables;

    inpVariable(variables);
    printVariables(variables);

    while(true)
    {
        cout << "Adj meg egy meg kifejezest!"<< endl ;
        //cin >> inp;

        getline (cin,inp);
        if(inp.empty()){break;}
        inputpostfixevaluator(inp, variables);

        cout << "Szeretnel tovabbi kifejezest megadni? (y/n)"<< endl ;
        //cin >> inp2;
        getline (cin,inp2);

        if(inp2.compare("y")!=0){
            return 0;
        }

    }

//    vector<Token> postfix = postfixExpr("2^3+(2+3)*4+5");

//    for(vector<Token>::iterator i = postfix.begin(); i != postfix.end(); ++i)
//    {
//        cout << i->value ;
//    }

    //----------------
//    cout << endl;
//    for(vector<Token>::iterator i = postfix.begin(); i != postfix.end(); ++i)
//    {
//        cout << i->type ;
//    }
    //-----------------



    return 0;
}
