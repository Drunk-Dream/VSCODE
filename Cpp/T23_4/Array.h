#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>

template <typename T>
class Array
{
    friend std::ostream &operator<<(std::ostream &, const Array<T> &);
    friend std::ostream &operator>>(std::ostream &, Array<T> &);

public:
    explicit Array(int = 10); //default constructor
    Array(const Array &);     //copy constructor
    ~Array();                 //destructor
    size_t getSize() const;   //return size

    const Array &operator=(const Array &); //assignment operator
    bool operator==(const Array &) const;  //equality operator
    bool operator!=(const Array &right) const
    {
        return !(*this == right);
    }
    //返回下标对应值的引用
    T &operator[](int);
    //返回不可修改的下标对应值
    T operator[](int) const;

private:
    size_t size;
    T *ptr;
};

#endif