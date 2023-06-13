#include <iostream>
#include "random"
using namespace std;
struct element{
    int number;
    element *next;
};
struct single_list{
    element *head;
    element *tail;
    int counter;
};
void add_tail(single_list &l, int value);
void add_head(single_list &l, int value);
void add_position(single_list &l, int value, int position);
void delete_tail(single_list &l);
void delete_head(single_list &l);
bool is_emptyy(single_list &l);
void delete_position(single_list &l, int position);
void pokazsrednia(single_list &l);
void makselement(single_list &l);
void show(single_list l);
void show_first(single_list &l);
void show_last(single_list &l);
void delete_all(single_list &l);
int main() {
    single_list l;
    l.head= nullptr;
    l.tail= nullptr;
    l.counter=0;
    int wybor;
    int pozycja;
    cout<<"podaj co chcesz zrobic:"<<endl
        <<" 1-Sprawdz czy lista jest pusta "<<endl
        <<" 2-dodanie elementu na koniec listy "<<endl
        <<" 3-dodanie elementu na poczatek listy "<<endl
        <<" 4-dodanie elementu na okreslona pozycje "<<endl
        <<" 5-usuniecie elementu z konca listy "<<endl
        <<" 6-usuniecie elementu z poczatku listy "<<endl
        <<" 7-usuniecie elementu znajdujacego sie na okreslonej pozycji , "<<endl
        <<" 8-pobranie pierwszego elementu z listy "<<endl
        <<" 9-pobranie pierwszego elementu z listy "<<endl
        <<" 10-wyswietlenie ostatniego element, ktory znajduje sie w liscie "<<endl
        <<" 11-policzenie sredniej arytmetycznej elementow w liscie "<<endl
        <<" 12-znalezienie elementu maksymalnego w liscie "<<endl
        <<" 13-wyswietlenie calej listy "<<endl
        <<" 14-usuniecie calej listy wraz ze zwolnieniem pamieci "<<endl
        <<" 15-wyjscie z programu "<<endl;
    cout<<"podaj co chcesz zrobic: ";
    cin>>wybor;
    while(wybor!=15) {
        switch (wybor) {
            case 1:
                if (is_emptyy(l)) {
                    cout << "Jest Pusta" << endl;
                } else {
                    cout << "Nie jest pusta" << endl;
                }
                break;
            case 2:
                add_tail(l, rand() % 50);
                break;
            case 3:
                add_head(l, rand() % 50);
                break;
            case 4:
                cout<<"podaj pozycja: ";
                cin>>pozycja;
                add_position(l, rand() % 50, pozycja);
                break;
            case 5:
                delete_tail(l);
                break;
            case 6:
                delete_head(l);
                break;
            case 7:
                cout<<"podaj pozycja: ";
                cin>>pozycja;
                delete_position(l, pozycja);
                break;
            case 8:
                show_first(l);
                break;
            case 9:
                show_last(l);
                break;
            case 10:
                show_last(l);
                break;
            case 11:
                pokazsrednia(l);
                break;
            case 12:
                makselement(l);
                break;
            case 13:
                show(l);
                break;
            case 14:
                delete_all(l);
                break;
            default:
                break;
        }
            cout<<"podaj co chcesz zrobic: ";
            cin>>wybor;
    }
    return 0;
}
void delete_all(single_list &l){
    l.tail= nullptr;
    l.head= nullptr;
}
void show_first(single_list &l){
    cout<<l.head->number<<endl;
}
void show_last(single_list &l){
    cout<<l.tail->number<<endl;
}
void makselement(single_list &l){
    int i=1;
    element *temp=l.head;
    int max=temp->number;
    int pozycja=1;
    while(i<=l.counter){
        if(temp->number>max){
            max=temp->number;
            pozycja=i;
        }
        temp=temp->next;
        i++;
    }
    cout<<"Max: "<<max<<" pozycja: "<<pozycja<<endl;
}
void pokazsrednia(single_list &l){
    int i=1;
    int suma=0;
    element *temp=l.head;
    while(i<=l.counter){
        suma+=temp->number;
        temp=temp->next;
        i++;
    }
    cout<<"Srednia: "<<suma/l.counter<<endl;
}
bool is_emptyy(single_list &l){
    if(l.head== nullptr && l.tail== nullptr){
        return true;
    }
    else{
        return false;
    }
}
void add_tail(single_list &l, int value) {
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    if (l.tail != nullptr) {
        l.tail->next=el;
    }
    else {
        l.head = el;
    }
    l.tail=el;
    l.counter++;
}


void add_head(single_list &l, int value){
    element *el = new element;
    el->number=value;
    el->next= l.head;
    l.head=el;
    if(l.tail == nullptr){
        l.tail=el;
    }
    l.counter++;
}
void add_position(single_list &l, int value, int position){
    element *el = new element;
    el->number=value;
    element *temp = l.head;
    int i=1;
    while(i<position-1) {
        temp=temp->next;
        i++;
    }
    l.counter++;
    el->next=temp->next;
    temp->next=el;
}
void delete_tail(single_list &l){
    element *temp = l.tail;
    if(l.counter==1){
        l.tail= nullptr;
        l.head= nullptr;
    }
    else{
        element *bef_temp=l.head;
        int i=1;
        while(i<l.counter-1){
            bef_temp=bef_temp->next;
            i++;
        }
        l.tail=bef_temp;
        l.tail->next= nullptr;
    }
    l.counter-=1;
    delete temp;
}
void delete_head(single_list &l){
    element *temp = l.head;
    l.head=l.head->next;
    if(l.counter==1){
        l.tail= nullptr;
    }
    l.counter-=1;
    delete temp;
}
void delete_position(single_list &l, int position){
    element *prev = l.head;
    int i=1;
    while(i<position-1){
        prev=prev->next;
        i++;
    }
    l.counter-=1;
    element *temp = prev->next;
    prev->next=temp->next;
    delete temp;
}
void show(single_list l){
    int i=1;
    element *temp=l.head;
    while(i<=l.counter){
        cout<<temp->number<<endl;
        temp=temp->next;
        i++;
    }
}
