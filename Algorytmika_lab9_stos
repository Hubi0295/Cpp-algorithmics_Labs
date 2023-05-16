#include <iostream>
#include "random"
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
struct stos{
    int number;
    stos *next;
};
struct stoss{
    char znak;
    stoss *next;
};
void is_emptyy(stos *stack);
void topp(stoss *stack, ofstream *file);
void popp(stoss *&stack);
void push(stos *&stack);
void pop(stos *&stack);
void top(stos *stack);
void zdjemijwszystko(stos *&stack);
void pushh(stoss *&stack, string linijka);
int main() {
    stos *nowy_element=nullptr;
    int wybor;

    while(wybor!=6) {
        cout<<endl;
        cout << "1) sprawdzenie czy stos jest pusty\n"
                "2) dodanie elementu na stos, liczbe\n"
                "3) usuniecie elementu ze stosu\n"
                "4) pobranie elementu ze stosu\n"
                "5) usuniecie wszystkich elementow ze stosu\n"
                "6) wyjscie z programu." << endl;
        cin>>wybor;
        switch (wybor) {
            case 1:is_emptyy(nowy_element); break;
            case 2:push(nowy_element); break;
            case 3:pop(nowy_element); break;
            case 4:top(nowy_element); break;
            case 5:zdjemijwszystko(nowy_element); break;
            default:break;
        }
    }
    string sciezka,linia,pomoc;
    int liczbalinijek;
    fstream plik;
    plik.open("znaki1.txt");
    string linijka;
    ofstream wynikk("wynik.txt");
    ofstream *wsk = &wynikk;
    stoss *wers=nullptr;
    while(!plik.eof()) {
        getline(plik, linijka);
        linijka += "\n";
        pushh(wers,linijka);
    }
    while(wers!=nullptr){
        topp(wers, wsk);
        popp(wers);
    }
    plik.close();
    return 0;
}
void is_emptyy(stos *stack){
    if(stack!=nullptr){
        cout<<"Na stosie cos jest"<<endl;
    }
    else{
        cout<<"Brak elementow w stosie"<<endl;
    }
}
void pushh(stoss *&stackk, string linijka){
    stoss *element = new stoss;
    char znak;
    int licznik=0;
    char tab[linijka.length()];
    for(int i=0;i<linijka.length();i++){
        tab[i]=linijka[i];
    }
    for(int i=0;i<linijka.length();i++){
        stoss *element = new stoss;
        element->znak=tab[i];
        element->next=stackk;
        stackk=element;
    }
}
void popp(stoss *&stack){
    if(stack!=nullptr){
        stoss *temp=stack;
        stack=stack->next;
        delete temp;
    }
    else{
        cout<<"Brak elementow na stosie"<<endl;
    }
}
void push(stos *&stack){
    stos *element = new stos;
    element->number=rand()%10;
    element->next=stack;
    stack=element;
}
void pop(stos *&stack){
    if(stack!=nullptr){
        stos *temp=stack;
        stack=stack->next;
        delete temp;
    }
    else{
        cout<<"Brak elementow na stosie"<<endl;
    }
}
void zdjemijwszystko(stos *&stack){
    while(true){
        if(stack==nullptr){
            cout<<"Juz brak elementow na stosie"<<endl;
            break;
        }
        stos *temp=stack;
        stack=stack->next;
        delete temp;
    }
}
void topp(stoss *stack, ofstream *file){
    if(*&stack!=nullptr){
        cout<<stack->znak;
        *file<<stack->znak;
    }
    else{
        cout<<"Brak elementow w stosie"<<endl;
    }
}
void top(stos *stack){
    if(*&stack!=nullptr){
        cout<<stack->number;

    }
    else{
        cout<<"Brak elementow w stosie"<<endl;
    }
}
