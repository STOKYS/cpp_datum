//
// Created by david_stocek on 3/14/22.
//

#include <iostream>
#include "time.h"
#include "datum.hpp"

using std::cout;
using std::endl;

datum::datum() {
    zakladniNastaveni();
}

datum::datum(int d, int m, int r) {
    if(!nastavDatum(d,m,r)){
        cout << "Bylo zadane nevalidni datum, bude pouzito systemove" << endl;
        zakladniNastaveni();
    }
}

bool datum::nastavDatum(int d, int m, int r) {
    if (validniDatum(d, m, r)){
        this -> den = d;
        this -> mesic = m;
        this -> rok = r;
        return true;
    } else {
        return false;
    }
}

bool datum::validniDatum(int d, int m, int r) const {
    if (1 > m or m > 12){
        return false;
    } else if ((m == 1 or m == 3 or m==5 or m==7 or m==8 or m==10 or m==12) and (1 > d or d > 31)) {
        return false;
    } else if ((m == 4 or m == 6 or m==9 or m == 11) and (1 > d or d > 30)){
        return false;
    } else if ((m == 2 and 1 > d) or (m == 2 and (prestupnyRok(r) ? d > 29 : d > 28))) {
        return false;
    } else {
        return true;
    }
}

bool datum::prestupnyRok(int r) const {
    if ((r % 4 == 0 and r % 100 != 0) or r % 400 == 0){
        return true;
    } else {
        return false;
    }
}

void datum::zakladniNastaveni() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    nastavDatum(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int datum::getDen() const {
    return den;
}

int datum::getMesic() const {
    return mesic;
}

int datum::getRok() const {
    return rok;
}

int datum::pocetDni() {
    int r = this->rok;
    int m = this->mesic;
    int d = this->den;
    int rozdil = (r - 1900) * 365;
    for (int i = 0; i <= (r - 1900); i++){
        if (prestupnyRok(1900 + i)){
            rozdil++;
        }
    }
    for (int i = 1; i < m; i++) {
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) {
            rozdil += 31;
        } else if (i == 4 or i == 6 or i == 9 or i == 11) {
            rozdil += 30;
        } else if (i == 2){
            rozdil += 28;
        }
    }
    this -> rozdil = (rozdil + d);
    return this->rozdil;
}

int datum::denTyden() const {
    if (this->rozdil){
        return this->rozdil%7;
    }
}

std::ostream & operator<< (std::ostream & os, const datum & d){
    os << (d.getDen()<10 ? "0" : "") << d.getDen() << "."
       << (d.getMesic()<10 ? "0" : "") << d.getMesic() << "."
       << d.getRok() ;
    return os;
}