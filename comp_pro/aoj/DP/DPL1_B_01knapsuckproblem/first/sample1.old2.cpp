#include<iostream>
using namespace std;
template<class T>
 bool chmax(T& a,T b)
 {
    if(a<b)
    {
        a=b;
        return true;
    }
    return false;
}
template<class T>bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }
    false;
}
int N;
int W,weight[110],value[110];
int dp[110][100100]={0};

int main(void){
    cin >> N >> W;
    for(int j=0;j<N;++j){
        cin >> value[j] >> weight[j];
    }
    for(int j=0;j<N;++j){
        for(int sum_w=0;sum_w<W;++sum_w){
            if(sum_w-weight[j]>0){
                chmax(dp[j+1][sum_w],dp[j][sum_w-weight[j]]+value[j]);
            }
            else{
                chmax(dp[j+1][sum_w],dp[j][sum_w]);
            }
        }
    }
    cout << dp[N][W] << "\n" << flush;
}
