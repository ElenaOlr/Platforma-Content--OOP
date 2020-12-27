#include "headers/List.h"
#include <fstream>

List::List(string &fisierFilmeNou) { fisierFilme = fisierFilmeNou; }

List::~List() {}

void List::adaugareFilmInLista(double durata, string &nume, string &categorie, int numar_vizionari) {
    Film film{durata, nume, categorie, numar_vizionari};
    filme.push_back(film);
    scriereFilmeInFisier();
}

void List::stergereFilmDinLista(string &nume, string &categorie) {
    Film filmCurent;
    for (auto& film : filme) {
        if (film.getNume() == nume && film.getCategorie() == categorie) {
            filmCurent = film;
        }
    }
    filme.remove(filmCurent);
    scriereFilmeInFisier();
}

void List::modificareFilmDinLista(string &nume, string &categorie, double durataNoua, string &numeNou, string &categorieNoua, int numar_vizionariNou) {
    for (auto& film : filme) {
        if (film.getNume() == nume && film.getCategorie() == categorie) {
            Film filmNou{durataNoua, numeNou, categorieNoua, numar_vizionariNou};
            film = filmNou;
        }
    }
    scriereFilmeInFisier();
}

void List::citireFilmeDinFisier() {
    ifstream f(fisierFilme);
    if (!f.is_open())
        throw ifstream::failure("Nu s-a putut deschide fisierul spre citire!");

    string nume,categorie, durata, numarVizionari;
    while(getline(f, nume, ',')) {
        getline(f, categorie, ',');
        getline(f, durata, ',');
        getline(f, numarVizionari, '\n');
        Film film{stod(durata), nume, categorie, stoi(numarVizionari)};
        filme.push_back(film);
    }
    f.close();
}

void List::scriereFilmeInFisier() {
    ofstream g(fisierFilme);
    if (!g.is_open())
        throw ofstream::failure("Nu s-a putut deschide fisierul spre scriere!");

    for (auto& f : filme)
        g << f.getNume() << ',' << f.getCategorie() << ',' << f.getDurata() << ',' << f.getNumarVizionari() << '\n';

    g.close();
}



