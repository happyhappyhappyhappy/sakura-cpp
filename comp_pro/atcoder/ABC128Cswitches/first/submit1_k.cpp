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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // 宣言～データ入力箇所
    int N,M; // N:switch M:lamp
    cin >> N >> M;
    vector<vector<int>> SW(M,vector<int>(0)); // 各電球が影響するスイッチ
    vector<int> SW_CNT(M); // 電球ごと必要なスイッチの個数;
    vector<int> NUM(M); // 奇数個か偶数個か示す数
    for(int j=0;j<M;j++){
        cin >> SW_CNT[j];
        SW[M].resize(SW_CNT[j]);
        for(int k=0;k<SW_CNT[j];k=k+1){
            int tmp;
            cin >> tmp;
            SW[M][k]=tmp-1; // 0-indexにしたい
        }
    }
    for(int j=0;j<M;j++){
        cin >> NUM[j];
    }
    // SW_CNTが正しく入っているか確認
    for(int j=0;j<M;j=j+1){
        for(int k=0;k<)
    }
    return 0;
}
