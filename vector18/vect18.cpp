#include <iostream>
#include "vect18.h"
using namespace std;
    vector::vector(vector&& a)
        :sz{a.sz}, elem{a.elem}
    {
        a.sz=0;
        a.elem=nullptr;
    }

    vector& vector::operator=(const vector& a)
    {
        double*p=new double[a.sz];
        copy(a.elem, a.elem+a.sz, p);
        delete[] elem;
        elem=p;
        sz=a.sz;
        return *this;
    }

    vector::vector(const vector& arg)
        :sz{arg.sz}, elem{new double[arg.sz]}
    {
        for (int i = 0; i < sz; i++)
        {
            this->elem[i] = arg.elem[i];
        }
    }
    vector& vector::operator=(vector&& a)
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
