//
// Created by Admin on 10.07.2021.
//

#ifndef KLAUSUR_VERK_ARTIKEL_H
#define KLAUSUR_VERK_ARTIKEL_H
#include "iostream"
using namespace std;
class Verk_Artikel {
public:
    int artnr;
    float betrag;
    float summe;
    string datum;

    Verk_Artikel(int artnr, float betrag, float summe, const string &datum);

};


#endif //KLAUSUR_VERK_ARTIKEL_H
