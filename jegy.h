#ifndef NAGYHAZI_2_JEGY_H
#define NAGYHAZI_2_JEGY_H

#include <string>
#include "datum.h"
using namespace  std;
class Jegy {
private:
    ///pontos hely
    string vonatszam;
    int kocsiszam;
    int hely;
    ///indulasi adatok
    string indul_allomas;
    Datum indul_datum;
    ///erkezesi adatok
    string erkez_allomas;
    Datum erkez_datum;
public:
    Jegy(string vsz, int ksz, int hely, string ind_all, Datum ind_dt, string erk_all, Datum erk_dt) :vonatszam(vsz), kocsiszam(ksz), hely(hely), indul_allomas(ind_all), indul_datum(ind_dt), erkez_allomas(erk_all), erkez_datum(erk_dt) {}

    Jegy() {}


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
