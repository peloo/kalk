#ifndef BIN_H
#define BIN_H

#include "tipo.h"
#include <vector>
#include <algorithm>                            /* reverse */
#include <math.h>                               /* pow */

class bin: public tipo{
    /* dichiarazione di amicizia per i metodi dichiarati fuori dalla classe */
    friend bin operator+ (const bin&, const bin&);                              /* friend */
    friend bin operator- (const bin&, const bin&);                              /* friend */
    friend bin operator* (const bin&, const bin&);                              /* friend */
    friend bin operator* (int, const bin&);                                     /* friend */
    friend bin operator/ (const bin&, const bin&);           /* friend */
    friend bin operator/ (int, const bin&);                  /* friend */

    friend bool operator< (const bin&, const bin&);                             /* friend */
    friend bool operator<= (const bin&, const bin&);                            /* friend */
    friend bool operator> (const bin&, const bin&);                             /* friend */
    friend bool operator>= (const bin&, const bin&);                            /* friend */
    friend bool operator== (const bin&, const bin&);                            /* friend */
    friend std::ostream& operator<< (std::ostream&, const bin&);                /* friend */
    friend string to_string(const bin&);                                        /* friend */
private:
    std::vector<bool> intera;
    //std::vector<bool> frazionaria;

    bool segno;                                   /* 1 negativo 0 positivo */
public:
    bin(int = 0);                                 /* costruttore che dato in input un valore base 10 lo trasforma in base 2 */

    /* metodi ausiliari */
    double base10() const;                        /* converte un tipo bin in un intero in base 10 */
    std::string base16() const;                   /* converte un tipo bin in una stringa in base 16 */
    unsigned int getDimIntera() const;            /* ritorna la dimensione/lunghezza del vettore che rappresente la parte intera in binario */

    /* metodi virtuali ereditati dalla classe tipo e implementati della classe bin */
    bin* somma(tipo*);
    bin* differenza(tipo*);
    bin* moltiplicazione(int);
    bin* divisione(int);
    bool uguale(tipo*)const;
    bool min(tipo*)const;
    string to_stringa()const;
};

/* OVELOADING degli operatori come metodi fuori dalla classe bin, dichiarazione di amicizia per poter accedere ai campi e poter operare */
bin operator+ (const bin&, const bin&);                         /* oveloading degli operatori */
bin operator- (const bin&, const bin&);                         /* oveloading degli operatori */
bin operator* (const bin&, const bin&);                         /* oveloading degli operatori */
bin operator* (int, const bin&);                                /* oveloading degli operatori, vuole un intero come primo operando e un bin come secondo operando */
bin operator/ (const bin&, const bin&);      /* oveloading degli operatori */
bin operator/ (int, const bin&);             /* oveloading degli operatori, vuole un intero come primo operando e un bin come secondo operando */


bool operator< (const bin&, const bin&);        /* oveloading degli operatori */
bool operator<= (const bin&, const bin&);       /* oveloading degli operatori */
bool operator> (const bin&, const bin&);        /* oveloading degli operatori */
bool operator>= (const bin&, const bin&);       /* oveloading degli operatori */
bool operator== (const bin&, const bin&);       /* oveloading degli operatori */

std::ostream& operator<< (std::ostream&, const bin&);       /* oveloading di stampa */

string to_string(const bin&);                   /* funzione che converte un bin in una string */
#endif // BIN_H
