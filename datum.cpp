#include "datum.h"

bool Datum::operator>(Datum &datum2){
    if(this->ev < datum2.ev) {
        return false;
    } else if(this->ev > datum2.ev) {
        return true;
    }

    if(this->ev == datum2.ev) {
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

    }
    return true;
}

bool Datum::operator<(Datum &datum2) {
    return !(*this > datum2);
}

ostream& operator<<(ostream& os, const Datum& d) {
    int ora = d.get_idopont()/60;
    int perc = d.get_idopont() - ora*60;
    os << d.get_ev() << '/' << d.get_honap() << '/' << d.get_nap() << ' ' << ora << ':';
    if(perc < 10) {
        os << '0';
    }
    return os << perc;
}