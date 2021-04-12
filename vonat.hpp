#ifndef NAGYHAZI_2_VONAT_H
#define NAGYHAZI_2_VONAT_H
#include <string>
#include "datum.hpp"
#include "string.hpp"

using namespace std;

class Vonat {
private:
    String vonatszam;
    ///indulási adatok
    String indul_allomas;
    Datum indul_datum;
    ///érkezési adatok
    String erkez_allomas;
    Datum erkez_datum;
public:
    Vonat(String vsz, String ind_all, Datum ind_dt, String erk_all, Datum erk_dt) :vonatszam(vsz), indul_allomas(ind_all), indul_datum(ind_dt), erkez_allomas(erk_all), erkez_datum(erk_dt) {}

    Vonat() {}

    bool operator==(const Vonat& v) const;

    String get_vsz() const {return vonatszam;}
    String get_ind_all() const {return indul_allomas;}
    Datum get_ind_dt() const {return indul_datum;}
    String get_erkez_all() const {return erkez_allomas;}
    Datum get_erkez_dt() const {return erkez_datum;}
};

ostream& operator<<(ostream& os, const Vonat& v);

//Heterogén kollekció a járatok tárolására
class Jaratok {
private:
    size_t meret;
    Vonat* jaratok;
public:
    Jaratok() {
        jaratok = new Vonat[0];
        meret = 0;
    }

    Vonat operator[](size_t i) const;

    void add(const Vonat &v);

    void remove(const char* vonatszam);

    size_t size() const;

    bool checkID(String azonosito);

    ~Jaratok() {
        delete[] jaratok;
    }
};

void beolvas(Jaratok& j, const char* fajlnev);

void keres(Jaratok& j, String honnan, String hova, Datum kezdo, Datum vegso);

ostream& operator<<(ostream& os, const Jaratok& j);

#endif
