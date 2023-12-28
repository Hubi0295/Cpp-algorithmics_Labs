#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void wprowadzdane(string *tekst, string *wzorzec);
void algorytmnaiwny(string tekst, string wzorzec);
void algorytmKMP(string tekst, string wzorzec);
void zbudujTabliceDopasowan(string wzorzec, int *p);
void tablicaPrzesuniec(string wzorzec, int *p, int pocz, int kon);
void algorytmBM(string wzorzec, string tekst, int *p, int pocz);
int main() {
    string *w_tekst, *w_wzorzec, tekst, wzorzec;
    w_tekst=&tekst;
    w_wzorzec=&wzorzec;
    int wybor=5;
    while(wybor!=0 ){
        cout<<"Wcisnij 1- jesli chcesz wprowadzic tekst oraz wzorzec"<<endl;
        cout<<"Wcisnij 2- jesli chcesz wykonac algorytm naiwny"<<endl;
        cout<<"Wcisnij 3- jesli chcesz wykonac algorytm Knutha-Morrisa-Pratta"<<endl;
        cout<<"Wcisnij 4- jesli chcesz wykonac algorytm Boyer'a Moore'a"<<endl;
        cout<<"Wcisnij 0- jesli chcesz wyjsc z aplikacji"<<endl;
        cout<<"Wybor: ";
        cin.sync();
        cin>>wybor;
        if(wybor>4 || wybor<0){
            cout<<"Bledne dane!"<<endl;
        }
        if(wybor==1){
            wprowadzdane(w_tekst, w_wzorzec);
        }
        if(wybor==2){
            algorytmnaiwny(tekst,wzorzec);
        }
        if(wybor==3){
            algorytmKMP(tekst,wzorzec);
        }
        if(wybor==4){
            int *p= new int[255];
            algorytmBM(wzorzec,tekst,p,0);
        }
    }
    return 0;
}
void wprowadzdane(string *tekst, string *wzorzec){
    cout<<"Podaj tekst: ";
    fflush(stdin);
    getline(cin,*tekst);
    cout<<endl;
    fflush(stdin);
    cout<<"Podaj wzorzec: ";
    getline(cin,*wzorzec);
}
void algorytmnaiwny(string tekst, string wzorzec){
    int i=0, l=0;
    while(i<=(tekst.length()-wzorzec.length())){
        int j=0;
        while(j<wzorzec.length() && wzorzec[j]==tekst[i+j]){
            j++;
        }
        if(j==wzorzec.length()){
            cout<<"Indeks: "<<i<<endl;
        }
        i++;
    }
}
void algorytmKMP(string tekst, string wzorzec) {
    int *p = new int[wzorzec.length()];
    zbudujTabliceDopasowan(wzorzec, p);
    int l=0;
    int i = 0;
    while (i < wzorzec.length()) {
        i++;
    }
    i = 0;
    int j = 0;
    while (i < tekst.length() - wzorzec.length() + 1) {
        while(wzorzec[j]==tekst[i+j]&&j<wzorzec.length()){
            j++;
        }
        if(j==wzorzec.length()){
            cout<<"Indeks: "<<i<<endl;
        }
        i+=max(1,j-p[j]);
        j=p[j];
    }
}
void zbudujTabliceDopasowan(string wzorzec, int *p){
    p[0]=0;
    p[1]=0;
    int t=0;
    int i=1;
    while(i<wzorzec.length()){
        while(t>0 && wzorzec[t]!=wzorzec[i]){
            t=p[t];
        }
        if(wzorzec[t]==wzorzec[i]){
            t++;
        }
        p[i+1]=t;
        i++;
    }
}
void algorytmBM(string wzorzec, string tekst, int *p, int pocz){
    tablicaPrzesuniec(wzorzec,p,0,255);
    int n_pocz=(int)pocz;
    int i=0;
    while(i<=tekst.length()-wzorzec.length()){
        int j=wzorzec.length()-1;
        while(j>-1 && wzorzec[j]==tekst[i+j]){
            j--;
        }
        if(j==-1){
            cout<<"Indeks: "<<i<<endl;
            i++;
        }
        else{
            i=i+max(1,j-p[tekst[i+j]-n_pocz]);
        }
    }
}
void tablicaPrzesuniec(string wzorzec, int *p, int pocz, int kon){
    int n_pocz = (int)pocz;
    int n_kon = (int)kon;
    int i=0;
    while(i<=n_kon-n_pocz){
        p[i]=-1;
        i++;
    }
    i=0;
    while(i<wzorzec.length()){
        p[wzorzec[i]-n_pocz]=i;
        i++;
    }
    
}
