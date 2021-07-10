#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include <map>
#include <list>
#include <cstring>

class Rohteil;
class Baugruppe;
class Fertigteil;

class Rohteil{
public:
    Rohteil(int rohteilnr);

public:
    int Rohteilnr;

};
class Baugruppe{
public:
    Baugruppe(int bgn, const list<Rohteil> &teile);

public:
    int BGN;
    list<Rohteil> teile;
};
class Fertigteil{
public:
    Fertigteil(int ftn, const list<Baugruppe> &teile);

public:
    int FTN;
    list<Baugruppe> teile;
};

list<Fertigteil> Projekt;

Rohteil::Rohteil(int rohteilnr) : Rohteilnr(rohteilnr) {}

Baugruppe::Baugruppe(int bgn, const list<Rohteil> &teile) : BGN(bgn), teile(teile) {}

Fertigteil::Fertigteil(int ftn, const list<Baugruppe> &teile) : FTN(ftn), teile(teile) {}

void meisteTeile(){
    list<Fertigteil>::iterator projektsucher;
    list<Baugruppe>::iterator gruppensucher;
    int max, stelle, summe;
    for (projektsucher = Projekt.begin();projektsucher != Projekt.end();projektsucher++){
        summe=0;
        for(gruppensucher=projektsucher->teile.begin();gruppensucher != projektsucher->teile.end(); gruppensucher++){
            summe+=gruppensucher->teile.size();
        }
        if (summe>max){
            max = summe;
            stelle = projektsucher->FTN;
        }
    }
    printf("Meiste Rohteile hat FT mit nr %i", stelle);
}
void einlesen(char pfad[]){
    struct Artikel {
        int artnr,preis;
        char name[25];
    };

    FILE *FilePointer;
    char str[125];
    int artnr, preis, anz, mom= 0;
    char name[25];
    struct Artikel *seindummerscheißarray;
    FilePointer = fopen(pfad, "r");

    while (!feof(FilePointer)){
        fgets(str,125,FilePointer);
        anz++;
    }
    seindummerscheißarray = (struct Artikel*)malloc(anz*sizeof(Artikel));
    while (!feof(FilePointer)){
        struct Artikel art;
        fgets(str,125,FilePointer);
        int init_size = strlen(str);
        char delim[] = ";";
        char *ptr = strtok(str, delim);
        art.artnr= atoi(ptr);
        ptr = strtok(NULL, delim);
        art.preis = atoi(ptr);
        ptr = strtok(NULL, delim);
        strcpy(ptr,art.name);
        seindummerscheißarray[mom] = art;
        mom++;S
    }



}

int main (){
    Rohteil Rohteil1(1);
    list<Rohteil> Liste1 = {Rohteil1};
    Baugruppe Baugruppe1(123, Liste1);
    list<Baugruppe> Liste2 = {Baugruppe1};
    Fertigteil Fertigteil1(1234, Liste2);

    for (auto i = Fertigteil1.teile.begin(); i != Fertigteil1.teile.end(); i++){
        printf("Baugruppe %d \n", i->BGN);
        for (auto j = i->teile.begin(); j != i->teile.end();j++){
            printf("%d", j->Rohteilnr);
        }
    }

}
