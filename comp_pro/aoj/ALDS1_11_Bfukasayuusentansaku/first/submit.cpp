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

// TODO: P.280 L.22


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();

    return 0;
}
