
#ifndef MAIN_CPP_SERIAL_H
#define MAIN_CPP_SERIAL_H
#include <string>
using namespace std;

class Serial {
    string nume, actor_principal, producator, regizor;

    //destructor
protected:
    int durata{};
    int numar_episoade{};
public:
    //constructori
    Serial() {}
    Serial(int durata, int numar_episoade, const string &nume, const string &actor_principal, const string &producator,
           const string &regizor);
    Serial(const Serial &serial_copiat);

    //destructor
    virtual ~Serial();

    //getters setters
    int getDurata() const { return durata; }
    void setDurata(int durataNoua) { durata = durataNoua; }

    int getNumar_episoade() const { return numar_episoade; }
    void setNumar_episoade(int numarNouEpisoade) { numar_episoade = numarNouEpisoade; }

    const string &getNume() const { return nume; }
    void setNume(const string &numeNou) { nume = numeNou;}

    const string &getActor_principal() const { return actor_principal; }
    void setActor_principal(const string &actorNouPrincipal) { actor_principal = actorNouPrincipal; }

    const string &getProducator() const { return producator; }
    void setProducator(const string &producatorNou) { producator = producatorNou; }

    const string &getRegizor() const { return regizor; }
    void setRegizor(const string &regizorNou) { regizor = regizorNou; }

    //operators overrides
    bool operator<(const Serial &rhs) const;
    bool operator>(const Serial &rhs) const;
    bool operator<=(const Serial &rhs) const;
    bool operator>=(const Serial &rhs) const;
    friend ostream &operator<<(ostream &os, const Serial &serial);
    friend istream &operator>>(istream &input, Serial &serial);

    //afisare
    void afisare_serial(Serial serial_afisat);

    Serial& operator= (const Serial &serial_copiat);
    string operator== (const Serial &serial_comparat);

    void operator++() { numar_episoade++; };
    void operator--() { numar_episoade--; };
    void operator++(int) { numar_episoade++; };
    void operator--(int) { numar_episoade--; };

    friend int operator+(const Serial &f1, const Serial &f2); //operator +
    friend int operator-(const Serial &f1, const Serial &f2); //operator -

    //operator indexare
    char& operator[](int);

    operator int() { return (int)durata; }
};


#endif //MAIN_CPP_SERIAL_H
