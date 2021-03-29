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
        }else if(this->nap < datum2.nap) {
            return false;
        }else if(this->nap > datum2.nap) {
            return true;
        }
    }
    return true;
}

bool Datum::operator<(Datum &datum2) {
    return !(*this > datum2);
}