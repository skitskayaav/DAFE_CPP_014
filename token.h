#ifndef TOKEN_H
#define TOKEN_H

#include "std_lib_facilities(1).h"

constexpr double pi=3.1415926353;
constexpr double e=2.7182818284;
constexpr int k=1000;

const char quit='q';
const char print=';';

const string prompt = ">";
const string result= "=";

const char name = 'a';
const char let = 'l';

const string declkey = "let";
const string Exit = "exit";
const string showval = "show";


class Token
{
        public:
        char kind;
        double value;
        string name;
        Token(char ch): kind {ch}{}
        Token (char ch, double v): kind {ch}, value{v}{}
        Token (char ch, string n): kind {ch}, name{n}{}
};

class Token_stream
{
private:
    bool full{false};
    Token buffer{ '\0' };

  public:
    Token_stream () { }

    Token get ();
    void putback (Token t);

    void ignore (char c);
 };

#endif // TOKEN_H

