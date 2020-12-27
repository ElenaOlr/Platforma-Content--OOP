#include <iostream>
#include "headers/Film.h"

Film::Film(double durata, string& nume, string& categorie, int numar_vizionari) : durata(durata), nume(nume),
                                                                                    categorie(categorie),
                                                                                    numar_vizionari(numar_vizionari) {}

Film::Film(const Film &film_copiat) {
    durata = film_copiat.durata;
    nume = film_copiat.nume;
    categorie = film_copiat.categorie;
    numar_vizionari = film_copiat.numar_vizionari;
}


ostream &operator<<(std::ostream &os, const Film &film) {
    os << "durata: " << film.durata << " nume: " << film.nume << " categorie: " << film.categorie
       << " numar_vizionari: " << film.numar_vizionari;
    return os;
}

istream &operator>>(std::istream &input, Film &film) {
    input >> film.durata >> film.nume >> film.categorie >> film.numar_vizionari;
    return input;
}

void Film::afisare_film(const Film& film_afisat) {
    std::cout << std::endl;
    std::cout << film_afisat.getNume() << " " << film_afisat.getCategorie() << " " << film_afisat.getDurata() << " "
              << film_afisat.getNumarVizionari();
}

Film &Film::operator=(const Film &film_copiat) {
    nume = film_copiat.nume;
    durata = film_copiat.durata;
    categorie = film_copiat.categorie;
    numar_vizionari = film_copiat.numar_vizionari;

    return *this;
}

bool Film::operator==(const Film &film_comparat) {
    if(nume==film_comparat.nume)
        return true;
    else
        return false;
}

int operator+(const Film &f1, const Film &f2) {
    return f1.getDurata() + f2.getDurata();
}

int operator-(const Film &f1, const Film &f2) {
    return f1.getDurata() - f2.getDurata();
}

char &Film::operator[](int index) {
    return nume[index];
}

