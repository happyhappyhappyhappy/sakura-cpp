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

// デバッグ用スイッチパターンチェック
void d_switch_pattern(int allsw,int bit){
    debug("=====\n スイッチパターン %dの時\n=====\n",bit);
    for(int j=0;j < allsw;j=j+1){
        debug("スイッチ[%d] :",j);
        if((bit & (1<<j))!=0){
            debug("ON\n");
        }
        else{
            debug("OFF\n");
        }
    }
}
int light_cnt(int &bit,int &switches,int &lamps,vector<int> &relative,
vector<vector<int>> &LANDS,vector<int> ODDS){
    d_switch_pattern(switches,bit);
    int count=0;
    for(int j=0;j<lamps;j=j+1){
        int cond=0;
        for(int k=0;k<relative[j];k=k+1){
            int switch_num;
            switch_num=LANDS[j][k];
            if((bit & (1<<switch_num))!=0){
                cond = cond+1;
            }
        }
        if(cond == 0) continue;
        if(cond % 2 == ODDS[j]){
            count = count + 1;
        }
    }
    debug("点灯した数 %d 個\n",count);
    return count;
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
        SW[j].resize(SW_CNT[j]);
        for(int k=0;k<SW_CNT[j];k=k+1){
            int tmp;
            cin >> tmp;
            SW[j][k]=tmp-1; // 0-indexにしたい
        }
    }
    for(int j=0;j<M;j++){
        cin >> NUM[j];
    }
    for(int swpat=0;swpat<(1<<N);swpat=swpat+1){
        int on_lampcnt;
        on_lampcnt=light_cnt(swpat,N,M,SW_CNT,SW,NUM);
    }
    // SW_CNTが正しく入っているか確認 OK!
    /**
    for(int j=0;j<M;j=j+1){
        debug("電球 %d のスイッチ条件\n",j);
        for(int k=0;k<SW_CNT[j];k=k+1){
            debug("%d ",SW[j][k]);
        }
        debug("\nが[ON]の時\n");
    }
    **/

    return 0;
}
