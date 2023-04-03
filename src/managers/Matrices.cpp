#include "managers/Matrices.h"

Matrices::Matrices(int data, int clock, int store, int bitOrder) :
data(data), clock(clock), store(store), bitOrder(bitOrder) { }

Matrices::~Matrices() { }

void Matrices::retainInfo() {
    // Talvez tenhamos que mudar a função delay no futuro pq ela pausa o programa completamente
    digitalWrite(store, HIGH); delayMicroseconds(10); 
    digitalWrite(store, LOW); delayMicroseconds(10);
}

void Matrices::draw() {
    
}