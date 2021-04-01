#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>

#include "memtrace.h"
#include "string.h"
using namespace std;

/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char param) {
    len = 1;
    pData = new char[2];
    pData[0] = param;
    pData[1] = '\0';
}

String::String(const char* cstring) {
    len = strlen(cstring);
    pData = new char[len+1];
    for(int i = 0; cstring[i] != '\0'; i++) {
        pData[i] = cstring[i];
    }
    pData[len] = '\0';
}



/// Másoló konstruktor: String-ből készít (createString)
String::String(const String &s) {
    len = s.len;
    pData = new char[len+1];
    for(size_t i = 0; i < len; i++) {
        pData[i] = s.pData[i];
    }
    pData[len] = '\0';
}

/// Destruktor (disposeString)
String::~String() {
    delete[] pData;
}

/// operator=
String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] pData;
        len = rhs_s.len;
        pData = new char[len+1];
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}


char String::operator[](size_t i) {
    if(i < 0 || i >= len) {
        throw "KIVETEL";
    }
    return pData[i];
}

String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete[] temp.pData;
    temp.pData = new char[temp.len+1];
    if(len > 0) {
        strcpy(temp.pData, pData);
        strcat(temp.pData, rhs_s.pData);
    } else {
        strcpy(temp.pData, rhs_s.pData);
    }
    return temp;
}

bool String::operator==(const String &s) {
    if(strcmp(this->c_str(), s.c_str()) == 0) {
        return true;
    }
    return false;
}

bool String::operator!=(const String &s) {
    return !(*this == s);
}

/// << operator, ami kiír az ostream-re
ostream& operator<<(std::ostream& os, const String& s) {
    return os << s.c_str() ;
}


bool getline(std::istream& is, String& s, char d) {
    char current;
    while(is.get(current)) {
        if(current == d) {
            return true;
        }
        s = s + current;
    }
    return false;
}

int stoi(String& s) {
    return atoi(s.c_str());
}
