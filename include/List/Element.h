#pragma once
#include <stdio.h>

template <class ELEM> class Element {
private:
    Element <ELEM>* pProx;
    ELEM* item;

public:
    Element();
    ~Element();

    void setProx(Element<ELEM>* prox) { this->pProx = prox; }
    void setItem(ELEM* it) { this->item = it; }
    Element<ELEM>* getProx() { return pProx; }
    ELEM* getItem () { return item; }

    void deleteItem() { if (item) delete item; }
};

template<class ELEM>
inline Element<ELEM>::Element()
{
    pProx = NULL;
    item = NULL;
}
template<class ELEM>
inline Element<ELEM>::~Element()
{
    pProx = NULL;
    item = NULL;
}
