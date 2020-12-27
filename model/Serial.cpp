
#include <iostream>
#include "headers/Serial.h"

//implementare constructori/destructori
Serial::Serial(int durata, int numar_episoade, const string &nume, const string &actor_principal,
               const string &producator, const string &regizor) : durata(durata), numar_episoade(numar_episoade),
               nume(nume), actor_principal(actor_principal), producator(producator), regizor(regizor) {}

Serial::Serial(const Serial &serial_copiat) {
    durata = serial_copiat.durata;
    numar_episoade = serial_copiat.numar_episoade;
    nume = serial_copiat.nume;
    actor_principal = serial_copiat.actor_principal;
    producator = serial_copiat.producator;
    regizor = serial_copiat.regizor;
}

Serial::~Serial() {}

//implementare supraincarcare operatori
bool Serial::operator<(const Serial &rhs) const {
    return numar_episoade < rhs.numar_episoade;
}

bool Serial::operator>(const Serial &rhs) const {
    return rhs < *this;
}

bool Serial::operator<=(const Serial &rhs) const {
    return !(rhs < *this);
}

bool Serial::operator>=(const Serial &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Serial &serial) {
    os << "durata: " << serial.durata << "numar_episoade" << serial.numar_episoade << " nume: " << serial.nume
       << " actor_principal: " << serial.actor_principal
       << " producator: " << serial.producator << "regizor: " << serial.producator;
    return os;
}

istream &operator>>(istream &input, Serial &serial) {
    input >> serial.durata >> serial.numar_episoade >> serial.nume >> serial.actor_principal >> serial.producator
          >> serial.regizor;
    return input;
}

void Serial::afisare_serial(Serial serial_afisat) {
    cout << serial_afisat.getDurata() << "," << serial_afisat.getNumar_episoade() << "," << serial_afisat.getNume()
         << "," << serial_afisat.getActor_principal() << "," << serial_afisat.getProducator() << ","
         << serial_afisat.getRegizor() << '\n';
}

int operator+(const Serial &f1, const Serial &f2)
{
    return f1.getDurata() + f2.getDurata();
}

int operator-(const Serial &f1, const Serial &f2)
{
    return f1.getDurata() - f2.getDurata();
}


Serial& Serial::operator= (const Serial &serial_copiat)
{
    nume = serial_copiat.nume;
    durata = serial_copiat.durata;
    numar_episoade = serial_copiat.numar_episoade;
    producator = serial_copiat.producator;
    regizor = serial_copiat.regizor;
    actor_principal = serial_copiat.actor_principal;

    return *this;
}

string Serial::operator== (const Serial &serial_copiat)
{
    if(actor_principal==serial_copiat.actor_principal)
        return "Serialele au acelasi actor principal";
    else
        return "Serialele nu au acelasi actor principal";
}

char& Serial::operator[](int index)
{
    return nume[index];
}
