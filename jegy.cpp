#include "jegy.hpp"

///Jegy
ostream& operator<<(ostream& os, const Jegy& j) {
    return os << j.get_nev() << '#' << j.get_vsz() << '#' << j.get_ksz() << '#' << j.get_hely() << '#' << j.get_ind_dt() << '#' << j.get_ind_all() << '#' << j.get_erkez_dt() << '#' << j.get_erkez_all() << endl;
}


///Jegyek
Jegy Jegyek::operator[](size_t i) const {
    return jegyek[i];
}

void Jegyek::add(const Jegy &j) {
    Jegy* temp = new Jegy[meret+1];
    for(size_t i = 0; i < meret; i++) {
        temp[i] = jegyek[i];
    }
    temp[meret] = j;
    delete[] jegyek;
    jegyek = temp;
    meret++;
}

void Jegyek::remove(const char* nev) {
    for(size_t i = 0; i < meret; i++) {
        if(jegyek[i].get_nev() == nev) {
            Jegy* temp = new Jegy[meret-1];
            size_t idx = 0;
            for(size_t j = 0; j < meret; j++) {
                if(jegyek[j].get_nev() != nev) {
                    temp[idx] = jegyek[j];
                    idx++;
                }
            }
            meret--;
            delete[] jegyek;
            jegyek = temp;
            return;
        }
    }
    throw "Ilyen neven nincs foglalas!";
}

/*void beolvas(Jaratok& j, const char* fajlnev) {
    ifstream fpp;
    fpp.open(fajlnev);
    if(!fpp) {
        printf("KIVETEL\n");
        throw "QP4TVJ";
    }
    String* adatok = new String[15];

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
}*/