#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include<limits>
#include "plansza.h"

using namespace std;

int ustawM(){
    int m=5;
    return m;
}

int ustawN(){
    int n=4;
    return n;
}

Plansza::Plansza(){
    m=ustawM();
    n=ustawN();

    vector<std::vector<int> > tab1(m, std::vector<int>(n, 0));

    tab=tab1;
}

vector<std::vector<int> > Plansza::zwrocTab(){
    return tab;
}

Plansza::~Plansza(){}

Figura::~Figura(){}

//pobiera liczbe kwadratow jednostkowych dla figury od uzytkownika
int Figura::ileBedzieKw(){
    int wart;
    cout<<"Z ilu kwadratow jednostkowych ma skladac sie figura?"<<endl;
    cin>>wart;
    return wart;
}

//wyswietlanie vectora tab klasy Plansza
void Plansza::wyswietl(){
    for (int i=0; i< ustawM(); i++)
    {
        for (int j=0; j< ustawN(); j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

//wyswietlanie kolejnych elementow vectora tab klasy WektorFigur
void WektorFigur::wyswietlWektor(){
        for (int i=0; (unsigned)i<tab.size();i++){
            cout<<"FIGURA "<<(i+1)<<endl;
            tab[i].wyswietl();
            cout<<endl;
    }
}

int Figura::pobierzX() {
    int x;
    cout<<"Podaj wspolrzedna x: ";
    cin>>x;

    //obsluga bledu strumienia wejsciowego
    while(!cin ||x>ustawM() ||x==ustawM()){
    cout << "Zla wartosc!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> x;
}
    return x;
}

int Figura::pobierzY() {
    int y;
    cout<<"Podaj wspolrzedna y: ";
    cin>>y;

    //obsluga bledu strumienia wejsciowego
    while(!cin ||y>ustawN() ||y==ustawN()){
    cout << "Zla wartosc!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> y;
}
    return y;
}

int decyzja(){
    int decyzja;
    cout<<"Czy to wszystkie figury? 0-->tak  1-->nie"<<endl;
    cin>>decyzja;

    //obsluga bledu strumienia wejsciowego
    while(!cin || decyzja>1){
    cout << "Zla wartosc!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> decyzja;
}
    return decyzja;
}

void WektorFigur::rysujWyp(){
    //tworzenie dwoch tablic
   vector<std::vector<int> > tab1;
   vector<std::vector<int> > tab2;
   int reszta=0;
   int druga=0;
   int ileKwMaFig=0; //ileKw klasy Figura
   int licznik=1; //ktora figura z kolei jest wypisywana
   int n=0; //sprawdza ile z kwadratow jednowstkowych figury dotad wypisano

   //tab2 to plansza figury znajdujacej sie aktualnie na poczatku.
   tab2=zwrocWektor().front().zwrocTab();
   tab1=tab2;
   ileKwMaFig=tab[0].zwrocIleKw();

   //ukladanie klockow poprzez wypisywanie ich w tablicy od lewej do prawej w wierszach parzystych
   //i od prawej do lewej w nieparzystych
    cout<<"Oto plansza z wypisanymi klockami"<<endl<<endl;
    for (int i=0; i< ustawM(); i++)
    {
        reszta=(i%2);
        for (int j=0; j< ustawN(); j++)
        {
            if(n==ileKwMaFig){
                //biore nastepna figure z wektora
                ileKwMaFig=tab[licznik].zwrocIleKw();
                ++licznik;
                n=0;
            }
            if(reszta==0){
                tab1[i][j]=licznik;
            }
            else {
                druga=(ustawN()-1)-j;
                tab1[i][druga]=licznik;
            }
            ++n;
        }
    }

    //wypisanie wypelnionej planszy
    for (int i=0; i< ustawM(); i++)
    {
        for (int j=0; j< ustawN(); j++)
        {
            cout<<tab1[i][j]<<" ";
        }
        cout<<endl;
    }
}

//tworzenie figury o ksztalcie narzuconym przez uzytkownika
void Figura::rysujFig() {
    int y;
    int x;
    int n=0;
    for(int i=0; i<ileKw;i++)
    {
        do {
            x=pobierzX();
            y=pobierzY();
            if(tab[x][y]==0) {
                    tab[x][y]=1;
                    n=1;
            }
            else {
                    cout<<"To pole jest juz zajete!"<<endl;
                    n=0;
            }
        }
        while(n==0);

            wyswietl();
    }
}

//sprawdza, czy klockow jest wystarczajaca ilosc, zeby pokryc plansze
bool porownajSume (WektorFigur A, Plansza Pl){
    int m;
    m=Pl.zwrocM();
    int n;
    n=Pl.zwrocN();

    int sumaKw;
    sumaKw=A.zwrocSumeKw();

    if((m*n)==sumaKw){
        return true;
    }

    else {
            return false;
    }
}


//konstruktor
WektorFigur::WektorFigur() {
sumaKw=0;
int n=1;
    vector<Figura>tab1;
    do {
            cout<<endl<<"Figura nr "<<n<<endl;;
            tab1.push_back(Figura());
            //tab1.back().rysujFig();
            sumaKw+=tab1.back().zwrocIleKw();
            n++;
        }
    while(decyzja());
    tab=tab1;
}

WektorFigur::~WektorFigur(){}

int Figura::zwrocIleKw(){
    return ileKw;
}

int WektorFigur::zwrocSumeKw(){
    return sumaKw;
}

vector<Figura> WektorFigur::zwrocWektor(){
    return tab;
}

int Plansza::zwrocM(){
    return m;
}

int Plansza::zwrocN(){
    return n;
}

