
#ifndef MAIN_CPP_FILM_H
#define MAIN_CPP_FILM_H
#include <string>
using namespace std;

class Film {
private:
    double durata{};
    string nume, categorie;
    int numar_vizionari{};

public:
    virtual ~Film() = default;

    Film(double durata, string &nume, std::string &categorie, int numar_vizionari);
    Film() = default;
    Film(const Film &film_copiat);

    double getDurata() const { return durata; }
    void setDurata(double Durata) { Film::durata = Durata; }

    const string &getNume() const { return nume; }
    void setNume(const string &Nume) { Film::nume = Nume; }

    const string &getCategorie() const { return categorie; }
    void setCategorie(const string &Categorie) { Film::categorie = Categorie; }

    int getNumarVizionari() const { return numar_vizionari; }
    void setNumarVizionari(int numarVizionari) { numar_vizionari = numarVizionari;}


    friend ostream &operator<<(ostream &os, const Film &serial);
    friend istream &operator>>(istream &input, Film &serial);

    static void afisare_film(const Film& film_afisat);

    Film& operator= (const Film &film_copiat);
    bool operator== (const Film &film_comparat);

    void operator++() { numar_vizionari++; };
    void operator--() { numar_vizionari--; };
    void operator++(int) { numar_vizionari++; };
    void operator--(int) { numar_vizionari--; };
    bool operator<(const Film &rhs) const { return numar_vizionari < rhs.numar_vizionari; }
    bool operator>(const Film &rhs) const { return rhs < *this; }
    bool operator<=(const Film &rhs) const { return !(rhs < *this); }
    bool operator>=(const Film &rhs) const { return !(*this < rhs); }

    friend int operator+(const Film &f1, const Film &f2); //operator +
    friend int operator-(const Film &f1, const Film &f2); //operator -

    char& operator[](int index);
    explicit operator int() { return (int)durata;}

};

#endif //MAIN_CPP_FILM_H