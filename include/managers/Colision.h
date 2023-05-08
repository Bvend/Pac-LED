#pragma once

#include "List.h"
#include "Ent.h"

class Colision {
private:

    List<Ent>* pListEnt;

    int board[16][32];

public:
    Colision();
    Colision(List<Ent>* pL);
    ~Colision();

    void checkColisions();

    void fillBoard();

    /*void colisionEnt(){}
        A funçao verifica se a posição de duas entidades são iguais
        se forem iguais acontece o seguinte:

        character e parede : character volta a pos anterior
        player e ghost: player morre e é jogo encerrado
        player e cookie: cookie some


        Tem que ter ponteiro para player,  lista de character, lista de paredes e lista de cookies 
        ou fazer na class Entidades boleanos 
    */
};