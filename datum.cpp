#include "datum.hpp"

bool Datum::operator>(Datum &datum2) const{
    if(this->ev < datum2.ev) {
        return false;
    } else if(this->ev > datum2.ev) {
        return true;
    }

    if(this->honap < datum2.honap) {
        return false;
    }else if(this->honap > datum2.honap) {
        return true;
    }
    else if(this->nap < datum2.nap) {
        return false;
    }else if(this->nap > datum2.nap) {
        return true;
    }
    else if(this->idopont < datum2.idopont) {
        return false;
    }else if(this->idopont > datum2.idopont) {
        return true;
    }

    return true;
}

bool Datum::operator<(Datum &datum2) const{
    if(this->ev == datum2.ev && this->honap == datum2.honap && this->nap == datum2.nap && this->idopont == datum2. idopont) {
        return true;
    }
    return !(*this > datum2);
}

ostream& operator<<(ostream& os, const Datum& d) {
    int ora = d.get_idopont()/60;
    int perc = d.get_idopont() - ora*60;
    if(&os == &cout) {
        os << d.get_ev() << '/' << d.get_honap() << '/' << d.get_nap() << ' ' << ora << ':';
    } else {
        os << d.get_ev() << '#' << d.get_honap() << '#' << d.get_nap() << ora << '#';
    }
    if(perc < 10) {
        os << '0';
    }
    return os << perc;
}

///Datum beolvasasa, beolvasas koyben kiirja cout-ra, hogy milyen adatot var eyyel segitve a felhasznalot
istream& operator>>(istream& is, Datum& d) {
    String ev;
    String honap;
    String nap;
    String ora;
    String perc;

    cout << "ev:";
    is >> ev;
    while(stoi(ev) < 2021) {
        cout << "Hibas evszam, kerlek 2021 vagy kesobbi evszamot adj meg!" << endl;
        is >> ev;
    }

    cout << "honap:";
    is >> honap;
    while(stoi(honap) < 1 || stoi(honap) > 12) {
        cout << "Hibas honap, kerlek 1 es 12 kozotti szamot adj meg!" << endl;
        is >> honap;
    }

    cout << "nap:";
    is >> nap;
    while(stoi(nap) < 1 || stoi(nap) > 31) {
        cout << "Hibas nap, kerlek 1 es 31 kozotti szamot adj meg!" << endl;
        is >> nap;
    }

    cout << "ora:";
    is >> ora;
    while(stoi(ora) < 0 || stoi(ora) > 24) {
        cout << "Hibas ora, kerlek 0 es 24 kozotti szamot adj meg!" << endl;
        is >> ora;
    }

    cout << "perc:";
    is >> perc;
    while(stoi(perc) < 0 || stoi(perc) > 60) {
        cout << "Hibas perc, kerlek 0 es 60 kozotti szamot adj meg!" << endl;
        is >> perc;
    }

    d = Datum(stoi(ev),stoi(honap), stoi(nap), stoi(ora)*60+stoi(perc));

    return is;
}