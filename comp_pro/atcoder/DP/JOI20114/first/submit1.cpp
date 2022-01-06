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
    DP[0][value[0]]=1;
    if(value[0]+value[1] <= 20){
        DP[1][value[0]+value[1]]=1LL;
    }
    if(value[0]-value[1]>=0){
        DP[1][value[0]-value[1]]=1LL;
    }
    for(int ii=2;ii<number-2;ii++){
        for(int j=2;j<25;j++){
            // if(j-)
        }
    }
    /**
    for(int ii=0;ii<number;ii++){
        cout << value[ii] << " ";
    }**/

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
