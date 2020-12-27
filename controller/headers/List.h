
#ifndef MAIN_CPP_LIST_H
#define MAIN_CPP_LIST_H

#include "../../model/headers/Film.h"
#include <list>

class List {
string fisierFilme;
list<Film> filme;
public:
    List() {}
    List(string& fisierFilme);

    void adaugareFilmInLista(double durata, string& nume, string& categorie, int numar_vizionari);
    void stergereFilmDinLista(string& nume, string& categorie);
    void modificareFilmDinLista(string& nume, string& categorie, double durataNoua, string& numeNou, string& categorieNoua,
                                int numar_vizionariNou);
    list<Film> getFilme() {return filme;}
    void citireFilmeDinFisier();

    virtual ~List();
private:
    void scriereFilmeInFisier();

};


#endif //MAIN_CPP_LIST_H
