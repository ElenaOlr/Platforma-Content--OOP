
#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H


#include "../../model/headers/Serial.h"
#include <vector>

class Vector {
    vector<Serial> seriale;
    string fisierSeriale;
public:
    Vector() {}
    Vector(string& fisierSeriale);

    void adaugareSerialInVector(string& nume, string& actorPrincipal, string& producator, string& regizor, int durata, int numarEpisoade);
    void stergereSerialDinVector(string& nume, string& actorPrincipal);
    void modificareSerialDinVector(string& nume, string& actorPrincipal, string& numeNou, string& actorPrincipalNou,
                                   string& producatorNou, string& regizorNou, int durataNoua, int numarEpisoadeNou);
    Serial gasesteSerial(const std::string& nume, const std::string& actor_principal);
    int gasestePozitiaSerialuluiInVector(Serial s);
    vector<Serial> getSeriale() {return seriale;}
    void citireSerialeDinFisier();

    virtual ~Vector();
private:
    void scriereSerialeInFisier();
};


#endif //MAIN_CPP_VECTOR_H
