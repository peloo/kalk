#ifndef RAZ_H
#define RAZ_H
#include <cmath>
#include <iostream>
#include "tipo.h"
using std::string;
using std::to_string;
using std::ostream;
using std::cout;
using std::endl;
using std::sqrt;
using std::floor;
using std::pow;
using std::cbrt;

class raz: public tipo{
    friend raz operator+(const raz&, const raz&);
    friend raz operator-(const raz&, const raz&);
    friend raz operator*(const raz&, const raz&);
    friend raz operator/(const raz&, const raz&);
    friend bool operator==(const raz&, const raz&);
    friend bool operator!=(const raz&, const raz&);
    friend bool operator<=(const raz&, const raz&);
    friend bool operator<(const raz&, const raz&);
    friend ostream& operator<<(ostream&, const raz&);
    friend string to_string(const raz&);
private:
    int num, den;
    int degree(double);
public:
    raz(int n=0, int d=1);
    raz(double n, double d=1);
    int getNum()const;
    int getDen()const;
    static raz inverso(const raz&);
    explicit operator double();//da raz a double, dev'essere invocato "static_cast<double>(raz r)"
    explicit operator int();
    raz& operator++();//prefisso
    raz operator++(int);//postfisso
    static raz pow(const raz&, int);
    static raz sqrt(const raz&);
    static raz cbrt(const raz&);
    raz riduzione() const;

    raz* somma(tipo*);
    raz* differenza(tipo*);
    raz* moltiplicazione(int);
    raz* divisione(int);
    bool uguale(tipo*)const;
    bool min(tipo*)const;
    string to_stringa()const;
};

raz operator+(const raz&, const raz&);
raz operator-(const raz&, const raz&);
raz operator*(const raz&, const raz&);
raz operator/(const raz&, const raz&);
bool operator==(const raz&, const raz&);
bool operator!=(const raz&, const raz&);
bool operator<=(const raz&, const raz&);
bool operator<(const raz&, const raz&);
ostream& operator<<(ostream&, const raz&);
string to_string(const raz&);

//throw(0) c'e' quando il raz da il denominatore nullo

#endif // RAZ_H
