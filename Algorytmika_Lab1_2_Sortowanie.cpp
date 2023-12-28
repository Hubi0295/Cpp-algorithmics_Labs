#include <iostream>
using namespace std;
void przydzielPamiec1D(int *&tab, int n);
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice1D(int *&tab);
void usunTablice2D(int **&tab, int w);
void wyswietl1D(int* tab, int n);
void wyswietl2D(int** tab, int w, int k);
void sortowanieBabelkowe(int *&tablica, int n, int tryb);
void sortowaniePrzezWybor(int *&tablica, int n, int tryb);
void sortowaniePrzezWstawianie(int *&tablica, int n, int tryb);
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol);
int main() {
    int a,b,n, *tablica, tryb, wybor, **tab,w,k,nrkol;
    cout<<"Podaj wielkosc tablicy 1D: ";
    cin>>n;
    cout<<"Podaj zakres z ktorego beda losowane dane w tablicy"<<endl;
    cout<<"Poczatek: ";
    cin>>a;
    cout<<"Koniec: ";
    cin>>b;
    przydzielPamiec1D(tablica,n);
    wypelnijTablice1D(tablica,n,a,b);
    wyswietl1D(tablica,n);

    cout<<"Podaj ile chcesz wierszy tablicy 2D";
    cin>>w;
    cout<<"Podaj ile chcesz kolumn";
    cin>>k;
    cout<<"Podaj nr kolumny ktora ma byc sortowana: ";
    cin>>nrkol;
    przydzielPamiec2D(tab,w,k);
    wypelnijTablice2D(tab,w,k,a,b);

    cout<<"Z ktorego sortowania chcesz skorzystac, "<<endl<<"1-babelkowe"<<endl<<" 2-przez wybor"<<endl<<" 3-wstawianie"<<endl<<" 4-tablica2D babelkowe"<<endl<<" jezeli chcesz wyjsc wcisnij 0: ";
    cin>>wybor;
    if (wybor!=0){
        cout<<"Podaj jak chcesz posortowac tablice, 0-rosnaca, 1-malejaca: ";
        cin>>tryb;
    }
    while(wybor!=0) {
        if(wybor==1 and (tryb==0 or tryb==1)) {
            sortowanieBabelkowe(tablica, n, tryb);
            cout<<"Tablica posortowana:"<<endl;
            wyswietl1D(tablica,n);
            cout<<endl;
        }
        else if(wybor==2 and (tryb==0 or tryb==1)) {
            sortowaniePrzezWybor(tablica, n, tryb);
            cout<<"Tablica posortowana:"<<endl;
            wyswietl1D(tablica,n);
            cout<<endl;
        }
        else if(wybor==3 and (tryb==0 or tryb==1)) {
            sortowaniePrzezWstawianie(tablica, n, tryb);
            cout<<"Tablica posortowana:"<<endl;
            wyswietl1D(tablica,n);
            cout<<endl;
        }
        else if(wybor==4 and (tryb==0 or tryb==1)){
            wyswietl2D(tab,w,k);
            cout<<"Sortowanie"<<endl;
            sortowanieBabelkowe2D(tab,w,k,tryb,nrkol-1);
            wyswietl2D(tab,w,k);
        }
        else {
            cout<<"Niepoprawne dane"<<endl;
        }

        cout<<"Z ktorego sortowania chcesz skorzystac, "<<endl<<" 1-babelkowe"<<endl<<" 2-przez wybor"<<endl<<" 3-wstawianie"<<endl<<" 4-tablica2D babelkowe"<<endl<<" jezeli chcesz wyjsc wcisnij 0: ";
        cin>>wybor;
        if(wybor==0){
            break;
        }
        cout<<endl;
        cout<<"Podaj jak chcesz posortowac tablice, 0-rosnaca, 1-malejaca: ";
        cin>>tryb;
    }
    cout<<"Dziekuje, koniec aplikacji"<<endl;
    usunTablice1D(tablica);
    usunTablice2D(tab,w);
    return 0;
}
void sortowanieBabelkowe(int *&tablica, int n, int tryb){
    int x=n-1;
    while(x>0){
        for(int i=0;i<x;i++){
            int robocza = tablica[i];
            if(tryb) {
                if (tablica[i] < tablica[i + 1]) {
                    tablica[i] = tablica[i + 1];
                    tablica[i + 1] = robocza;
                }
            }
            else{
                if (tablica[i] > tablica[i + 1]) {
                    tablica[i] = tablica[i + 1];
                    tablica[i + 1] = robocza;
                }
            }
        }
        x-=1;
    }
}
void sortowaniePrzezWybor(int *&tablica, int n, int tryb){
    int i=n-1;
    while(i>0){
        int ind=0;
        int j=1;
        while(j<=i) {
            if(tryb) {
                if (tablica[j] < tablica[ind]) {
                    ind = j;
                }
            }
            else{
                if (tablica[j] > tablica[ind]) {
                    ind = j;
                }
            }
            j += 1;
        }
        int robocza = tablica[i];
        tablica[i] = tablica[ind];
        tablica[ind] = robocza;
        i-=1;
    }
}
void sortowaniePrzezWstawianie(int *&tablica, int n, int tryb){
    int i=n-2;
    while(i>=0){
        int j=i;
        int temp = tablica[j];
        if(tryb) {
            while (temp < tablica[j + 1] && j < n - 1) {
                tablica[j] = tablica[j + 1];
                j += 1;
            }
        }
        else{
            while (temp > tablica[j + 1] && j < n - 1) {
                tablica[j] = tablica[j + 1];
                j += 1;
            }
        }
        tablica[j]=temp;
        i-=1;
    }
}
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol){
    int x=w-1;
    while(x>0){
        for(int j=0;j<x;j++){
            if(tryb) {
                if (tab[j][nrKol] < tab[j + 1][nrKol]) {
                    int robocza = tab[j][nrKol];
                    tab[j][nrKol] = tab[j + 1][nrKol];
                    tab[j + 1][nrKol] = robocza;
                }
            }
            else{
                if (tab[j][nrKol] > tab[j + 1][nrKol]) {
                    int robocza = tab[j][nrKol];
                    tab[j][nrKol] = tab[j + 1][nrKol];
                    tab[j + 1][nrKol] = robocza;
                }
            }
        }
        x-=1;
    }
}
void przydzielPamiec1D(int *&tab, int n){
    tab=new int[n];
}
void przydzielPamiec2D(int **&tab, int w, int k){
    tab=new int*[w];
    for(int i=0;i<w;i++){
        tab[i]=new int[k];
    }
}
void wypelnijTablice1D(int *tab, int n, int a, int b){
    for(int i=0;i<n;i++){
        tab[i]=rand()%(b-a+1)+a;
    }
}
void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }
}
void wyswietl1D(int* tab, int n){
    for(int i=0;i<n;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void wyswietl2D(int** tab, int w, int k){
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}
void usunTablice1D(int *&tab){
    delete []tab;
}
void usunTablice2D(int **&tab, int w){
    for(int i=0;i<w;i++){
        delete [] tab[i];
    }
    delete []tab;
}
