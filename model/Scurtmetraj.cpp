#include "headers/Scurtmetraj.h"
#include <string>

Scurtmetraj::Scurtmetraj(double durata, string &nume, string &categorie, int numarVizionari,
            const string &tipScurtmetraj) : Film(durata, nume, categorie, numarVizionari),
                                            tip_scurtmetraj(tipScurtmetraj) {}

void Scurtmetraj::afisare_scurtmetraj(Scurtmetraj scurtmetraj_afisat) {
    cout << endl;
    cout << scurtmetraj_afisat.getNume() << " " << scurtmetraj_afisat.getCategorie() << " " << scurtmetraj_afisat.getDurata() << " "
         << scurtmetraj_afisat.getNumarVizionari()<<scurtmetraj_afisat.getTipScurtmetraj();
}
