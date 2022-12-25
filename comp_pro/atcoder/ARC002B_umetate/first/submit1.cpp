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

static const int LEN=10;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // 島の地図G
    vector<vector<char>> G(LEN,vector<char>(LEN));
    // 現在の島の位置
    // 地図を取り込む
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            cin >> G[j][k];
        }
    }

    return 0;
}


