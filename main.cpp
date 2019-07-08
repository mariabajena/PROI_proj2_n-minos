#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include<limits>
#include "plansza.h"
using namespace std;

int main()
{
    cout<<"PROGRAM TESTUJACY MOZLIWOSCI KLASY"<<endl<<endl;

    Plansza Pl;
    cout<<"1. Tworzenie planszy: "<<endl;
    Pl.wyswietl();

    cout<<endl<<"2. Tworzenie wektora figur: "<<endl;
    WektorFigur W;

    cout<<endl<<"3. Wyswietlanie figur: "<<endl;
    W.wyswietlWektor();

    cout<<endl<<"4. Sprawdzenie, czy figury mozna wpisac w plansze: "<<endl;
    if(porownajSume(W, Pl)) {
            cout<<"Mozna"<<endl;
            W.rysujWyp();
    }
    else cout<<"Nie mozna wypelnic tablicy podanymi elementami :("<<endl;

    return 0;
}
