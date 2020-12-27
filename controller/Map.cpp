
#include "headers/Map.h"
#include "../model/headers/Jpeg.h"
#include "../model/headers/Png.h"
#include <fstream>

Map::Map(string &fisierImaginiNoi) {
    fisierImagini = fisierImaginiNoi;
}

void Map::adaugareImagineInMap(string& numeImagine, string& tipImagine, int x, int y) {
    Imagine* imagine;
    if (tipImagine == "Jpeg") {
        imagine = new Jpeg(tipImagine, x, y);
    }
    else {
        imagine = new Png(tipImagine, x, y);
    }
    imagini.insert(pair<string, Imagine*>(numeImagine, imagine));
    scriereImaginiInFisier();
}

void Map::stergereImagineDinMap(string& nume) {
    imagini.erase(nume);
    scriereImaginiInFisier();
}

void Map::modificareImagineDinMap(string& nume, string& numeNou, string& tipImagineNou, int xNou, int yNou) {
    imagini.erase(nume);
    adaugareImagineInMap(numeNou, tipImagineNou, xNou, yNou);
}

void Map::citireImaginiDinFisier() {
    ifstream f(fisierImagini);
    if (!f.is_open())
        throw ifstream::failure("Nu s-a putut deschide fisierul spre citire!");

    string nume,tipImagine,x,y;
    while(getline(f, nume, ',')) {
        getline(f, tipImagine, ',');
        getline(f, x, ',');
        getline(f, y, '\n');
        Imagine* imagine;
        if (tipImagine == "Jpeg") {
            imagine = new Jpeg(tipImagine, stoi(x), stoi(y));
        }
        else {
            imagine = new Png(tipImagine, stoi(x), stoi(y));
        }
        imagini.insert(pair<string, Imagine*>(nume, imagine));
    }
    f.close();
}

Map::~Map() {}

void Map::scriereImaginiInFisier() {
    ofstream g(fisierImagini);
    if (!g.is_open())
        throw ofstream::failure("Nu s-a putut deschide fisierul spre scriere!");

    for (auto s : imagini)
        g << s.first << "," << s.second->getTipImagine() << "," << s.second->rezolutie_x << "," << s.second->rezolutie_y << '\n';

    g.close();
}
