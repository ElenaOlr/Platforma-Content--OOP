
#ifndef MAIN_CPP_MAP_H
#define MAIN_CPP_MAP_H

#include "../../model/headers/Imagine.h"
#include <string>
#include <map>
using namespace std;

class Map {
    map<string, Imagine*> imagini;
    string fisierImagini;
public:
    Map() {}
    Map(string& fisierImagini);

    void adaugareImagineInMap(string& nume, string& tipImagine, int x, int y);
    void stergereImagineDinMap(string& nume);
    void modificareImagineDinMap(string& nume, string& numeNou, string& tipImagineNou, int xNou, int yNou);
    map<string, Imagine*> getImagini() { return imagini;}
    void citireImaginiDinFisier();

    virtual ~Map();
private:
    void scriereImaginiInFisier();
};


#endif //MAIN_CPP_MAP_H
