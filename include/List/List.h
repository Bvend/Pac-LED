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

    Element<LIST>* getFirst() { return pFirst; }

    LIST* getItem(int position){
        Element<LIST>* temp = pFirst;
        if (position == 0)
            return temp->getItem();
        for (int i=0; i<position; i++){
            temp = temp->getNext();
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
         pLast->setNext(temp);
         pLast = temp;
        }
        amount++;
    }

    void pop(LIST* it){
        Element<LIST>* temp = pFirst;
        Element<LIST>* tempPrev = NULL;

        while(temp->getItem()!= it){
            tempPrev = temp;
            temp = temp->getNext();
        }
        if (temp == pFirst){
            pFirst = temp->getNext();
        }
        else if (temp == pLast){
            tempPrev->setNext(NULL);
            pLast = tempPrev;
        }
        else {
            tempPrev->setNext(temp->getNext());
        }
        delete temp;
        amount--;
    }

    void clear() {
        if (pFirst){
			Element<LIST>* temp = pFirst;
			int i = 0;

			while (temp != NULL && i < amount){
					pFirst = (temp->getNext());
					delete temp;
					temp = pFirst;
					i++;
			}

		}
		pLast = NULL;
		amount = 0;
    }

    void clearAndDelete() {
        if (pFirst){
			Element<LIST>* temp = pFirst;
			int i = 0;

			while (temp != NULL && i < amount){
					pFirst = (temp->getNext());
                    temp->deleteItem();
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
