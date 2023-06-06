#include <iostream>
using namespace std;
struct node{
    int key;
    node *parent;
    node *left;
    node *right;
};

node *make_node(int value);
void add_node(int value, node *&root);
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);
node *findnode(node *root,int value);
node *findsuccessor(node *n);
void deletenode(node *&root, node *delete_node);
bool isemptyy(node *root);
void deleteall(node *n);
int main() {
    node *root= nullptr;
    bool flaga= true;
    cout<<"Witam w menu, mozesz: "<<endl;
    cout<<"Sprawdzic czy drzewo jest puste - 1"<<endl;
    cout<<"Dodac wezel do drzewa - 2"<<endl;
    cout<<"Sprawdzic czy klucz znajduje sie w drzewie - 3"<<endl;
    cout<<"Wyswietlic drzewo preorder - 4"<<endl;
    cout<<"Wyswietlic drzewo inorder - 5"<<endl;
    cout<<"Wyswietlic drzewo postorder - 6"<<endl;
    cout<<"Usuniecie klucza - 7"<<endl;
    cout<<"Usuniecie drzewa - 8"<<endl;
    cout<<"Wyjscie z programu - 9"<<endl;
    int wybor;
    int klucz;
    while(flaga){
        cout<<"Twoj wybor: ";
        cin>>wybor;
        switch (wybor) {
            case 1:if(isemptyy(root)){
                cout<<"Pusto"<<endl;
                }
                else{
                    cout<<"Nie pusto"<<endl;
                }
                break;
            case 2:
                cout<<"dodaj unikalny klucz: "<<endl;
                cin>>klucz;
                if(root== nullptr){
                    root=make_node(klucz);
                    cout<<"Drzewo po dodaniu: "<<endl;
                    inorder(root);
                    break;
                }
                cout<<"Drzewo przed dodaniem: "<<endl;
                inorder(root);
                if(findnode(root,klucz)){
                    cout<<"nie mozesz dodac klucza, on juz jest"<<endl;
                }
                else{
                    add_node(klucz,root);
                }
                cout<<"Drzewo po dodaniu: "<<endl;
                inorder(root);
                break;
            case 3:
                cout<<"Podaj klucz: ";
                cin>>klucz;
                if(findnode(root,klucz)){
                    cout<<"Klucz znaleziono!"<<endl;
                }
                else{
                    cout<<"Klucza nie ma w drzewie"<<endl;
                }
                break;
            case 4:
                preorder(root);break;
            case 5:
                inorder(root);break;
            case 6:
                postorder(root);break;
            case 7:
                cout<<"Drzewo przed akcją: "<<endl;
                inorder(root);
                cout<<"Podaj klucz do usuniecia";
                cin>>klucz;
                if(findnode(root,klucz)){
                    deletenode(root, findnode(root,klucz));
                }
                else{
                    cout<<"Niestety nie znalziono klucza w drzewie"<<endl;
                }
                cout<<"Drzewo po akcji: "<<endl;
                inorder(root);
                break;
            case 8:
                deleteall(root);root= nullptr;break;
            case 9:flaga=false;break;
        }
    }
    return 0;
}


bool isemptyy(node *root){
    if(root== nullptr){
        return true;
    }
    return false;
}
node *make_node(int value){
    node *n = new node;
    n->key=value;
    n->left= nullptr;
    n->right= nullptr;
    n->parent=nullptr;
    return n;
}
void add_node(int value, node *&root){
    if(root==nullptr){
        root = make_node(value);
        return;
    }
    node *temp=root;
    while(true){
        if(value>=temp->key){
            if(temp->right== nullptr){
                temp->right= make_node(value);
                temp->right->parent=temp;
                return;
            }
            temp=temp->right;
        }
        else{
            if(temp->left==nullptr){
                temp->left= make_node(value);
                temp->left->parent=temp;
                return;
            }
            else{
                temp=temp->left;
            }
        }
    }
}
void preorder(node *root){
    if(root!=nullptr){
        cout<<root->key<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root){
    if(root!= nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<endl;
    }
}
void inorder(node *root){
    if(root!= nullptr){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
node *findnode(node *root,int value){
    while(root!= nullptr){
        if(root->key==value){
            return root;
        }
        if(value>root->key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return nullptr;
}
node *findsuccessor(node *n){
    if(n->right!= nullptr){
        n=n->right;
        while(n->left!= nullptr){
            n=n->left;
        }
        return n;
    }
    node *temp = n->parent;
    while(temp!= nullptr && temp->left!=n){
        n=temp;
        temp=temp->parent;
    }
    return temp;
}
void deletenode(node *&root, node *delete_node){
    node *temp1, *temp2;
    if(delete_node->left== nullptr||delete_node->right== nullptr){
        temp1 = delete_node;
    }
    else{
        temp1 = findsuccessor(delete_node);
    }
    if(temp1->left!= nullptr){
        temp2 = temp1->left;
    }
    else{
        temp2=temp1->right;
    }
    if(temp2!= nullptr){
        temp2->parent=temp1->parent;
    }
    if(temp1->parent== nullptr){
        root=temp2;
    }
    else{
        if(temp1==temp1->parent->left){
            temp1->parent->left=temp2;
        }
        else{
            temp1->parent->right=temp2;
        }
    }
    if(temp1!=delete_node){
        delete_node->key=temp1->key;
    }
    delete temp1;
}
void deleteall(node *node){
    if (node == NULL) return;
    deleteall(node->left);
    deleteall(node->right);
    cout << "\n Deleting node: " << node->key;
    delete node;
}
