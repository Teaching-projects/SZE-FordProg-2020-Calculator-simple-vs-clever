#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <cctype>
#include <map>
#include <string>

using namespace std;

enum TokenType{
    Const,
    Operat,
    Openp,
    Closep,
    Var
};

struct Token{
    string value;
    TokenType type;
};

class Tokenizer
{
    public:
        Tokenizer(const string &input);
        bool getNext(Token &token);
    private:
        string input_;
        string::iterator current_;
        void skipWhitespace();
};

#endif // TOKENIZER_H
