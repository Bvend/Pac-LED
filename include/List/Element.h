#pragma once
#include <stdio.h>

template <class ELEM> class Element {
private:
    Element <ELEM>* pNext;
    ELEM* item;

public:
    Element();
    ~Element();

    void setNext(Element<ELEM>* pnext) { this->pNext = pnext; }
    void setItem(ELEM* it) { this->item = it; }
    Element<ELEM>* getNext() { return pNext; }
    ELEM* getItem () { return item; }

    void deleteItem() { if (item) delete item; }
};

template<class ELEM>
inline Element<ELEM>::Element()
{
    pNext = NULL;
    item = NULL;
}
template<class ELEM>
inline Element<ELEM>::~Element()
{
    pNext = NULL;
    item = NULL;
}
