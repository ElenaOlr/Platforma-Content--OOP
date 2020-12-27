
#ifndef MAIN_CPP_UI_H
#define MAIN_CPP_UI_H


#include "../../controller/headers/Controller.h"

class UI {
private:
    Controller controller;
public:
    UI(const Controller& controller);
    void meniuPrincipal();
    ~UI();
private:
    static void printMeniuPrincipal();
    static void printMeniuSeriale();
    static void printMeniuFilme();
    static void printMeniuImagini();
    static void printMeniuScurtmetraje();

    void adaugaSerialInVector();
    void stergeSerialDinVector();
    void modificaSerialDinVector();
    void afiseazaSeriale();

    void adaugaFilmInLista();
    void stergeFilmDinLista();
    void modificaFilmDinLista();
    void afiseazaFilme();

    void adaugaImaginiInMap();
    void stergeImaginiDinMap();
    void modificaImaginiDinMap();
    void afiseazaImagini();

    void adaugaScurtmetrajeInSet();
    void stergeScurtmetrajeDinSet();
    void modificaScurtmetrajeDinSet();
    void afiseazaScurtmetraje();
};


#endif //MAIN_CPP_UI_H
