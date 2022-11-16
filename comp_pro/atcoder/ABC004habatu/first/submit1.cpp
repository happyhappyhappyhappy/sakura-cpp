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
// 議員間の関係は最大15まで入れ、ここではデフォルトとしてfalseにする
vector<vector<bool>> R(15,vector<bool>(15,false));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}

void nowInfo(int bit,int N){
    for(int j=0;j<N;j=j+1){
        if((bit & (1<<j)!=0)){
            // TODO: bit毎の情報を取り出す
        }
    }
}

int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    for(int j=1;j<=M;j=j+1){
        int x,y;// 知り合いであるx,y
        cin >> x >> y; 
        R[x-1][y-1]=true; 
        R[y-1][x-1]=true;
        R[x-1][x-1]=true; // 自己関連x
        R[y-1][y-1]=true; // 自己関連y
    }
    int ans=-1;
    for(int bit=1;bit<(1<<N);bit=bit+1){
        vector<int> v;
        for(int j=0;j<N;j=j+1){
            if((bit & (1<<j)) != 0){
                v.push_back(j);
            }
        } // つながり候補の人を洗い出す
        bool bj=true;
        for(int x=0;x<v.size();x=x+1){
            for(int y=0;y<v.size();y=y+1){
                if(!R[x][y]){
                    bj=false;
                    break;
                }
                else{
                    debug("%d さんと %d は関係がありました\n",x,y);
                }
            }
        }
        if(bj){
            chmax(ans,int(v.size()));
        }
    }
    cout << ans << "\n" << flush;
    return 0;
}
