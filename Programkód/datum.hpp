#ifndef NAGYHAZI_2_DATUM_H
#define NAGYHAZI_2_DATUM_H
#include <iostream>
#include <fstream>
#include "string.hpp"

using namespace std;
class Datum {
private:
    int ev;
    int honap;
    int nap;
    int idopont; // időpont percekben, kiíraskor lesz szétosztva órára es percre
public:
    Datum(int ev, int honap, int nap, int idopont) :ev(ev), honap(honap), nap(nap), idopont(idopont) {}

    Datum() {}

    int get_ev() const{return ev;}
    int get_honap() const{return honap;}
    int get_nap() const{return nap;}
    int get_idopont() const{return idopont;}

    bool operator>=(Datum &datum2) const;

    bool operator<=(Datum &datum2) const;

    bool operator==(const Datum &datum2) const;
};

ostream& operator<<(ostream& os, const Datum& d);

///Dátum beolvasása
istream& operator>>(istream& is, Datum& d);

#endif
