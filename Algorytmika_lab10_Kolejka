#include <iostream>
#include <fstream>
using namespace std;
struct element{
    char character;
    element* next;
};
struct queue{
    element *head;
    element *tail;
};
void push(queue &q, char value);
int pop(queue &q);
bool isEmpty(queue &q);
void first(queue &q);
void deleteall(queue &q);
    int main() {
    queue q;
    char znak;
    q.head= nullptr;
    q.tail= nullptr;
    int wybor=0;
    fstream plik;
    string linijka;
    string nazwa;
    while(wybor!=7){
        cout<<"Podaj wybor"<<endl;
        cin>>wybor;
        switch(wybor){
            case 1:
            if(isEmpty(q)){
                cout<<"Kolejka pusta"<<endl;
            }
            else{
                cout<<"Kolejka nie pusta"<<endl;
            }
            break;
            case 2:cout<<"Podaj znak";cin>>znak;push(q,znak);break;
            case 3:pop(q);break;
            case 4:first(q);break;
            case 5:deleteall(q);break;
            case 6:
                cout<<"Podaj nazwe pliku"<<endl;
                cin>>nazwa;
                plik.open(nazwa);
                while(!plik.eof()){
                    getline(plik,linijka);
                    for(int i=0;i<linijka.length();i++){
                        if(int(linijka[i])>=65 && int(linijka[i]<=90)){
                            push(q,linijka[i]);
                        }
                    }
                }
                break;
            case 7:break;
            default:cout<<"Zle dane"<<endl;break;
        }
    }
    return 0;
}
void push(queue &q, char value){
    element *el=new element;
    el->character=value;
    el->next= nullptr;
    if(q.tail!=nullptr){
        q.tail->next=el;
    }
    else{
        q.head=el;
    }
    cout<<el->character;
    q.tail=el;
}
int pop(queue &q){
    if(q.head==nullptr){
        cout<<"brak elementow"<<endl;
        return 0;
    }
    element *temp=q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head== nullptr){
        q.tail=nullptr;
    }

}
bool isEmpty(queue &q){
    if(q.head==nullptr){
        return true;
    }
    else{
        return false;
    }
}
void first(queue &q){
        if(q.tail== nullptr){
            cout<<"koniec"<<endl;
        }
    cout<< q.head->character;
}
void deleteall(queue &q){
        while(q.head!= nullptr){
            element *temp=q.head;
            q.head=q.head->next;
            delete temp;
            if(q.head== nullptr){
                q.tail= nullptr;
            }
        }
}
