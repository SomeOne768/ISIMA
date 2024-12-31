#ifndef LIST_CODE_HPP_AZ
#define LIST_CODE_HPP_AZ

template <typename T>
List_T<T>::List_T() : begin(nullptr) {}

template <typename T>
List_T<T>::~List_T()
{
    while (begin != nullptr)
    {
        Cell_T<T> *temp = begin;
        begin = begin->getNext();
        delete temp;
    }
}

template <typename T>
List_T<T>::List_T(const List_T &L)
{
    if (L.empty())
    {
        begin = nullptr;
    }
    else
    {
        begin = new typename Cell_T<T>::Cell_T(*(L.begin));
        // begin = new typename Cell_T<T>::template Cell_T(*(L.begin));

        Cell_T<T> *parcourir = begin;
        Cell_T<T> *current = L.begin->getNext();
        while (current)
        {
            parcourir->addNext(new typename Cell_T<T>::Cell_T(*current));
            parcourir = parcourir->getNext();
            current = current->getNext();
        }
    }
}

template <typename T>
bool List_T<T>::empty() const
{
    return begin == nullptr;
}

template <typename T>
void List_T<T>::push_back(Cell_T<T> *c)
{
    if (empty())
        begin = c;
    else
    {
        Cell_T<T> *curr = begin;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->addNext(c);
    }
}

template <typename T>
void List_T<T>::push_back(T t)
{
    push_back(new Cell_T<T>(t));
}

template <typename T>
void List_T<T>::display(std::ostream &os)
{
    if (!empty())
    {
        os << "[";

        Cell_T<T> *parcourir = begin;
        while (parcourir != nullptr)
        {
            os << parcourir->getData() << " ";
            parcourir = parcourir->getNext();
        }

        os << "]";
    }
}

template <typename T>
void List_T<T>::push_front(Cell_T<T> *c)
{
    c->addNext(begin);
    begin = c;
}

template <typename T>
void List_T<T>::push_front(T t)
{
    push_front(new Cell_T<T>(t));
}

template <typename T>
Cell_T<T> *List_T<T>::front()
{
    return begin;
}

template <typename T>
Cell_T<T> *List_T<T>::back()
{
    if (empty())
        return nullptr;

    Cell_T<T> *parcourir = begin;
    while (parcourir->getNext())
        parcourir = parcourir->getNext();

    return parcourir;
}

template <typename T>
Cell_T<T> *List_T<T>::pop_front()
{
    Cell_T<T> *out = begin;
    if (!empty())
        begin = begin->getNext();

    return out;
}

template <typename T>
Cell_T<T> *List_T<T>::pop_back()
{
    Cell_T<T> *out = begin;
    if (!empty())
    {
        Cell_T<T> *parcourir = begin->getNext();
        while (parcourir->getNext())
        {
            out = parcourir;
            parcourir = parcourir->getNext();
        }
        out->addNext(nullptr);
        out = parcourir;
    }

    return out;
}

template <typename T>
int List_T<T>::size()
{
    int compteur = 0;
    Cell_T<T> *parcourir = begin;
    while (parcourir)
    {
        compteur++;
        parcourir = parcourir->getNext();
    }

    return compteur;
}

template <typename T>
ItList<T> List_T<T>::find(T t) const
{
    ItList<T> it = this->beginIt();
    while (it != end() && (*it) != t)
    {
        it++;
    }

    return it;
}

template <typename T>
void List_T<T>::remove(ItList<T> &it)
{
    // Si on avait ajouter les prec ez
    // sinon methdoe 2:

    if (empty())
        return;

    Cell_T<T> *curr = it.cell;
    if (begin == curr)
    {   
        begin = begin->getNext();
        delete[] curr;
    }
    else
    {
        Cell_T<T> *next = curr->getNext();
        if (next)
        {
            curr->data = next->data;
            curr->addNext(next->getNext());
            delete[] next;
        }
    }
}

template <typename T>
void List_T<T>::insert(ItList<T> &it, T elt)
{
    Cell_T<T> *next = it.cell->getNext();
    Cell_T<T> *newElt = new Cell_T<T>{elt};
    it.cell->addNext(newElt);
    newElt->addNext(next);
}
#endif