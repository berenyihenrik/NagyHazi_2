#ifndef NAGYHAZI_2_JEGY_H
#define NAGYHAZI_2_JEGY_H

#include <string>
#include "datum.hpp"
#include "string.hpp"
#include "vonat.hpp"
using namespace  std;
class Jegy {
private:
    ///pontos hely
    String nev;
    int kocsiszam;
    int hely;
    ///vonat adatai
    Vonat vonat;
public:
    Jegy(String nev, int ksz, int hely, Vonat v) :nev(nev), kocsiszam(ksz), hely(hely), vonat(v) {}

    Jegy() {}

    String get_nev() const{return nev;}
    String get_vsz() const {return vonat.get_vsz();}
    int get_ksz() const {return kocsiszam;}
    int get_hely() const {return hely;}
    String get_ind_all() const {return vonat.get_ind_all();}
    Datum get_ind_dt() const {return vonat.get_ind_dt();}
    String get_erkez_all() const {return vonat.get_erkez_all();}
    Datum get_erkez_dt() const {return vonat.get_erkez_dt();}
};

ostream& operator<<(ostream& os, const Jegy& j);

class Jegyek {
private:
    size_t meret;
    Jegy* jegyek;
public:
    Jegyek() {
        jegyek = new Jegy[0];
        meret = 0;
    }

    Jegy operator[](size_t i) const;

    void add(const Jegy &j);

    void remove(const char* nev);

    size_t size() const {return meret;}

    ~Jegyek() {
        delete[] jegyek;
    }
};

void beolvas(Jegyek& j, const char* fajlnev);

#endif
