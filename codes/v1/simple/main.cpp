#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <stdexcept>
#include <stack>
#include <cstdlib>

#include "Tokenizer.h"

using namespace std;


int main()
{

	Tokenizer tz("(2+3)");
    Token t;
    while(tz.getNext(t))
    {
        cout << t.value<< endl;
    }

    cout << "exit" << endl;
    return 0;
}