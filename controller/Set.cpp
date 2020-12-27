#include "headers/Set.h"
#include <fstream>

Set::Set(string &fisierScurtmetrajeNou) {
    fisierScurtmetraje = fisierScurtmetrajeNou;
}

void Set::adaugareScurtmetrajInSet(string &tipScurtmetraj, double durata, string &nume, string &categorie,
                                   int numar_vizionari) {
    Scurtmetraj scurtmetraj{durata, nume, categorie, numar_vizionari, tipScurtmetraj};
    scurtmetraje.insert(scurtmetraj);
    scriereScurtMetrajeInFisier();
}

void Set::stergereScurtmetrajDinSet(string &tipScurtmetraj, string &nume) {
    Scurtmetraj scurtmetrajCurent;
    for (auto& scurtmetraj : scurtmetraje) {
        if (scurtmetraj.getNume() == nume && scurtmetraj.getTipScurtmetraj() == tipScurtmetraj) {
            scurtmetrajCurent = scurtmetraj;
        }
    }
    scurtmetraje.erase(scurtmetrajCurent);
    scriereScurtMetrajeInFisier();
}

void Set::modificareScurtmetrajDinSet(string &tipScurtmetraj, string &nume, string &tipNou, double durataNoua,
                                      string &numeNou, string &categorieNoua, int numar_vizionariNou) {
    Scurtmetraj scurtmetrajCurent;
    for (auto& scurtmetraj : scurtmetraje) {
        if (scurtmetraj.getNume() == nume && scurtmetraj.getTipScurtmetraj() == tipScurtmetraj) {
            scurtmetrajCurent = scurtmetraj;
        }
    }
    scurtmetraje.erase(scurtmetrajCurent);
    adaugareScurtmetrajInSet(tipNou, durataNoua, numeNou, categorieNoua, numar_vizionariNou);
}

void Set::citireScurtmetrajeDinFisier() {
    ifstream f(fisierScurtmetraje);
    if (!f.is_open())
        throw ifstream::failure("Nu s-a putut deschide fisierul spre citire!");

    string tip, nume,categorie, durata, numarVizionari;
    while(getline(f, tip, ',')) {
        getline(f, nume, ',');
        getline(f, categorie, ',');
        getline(f, durata, ',');
        getline(f, numarVizionari, '\n');
        Scurtmetraj scurtmetraj{stod(durata), nume, categorie, stoi(numarVizionari), tip};
        scurtmetraje.insert(scurtmetraj);
    }
    f.close();
}

Set::~Set() {}

void Set::scriereScurtMetrajeInFisier() {
    ofstream g(fisierScurtmetraje);
    if (!g.is_open())
        throw ofstream::failure("Nu s-a putut deschide fisierul spre scriere!");

    for (auto& f : scurtmetraje)
        g << f.getTipScurtmetraj() << ',' << f.getNume() << ',' << f.getCategorie() << ',' << f.getDurata() << ',' << f.getNumarVizionari() << '\n';

    g.close();
}
