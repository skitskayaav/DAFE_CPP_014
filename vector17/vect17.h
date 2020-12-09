#ifndef VECT17_H
#define VECT17_H
#include <iostream>
using namespace std;
class vector{
    int sz;
    double *elem;

public:
    vector(int sz);
    int size() const;
    ~vector();

    double get(int n) const;
    void set(int n, double val);
};


#endif // VECT17_H
