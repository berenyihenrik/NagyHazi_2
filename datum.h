#ifndef NAGYHAZI_2_DATUM_H
#define NAGYHAZI_2_DATUM_H
#include <iostream>
#include <fstream>
using namespace std;
class Datum {
private:
    int ev;
    int honap;
    int nap;
    int idopont; //idopont percekben, kiiraskor lesz szetosztva orara es percre
public:
    Datum(int ev, int honap, int nap, int idopont) :ev(ev), honap(honap), nap(nap), idopont(idopont) {}

    Datum() {}

    int get_ev() const{return ev;}
    int get_honap() const{return honap;}
    int get_nap() const{return nap;}
    int get_idopont() const{return idopont;}

    bool operator>(Datum &datum2);

    bool operator<(Datum &datum2);
};

ostream& operator<<(ostream& os, const Datum& d);


#endif
