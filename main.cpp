#include <iostream>
#include "std_lib_facilities(1).h"
#include "token.h"
#include "variable.h"

using namespace std;
Token_stream ts;
Symbol_table symbol_table;

double expression();
double statement();
double primary(){
      Token t = ts.get();
      switch (t.kind)
      {
      case '(':
      {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
          error("')' expected");
        return d;
      }

      case '+':
        return +primary();
      case '-':
        return -primary();
}
}

double term()
{
    double left = primary();
     while (true)
     {
       Token t = ts.get();
       switch (t.kind)
       {
       case '*':
         left *= primary();
         break;

       case '/':
       {
         double d = primary();
         if (d == 0) error("divide by zero");
         left /= d;
         break;
       }

       case '%':
       {
         int il = narrow_cast<int> (left) ;
         int i2 = narrow_cast<int> (primary());
         if (i2 == 0) error("% : деление на 0");
         left = il % i2;
         t=ts.get();
         break;
       }

       default:
         ts.putback(t);
         return left;
       }
     }
   }

double declaration(){
    Token t = ts.get();
    if (t.kind != name)
      error("name expected in declaration");

    string var = t.name;
    if (symbol_table.is_declared(var))
      error(var, " declared twice");

    t = ts.get();
    if (t.kind != '=')
      error("'=' missing in declaration of ", var);
    double d = expression();
    return symbol_table.define_name(var,d,true);

  }


double statement() {
    Token t = ts.get();
      switch (t.kind)
      {
      case let:
        return declaration();
      default:
        ts.putback(t);
        return expression();
      }
}

double expression(){
    double left = term();
      while (true)
      {
        Token t = ts.get();

        switch (t.kind)
        {
        case '+':
          left = left+term();
          break;

        case '-':
          left = left-term();
          break;

        default:
          ts.putback(t);
          return left;
        }
      }
}


void clean_up_mess(){
    ts.ignore(print);
}

void calculate ()
{
  while (cin)
  try
  {
    cout <<prompt;
    Token t = ts.get();
    while (t.kind == print)
      t = ts.get();
    if (t.kind == quit)
        return;
    ts.putback(t);
    cout << result << statement() << endl;
  }
  catch (runtime_error& e)
  {
    cerr << e.what() << endl;
    clean_up_mess();
  }
}


int main()
try {

    calculate();
    keep_window_open();
    return 0;
}
catch (exception& e)
    {
        cerr << "exception: " << e.what() << endl;
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception!" << endl;
        keep_window_open("~~");
        return 2;
    }




























