#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>> ;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

// グローバル変数
int N,Q;
Graph G;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(){
    debug("Gの今回の情報です\n");
    for(int j=0;j<G.size();j=j+1){
        debug("%d : ",j);
        for(int k=0;k<G[j].size();k=k+1){
            debug(" %d",G[j][k]);
        }
        debug("\n");
    }
}
void showRES(vector<ll> &X){
    debug("現在のRESの内容です\n");
    for(int j=0;j<X.size();j=j+1){
        debug(" %lld",X[j]);
    }
    debug("\n");
}

void solver(int now,int sended,vector<ll> &res){

}

int main(void){
    initial();
    cin >> N >> Q;
    G.assign(N,vector<int>());
    for(int j=0;j<N-1;j=j+1){
        int a,b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    showG();
    vector<ll> RES(Q);
    for(int j=0;j<Q;j=j+1){
        int a,b;
        cin >> a >> b;
        a = a-1;
        RES[a] = RES[a]+b;
    }
    showRES(RES);
    solver(0,-1,RES);
    return 0;
}

