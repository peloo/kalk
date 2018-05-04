#ifndef TIPO_H
#define TIPO_H
#include <string>
using std::string;

//ogni tipo di dato da usare nell'alero deve includere
//ed implementare questa classe
class tipo{
public:
    virtual tipo* somma(tipo*) =0;//somma tra due tipi
    virtual tipo* differenza(tipo*) =0;//differenza tra due tipi
    virtual tipo* moltiplicazione(int) =0;//moltiplicazione per uno scalare
    virtual tipo* divisione(int) =0;//divisione per uno scalare
    virtual bool uguale(tipo*)const =0;//operatore di uguaglianza ==
    virtual bool min(tipo*)const =0;//operatore <
    virtual string to_stringa()const =0;//stampa
};

#endif // TIPO_H