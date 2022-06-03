#include<bits/stdc++.h>
using namespace std;
// using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

struct Node{
    int key;
    Node *p_left,*p_right,*p_parent;
};

Node *p_root=nullptr;
Node *p_NIL=nullptr;

void insert(int x){
    Node *p_y=p_NIL;
    Node *p_x=p_root;
    Node *p_z=(Node*)malloc(sizeof(Node));
    p_z->key = x;
    p_z->p_left= p_NIL;
    p_z->p_right=p_NIL;
    while(p_x!=p_NIL){
        p_y=p_x;
        if(p_z->key < p_x->key){
            p_x=p_x->p_left;
        }
        else{
            p_x=p_x->p_right;
        }
    }
    p_z->p_parent=p_y;
    if(p_y==p_NIL){
        p_root = p_z;
    }
    else{
        if(p_z->key < p_y->key){
            p_y->p_left=p_z;
        }
        else{
            p_y->p_right=p_z;
        }
    }
}

Node* find(Node *p_u,int k){
    while(p_u != p_NIL && k!=p_u->key){
        if(k < p_u->key){
            p_u=p_u->p_left;
            }
            else{
                p_u = p_u->p_right;
            }
        
    }
    return p_u;
}
// 木の出力1
void inorder(Node *p_u){
    if(p_u == p_NIL){
        return;
    }
    inorder(p_u->p_left);
    cout << " " << p_u->key;
    inorder(p_u->p_right);
}

void preorder(Node *p_u){
    if(p_u==p_NIL){
        return;
    }
    cout << " " << p_u->key;
    preorder(p_u->p_left);
    preorder(p_u->p_right);
}

int main(void)
{
//    initial();
    int n,i;
    string com;
    scanf("%d",&n);
    for(int j=0;j<n;j=j+1){
        cin >> com;
        if(com == "print")
        {
            inorder(p_root);
            cout << "\n" << flush;
            preorder(p_root);
            cout << "\n" << flush;
            continue;
        }
        int x;
        cin >> x;
        if(com == "insert"){
            insert(x);
        }
        if(com == "find"){
            Node *t;
            t = find(p_root,x);
            if(t != p_NIL){
                cout << "yes\n" << flush;
            }
            else{
                cout << "no\n" << flush;
            }
        }
    }
return 0;
}