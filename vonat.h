#ifndef NAGYHAZI_2_VONAT_H
#define NAGYHAZI_2_VONAT_H
#include <string>
#include "datum.h"
#include "string.h"

using namespace std;

class Vonat {
private:
    String vonatszam;
    int kocsik_szama;
    ///indulasi adatok
    String indul_allomas;
    Datum indul_datum;
    ///erkezesi adatok
    String erkez_allomas;
    Datum erkez_datum;
public:
    Vonat(String vsz, int ksz, String ind_all, Datum ind_dt, String erk_all, Datum erk_dt) :vonatszam(vsz), kocsik_szama(ksz), indul_allomas(ind_all), indul_datum(ind_dt), erkez_allomas(erk_all), erkez_datum(erk_dt) {}

    Vonat() {}

    String get_vsz() const {return vonatszam;}
    int get_ksz() const {return kocsik_szama;}
    String get_ind_all() const {return indul_allomas;}
    Datum get_ind_dt() const {return indul_datum;}
    String get_erkez_all() const {return erkez_allomas;}
    Datum get_erkez_dt() const {return erkez_datum;}


};

ostream& operator<<(ostream& os, const Vonat& v);

//Heterogen kollekcio a jaratok tarolasara
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

    void remove();

    size_t size() const;

    ~Jaratok() {
        delete[] jaratok;
    }
};

void beolvas(Jaratok& j, const char* fajlnev);

ostream& operator<<(ostream& os, const Jaratok& j);

#endif
