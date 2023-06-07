#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
struct Studenci{
    string imie;
    string nazwisko;
    int punkty;
};
void tworzenie_kopca(int *tab,int n);
void rozbieranie_kopca(int *tab, int n);
void WczytywanieDanych(Studenci *student);
void tworzenie_kopca_struktur(Studenci *tab,int n, int tryb);
void rozbieranie_kopca_struktur(Studenci *tab, int n, int tryb);


int main()
{
    Studenci *tab = new Studenci[20];
    WczytywanieDanych(tab);
    for(int i=0;i<14;i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }
    int wybor;
    cout<<"Podaj tryb 1-rosnaco, 0- malejaco"<<endl;
    cin>>wybor;
    tworzenie_kopca_struktur(tab,14,wybor);
    rozbieranie_kopca_struktur(tab,14,wybor);
    cout<<endl;
    for(int i=0;i<14;i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }
    delete []tab;

}
void tworzenie_kopca_struktur(Studenci *tab,int n, int tryb){
   int i=1;
    while(i<n){
        int j=i;
        int k=(int)(j-1)/2;
        Studenci x=tab[i];
        if(tryb==1){
        while(j>0 && tab[k].punkty<x.punkty){
            tab[j]=tab[k];
            j=k;
            k=(int)(j-1)/2;
        }
        tab[j]=x;
        i++;
        }
        else{
        while(j>0 && tab[k].punkty>x.punkty){
            tab[j]=tab[k];
            j=k;
            k=(int)(j-1)/2;
        }
        tab[j]=x;
        i++;
        }

    }
}
void rozbieranie_kopca_struktur(Studenci *tab, int n, int tryb){
int i=n-1;
    int m;
    while(i>0){
        swap(tab[0],tab[i]);
        int j=0;
        int k=1;
        if(tryb==1){
                while(k<i){
            if(k+1<i && tab[k+1].punkty>tab[k].punkty){
                m=k+1;

            }
            else{
                m=k;
            }
            if(tab[m].punkty<=tab[j].punkty){
                break;
            }
            swap(tab[j],tab[m]);
            j=m;
            k=2*j+1;
        }
        i--;
        }
        else{
            while(k<i){
            if(k+1<i && tab[k+1].punkty<tab[k].punkty){
                m=k+1;

            }
            else{
                m=k;
            }
            if(tab[m].punkty>=tab[j].punkty){
                break;
            }
            swap(tab[j],tab[m]);
            j=m;
            k=2*j+1;
        }
        i--;}

    }
}



void WczytywanieDanych(Studenci *student){
    string sciezka,linia,pomoc;
    int liczbaStudentow;
    fstream plik;
    plik.open("studenci.csv");
    char sredniki;
    plik >> liczbaStudentow;
    for(int i = 0; i < 2; i++)
        plik >> sredniki;
    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, student[i].imie, ';');
        getline(ss, student[i].nazwisko, ';');
        getline(ss, pomoc);
        student[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();
}
