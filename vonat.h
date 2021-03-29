#ifndef NAGYHAZI_2_VONAT_H
#define NAGYHAZI_2_VONAT_H
#include <string>
#include "datum.h"

using namespace std;

class Vonat {
private:
    int vonatszam;
    int kocsik_szama;
    //indulasi adatok
    string indul_allomas;
    Datum indul_datum;
    //erkezesi adatok
    string erkez_allomas;
    Datum erkez_datum;
public:

};

#endif //NAGYHAZI_2_VONAT_H
