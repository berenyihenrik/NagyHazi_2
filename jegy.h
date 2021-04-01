#ifndef NAGYHAZI_2_JEGY_H
#define NAGYHAZI_2_JEGY_H

#include <string>
#include "datum.h"
#include "string.h"
using namespace  std;
class Jegy {
private:
    ///pontos hely
    String vonatszam;
    int kocsiszam;
    int hely;
    ///indulasi adatok
    String indul_allomas;
    Datum indul_datum;
    ///erkezesi adatok
    String erkez_allomas;
    Datum erkez_datum;
public:
    Jegy(String vsz, int ksz, int hely, String ind_all, Datum ind_dt, String erk_all, Datum erk_dt) :vonatszam(vsz), kocsiszam(ksz), hely(hely), indul_allomas(ind_all), indul_datum(ind_dt), erkez_allomas(erk_all), erkez_datum(erk_dt) {}

    Jegy() {}

    String get_vsz() const {return vonatszam;}
    int get_ksz() const {return kocsiszam;}
    String get_ind_all() const {return indul_allomas;}
    Datum get_ind_dt() const {return indul_datum;}
    String get_erkez_all() const {return erkez_allomas;}
    Datum get_erkez_dt() const {return erkez_datum;}


};

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

    void remove();

    size_t size() const;

    ~Jegyek() {
        delete[] jegyek;
    }
};



#endif
