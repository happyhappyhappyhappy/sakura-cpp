#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 大域変数
static int MAX_COUNT=20;
ll dp[100+10][20+2];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int ii=0;ii<100+10;ii++){
        for(int j=0;j<20+2;j++){
            dp[ii][j]=0LL;
        }
    }
}

int main(void){
    initial();
    int N;
    cin >> N;
    int value[N];
    for(auto& e:value){
        cin >> e;
    }
    dp[0][value[0]]=1LL;
    for(int ii=0;ii<N-2;i++){
        if()
    }
    for(int ii=0;ii<N;ii++){
        cout << value[ii] << " ";
    }
    cout << "\n" << flush;
    return 0;
}
