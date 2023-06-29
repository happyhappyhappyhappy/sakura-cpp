#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
// 大域変数
int D; // 問題数
ll G; // 目標点

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
string bitCode(int B){
    string res="";
    for(int j=0;j<D;j=j+1){
        if(((B>>j)&1)==1){
            res=res+"1";
        }
        else{
            res=res+"0";
        }
    }
    return res;
}
ll solver(vector<ll> &tc,vector<ll> &tp,vector<ll> &cp){
    ll res=0;
    for(int j=0;j<D;j=j+1){
        res=res+tc[j];
    }
    for(int bit=0;bit<(1<<D);bit=bit+1){
        string bc=bitCode(bit);
        ll sum=0; // 得点合計
        ll count=0; // テスト合計数
        for(int j=0;j<D;j=j+1){
            int j1=j+1;
            int bitFlg=(bit>>j)&1;
            if(bitFlg==1){
                sum=sum+tp[j]*tc[j]+cp[j];
                count=count+tc[j];
            }
        } // 指定問題の解答完了
        if(G <= sum){
            chmin(res,count);
        }
        else{
            for(int j=D-1;0<=j;j=j-1){
                int j1=j+1;
                int bitFlg=(bit>>j)&1;
                if(bitFlg==1){
                    continue;
                }
                else{
                    int prob=int(tc[j]);
                    for(int k=0;k<prob;k=k+1){
                        if(G<=sum){
                            break;
                        }
                        else{
                            int k1=k+1;
                            sum = sum+tp[j];
                            count=count+1;
                        }
                    }
                }
            }
        }
        chmin(res,count);
    }
    return res;
}
int main(void){
    initial();
    cin >> D >> G;
    vector<ll> TC(D);
    vector<ll> CP(D);
    vector<ll> TP(D);
    for(int j=0;j<D;j=j+1){
        TP[j]=100*(j+1);
        cin >> TC[j] >> CP[j];
    }
    cout << solver(TC,TP,CP) << "\n" << flush;
    return 0;
}