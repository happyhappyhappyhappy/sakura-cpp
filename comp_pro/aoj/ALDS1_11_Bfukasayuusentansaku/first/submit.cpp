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
    for(int v=nt[u];v<n;v++){
        nt[u] = v + 1;
        if(M[u][v]==1){ // u->vに辺がある
            return v;
        }
    }
    return -1;
}

void dfs_visit(int r){
    for(int j=0;j<n;j=j+1){
        nt[j];
    }
    stack<int> S;
    S.push(r);
    color[r]=GRAY;
    tt=tt+1
    d[r] = tt;
    while(!S.empty()){
        int u = S.top(); // Sの末尾を読む
        int v = next(u);
        if(v != -1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                tt = tt +1;
                d[v] = tt;
                S.push(v);
            }
            else{
                // 白でない→すでにチェック済み
                S.pop();
                color[u] = BLACK;
                tt=tt+1;
                f[u];
            }
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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // TODO: 令和4年12月10日(土)ここまでやった
    // 螺旋本 P.280 L.67
    return 0;
}
