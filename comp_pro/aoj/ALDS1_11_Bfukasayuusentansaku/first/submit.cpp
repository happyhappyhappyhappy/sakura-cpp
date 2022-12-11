#include<bits/stdc++.h>
#include<stack>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,M[N][N];
int color[N],d[N],f[N], tt;
int nt[N];

int next(int u){
    // ("頂点 %d の値を求めに来ました\n",u);
    for(int v=nt[u];v<n;v++){
        nt[u] = v + 1;
        if(M[u][v]==1){
        //    debug("%d が次の頂点です\n",v);
            return v;
        }
    }
    // debug("次の頂点がありませんでした\n");
    return -1;
}

void dfs_visit(int r){
    // debug("頂点 j = %dの中に入りました\n",r);
    for(int j=0;j<n;j=j+1){
        nt[j]=0;
    }
    stack<int> S;
    S.push(r);
    color[r]=GRAY;
    // tt=tt+1;
    tt=tt+1;
    d[r] = tt;
    while(!S.empty()){
        int u = S.top(); // Sの末尾を読む
        int v = next(u);
        if(v!=-1){
            if(color[v]==WHITE){
                color[v]=GRAY;
                tt=tt+1;
                d[v]=tt;
                S.push(v);
            }// if(color[v]==WHITE)
        }
        else
        { // if(v!=-1)
            S.pop();
            color[u]=BLACK;
            tt=tt+1;
            f[u]=tt;
            }
    }
}


void dfs(){
    for(int j=0;j<n;j=j+1){
        color[j] = WHITE;
        nt[j]=0;
    }
    tt = 0;
    for(int u = 0;u<n;u=u+1){
        if(color[u] == WHITE){
            dfs_visit(u);
        }
    }
    for(int j=0;j<n;j=j+1){
        cout << j+1 << " " << d[j] << " " << f[j] << "\n" << flush;
    }
}


int main(void){
    int u,k,v;
    cin >> n;
    //
    for(int j=0;j<n;j=j+1){
        for(int k=0;k<n;k=k+1){
            // グラフの初期化
            M[j][k]=0;
        }
    }
    for(int j=0;j<n;j=j+1){
        cin >> u >> k;
        u=u-1;
        for(int m=0;m<k;m=m+1){
            cin >> v;
            v=v-1;
            M[u][v]=1;
        }
    }
    dfs();
    return 0;
}
