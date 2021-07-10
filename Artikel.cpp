#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


#include <map>
#include <list>

class artikel;
class verkaufteartikel;
class warengruppe;

class artikel
{
public:
    int artnr;
    string name;
    list <warengruppe> listwarengruppe;
};

class warengruppe
{
public: int wgrnr;
    string name;
};

class verkaufteartikel
{
public:
    int artnr;
    int betrag;
    int summe;
};

list <verkaufteartikel> listva;
map <int,int> mapSumme;// Artbr und Summe
map <int, artikel> mapArtikel;

artikel bestseller() {

    list<verkaufteartikel>::iterator setiter;
    for(setiter=listva.begin(); setiter != listva.end(); setiter++)
    {
        mapSumme[setiter->artnr]+=setiter->summe;
    }
    map<int,int>::iterator mapiter;
    int max=0, max_artnr=0;
    for(mapiter=mapSumme.begin(); mapiter != mapSumme.end(); mapiter++)
    {
        if ( mapiter->second > max)
        {
            max=mapiter->second;
            max_artnr=mapiter->first;
        }
    }
    return mapArtikel[max_artnr];
}

void schreibeva()
{
    FILE *fp;
    int i, artnr, err;
    float preis;
    char name[100];

    fp=fopen("d:\\va.txt", "w+");
    if (fp==NULL) //Datei konnten icht ge�ffnet werden
        return;
    fseek(fp, 0, SEEK_SET);
    list<verkaufteartikel>::iterator setiter;
    for(setiter=listva.begin(); setiter != listva.end(); setiter++)
        fprintf(fp, "%d,%d\n", setiter->artnr, setiter->summe);
    fclose(fp);
}

int main()
{
    verkaufteartikel va1,va2,va3;
    va1.artnr=1;
    va1.summe=13;

    va2.artnr=1;
    va2.summe=14;

    va3.artnr=2;
    va3.summe=23;

    artikel a1,a2;
    a1.artnr=1;
    a1.name="Hose";

    a2.artnr=2;
    a2.name="Shirt";

    mapArtikel[1]=a1;
    mapArtikel[2]=a2;

    listva.push_front(va1);
    listva.push_front(va2);
    listva.push_front(va3);

    artikel a;
    a=bestseller();

    cout << "Topseller Artikelname= " << a.name;
    schreibeva();
}
