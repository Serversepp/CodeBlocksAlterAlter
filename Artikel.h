//
// Created by Admin on 10.07.2021.
//

#ifndef KLAUSUR_ARTIKEL_H
#define KLAUSUR_ARTIKEL_H

#include "iostream"
#include "Verk_Artikel.h"
using namespace std;

class Artikel {
    public:
        int artnr;
        string name;
        Verk_Artikel verkauft[15]; // Maximal 15 Verkaufe blyad

    bool neuerVerkauf(string Date, float betrag, float sum);
};


#endif //KLAUSUR_ARTIKEL_H
