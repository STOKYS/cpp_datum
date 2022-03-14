//
// Created by david_stocek on 3/14/22.
//

#ifndef DATUM_DATUM_HPP
#define DATUM_DATUM_HPP


class datum {
public:
    datum();
    datum(int, int, int);
//    virtual ~datum();
    int getDen() const;
    int getMesic() const;
    int getRok() const;
    int pocetDni();
    int denTyden() const;
    bool nastavDatum(int, int, int);
private:
    int den;
    int mesic;
    int rok;
    int rozdil;
    bool validniDatum(int, int, int) const;
    bool prestupnyRok(int) const;
    void zakladniNastaveni();
};

std::ostream & operator <<(std::ostream & , const datum &);
#endif //DATUM_DATUM_HPP
