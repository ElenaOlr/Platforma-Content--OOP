
#ifndef MAIN_CPP_SCURTMETRAJ_H
#define MAIN_CPP_SCURTMETRAJ_H

#include "Film.h"
#include <iostream>
using namespace std;

class Scurtmetraj : public Film {
    string tip_scurtmetraj;
public:
    Scurtmetraj() {}
    Scurtmetraj(double durata, string &nume, string &categorie, int numarVizionari, const string &tipScurtmetraj);

    virtual ~Scurtmetraj() {}

    const string &getTipScurtmetraj() const { return tip_scurtmetraj;}
    void setTipScurtmetraj(const string &tipScurtmetraj) { tip_scurtmetraj = tipScurtmetraj; }

    void afisare_scurtmetraj(Scurtmetraj scurtmetraj_afisat);
};


#endif //MAIN_CPP_SCURTMETRAJ_H
