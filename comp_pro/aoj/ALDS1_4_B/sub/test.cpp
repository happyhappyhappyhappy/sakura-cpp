#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

struct Node {
    int key;
    Node* pright,pleft,pparent;
};

Node* proot,pNIL;

void insert(int k){
    Node* py = pNIL;
    Node* px = proot;
    Node* pz;
    pz = (Node*)malloc(sizeof(Node));
    pz->key = k;
    pz->pleft = pNIL;
    pz->pright = pNIL;

    while(px != pNIL){
        py = px;
        if(pz->key < px->key){
            px = px->pleft;
        }
        else{
            px = px->pright;
        }
    }
    pz->pparent =py;
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
