#ifndef CELL_CODE_HPP_AZ
#define CELL_CODE_HPP_AZ


template <typename T>
Cell_T<T>::Cell_T(T t) 
{
    next = nullptr;
    previous = nullptr;
    data = t;
}

template <typename T>
Cell_T<T>::Cell_T(const Cell_T &t) : Cell_T(t.data)
{
    
}

template <typename T>
const T Cell_T<T>::getData() const
{
    return data;
}


template <typename T>
void Cell_T<T>::addNext(Cell_T * c)
{
    next = c;
}


template <typename T>
void Cell_T<T>::addPrev(Cell_T * c)
{
    previous = c;
}

template <typename T>
Cell_T<T>* Cell_T<T>::getNext() const 
{
    return next;
}

template <typename T>
Cell_T<T>* Cell_T<T>::getPrev() const 
{
    return previous;
}

#endif