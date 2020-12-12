#include <iostream>
#include "vect18.h"
using namespace std;
  
    vector& vector::operator=(const vector& a) ///копирующий оператор
    {
        double*p=new double[a.sz];
        copy(a.elem, a.elem+a.sz, p);
        delete[] elem;
        elem=p;
        sz=a.sz;
        return *this;
    }

    vector::vector(const vector& arg)           ///копирующее присваивание
        :sz{arg.sz}, elem{new double[arg.sz]}
    {
        copy(arg,arg+sz,elem);
    }


    vector::vector(vector&& a)                  ///перемещ. конструктор
        :sz{a.sz}, elem{a.elem}
    {
        a.sz=0;
        a.elem=nullptr;
    }

    vector& vector::operator=(vector&& a)           ///перемещающий оператор
    {
        delete[] elem;
        elem=a.elem;
        sz=a.sz;
        a.elem=nullptr;
        a.sz=0;
        return *this;
    }
    vector::vector(initializer_list<double>lst){
                       sz=lst.size();
                       elem=new double [sz];
                       copy(lst.begin(), lst.end(), elem);
    }
