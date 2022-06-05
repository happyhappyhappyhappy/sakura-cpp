#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
// using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

struct Node {
    int key;
    Node *p_right,*p_left,*p_parent;
};

Node *p_root,*p_NIL;

void insert(int k){
    Node* p_y = p_NIL;
    Node* p_x = p_root;
    Node* p_z;
    p_z = (Node*)malloc(sizeof(Node));
    p_z->key = k;
    p_z->p_left = p_NIL;
    p_z->p_right = p_NIL;

    while(p_x != p_NIL){
        p_y = p_x;
        if(p_z->key < p_x->key){
            p_x = p_x->p_left;
        }
        else{
            p_x = p_x->p_right;
        }
    }
    p_z->p_parent =p_y;
    if(p_y == p_NIL){
        p_root = p_z;
    }
    else{ 
        if(p_z->key < p_y->key){
            p_y->p_left = p_z;
        }
        else{
            p_y->p_right =  p_z;
        }
    }
}

void inorder(Node* p_u){
    if(p_u == p_NIL){
        return;
    }
    inorder(p_u->p_left);
    printf(" %d",p_u->key);
    inorder(p_u->p_right);
}
void preorder(Node* p_u){
    if(p_u == p_NIL){
        return;
    }
    printf(" %d",p_u->key);
    preorder(p_u->p_left);
    preorder(p_u->p_right);
}
/**
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
**/
int main(void){
//    initial();
    int n,i,x;
    char com[20];
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        scanf("%s",com);
//        cout << "[" << com << "]" << "\n" << flush;
        if(com[0] == 'i'){
            scanf("%d",&x);
            insert(x);
        }
        else{
            if(com[0] == 'p'){
                inorder(p_root);
                printf("\n");
                preorder(p_root);
                printf("\n");
            }
        }
    }
    return 0;
}
