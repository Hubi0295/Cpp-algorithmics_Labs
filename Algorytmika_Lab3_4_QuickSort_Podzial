#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <cstdlib>
using namespace std;
struct student{
    string imie;
    string nazwisko;
    int punkty;
};
void quickSort(int tablica[], int lewy,int prawy, int tryb);
void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb);
void wczytajStudentow(student *&tab,int *liczba_studentow);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student*tab,int n);
void dwupodzial(student*tab,int n, int granica, int *koniec);
void dwupodzial_wyswietl(student*tab,int n, int granica, int koniec);
void trojpodzial(student *tab, int n, int *koniec1, int *koniec2);
void trojpodzial_wyswietl(student *tab, int n, int kon1, int kon2);
int main() {
    int liczba_studentow=0, *wsk, granica,
            *koniec,*koniec1,*koniec2, kon, kon1, kon2;
    int wybor=3;
    koniec1=&kon1;
    koniec2=&kon2;
    koniec=&kon;
    wsk=&liczba_studentow;
    student *tab2=new student[20];
    wczytajStudentow(tab2, wsk);
    wyswietlStudentow(tab2,liczba_studentow);
    while(wybor!=2){
        cout<<"Chcesz podzial na dwie czesci- wcisnij 0, chcesz podzial na trzy czesci- wcisnij 1, chcesz wyjsc- wcisnij 2";
        cin>>wybor;
        if(wybor==0){
            cout<<"Podaj granice: ";
            cin>>granica;
            cout<<"Dwupodzial"<<endl;
            dwupodzial(tab2,liczba_studentow,granica,koniec);
            dwupodzial_wyswietl(tab2,liczba_studentow,granica,kon);
            cout<<endl;
        }
        if(wybor==1){
            cout<<"Trojpodzial"<<endl;
            trojpodzial(tab2,liczba_studentow,koniec1,koniec2);
            trojpodzial_wyswietl(tab2,liczba_studentow,kon1,kon2);

        }

    }
    int tab[8]={123,123,1,2,-123,123123,21,-1234};
    quickSort(tab,0,7,1);
    int i=0;
    while(i<8){
        cout<<tab[i]<<endl;
        i++;
    }
    quickSortDlaStruktur(tab2,0,13,1);
    wyswietlStudentow(tab2,13);
    return 0;
}
void quickSort(int tablica[], int lewy,int prawy, int tryb){//Quicksort dla liczb
    int srodek=(int)(lewy+prawy)/2;
    int piwot=tablica[srodek];
    int zamiana=tablica[prawy];
    tablica[prawy]=tablica[srodek];
    tablica[srodek]=zamiana;
    int granica = lewy;
    int i=lewy;
    while(i<prawy){
        if(tryb) {
            if(tablica[i]<piwot){
                int y =tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=y;
                granica+=1;
            }
        }
        else{
            if(tablica[i]>piwot){
                int x=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=x;
                granica+=1;
            }
        }
        i+=1;
    }
    zamiana=tablica[prawy];
    tablica[prawy]=tablica[granica];
    tablica[granica]=zamiana;
    if(lewy<granica-1){
        quickSort(tablica,lewy,granica-1,tryb);
    }
    if(granica+1<prawy){
        quickSort(tablica,granica+1,prawy,tryb);
    }
}
void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb){//Quicksort dla struktur
    int srodek=(int)(lewy+prawy)/2;
    int piwot=tablica[srodek].punkty;
    student robocza1 = tablica[srodek];
    tablica[srodek]=tablica[prawy];
    tablica[prawy]=robocza1;
    int granica = lewy;
    int i=lewy;
    while(i<prawy){
        if(tryb) {
            if(tablica[i].punkty<piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        else{
            if(tablica[i].punkty>piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        i+=1;
    }
    student robocza3 = tablica[prawy];
    tablica[prawy]=tablica[granica];
    tablica[granica]=robocza3;
    if(lewy<granica-1){
        quickSortDlaStruktur(tablica,lewy,granica-1,tryb);
    }
    if(granica+1<prawy){
        quickSortDlaStruktur(tablica,granica+1,prawy,tryb);
    }
}
void wczytajStudentow(student *&tab, int *liczba_studetnow){
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
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    *liczba_studetnow=liczbaStudentow;
    plik.close();
}
void usunTabliceStudentow(student *&tab){
    delete []tab;
}
void wyswietlStudentow(student*tab,int n){
    for(int i=0;i<n;i++){
        cout<<"numer:"<<i+1<<" imie:"<<tab[i].imie<<endl;
        cout<<"nazwisko:"<<tab[i].nazwisko<<endl;
        cout<<"punkty:"<<tab[i].punkty<<endl;
        cout<<endl;
    }
}
void dwupodzial(student*tab,int n,int granica, int *koniec){
    int i=0;
    int j =n-1;
    while(i<j){
        while(tab[i].punkty <= granica && i<j){
            i++;
        }
        while(tab[j].punkty>granica && i<j){
            j--;
        }
        if(i<j){
            student robocza=tab[i];
            tab[i]=tab[j];
            tab[j]=robocza;
            i+=1;
            j-=1;
        }
    }
    if(tab[i].punkty<=granica){
        *koniec=i+1;
    }
    else{
        *koniec=i;
    }
}
void dwupodzial_wyswietl(student*tab,int n, int granica, int koniec){
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<"Studenci Ktorzy otrzymali<="<<granica<<" punktow:"<<endl;
            cout<<endl;
        }
        if(i<koniec){
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
            continue;
        }
        if(i==koniec){
            cout<<endl;
            cout<<"Studenci Ktorzy otrzymali>"<<granica<<" punktow:"<<endl;
        }
        if(i>=koniec){
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
    }
}
void trojpodzial(student *tab, int n, int *koniec1, int *koniec2){
    int i=-1;
    int j=0;
    int k=n;
    while(j<k){
        if(tab[j].punkty%3==0){
            i++;
            student robocza=tab[i];
            tab[i]=tab[j];
            tab[j]=robocza;
            j++;
        }
        else{
            if(tab[j].punkty%3==2){
                k--;
                student robocza=tab[k];
                tab[k]=tab[j];
                tab[j]=robocza;
            }
            else{
                j++;
            }
        }
    }
    *koniec1=i;
    *koniec2=k;
}
void trojpodzial_wyswietl(student *tab, int n, int kon1, int kon2){
    for(int i=0;i<n;i++){
        if(i<=kon1){
            if(i==0){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
        if(i>kon1 && i<kon2){
            if(i==kon1+1){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3 z reszta 1"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
        if(i>=kon2){
            if(i==kon2){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3 z reszta 2"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
    }
}
