#ifndef MAIN_CPP_SET_H
#define MAIN_CPP_SET_H


#include "../../model/headers/Scurtmetraj.h"
#include <set>
class Set {
    set<Scurtmetraj> scurtmetraje;
    string fisierScurtmetraje;
public:
    Set() {}
    Set(string& fisierScurtmetrajeNou);

    void adaugareScurtmetrajInSet(string& tipScurtmetraj, double durata, string& nume, string& categorie, int numar_vizionari);
    void stergereScurtmetrajDinSet(string& tipScurtmetraj, string& nume);
    void modificareScurtmetrajDinSet(string& tipScurtmetraj, string& nume, string& tipNou, double durataNoua, string& numeNou,
                                     string& categorieNoua, int numar_vizionariNou);

    set<Scurtmetraj> getScurtmetraje() {return scurtmetraje;}
    void citireScurtmetrajeDinFisier();

    virtual ~Set();
private:
    void scriereScurtMetrajeInFisier();
};


#endif //MAIN_CPP_SET_H
