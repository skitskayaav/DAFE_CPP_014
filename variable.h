#ifndef VARIABLE_H
#define VARIABLE_H
#include "std_lib_facilities(1).h"

struct Variable{
    string name;
    double val;
    bool isConstant;
      Variable (string n, double v, bool c)
        : name{n}, val{v}, isConstant{c}
      { }
 };
struct Symbol_table
{
    vector<Variable> var_table;
    double get_value(string s);
    void set_value(string s, double d);
    bool is_declared(string s);
    double define_name(string var, double val, bool isConstant);
};
#endif // VARIABLE_H
