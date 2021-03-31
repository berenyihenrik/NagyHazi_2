#ifndef NAGYHAZI_2_VONAT_H
#define NAGYHAZI_2_VONAT_H
#include <string>
#include "datum.h"

using namespace std;

class Vonat {
private:
    string vonatszam;
    int kocsik_szama;
    ///indulasi adatok
    string indul_allomas;
    Datum indul_datum;
    ///erkezesi adatok
    string erkez_allomas;
    Datum erkez_datum;
public:
    Vonat(string vsz, int ksz, string ind_all, Datum ind_dt, string erk_all, Datum erk_dt) :vonatszam(vsz), kocsik_szama(ksz), indul_allomas(ind_all), indul_datum(ind_dt), erkez_allomas(erk_all), erkez_datum(erk_dt) {}

    Vonat() {}

    string get_vsz() const {return vonatszam;}
    int get_ksz() const {return kocsik_szama;}
    string get_ind_all() const {return indul_allomas;}
    Datum get_ind_dt() const {return indul_datum;}
    string get_erkez_all() const {return erkez_allomas;}
    Datum get_erkez_dt() const {return erkez_datum;}


};

ostream& operator<<(ostream& os, const Vonat& v);

//Heterogen kollekcio a jaratok tarolasara
class Jaratok {
private:
    int meret;
    Vonat* jaratok;
public:
    Jaratok() {
        jaratok = new Vonat[0];
        meret = 0;
    }

    Vonat operator[](int i) const;

    void add(const Vonat &v);

    void remove();

    int size() const;

    ~Jaratok() {
        delete[] jaratok;
    }
};

void beolvas(Jaratok& j, const char* fajlnev);

ostream& operator<<(ostream& os, const Jaratok& j);

#endif
