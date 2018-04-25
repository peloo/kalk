#include "bin.h"

bin::bin(double d){
    if(d>=0)
        segno = 0;
    else{
        segno = 1;
        d = -1 * d;
    }

    int intero = (int) d;
    double frazionario = d - intero;
    int quoziente = intero;
    bool resto = 0;

    while(quoziente != 0){
        resto = quoziente%2;
        intera.push_back(resto);
        quoziente = quoziente/2;
    }
    std::vector<bool> tmp;
    quoziente = intera.size();
    for(unsigned int it = 0; it<quoziente; it++){
        resto = intera.back();
        intera.pop_back();
        tmp.push_back(resto);
    }

    /* VEDERE SE IL VECTOR tmp CREA GARDBAGE */
    intera = tmp;

    if(frazionario == 0)
        frazionaria.push_back(0);
    else{
        while(frazionario != 0){
            frazionario = frazionario*2;

            if(frazionario >= 1){
                frazionaria.push_back(1);
                frazionario = frazionario-1;
            }
            else
                frazionaria.push_back(0);
        }
    }
}
bin::bin(int d){
    if(d>=0)
        segno = 0;
    else{
        segno = 1;
        d = -1 * d;
    }

    int quoziente = d;
    bool resto = 0;

    while(quoziente != 0){
        resto = quoziente%2;
        intera.push_back(resto);
        quoziente = quoziente/2;
    }
    std::vector<bool> tmp;
    quoziente = intera.size();
    for(unsigned int it = 0; it<quoziente; it++){
        resto = intera.back();
        intera.pop_back();
        tmp.push_back(resto);
    }

    /* VEDERE SE IL VECTOR tmp CREA GARDBAGE */
    intera = tmp;
    frazionaria.push_back(0);
}


void bin::stampa() const{
    if(segno)
        std::cout<<"-";
    else
        std::cout<<"+";

    for(unsigned int i=0; i<intera.size(); i++)
        std::cout<<intera[i];
    std::cout<<".";
    for(unsigned int i=0; i<frazionaria.size(); i++)
        std::cout<<frazionaria[i];
}
double bin::base10() const{
    int i_out = 0;
    double f_out = 0;
    int i = 0;
    for(std::vector<bool>::const_reverse_iterator it = intera.rbegin(); it != intera.rend(); ++it){
        i_out = i_out + (*it * (pow(2,i)));
        i++;
    }

    for(int i=0; i<frazionaria.size(); i++)
        f_out = f_out + (frazionaria[i] * (pow(2,-(i+1))));

    f_out = i_out + f_out;

    if(segno)
        f_out = -1 * f_out;
    return f_out;
}
std::string bin::base16() const{
    int a = (*this).base10();
    std::string out = "";

    int quoziente = a;
    int resto = 0;

    while(quoziente != 0){
        resto = quoziente%16;
        if(resto < 10)
            out = out + std::to_string(resto);
        else{
            switch (resto)
            {
                case 10:
                    out = out + "A";
                break;

                case 11:
                    out = out + "B";
                break;

                case 12:
                    out = out + "C";
                break;

                case 13:
                    out = out + "D";
                break;

                case 14:
                    out = out + "E";
                break;

                case 15:
                    out = out + "F";
                break;
            }
        }
        quoziente = quoziente/16;
    }
    std::reverse(out.begin(), out.end());
    return out;
}

bin operator+ (const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();
    bin out(a+b);
    return out;
}
bin operator -(const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();
    bin out(a-b);
    return out;
}
bin operator *(const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();
    bin out(a*b);
    return out;
}
bin operator /(const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();

    if(b<0)
        throw eccezione();

    bin out(a/b);
    return out;
}
bool operator< (const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();

    return a<b;
}
bool operator<= (const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();

    return a<=b;
}
bool operator> (const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();

    return a>b;
}
bool operator>= (const bin& bin1, const bin& bin2){
    double a = bin1.base10();
    double b = bin2.base10();

    return a>=b;
}
