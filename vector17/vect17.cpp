#include <iostream>
#include "vect17.h"
using namespace std;
    vector::vector(int sz):sz{sz},elem { new double [sz]}
        {  for (int i = 0; i < sz; ++i)
            elem[i] = 0;
         };

    int vector::size() const
        { return sz; };

    vector::~vector()
        { delete [] elem; };

    double vector::get(int n) const
        { return elem[n]; }

    void vector::set(int n, double val){
        elem[n]=val;
    }
