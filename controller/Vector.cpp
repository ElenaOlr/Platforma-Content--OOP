#include "headers/Vector.h"
#include <fstream>
#include <string>

Vector::Vector(string& fisierNouSeriale) { fisierSeriale = fisierNouSeriale; }

Vector::~Vector() {}

void Vector::adaugareSerialInVector(string& nume, string& actorPrincipal, string& producator, string& regizor,
                                    int durata, int numarEpisoade) {
    Serial serial{durata, numarEpisoade, nume, actorPrincipal, producator, regizor};
    seriale.push_back(serial);
    scriereSerialeInFisier();
}

void Vector::stergereSerialDinVector(string& nume, string& actorPrincipal) {
    Serial serialCurent = gasesteSerial(nume, actorPrincipal);
    int index = gasestePozitiaSerialuluiInVector(serialCurent);
    if (index == -1)
        throw out_of_range("Nu s-a gasit serialul in vector!");
    seriale.erase(seriale.begin() + index);
    scriereSerialeInFisier();
}

void Vector::modificareSerialDinVector(string& nume, string& actorPrincipal, string& numeNou, string& actorPrincipalNou,
                                       string& producatorNou, string& regizorNou, int durataNoua, int numarEpisoadeNou) {
    Serial serialCurent = gasesteSerial(nume, actorPrincipal);
    int index = gasestePozitiaSerialuluiInVector(serialCurent);
    if (index == -1)
        throw out_of_range("Nu s-a gasit serialul in vector!");
    Serial serialModificat{durataNoua, numarEpisoadeNou, numeNou, actorPrincipalNou, producatorNou, regizorNou};
    seriale[index] = serialModificat;
    scriereSerialeInFisier();
}

Serial Vector::gasesteSerial(const std::string& nume, const std::string& actor_principal)
{
    for (auto s : seriale)
    {
        if (s.getNume() == nume && s.getActor_principal() == actor_principal )
            return s;
    }

    return Serial{};

}

int Vector::gasestePozitiaSerialuluiInVector(Serial s)
{
    for (int i = 0; i < seriale.size(); i++)
        if (s.getNume() == seriale[i].getNume() && s.getActor_principal() == seriale[i].getActor_principal())
            return i;
    return -1;
}

void Vector::citireSerialeDinFisier() {
    ifstream f(fisierSeriale);
    if (!f.is_open())
        throw ifstream::failure("Nu s-a putut deschide fisierul spre citire!");


    string nume,actorPrincipal, producator, regizor, durata, numarEpisoade;
    while(getline(f, nume, ',')) {
        getline(f, actorPrincipal, ',');
        getline(f, producator, ',');
        getline(f, regizor, ',');
        getline(f, durata, ',');
        getline(f, numarEpisoade, '\n');
        Serial serial{stoi(durata), stoi(numarEpisoade), nume, actorPrincipal, producator, regizor};
        seriale.push_back(serial);
    }
    f.close();
}

void Vector::scriereSerialeInFisier() {
    ofstream g(fisierSeriale);
    if (!g.is_open())
        throw ofstream::failure("Nu s-a putut deschide fisierul spre scriere!");

    for (auto s : seriale)
        g << s.getNume() << ',' << s.getActor_principal() << ',' << s.getProducator() << ',' << s.getRegizor() << ',' <<
        s.getDurata() << ',' << s.getNumar_episoade() << '\n';

    g.close();
}
