#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << trim_leading_zeros("-00");
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    cout << ">> ";
    string input;
    getline(cin,input);
    string num1, num2, op;
    std::istringstream inSS;
    inSS.str(input);
    inSS >> num1;
    while((num1 != "q") && (num1 != "quit")) {
      inSS >> op >> num2;
      if(op == "+") {
        cout << endl << "ans =" << endl << endl << "    " << add(num1, num2) << endl << endl;
      } else {
        cout << endl << "ans =" << endl << endl << "    " << multiply(num1, num2) << endl << endl;
      }
      cout << ">> ";
      getline(cin,input);
      inSS.clear();
      inSS.str(input);
      inSS >> num1;
    }
    cout << endl << "farvel!" << endl;
}

