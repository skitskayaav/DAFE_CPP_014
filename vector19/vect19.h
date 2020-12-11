#ifndef VECT19_H
#define VECT19_H
#include <iostream>
using namespace std;

template <typename T, typename A>
class vector_base
{
public:
    int sz;
    T *elem;
    int space;
    A alloc;
    vector_base()
    {
        sz = 0;
        space = 0;
        elem = nullptr;
    }
    vector_base(A &a, int n)
    {
        alloc = a;
        elem = a.allocate(n);
        sz = n;
        space = n;
    }
    ~vector_base()
    {
        alloc.deallocate(elem, space);
    }
};

template <typename T, typename A = allocator<T>>
class vector:
        private vector_base<T,A>
{
public:
    vector()
    {
        this->sz = 0;
        this->elem = nullptr;
        this->space = 0;
    };

    vector(initializer_list<T> lst)
    {
        this->sz = lst.size();
        this->elem = new T[this->sz];
        copy(lst.begin(), lst.end (), this->elem) ;
    }

    explicit vector(int s)
    {
        this->sz =  s;
        this->space = s;
        this->elem = new T[s];
    }

    int size()
    {
        return this->sz;
    }

    ~vector()
    {
        delete[] this->elem;
    }

    vector(const vector&);
    vector& operator= (const vector&);
    vector (vector&& );
    vector& operator= (vector&&);
    T& operator [] (int n)
    {
        return this->elem[n];
    }
    const T& operator [] (int n) const
    {
        return this->elem[n];
    }

    void reserve(int newalloc);
    int capacity () const
    {
        return this->space;
    }
    void resize(int newsize , T value = T());
    void push_back (const T& value);

    T& at (int n);
    const T& at (int n) const;
};




#endif // VECT19_H
