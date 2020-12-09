#ifndef VECT18_H
#define VECT18_H
#include <iostream>
using namespace std;
class vector{
    int sz;
    double *elem;

public:
    vector(int sz):sz{sz},elem { new double [sz]}
    {  for (int i = 0; i < sz; ++i)
        elem[i] = 0;
     }
    int size() const{
        return sz;
    }

    vector(vector&& a);
    vector& operator=(vector&&);
    vector(const vector&);
    vector& operator=(const vector&);
    vector(initializer_list<double> lst);

    double &operator[](int n){
        return elem[n];
    }
    double &operator[](int n) const{
        return elem[n];
    }


    double get(int n) const{
        return elem[n];
    }
    void set(int n, double val){
        elem[n]=val;
    }

    ~vector() {
        delete [] elem;
    }
};





#endif // VECT18_H
