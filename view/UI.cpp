

#include "headers/UI.h"
#include <iostream>
#include <fstream>
#include <map>

UI::UI(const Controller &controller) : controller(controller) {}

UI::~UI() {}

void UI::printMeniuPrincipal() {
    cout << "--Meniu principal--" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Serial" << endl;
    cout << "2.Film" << endl;
    cout << "3.Scurtmetraj" << endl;
    cout << "4.Imagine" << endl;
}

void UI::printMeniuSeriale() {
    cout << "--Meniu seriale--" << endl;
    cout << "0.Back" << endl;
    cout << "1.Adauga Serial" << endl;
    cout << "2.Sterge Serial" << endl;
    cout << "3.Modifica Serial" << endl;
    cout << "4.Afiseaza Vector Seriale" << endl;
}

void UI::printMeniuFilme() {
    cout << "--Meniu filme--" << endl;
    cout << "0.Back" << endl;
    cout << "1.Adauga Film" << endl;
    cout << "2.Sterge Film" << endl;
    cout << "3.Modifica Film" << endl;
    cout << "4.Afiseaza Lista Filme" << endl;
}

void UI::printMeniuImagini() {
    cout << "--Meniu imagini--" << endl;
    cout << "0.Back" << endl;
    cout << "1.Adauga Imagine" << endl;
    cout << "2.Sterge Imagine" << endl;
    cout << "3.Modifica Imagine" << endl;
    cout << "4.Afiseaza Map Imagini" << endl;
}

void UI::printMeniuScurtmetraje() {
    cout << "--Meniu scurtmetraje--" << endl;
    cout << "0.Back" << endl;
    cout << "1.Adauga Scurtmetraj" << endl;
    cout << "2.Sterge Scurtmetraj" << endl;
    cout << "3.Modifica Scurtmetraj" << endl;
    cout << "4.Afiseaza Set Scurtmetraje" << endl;
}

void UI::meniuPrincipal() {
    UI::printMeniuPrincipal();
    int cmd{ 0 };
    cin >> cmd;
    cin.ignore();
    while (cmd==1)
    {
        UI::printMeniuSeriale();
        int command{ 0 };
        cout << "cmd:";
        cin >> command;
        //http://www.cplusplus.com/reference/istream/istream/ignore/
        cin.ignore();
        switch (command)
        {
            case 0:
                meniuPrincipal();
                break;
            case 1:
                adaugaSerialInVector();
                break;
            case 2:
                stergeSerialDinVector();
                break;
            case 3:
                modificaSerialDinVector();
                break;
            case 4:
                afiseazaSeriale();
                break;

        }

    }
    while (cmd==2)
    {
        UI::printMeniuFilme();
        int command{ 0 };
        cout << "cmd:";
        cin >> command;
        //http://www.cplusplus.com/reference/istream/istream/ignore/
        cin.ignore();
        switch (command)
        {
            case 0:
                meniuPrincipal();
                break;
            case 1:
                adaugaFilmInLista();
                break;
            case 2:
                stergeFilmDinLista();
                break;
            case 3:
                modificaFilmDinLista();
                break;
            case 4:
                afiseazaFilme();
                break;

        }

    }
    while (cmd==3)
    {
        UI::printMeniuScurtmetraje();
        int command{ 0 };
        cout << "cmd:";
        cin >> command;
        //http://www.cplusplus.com/reference/istream/istream/ignore/
        cin.ignore();
        switch (command)
        {
            case 0:
                meniuPrincipal();
                break;
            case 1:
                adaugaScurtmetrajeInSet();
                break;
            case 2:
                stergeScurtmetrajeDinSet();
                break;
            case 3:
                modificaScurtmetrajeDinSet();
                break;
            case 4:
                afiseazaScurtmetraje();
                break;

        }

    }
    while (cmd==4)
    {
        UI::printMeniuImagini();
        int command{ 0 };
        cout << "cmd:";
        cin >> command;
        //http://www.cplusplus.com/reference/istream/istream/ignore/
        cin.ignore();
        switch (command)
        {
            case 0:
                meniuPrincipal();
                break;
            case 1:
                adaugaImaginiInMap();
                break;
            case 2:
                stergeImaginiDinMap();
                break;
            case 3:
                modificaImaginiDinMap();
                break;
            case 4:
                afiseazaImagini();
                break;

        }

    }
    if (cmd == 0) {
        exit(0);
    }

}

//--------------------Seriale-------------------------
void UI::adaugaSerialInVector() {
    cout << "Nume Serial:";
    std::string nume;
    getline(cin, nume);

    cout << "Actor Principal:";
    std::string actorPrincipal;
    getline(cin, actorPrincipal);

    cout << "Producator:";
    std::string producator;
    getline(cin, producator);

    cout << "Regizor:";
    std::string regizor;
    getline(cin, regizor);

    int durata;
    cout << "Durata serialului:";
    cin >> durata;

    int numarEpisoade;
    cout << "Numar de episoade:";
    cin >> numarEpisoade;
    cin.ignore();

    try
    {
        controller.getVector()->adaugareSerialInVector(nume, actorPrincipal, producator, regizor, durata,
                                                       numarEpisoade);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }

}

void UI::stergeSerialDinVector() {
    cout << "Nume:";
    std::string nume;
    getline(cin, nume);

    cout << "Actor Principal:";
    std::string actorPrincipal;
    getline(cin, actorPrincipal);

    try
    {
        controller.getVector()->stergereSerialDinVector(nume, actorPrincipal);
    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::modificaSerialDinVector() {
    cout << "Nume:";
    std::string nume;
    getline(cin, nume);

    cout << "Actor Principal:";
    std::string actorPrincipal;
    getline(cin, actorPrincipal);

    cout << "--Acum modifica serialul!--\n";

    cout << "Nume Serial:";
    std::string numeNou;
    getline(cin, numeNou);

    cout << "Actor Principal:";
    std::string actorPrincipalNou;
    getline(cin, actorPrincipalNou);

    cout << "Producator:";
    std::string producatorNou;
    getline(cin, producatorNou);

    cout << "Regizor:";
    std::string regizorNou;
    getline(cin, regizorNou);

    int durataNoua;
    cout << "Durata serialului: ";
    cin >> durataNoua;

    int numarEpisoadeNou;
    cout << "Numar de episoade: ";
    cin >> numarEpisoadeNou;
    cin.ignore();
    try
    {
        controller.getVector()->modificareSerialDinVector(nume, actorPrincipal, numeNou, actorPrincipalNou,
                                                          producatorNou, regizorNou, durataNoua, numarEpisoadeNou);
    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::afiseazaSeriale() {
    std::vector<Serial> seriale = controller.getVector()->getSeriale();
    cout << "\n";
    if (seriale.empty())
    {
        cout << "Nu exista seriale" << endl;
        return;
    }

    for (auto s : seriale)
    {
        s.afisare_serial(s);
    }
    cout << "\n";
}

//--------------------Filme-------------------------
void UI::adaugaFilmInLista() {
    cout << "Nume Film:";
    std::string nume;
    getline(cin, nume);

    cout << "Categorie:";
    std::string categorie;
    getline(cin, categorie);

    cout << "Durata:";
    double durata;
    cin >> durata;
    cin.ignore();

    int numarVizionari;
    cout << "Numar de vizionari:";
    cin >> numarVizionari;
    cin.ignore();

    try
    {
        controller.getLista()->adaugareFilmInLista(durata, nume, categorie, numarVizionari);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::stergeFilmDinLista() {
    cout << "Nume Film:";
    std::string nume;
    getline(cin, nume);

    cout << "Categorie:";
    std::string categorie;
    getline(cin, categorie);

    try
    {
        controller.getLista()->stergereFilmDinLista(nume, categorie);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::modificaFilmDinLista() {
    cout << "Nume Film:";
    std::string nume;
    getline(cin, nume);

    cout << "Categorie:";
    std::string categorie;
    getline(cin, categorie);

    cout << "--Acum modifica filmul!--\n";

    cout << "Nume Film:";
    std::string numeNou;
    getline(cin, numeNou);

    cout << "Categorie:";
    std::string categorieNoua;
    getline(cin, categorieNoua);

    cout << "Durata:";
    double durataNoua;
    cin >> durataNoua;
    cin.ignore();

    int numarVizionariNou;
    cout << "Numar de vizionari:";
    cin >> numarVizionariNou;
    cin.ignore();

    try
    {
        controller.getLista()->modificareFilmDinLista(nume, categorie, durataNoua, numeNou, categorieNoua, numarVizionariNou);
    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::afiseazaFilme() {
    list<Film> filme = controller.getLista()->getFilme();
    cout << "\n";
    if (filme.empty())
    {
        cout << "Nu exista filme" << endl;
        return;
    }

    for (auto f : filme)
    {
        f.afisare_film(f);
    }
    cout << "\n";
}

//--------------------Imagini-------------------------
void UI::adaugaImaginiInMap() {
    cout << "Nume Imagine:";
    std::string nume;
    getline(cin, nume);

    cout << "Tip Imagine:";
    std::string tip;
    getline(cin, tip);

    cout << "Rezolutie x:";
    int x;
    cin >> x;
    cin.ignore();

    int y;
    cout << "Rezolutie y:";
    cin >> y;
    cin.ignore();

    try
    {
        controller.getMap()->adaugareImagineInMap(nume, tip, x, y);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::stergeImaginiDinMap() {
    cout << "Nume Imagine:";
    std::string nume;
    getline(cin, nume);
    try
    {
        controller.getMap()->stergereImagineDinMap(nume);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::modificaImaginiDinMap() {
    cout << "Nume Imagine:";
    std::string nume;
    getline(cin, nume);

    cout << "--Acum modifica imaginea!--\n";

    cout << "Nume Imagine:";
    std::string numeNou;
    getline(cin, numeNou);

    cout << "Tip Imagine:";
    std::string tip;
    getline(cin, tip);

    cout << "Rezolutie x:";
    int x;
    cin >> x;
    cin.ignore();

    int y;
    cout << "Rezolutie y:";
    cin >> y;
    cin.ignore();

    try
    {
        controller.getMap()->modificareImagineDinMap(nume, numeNou, tip, x, y);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::afiseazaImagini() {
    map<string, Imagine*> imagini = controller.getMap()->getImagini();
    cout << "\n";
    if (imagini.empty())
    {
        cout << "Nu exista imagini" << endl;
        return;
    }

    for (auto f : imagini)
    {
        cout << "Cheie: " << f.first << "  Valoare (dimensiune): " << f.second->getSize() << endl;
    }
    cout << "\n";
}

//--------------------Scurtmetraje-------------------------
void UI::adaugaScurtmetrajeInSet() {
    cout << "Tip Scurtmetraj:";
    std::string tip;
    getline(cin, tip);

    cout << "Nume:";
    std::string nume;
    getline(cin, nume);

    cout << "Categorie:";
    std::string categorie;
    getline(cin, categorie);

    cout << "Durata:";
    double durata;
    cin >> durata;
    cin.ignore();

    int numarVizionari;
    cout << "Numar de vizionari:";
    cin >> numarVizionari;
    cin.ignore();

    try
    {
        controller.getSet()->adaugareScurtmetrajInSet(tip, durata, nume, categorie, numarVizionari);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::stergeScurtmetrajeDinSet() {
    cout << "Tip Scurtmetraj:";
    std::string tip;
    getline(cin, tip);

    cout << "Nume Scurtmetraj:";
    std::string nume;
    getline(cin, nume);

    try
    {
        controller.getSet()->stergereScurtmetrajDinSet(tip, nume);

    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::modificaScurtmetrajeDinSet() {
    cout << "Tip Scurtmetraj:";
    std::string tip;
    getline(cin, tip);

    cout << "Nume Scurtmetraj:";
    std::string nume;
    getline(cin, nume);

    cout << "--Acum modifica scurtmetrajul!--\n";

    cout << "Tip Scurtmetraj:";
    std::string tipNou;
    getline(cin, tipNou);

    cout << "Nume Film:";
    std::string numeNou;
    getline(cin, numeNou);

    cout << "Categorie:";
    std::string categorieNoua;
    getline(cin, categorieNoua);

    cout << "Durata:";
    double durataNoua;
    cin >> durataNoua;
    cin.ignore();

    int numarVizionariNou;
    cout << "Numar de vizionari:";
    cin >> numarVizionariNou;
    cin.ignore();

    try
    {
        controller.getSet()->modificareScurtmetrajDinSet(tip, nume, tipNou, durataNoua, numeNou, categorieNoua, numarVizionariNou);
    }
    catch (const ofstream::failure& e)
    {
        cout << e.what() << "\n";
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << "\n";
    }
}

void UI::afiseazaScurtmetraje() {
    set<Scurtmetraj> scurtmetraje = controller.getSet()->getScurtmetraje();
    cout << "\n";
    if (scurtmetraje.empty())
    {
        cout << "Nu exista filme" << endl;
        return;
    }

    for (auto f : scurtmetraje)
    {
        f.afisare_scurtmetraj(f);
    }
    cout << "\n";
}




