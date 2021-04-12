#include <iostream>
#include <cstring>
#include "vonat.hpp"
using namespace std;

///Vonat
ostream& operator<<(ostream& os, const Vonat& v) {
    if(&os == &cout) {
        return os << v.get_vsz() << ' ' << v.get_ind_dt() << ' ' << v.get_ind_all() << ' ' << v.get_erkez_dt()
        << ' '<< v.get_erkez_all() << endl;
    } else {
        return os << v.get_vsz() << '#' << v.get_ind_dt() << '#' << v.get_erkez_dt() << '#' << v.get_ind_all()
        << '#'<< v.get_erkez_all() << endl;
    }
}

bool Vonat::operator==(const Vonat &v) const {
    if(this->vonatszam == v.get_vsz()) {
        return true;
    }
    return false;
}

///Járatok
Vonat Jaratok::operator[](size_t i) const{
    if(i < 0 || i >= meret) {
        throw "KIVÉTEL";
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

void Jaratok::remove(const char* vonatszam) {
    for(size_t i = 0; i < meret; i++) {
        if(jaratok[i].get_vsz() == vonatszam) {
            Vonat* temp = new Vonat[meret-1];
            size_t idx = 0;
            for(size_t j = 0; j < meret; j++) {
                if(jaratok[j].get_vsz() != vonatszam) {
                    temp[idx] = jaratok[j];
                    idx++;
                }
            }
            meret--;
            delete[] jaratok;
            jaratok = temp;
            return;
        }
    }
    throw "Nincs ilyen vonatszam!\n";
}

size_t Jaratok::size() const{
    return meret;
}

bool Jaratok::checkID(String azonosito) {
    for(size_t i = 0; i < meret; i ++) {
        if(jaratok[i].get_vsz() == azonosito) {
            return true;
        }
    }
    return false;
}

void beolvas(Jaratok& j, const char* fajlnev) {
    ifstream fpp;
    fpp.open(fajlnev);
    if(!fpp) {
        printf("KIVÉTEL\n");
        throw "QP4TVJ";
    }
    String* adatok = new String[13];

    int i = 0;
    while(getline(fpp,adatok[i],'#')) {
        if(i == 11) {
            getline(fpp, adatok[12], '\n');
            Datum ind(stoi(adatok[1]), stoi(adatok[2]), stoi(adatok[3]), stoi(adatok[4])*60+stoi(adatok[5]));
            Datum erk(stoi(adatok[6]), stoi(adatok[7]), stoi(adatok[8]), stoi(adatok[9])*60+stoi(adatok[10]));
            Vonat v(adatok[0], adatok[11], ind, adatok[12], erk);
            i = -1;
            j.add(v);
            delete[] adatok;
            adatok = new String[14];
        }

        i++;
    }
    delete[] adatok;
    fpp.close();
}

void keres(Jaratok& j, String honnan, String hova, Datum kezdo, Datum vegso) {
    bool vanTalalat = false;
    for (size_t i = 0; i < j.size(); i++) {
        if (strstr(j[i].get_ind_all().c_str(), honnan.c_str()) != 0 && strstr(j[i].get_erkez_all().c_str(), hova.c_str()) != NULL) {
            if (j[i].get_ind_dt() > kezdo && j[i].get_erkez_dt() < vegso) {
                cout << j[i];
                vanTalalat = true;
            }
        }
    }
    if(!vanTalalat) {
        cout << "Nem található járat a megadott keresési feltételek szerint." << endl;
    }
}

ostream& operator<<(ostream& os, const Jaratok& j) {
    for(size_t i = 0; i < j.size(); i++) {
        os << j[i];
    }
    return os;
}
