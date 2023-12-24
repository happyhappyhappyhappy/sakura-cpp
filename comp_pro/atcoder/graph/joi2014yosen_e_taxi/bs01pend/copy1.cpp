#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_N 5500
bool x[MAX_N][MAX_N];
int y[MAX_N][2];
bool z[MAX_N];
int m[MAX_N];
int s[MAX_N];
int t[MAX_N][MAX_N];

queue<int> Q;
int main(void){
    memset(x,false,sizeof(x));
    for(int j1=0;j1<5500;j1=j1+1){
        for(int j=0;j<5500;j=j+1){
            m[j1]=1000000000;
            s[j1]=0;
            t[j1][j]=0;
        }
    }
    int N,K,a,b;
    cin >> N >> K;
    for(int j=1;j<=K;j=j+1){
        cin >> a >> b;
        x[a][b]=true;
        x[b][a]=true;
        t[a][s[a]]=b;
        t[b][s[b]]=a;
        s[a]=s[a]+1;
        s[b]=s[b]+1;
    }
    int p;
    int r;
    int u;
    u = N;
    if(6000 < K){
        u=20;
    }
    m[1]=0;
    for(int j1=0;j1<u;j1=j1+1){
        for(int j=1;j<=N;j=j+1){
            if(m[j]<100000000){
                while(Q.empty()==false){
                    Q.pop();
                }
                Q.push(j);
                memset(z,false,sizeof(z));
                for(int k=0;k<y[j][1];k=k+1){
                    r=Q.size();
                    for(int l=0;l<r;l=l+1){
                        p = Q.front();
                        for(int o=0;)
                    }
                }
            }
        }
    }
}
