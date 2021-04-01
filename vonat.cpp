#include <iostream>
#include <fstream>
#include <string>
#include "vonat.h"
using namespace std;


ostream& operator<<(ostream& os, const Vonat& v) {
    return os << v.get_vsz() << '#' << v.get_ksz() << '#' << v.get_ind_dt() << '#' << v.get_ind_all() << '#' << v.get_erkez_dt() << '#' << v.get_erkez_all() << endl;
}



///JARATOK
void beolvas(Jaratok& j, const char* fajlnev) {
    ifstream fpp;
    fpp.open(fajlnev);
    if(!fpp) {
        printf("KIVETEL\n");
        throw "QP4TVJ";
    }
    String* adatok = new String[14];

    int i = 0;
    while(getline(fpp,adatok[i],'#')) {
        if(i == 12) {
            getline(fpp, adatok[13], '\n');
            Datum ind(stoi(adatok[1]), stoi(adatok[2]), stoi(adatok[3]), stoi(adatok[4])*60+stoi(adatok[5]));
            Datum erk(stoi(adatok[6]), stoi(adatok[7]), stoi(adatok[8]), stoi(adatok[9])*60+stoi(adatok[10]));
            Vonat v(adatok[0], stoi(adatok[13]), adatok[11], ind, adatok[12], erk);            i = -1;
            j.add(v);
            delete[] adatok;
            adatok = new String[14];
        }

        i++;
    }
    delete[] adatok;
}

Vonat Jaratok::operator[](size_t i) const{
    if(i < 0 || i >= meret) {
        throw "KIVETEL";
    }
    return jaratok[i];
}

void Jaratok::add(const Vonat& v) {
    Vonat* temp = new Vonat[meret+1];
    for(size_t i = 0; i < meret; i++) {
        temp[i] = jaratok[i];
    }
    temp[meret] = v;
    delete[] jaratok;
    jaratok = temp;
    meret++;
}

size_t Jaratok::size() const{
    return meret;
}

ostream& operator<<(ostream& os, const Jaratok& j) {
    for(int i = 0; i < j.size(); i++) {
        os << j[i];
    }
    return os;
}

