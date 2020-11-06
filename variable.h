#ifndef VARIABLE_H
#define VARIABLE_H

#include "std_lib_facilities(1).h"

struct Variable
{
  string name;
  double value;
  bool constant;
  Variable (string n, double v, bool c);
};

class Symbol_table{
private:
    vector<Variable> var_table;
public:
    double get_value (string s);
    void set_value (string s, double d);
    bool is_declared (string s);
    double define_name (string var, double val, bool isconst);
    void print_values();
};


#endif // VARIABLE_H
