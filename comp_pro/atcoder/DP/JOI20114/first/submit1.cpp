#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 大域変数
static int MAXN=100;
static int VMAX=20; // 20220106 この数までJOI君は計算できるものとする
static int VMIN=0;

ll DP[110][25];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dpclear(void){
    for(int ii=0;ii<110;ii++){
        for(int j=0;j<25;j++){
            DP[ii][j]=0LL;
        }
    }
}

ll solve(){
    dpclear();
    int number;
    cin >> number;
    ll value[number];
    for(auto& e:value){
        cin >> e;
    }
    for(int ii=0;ii<number;ii++){
        cout << value[ii] << " ";
    }
    cout << "\n" << flush;
    ll result=0LL;

    return result;
}

int main(void){
    initial();
    int testcase=1;
    //CodeForceの時はここのコメントを削除 cin >> testcase;
    for(int ii=0;ii<testcase;ii++){
        cout << solve() << "\n" << flush;
    }  
    return 0;
}
