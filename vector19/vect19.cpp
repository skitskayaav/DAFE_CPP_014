#include "vect19.h"

template <typename T, typename A>
vector<T, A>::vector(const vector& arg)
{
    this->sz = arg.sz;
    this->elem = new T[arg.sz];
    copy(arg.elem, arg.elem+arg.sz, this->elem);
}

template <typename T, typename A>
vector<T,A>&  vector<T,A>::operator = (const vector& a)
{
    if (this == &a)
        return *this ;
    if (a.sz <= this->space)
    {
        for (int i = 0; i<a.sz; ++i)
            this->elem[i] = a.elem[i];
        this->sz = a.sz;
        return *this ;
    }
    T *p = new T [a.sz];
    for (int i = 0; i < a.sz; i++)
        p[i] = a.elem[i];
    delete[] this->elem;
    this->space = a.sz;
    this->elem = p;
    return *this;
}

template <typename T, typename A>
vector<T,A>::vector (vector&& a)
{
    this->sz = a.sz;
    this->elem = a.elem;
    a.sz = 0;
    a.elem = nullptr;
}

template <typename T, typename A>
vector<T,A>&  vector<T,A>::operator = (vector&& a)
{
    delete[] this->elem;
    this->elem = a.elem;
    this->sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

template <typename T, typename A>
void vector<T,A>::reserve (int newalloc)
{
    if (newalloc <= this->space)
        return;

    vector_base<T,A> b(this->alloc, newalloc);
    uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);
    for (int i = 0; i < this->sz; i++)
        this->alloc.destroy(&this->elem[i]);
    swap<vector_base<T, A>>(*this, b) ;
}
template <typename T, typename A>
void vector<T,A>::resize (int newsize, T value)
{
    this->reserve(newsize) ;
    for (int i = this->sz ; i < newsize ; ++i)
        this->alloc.construct(&this->elem[i], value);
    for (int i = this->sz ; i < newsize ; ++i)
        this->alloc.destroy(&this->elem[i]);
    this->sz = newsize;
}

template <typename T, typename A>
void vector<T,A>::push_back (const T& value)
{
    if (this->space == 0)
        reserve(8);
    else if (this->sz == this->space)
        reserve(2 * this->space);
    this->alloc.construct(&this->elem[this->sz], value);
    ++this->sz;
}

template <typename T, typename A>
T& vector<T,A>:: at (int n)
{
    if (n < 0 || this->sz <= n)
        throw out_of_range("out of range");
    return this->elem[n];
}

int main(){
    vector <int> vi={1,2,3};
    vector <string> vs={"one"};
    vector <float> vf={1.2,10.,15.1};
    vs.push_back("two");
    cout <<vf.capacity();
}
