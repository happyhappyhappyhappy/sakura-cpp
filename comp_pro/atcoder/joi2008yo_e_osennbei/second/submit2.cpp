#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#endif
using namespace std;
using ll=long long;
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void show(int R,int C,vector<vector<int>> &G){
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}
int moving(int R,int C,int bit,vector<vector<int>> G){
    debug1("bit = %d\n",bit);
    int nowsum=0;
    vector<int> chline;
    for(int j=0;j<R;j=j+1){
        int nowpos = bit>>j;
        if((nowpos & 1) == 1){
            chline.push_back(j);
        }
    }
    // debug1("bit = %d の時の chain\n",bit);
    // if((int)chline.size()==0){
    //     debug1("無し");
    // }
    // for(int j=0;j<(int)chline.size();j=j+1){
    //     debug1(" %d",chline[j]);
    // }
    // debug1("\n");
    // 行を反転
    debug1("行 反転前\n");
    show(R,C,G);
    for(int j=0;j<(int)chline.size();j=j+1){
        int line = chline[j];
        for(int k=0;k<C;k=k+1){
            G[line][k] = (G[line][k]+1)%2;
        }
    }
    debug1("行 反転後\n");
    show(R,C,G);
    // TODO: 列を見ていって多い物の個数を足す(一応基準は1 figure1)
    return nowsum;
}

int main(void){
    initial();
    int R,C;
    cin >> R >> C;
    vector<vector<int>> M(R,vector<int>(C,0));
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            cin >> M[j][k];
        }
    }
    int result=0;
    for(int bit=0;bit<(1<<R);bit=bit+1){
        int nowsum;
        nowsum=moving(R,C,bit,M);
        chmax(result,nowsum);
    }
    cout << result << "\n" << flush;
    // for(int j=0;j<R;j=j+1){
    //     for(int k=0;k<C;k=k+1){
    //         debug1(" %d",M[j][k]);
    //     }
    //     debug1("\n");
    // }
    return 0;
}

