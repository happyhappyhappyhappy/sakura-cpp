#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

struct Node {
    int key;
    Node* p_right,p_left,p_parent;
};

Node* p_root,p_NIL;

void insert(int k){
    Node* p_y = p_NIL;
    Node* p_x = p_root;
    Node* p_z;
    p_z = (Node*)malloc(sizeof(Node));
    p_z->key = k;
    p_z->pleft = p_NIL;
    p_z->pright = p_NIL;

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
    if(py == pNIL){
        proot = pz;
    }
    else{ // FIXME: P.213 で かつポインタ変数は先頭にpを付けています
    // NEXTGO: ポインタ変数のpはp_と付けてください。訳分からなくなります。
        if(pz->key < py->key){
            y->left = z;
        }
        else{
            y->right =  z;
        }
    }
}

void inorder(Node* u){

}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();

    return 0;
}
