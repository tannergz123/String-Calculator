#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if(digit < '0' || digit > '9') {
      cout << digit;
      throw std::invalid_argument(""); 
    }
    return digit-'0';
}

char decimal_to_digit(unsigned int decimal) {
    if(decimal > 9) {
      throw std::invalid_argument("");
    }
    return (char)(decimal+'0');
}

string trim_leading_zeros(string num) {
    bool negative = false;
    if(num.at(0) == '-') {
      negative = true;
      num = num.substr(1,num.size()-1);
    }
    while(num.at(0) == '0' && num.size() > 1) {
      num = num.substr(1,num.size()-1);
    }
    return ((negative && num != "0")?"-":"")+num;
}

string add(string lhs, string rhs) {
    // TODO(sudent): implement

    int sign = 1;
    if(lhs.at(0) == '-') {
      sign =-1;
      lhs = lhs.substr(1,lhs.size()-1);
    }

    if(rhs.at(0) == '-') {
      sign = -1;
      rhs = rhs.substr(1,rhs.size()-1);
    }

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    string small;
    string large;

    if(lhs.size() > rhs.size()) {
      small = rhs;
      large = lhs;
    } else {
      small = lhs;
      large = rhs;
    }
    string ret = "";
    int carry = 0;
    for(unsigned int i = 0; i < small.size(); i++) {
      int digit = digit_to_decimal(small.at(small.size()-i-1));
      int digit2 = digit_to_decimal(large.at(large.size()-i-1));

      int total = digit2 + digit + carry;
      ret = decimal_to_digit(total%10) + ret;
      carry = total/10;
    }

    for(unsigned int i = 0; i < large.size()-small.size(); i++) {
      int digit2 = digit_to_decimal(large.at(large.size()-small.size()-1-i));
      int total = digit2 + carry;

      ret = decimal_to_digit(total%10) + ret;
      carry = total/10;
    }

    if(carry != 0) {
      ret = decimal_to_digit(carry) + ret;
     }

    if(sign == -1) {
      ret = "-" + ret;
    }
    return ret;
}

string multiply(string lhs, string rhs) {
    int sign = 1;
    if(lhs.at(0) == '-') {
      sign *=-1;
      lhs = lhs.substr(1,lhs.size()-1);
    }

    if(rhs.at(0) == '-') {
      sign *= -1;
      rhs = rhs.substr(1,rhs.size()-1);
    }
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    string ret = "0";
    for(unsigned int i = 0; i < lhs.size(); i++) {
      int digit = digit_to_decimal(lhs.at(lhs.size()-i-1));
      int carry = 0;
      string cur = "";
      for(unsigned int j = 0; j < rhs.size(); j++) {
        int digit2 = digit_to_decimal(rhs.at(rhs.size()-j-1));
        int total = (digit * digit2) + carry;
        cur = decimal_to_digit(total%10) + cur;
        carry = total/10;
      } 
      if(carry != 0) {
        cur = decimal_to_digit(carry) + cur;
      }
      for(unsigned int j = 0; j < i; j++) {
        cur += "0";
      }
      ret = add(ret, cur);
    }

    if(sign == -1) {
      ret = "-" + ret;
    }

    return ret;
}
