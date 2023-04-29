#pragma once
#include "Element.h"

template <class LIST> class List {
private:
    Element<LIST>* pFirst;
    Element<LIST>* pLast;
    int amount;

public:
    List();
    ~List();

    int getAmount() { return amount; }

    Element<LIST>* getPrimeiro() { return pFirst; }

    LIST* getItem(int position){
        Element<LIST>* temp = pFirst;
        if (position == 0)
            return temp->getItem();
        for (int i=0; i<position; i++){
            temp = temp->getProx();
        }
        return temp->getItem();
    }

    void push(LIST* it){
        if (pFirst == NULL){
            pFirst = new Element<LIST>;
            pFirst->setItem(it);
            pLast = pFirst;
        }
        else {
         Element<LIST>* temp = new Element<LIST>;
         temp->setItem(it);
         pLast->setProx(temp);
         pLast = temp;
        }
        amount++;
    }

    void pop(LIST* it){
        Element<LIST>* temp = pFirst;
        Element<LIST>* tempAnt = NULL;

        while(temp->getItem()!= it){
            tempAnt = temp;
            temp = temp->getProx();
        }
        if (temp == pFirst){
            pFirst = temp->getProx();
        }
        else if (temp == pLast){
            tempAnt->setProx(NULL);
            pLast = tempAnt;
        }
        else {
            tempAnt->setProx(temp->getProx());
        }
        delete temp;
        amount--;
    }

    void clear() {
        if (pFirst){
			Element<LIST>* temp = pFirst;
			int i = 0;

			while (temp != NULL && i < amount){
					pFirst = (temp->getProx());
					delete temp;
					temp = pFirst;
					i++;
			}

		}
		pLast = NULL;
		amount = 0;
    }

};

template <class LIST>
inline List<LIST>::List()
{
    pFirst = NULL;
    pLast = NULL;
    amount = 0;
}

template <class LIST>
inline List<LIST>::~List()
{
    clear();
}
