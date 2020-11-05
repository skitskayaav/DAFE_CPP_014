#include "std_lib_facilities(1).h"
#include "variable.h"

double Symbol_table::get_value(string s){
    for (int i=0; i<var_table.size();i++)
        if (var_table[i].name == s)
            return var_table[i].val;
    error("get: undefined name ", s);
      }

bool Symbol_table::is_declared(string var){
    for (int i = 0; i < var_table.size(); i++)
           if (var_table[i].name == var) return true;
           else {
            return false;
       }
}


void Symbol_table::set_value(string s,double d){
    for (int i = 0; i < var_table.size(); ++i)
      {
        if (var_table[i].name == s)
           {
             if (var_table[i].isConstant == false){
             var_table[i].val = d;
             return;
             }
             error(s, " - const");
           }
         }
 }


double Symbol_table::define_name(string var, double val, bool isConstant)
{
  if (is_declared(var)) {
      error(var, " declared twice");
  }
    var_table.push_back(Variable {var,val,isConstant});
    return val;
}
