#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <string>
#define L 20
#include "ConsoleColor.h"
#include <fstream>

// #define MAX 5
using namespace std;


class Pracownicy
{

protected: //private;
	 	 char nazwa [L];
      char stanowisko [L];

	 char miejscowosc [L];

	 public:
int l;
             int rok;
             int wiek;

 	void piszXY( int x, int y);

	 	Pracownicy();
	 	char* getNazwa();
	 	char* getMiejscowosc();
	 	char* getStanowisko();
	 	int getWiek();
	 	int getRok();
	 	void czysc();
	 	void pobierz(char *naz, char *miejsco ,int ro, int wie, char *stan);

	 	void drukuj();

};
class bazaPracownicy:public Pracownicy
{
protected:


    int current;

   int numerfound;
   Pracownicy *found;
Pracownicy *tab; //wskazanie do obiektu
int rozmiar;//rozmiar tablicy podmy w konstruktorze
int licznosc;


int licznoscFound;
int currentFound;
private :
int i; //wlasciwsze jest deklaracja w metodach
public:
	bool searchNazwa(char naz[]);
    	void  	usunaktualny();
	bazaPracownicy(int roz); //kontruktor parametryczny
	 	void dodajkolejny(char *naz, char *miejsco ,int ro, int wie, char *stan);

	 		void setCurrent();
	 		void setCurrentFound();
	 			void Wyszukiwarka(float  minim, float maksim);
	 			void sortuj();
	 			void edytuj(char *naz, char *miejsco ,int ro, int wie, char *stan);
	void next();
	void wroc();

	void previous();
	void showCurrent(int x, int y);
	void nextFound();
	void czysccalosc();

	void previousFound();
	void showCurrentFound(int x, int y);
void saveFile();
	void readFile();

	~bazaPracownicy(); //destruktor
};


void gotoxy(int x, int y)
{
 COORD c;
 c.X =x-1;
 c.Y =y-1;
 SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void Pracownicy::piszXY(int x, int y) //lepiej 2 metody(etykiet i wartosci)

{
	gotoxy(x + 10, y);
	cout <<blue<< "Nazwa:                         ";
	gotoxy(x + 10, y + 1);
	cout <<  "Miejscowosc:                            ";
	gotoxy(x + 10, y + 2);
	cout << "Rok:                     ";

    gotoxy(x + 10, y + 3);
	cout << "Stanowisko:                     ";
	gotoxy(x+10, y +4);
	cout<<"Wiek:                ";
	
	
	
	
	gotoxy(x + 25, y);
	cout <<white<< nazwa;
	gotoxy(x + 25, y + 1);
	cout << miejscowosc;
	gotoxy(x + 25, y + 2);
	cout << rok;
	gotoxy(x + 25, y + 3);
	cout << stanowisko;
	gotoxy(x+25, y+4);
	cout<<wiek;
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% METODY Pracownicy #################################
Pracownicy::Pracownicy()
{
	strcpy(nazwa, " ");
rok=0;
	strcpy(stanowisko, " ");
		strcpy(miejscowosc, " ");
		wiek=0;

}
	void Pracownicy::pobierz(char *naz, char *miejsco ,int ro, int wie, char *stan)
	{
		strcpy(nazwa, naz);
		strcpy(stanowisko, stan);
		strcpy(miejscowosc, miejsco);
	rok=ro;
	wiek=wie;
}

	void Pracownicy::drukuj()

	{

		cout<<nazwa<<"    "<<miejscowosc<<"   "<<rok<< "   "<<wiek<< "  " <<stanowisko<<endl;

}

	// ########################### metody baza%%%%%%%%%%%%%%%%%%%%%%%%%5





	 bazaPracownicy::bazaPracownicy(int roz) // wazna zmiana
	{
		rozmiar=roz; //wazna zmiana

found= new Pracownicy[rozmiar];
		tab=new Pracownicy[rozmiar];
		for (i=0;i<rozmiar;i++)
		tab[i].czysc();
		licznosc=0;
		licznoscFound=0;
		current=-1;
		currentFound=-1;

	}
	void Pracownicy::czysc()
{

	strcpy(nazwa, " ");
	strcpy(stanowisko, " ");
	strcpy(miejscowosc, " ");
	rok=0;
	wiek=0;

	}

void bazaPracownicy::previous()
	 {


if (current>0)
		 {
		 	cout<<current;
			 current--;

		 }

	 }
	 void bazaPracownicy::czysccalosc()
	 {
	 for(i=0;i<rozmiar;i++)
	 {
	 tab[i].czysc();
	 licznosc=0;
	 }

	 }
	 void bazaPracownicy::previousFound()
	 {

		 if (currentFound>rozmiar)
		 {
			 currentFound--;

		 }

	 }
	 


	 void bazaPracownicy::next()
	 {
	 if (current<licznosc - 1)
		 {
			 current++;

		 }
		}



	  void bazaPracownicy::nextFound()
	 {
		 if (currentFound<licznoscFound+rozmiar+1)
		 {
			 currentFound++;

		 }
	 }


	 void bazaPracownicy::showCurrent(int x, int y)

	 {
		 if (current >= 0)
			 tab[current].piszXY(x, y);

	 }
	 	 void bazaPracownicy::showCurrentFound(int x, int y)

	 {
		 if (currentFound >= rozmiar+l)
			 tab[currentFound].piszXY(x, y);

	 }
	 void bazaPracownicy::setCurrent()
	 {

			 current=0;

	 }

int Pracownicy::getWiek()

{
	return wiek;
}
char* Pracownicy::getStanowisko()
{
	return stanowisko;
}
	 void bazaPracownicy::usunaktualny()
{
	ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("Kosz.txt");
    fout.open ("Kosz.txt",ios::app); // Append mode
    if(fin.is_open())
    cout<<"hahaha";
        fout<< tab[current].getNazwa();
        fout<< "     "; 
         fout<< tab[current].getMiejscowosc();
         fout<< "     ";
          fout<<tab[current].getWiek();
          fout<< "     ";
           fout<< tab[current].getStanowisko();
            fout<< "     ";
            fout<< "  \n   ";
            
	
fin.close();
    fout.close(); // Closing the file

	
	
if (current>=0 && licznosc>1)

{

for(int i=current; i<licznosc; i++)
{
tab[i]=tab[i+1];
}
licznosc--;
current--;
}
else if (licznosc==1 || current==0)
{
    tab[0]=tab[i+1];
current=-1;
licznosc=0;

}
}



void bazaPracownicy::dodajkolejny(char *naz, char *miejsco ,int ro, int wie, char *stan)
	{
                          int wsk =0;     
                        for(int i =0; i<=rozmiar;i++)             
	if (tab[i].getRok()==0 && wsk==0)
	{
wsk=1;


tab[i].pobierz(naz,miejsco,ro, wie,stan);
licznosc++;

	}
}
	

char* Pracownicy::getNazwa()
{


	return nazwa;

}
char* Pracownicy::getMiejscowosc()
{
	
	return miejscowosc;
}

bool bazaPracownicy::searchNazwa (char naz[])
{

	licznoscFound=0;
	currentFound;
	for(i=0; i<licznosc; i++)
	if(strcmp(tab[i].getNazwa(), naz)==0)
	{
		found[licznoscFound]=tab[i];

		licznoscFound++;

	}
	if (licznoscFound)
	{

			for(i=0;i<licznoscFound;i++)
		 found[i].drukuj();
		currentFound=0;
		return 1;

	}
	else
cout<<"Nic nie znaleziono \n";
	return 0;


}




void bazaPracownicy::edytuj(char *naz, char *miejsco ,int ro, int wie, char *stan)
	{



tab[current].pobierz(naz,miejsco,ro,wie, stan);
}

void bazaPracownicy::Wyszukiwarka( float minim, float maksim)

{

int l= 2;
licznoscFound=0;
  currentFound=rozmiar+l;

	for(int i=0;i <licznosc; i++)
	{
	if(minim<=tab[i].rok && maksim>=tab[i].rok )
	{
             tab[rozmiar+l]=tab[i];

         l++;
		licznoscFound++;

}

}
cout<<licznoscFound;
if(licznoscFound==0)

{
cout<<"Nie znaleziono pracownikow w danym roczniku";
}
}

int Pracownicy::getRok() {


return rok;
}
void bazaPracownicy::sortuj()
{


 int nr,  indmin, pom, znacznik;



 if (licznosc>1)
 {
 Pracownicy pom;
 for ( int nr =1; nr <licznosc; nr++)
 for (i=0; i<licznosc-nr ; i++)
 if ( tab[i].getRok()>tab[i+1].getRok() )
 {
 	pom=tab[i];
 	tab[i]=tab[i+1];
	 tab[i+1]=pom;
	  }
 }
//koniec sortowania

  cout<<"POSORTOWANO"<<endl<<endl;

 for (i=0; i<=licznosc; i++)
 {
     cout<<i;
    tab[i].drukuj();

}

	
}

bazaPracownicy::~bazaPracownicy()
{

delete tab;
getchar();
}



void bazaPracownicy::saveFile()
{
FILE *fp;

fp=fopen("dane.dat", "wb");
fwrite(&rozmiar, sizeof(rozmiar),1, fp);
fwrite(&licznosc, sizeof(licznosc), 1, fp);

fwrite(tab, sizeof(*tab)*rozmiar, 1, fp);
fclose(fp);

}

void bazaPracownicy::readFile()
{
FILE *fp;

fp=fopen("dane.dat", "rb");
fread(&rozmiar, sizeof(rozmiar),1, fp);
fread(&licznosc, sizeof(licznosc), 1, fp);

fread(tab, sizeof(*tab)*rozmiar, 1, fp);
fclose(fp);
if (licznosc>0)
{
current = 0;

}
else current = -1;

}

main()
	{



		int sz, i, licznosc=0, rozmiar, r, licznoscFound, menu_item=0, ch, x=7, wi, got=2; ;

		char n[L] ,s[L], m[L], zn;
		float c;
	
		rozmiar=25;
		cin.ignore();
bazaPracownicy baza(rozmiar);
 baza.readFile();

	glownylabel:
	system("cls");
		cout<<blue<<" \t \t \t  \t \t  Program do obslugi bazy pracownikow";
	cout<<white;
	 gotoxy(15,2);
 printf("******************************************************\n");
	cout <<green<<" \t \t 1.Dodaj pracownika"<<endl;

		cout <<white<<"\t \t 2.Zapisz baze"<<endl;

		cout<<red<< " \t \t 3.Usun baze"<<white<<endl;

		cout <<  " \t \t 4.Przegladaj(widok przegladania)" <<white<<endl;

		cout << " \t \t 5.Zobacz pelna liste(sortowanie wedlug daty zatr)"<<endl<<white;;

		cout <<yellow<< " \t \t 6.Wyszukaj pracownikow"<<endl;

		cout <<red<< " \t \t 7.Koniec"<<endl;

		cout<<white<< "  "<<endl;
		 	 gotoxy(15,10);
 printf("******************************************************\n");

	do{
						zn=getch();

						switch (zn)
						{

                               case '1':
                                    {
                                        int wsk=0;
                                    

							cout<<"nazwa: \n" ; cin>>(n);
						cout<<"miejscowosc: \n" ; cin>>(m);
									cout<<"rok zatrudnienia: \n" ; cin>>r;
									cout<<"Wiek : \n ";  cin>>wi;

									cout<<"stanowisko: \n " ; cin>>(s);
									

							cin.ignore();
							baza.dodajkolejny(n,m ,r , wi,s);
						cout<<"dodano do bazy";
							Sleep(2000);
							
							goto glownylabel;
							 break;
                        }

				 case '2':
				{

	baza.saveFile();
							cout << "zapisano do pliku" << endl;
							break;
                        }


                        		 case '3':
				{

                                baza.czysccalosc();
							cout << "usunieto" << endl;
							break;
}

 case '4':
				{

                            baza.setCurrent();
                            goto labeldwa;

                            }

                       case '5':
				{

                      	baza.sortuj();
                      	cout<<"kliknij ENTER aby wyczyscisc";
                      	char aa;



do	{
        	aa=getch();

	switch(aa)
{
	case 13:
           { goto glownylabel;
                       }
break;
      default: 
               
               {cout<<"prosze kliknac enter "<<endl;}
break;

			}
	}
	while(aa!='u');
                      	
                      	break;
                       }

				     	 case '6':
				{
					 char gh;

						int wybor;
					do {

					cout<<"(1)Wyszukac po imieniu \t "<< "(2)Wyszukac po roku zatrudnienia[1 LUB 2] \n " ;
					cin >>wybor;
					if(wybor==1)
					{

					  	char wyszukanie[L];
                	cout<<"wprowadz imie ktore chcesz wyszukac   \n";
                	cin>>wyszukanie;
                	cout<<"Wyniki: \n ";
                	baza.searchNazwa(wyszukanie);
                	cout<<" Za 5 sekund wrocisz do MENU \n ";
                	
  
           Sleep(5000);
  
    goto glownylabel;

                }
                if (wybor==2)
                {

                           int m;
                            int w;
                           cout<< " \t \t Wprowadz przedzial rocznika przyjecia \n \n ";
                            do {
                           cout<<" \t \t \t Minimalny rok: \n \n ";


                           cin>>m;
                           cout<<" \t \t \t Maksymalny: \n \n ";

                           cin>>w;
                           if(w>2020||m<1950)
                           {
                                             cout<<"Bledna data, sproboj ponownie" << endl;

                                             }





				      	  }while(w>2020||m<1950);
				      	  
		      	baza.Wyszukiwarka(m, w);
		      	
		      	

		goto labeltrzy;

				      }
				      else if(wybor>2||wybor<1)
				      cout<<"Nieprawidlowy wybor sproboj jeszcze raz  \n \n ";
				  }while(wybor>2||wybor<1);
				      	break;
                    }

                     case '7':
				{
						 cout << "do widzenia" << endl;
							getchar();

					break;
                }
              
          }

}while(zn != 7);

		labeldwa:
		    baza.showCurrent(25, 50);

		    cout<<" \n \n"<<endl;
		 

cout<<red<<"1.Nastepny \t "<<"2.Wroc \t"<<"3.Usun \t "<<"4.Menu \t"<<"5.Edytuj rekord"<<endl;
	cout<<white<< "  "<<endl;

do
                {
             zn=getch();
			switch (zn)


			{
            case '1':

                baza.next();
                 baza.showCurrent(25,50);
                 
                 break;
           case '2':
                baza.previous();

                  baza.showCurrent(25,50);
                   
                  break;
           case '3':

               	baza.usunaktualny();
               	
               	Sleep(2000);
               	goto labeldwa;
            break;

           case '4' :

               cout<<"\n \n \n "<<endl;
                cout<<"\n \n \n "<<endl;
                 cout<<"\n \n \n "<<endl;

            goto glownylabel;
break;
case'5' :
        {   
            cout <<"  \n \n \n \n \n \t";
        cout<<endl;
        cout<<endl;
        		        cout<<"nazwa: \n " ; cin>>(n);
						cout<<"miejscowosc: \n " ; cin>>(m);
						cout<<"rok zatrudnienia: \n " ; cin>>r;
						cout<<"Wiek: \n"; cin>>wi;
					    cout<<"stanowisko: \n " ; cin>>(s);
					    	cin.ignore();

        baza.edytuj(n, m ,r,wi, s);
        	system("cls");
        goto labeldwa;
        }

         	}
         	}while(zn!='7');
      labeltrzy:
   

                     baza.showCurrentFound(25, 100);
                        
                     cout <<"\n";
                     
	cout<<yellow<<"\t \t 1. Dalej  \t \t "<<"2.Poprzedni \t \t"<<"3.Wroc do menu \t \t ";
		cout<<white<< "  "<<endl;

do
                {
             zn=getch();
			switch (zn)


			{
            case '1':

                baza.nextFound();
                 baza.showCurrentFound(25,100);
                 break;
           case '2':
                baza.previousFound();

                  baza.showCurrentFound(25,100);
                  break;


           case '3' :
{
               cout<<"\n \n \n "<<endl;

            goto glownylabel;
break;
	}
    }
    }while(zn!='7');


}


