#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<limits>
#include <vector>

using namespace std;

class Plansza
{
    protected:
	int m, n;
        vector<std::vector<int> > tab;
	public:
	Plansza();
	virtual void wyswietl();
	virtual vector<std::vector<int> > zwrocTab();
	virtual int zwrocM();
	virtual int zwrocN();
	friend int ustawM();
	friend int ustawN();
        ~Plansza();
};


class Figura : public Plansza {
        int ileKw;
    public:
        Figura(int wartIleKw=1):Plansza(){ileKw=ileBedzieKw();};
        void rysujFig();
        int pobierzX();
        int pobierzY();
        int ileBedzieKw();
        int zwrocIleKw();
        friend vector<Figura> tworzenieFigur();
        ~Figura();
};

class WektorFigur {
        vector<Figura>tab;
        int sumaKw;
    public:
        WektorFigur();
        int zwrocSumeKw();
        vector<Figura> zwrocWektor();
        void rysujWyp();
        void wyswietlWektor();
        friend int ustawM();
        friend int ustawN();
        friend void przepiszKlocki(Figura B, Plansza Pl);
        ~WektorFigur();
};

class Wypelniona : public Plansza {

};

bool porownajSume (WektorFigur A, Plansza Pl);
int wartIleFigur();
int decyzja();
vector<Figura> tworzenieFigur();
