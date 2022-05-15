#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

struct Node {
    int key;
    Node* right,left,parent;
};

Node* root,NIL;

void insert(int k){
    Node* y = NIL;
    Node* x = root;
    Node* z;
    z = (Node*)malloc(sizeof(Node));
    z->key = k;
    z->
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
