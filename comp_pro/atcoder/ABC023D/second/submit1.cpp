#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
const long long MAX_HIGH=1LL<<60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(int &target,vector<ll> &high,vector<ll> &speed){
    ll top=MAX_HIGH;
    ll under=0;
    while(abs(top-under)>1){
        bool flag=true;
        vector<ll> remainTime(target,0);
        ll mid=(top+under)/2;
        for(int j=0;j<target;j++){ 
            if(mid<high[j]){ // 風船の初期高度が判定高度を超えていたらダメ。
                flag=false;
            }
            else{
                remainTime[j] = (mid-high[j])/speed[j];
            }
        }
        sort(remainTime.begin(),remainTime.end());
        for(int bang=0;bang<target;bang=bang+1){ // bang=射撃をする時間内にあるか確認
            if(remainTime[bang] < bang){ // 射撃をする時間が残り時間超え
                flag=false;
            }
        }
        if(flag){ // true:まだまだ余裕ありそう→上位の位置を下げる→中心地へ
            top=mid;
        }
        else{ // false:失敗する。→下位の位置を中心値に上げる
            under=mid;
        }
//        debug("上位 %lld, 下位%lld\n",top,under);
    }

    return top;
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<ll> H(N);
    vector<ll> S(N);
    for(int j=0;j<N;j=j+1){
        cin >> H.at(j) >> S.at(j);
    }
    cout << solver(N,H,S) << "\n" << flush;
    return 0;
}
