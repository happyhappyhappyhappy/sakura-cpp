#include<iostream>
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a,T b){
    if(a < b){
        cout << "Change: a = " << a << " -> b = " << b << "\n"; 
        a=b;
        return true;
    }
    return false;
}

ll N;
ll W;
ll weight[110];
ll value[110];

ll DP[110][100100];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    for(ll j=0;j < 110;j=j+1){
        for(ll k=0;k < 100100;k=k+1){
            DP[j][k]=0;
        }
    }
    cin >> N >> W;
    for(ll j=0;j < N;j=j+1){
        cin >> weight[j] >> value[j];
    }
    for(ll j=0;j < N; j=j+1){
        for(ll sum_w=0;sum_w <= W; sum_w = sum_w + 1)
        // 
        // sum_wの値をループの順に出力してみる。                               ~~~~~~~~~~~このインクリメントは有り？
        {
            cout << "Now SUM_W LOOP : " << sum_w << "\n";
            if(sum_w - weight[j] >= 0 ){
                // まだまだ荷物に余裕があった為
                chmax(DP[j+1][sum_w],DP[j][sum_w-weight[j]]+value[j]);
            }
            chmax(DP[j+1][sum_w],DP[j][sum_w]);
        }
    }
    cout << DP[N][W] << "\n";
    // 出力する
    for(ll j=0 ; j <= N;j++){
        for(ll k=0; k <= W ; k++){
            cout << DP[j][k] << " ";
        }
        cout << "\n";
    }
    return 0;
}
