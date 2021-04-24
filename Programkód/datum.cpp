#include "datum.hpp"

bool Datum::operator>=(Datum &datum2) const{
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

bool Datum::operator<=(Datum &datum2) const{
    if(this->ev == datum2.ev && this->honap == datum2.honap && this->nap == datum2.nap && this->idopont == datum2. idopont) {
        return true;
    }
    return !(*this >= datum2);
}

bool Datum::operator==(const Datum &datum2) const {
    if(this->ev == datum2.ev && this->honap == datum2.honap && this->nap == datum2.nap && this->idopont == datum2.idopont) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Datum& d) {
    int ora = d.get_idopont()/60;
    int perc = d.get_idopont() - ora*60;
    if(&os == &cout) {
        os << d.get_ev() << '/' << d.get_honap() << '/' << d.get_nap() << ' ' << ora << ':';
    } else {
        os << d.get_ev() << '#' << d.get_honap() << '#' << d.get_nap() << '#' << ora << '#';
    }
    if(perc < 10) {
        os << '0';
    }
    return os << perc;
}

/// Dátum beolvasása, beolvasás közben kiírja cout-ra, hogy milyen adatot vár ezzel segítve a felhasználót
istream& operator>>(istream& is, Datum& d) {
    String ev;
    String honap;
    String nap;
    String ora;
    String perc;

    cout << "Év:";
    is >> ev;
    while(stoi(ev) < 2021) {
        cout << "Hibás évszám, kérlek 2021 vagy későbbi évszamot adj meg!" << endl;
        is >> ev;
    }

    cout << "Honap:";
    is >> honap;
    while(stoi(honap) < 1 || stoi(honap) > 12) {
        cout << "Hibás hónap, kérlek 1 és 12 közötti számot adj meg!" << endl;
        is >> honap;
    }

    cout << "Nap:";
    is >> nap;
    while(stoi(nap) < 1 || stoi(nap) > 31) {
        cout << "Hibás nap, kérlek 1 és 31 közötti számot adj meg!" << endl;
        is >> nap;
    }

    cout << "Óra:";
    is >> ora;
    while(stoi(ora) < 0 || stoi(ora) > 24) {
        cout << "Hibás óra, kérlek 0 és 24 közötti számot adj meg!" << endl;
        is >> ora;
    }

    cout << "Perc:";
    is >> perc;
    while(stoi(perc) < 0 || stoi(perc) > 60) {
        cout << "Hibás perc, kérlek 0 és 60 közötti számot adj meg!" << endl;
        is >> perc;
    }

    d = Datum(stoi(ev),stoi(honap), stoi(nap), stoi(ora)*60+stoi(perc));

    return is;
}