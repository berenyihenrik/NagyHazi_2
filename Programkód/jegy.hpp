#ifndef NAGYHAZI_2_JEGY_H
#define NAGYHAZI_2_JEGY_H

#include <string>
#include "datum.hpp"
#include "string.hpp"
#include "vonat.hpp"
using namespace  std;
class Jegy {
private:
    /// pontos hely
    String nev;
    int kocsiszam;
    int hely;
    /// vonat adatai
    Vonat vonat;
public:
    Jegy(String nev, int ksz, int hely, Vonat v) :nev(nev), kocsiszam(ksz), hely(hely), vonat(v) {}

    Jegy(String nev, int ksz, int hely, String vonatszam, Jaratok& ja):nev(nev), kocsiszam(ksz), hely(hely) {
        for(size_t i = 0; i < ja.size(); i ++) {
            if(vonatszam == ja[i].get_vsz()) {
                this->vonat = ja[i];
                break;
            }
        }
    }

    Jegy(const Jegy &j) {
        this->nev = j.get_nev();
        this->kocsiszam = j.get_ksz();
        this->hely = j.get_hely();
        this->vonat = j.get_vonat();
    }

    Jegy() {}

    Jegy& operator=(const Jegy j);

    bool operator==(const Jegy &j) const;

    String get_nev() const{return nev;}
    String get_vsz() const {return vonat.get_vsz();}
    int get_ksz() const {return kocsiszam;}
    int get_hely() const {return hely;}
    String get_ind_all() const {return vonat.get_ind_all();}
    Datum get_ind_dt() const {return vonat.get_ind_dt();}
    String get_erkez_all() const {return vonat.get_erkez_all();}
    Datum get_erkez_dt() const {return vonat.get_erkez_dt();}
    Vonat get_vonat() const {return vonat;}
};

ostream& operator<<(ostream& os, const Jegy& j);

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

    void remove(const char* nev);

    bool checkSeat(String azonosito, int kocsiszam, int ulohely) const;

    size_t size() const {return meret;}

    ~Jegyek() {
        delete[] jegyek;
    }
};

void beolvas(Jaratok& ja, Jegyek& je, const char* fajlnev);

ostream& operator<<(ostream& os, const Jegyek& j);

#endif
