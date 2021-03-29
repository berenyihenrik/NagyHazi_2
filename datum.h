#ifndef NAGYHAZI_2_DATUM_H
#define NAGYHAZI_2_DATUM_H

class Datum {
private:
    int ev;
    int honap;
    int nap;
public:
    Datum(int ev, int honap, int nap) :ev(ev), honap(honap), nap(nap) {}

    bool operator>(Datum &datum2);

    bool operator<(Datum &datum2);
};


#endif
