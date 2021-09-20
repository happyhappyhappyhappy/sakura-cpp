#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class XXX> inline bool changemax(XXX& x,XXX y){
    bool result=false;
    if(x < y){
        x = y;
        result = true;
    }
    return result;
}


// Global 変数(固定)
const ll MAX_DATE=100010;
const ll PATTARN = 3;
// DP絡み変数
int DP[MAX_DATE][PATTARN];
// 本人の幸福度変数
int HAPPY[MAX_DATE][PATTARN];
// 本体。_mainは実際の算術関数
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // 各テーブル初期化
    for(int j=0;j<MAX_DATE;j++){
        for(int k=0;k<PATTARN;k++){
            DP[j][k] = 0;
            HAPPY[j][k] = 0;
        }
    }
}

int main(void)
{
    initial();
    int N;
    cin >> N;
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<PATTARN;k++)
        {
            cin >> HAPPY[j][k];
        }
    }
    for(int taro_date=1;taro_date<N;taro_date=taro_date+1){
        for (int move1 = 0; move1 < PATTARN; move1=move1+1){ 
            // 何を前日したか
            for(int move2 = 0; move2 < PATTARN;move2=move2+1){
            // 今日は何をするか
                if(move1!=move2) {
                    // 同じ事はしない  
                    changemax(DP[taro_date+1][move2]
                    ,DP[taro_date][move1]+HAPPY[taro_date][move2]);  
                }
            }
        }
    }
    int result = 0;
 //   result = max(DP[N][0],max(DP[N][1],DP[N][2]));
    cout << "-----\n"; 
    for(int j=0;j < 3;j++){
        cout << j << " : " << DP[N][j] << "\n";
        changemax(result,DP[N][j]);
    }
    cout << result << "\n";
    return 0;
}
