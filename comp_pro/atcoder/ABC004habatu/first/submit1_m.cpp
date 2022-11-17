#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}

typedef pair<int,int> PAIR;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<PAIR> &R,int N,int M){
    int result=0;
    // 関連表
    vector<vector<bool>> RG(N,vector<bool>(N,false));
    // 関連表にセット
    // 個人対個人
    for(int j=0;j<M;j=j+1){
        int x,y;
        x = R[j].first-1;
        y = R[j].second-1;
        RG[x][y]=true;
        RG[y][x]=true;
    }
    // 自分は自分と関連している
    for(int j=0;j<N;j=j+1){
        RG[j][j]=true;
    }
    // ビット全探索
    for(int bit=1;bit<(1<<N);bit=bit+1){
        vector<int> chain;
        for(int pos=0;pos<N;pos=pos+1){
            if((bit & (1<<pos))!=0){
                chain.push_back(pos);
            }
        }
        int intsize = (int)chain.size();
        bool ok=true;
        for(int j=0;j<intsize;j=j+1){
            for(int k=0;k<intsize;k=k+1){
                if(!RG[chain[j]][chain[k]]){
                    ok=false;
                    break;
                }
            }
       }
       if(ok){
        chmax(result,intsize);
       }
    }
    return result;
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<PAIR> R(M);
    for(int j=0;j<M;j=j+1){
        cin >> R[j].first >> R[j].second;
    }
    cout << solver(R,N,M) << "\n" << flush;
    return 0;
}
