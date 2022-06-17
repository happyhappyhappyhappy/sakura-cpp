#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout << #x << " = " << (x) << " (L" <<__LINE__<< ")" << "\n" << flush
// めぐる式二分探索法(一般化の拡張)
// https://qiita.com/drken/items/97e37dd6143e33a64c8c

bool isGood(ll &mid_pos,ll &key){
    bool result = false;
    if(mid_pos >= key){
        result = true;
    }
    return result;
}
// good(right) は 常にあるキーになる数以上 「good」
// bad(left) は 常にあるキー以下になる「bad」
// right-left=1になったときgoodの値を返す→lower_boundと同じ振る舞い

ll now_binary_search(vector<ll> &shops,ll pos){
    ll good;
    ll bad;
    bad = -1; // 0が正解の時の防備
    good = shops.size()+1; // 最大値が正解だったときの防備
    while(abs(good-bad)>1) // 差が丁度1の時に完了
    {
        ll mid = (bad + good) / 2;//二つの中間点
        if(isGood(shops[mid],pos)){
            good = mid; // 条件を満たす良い値を幅寄せする
        }
        else{
            bad = mid; // 条件に満たない位置を幅寄せする
        }
    }
   return good; 
}

ll solver(vector<ll> &shops,ll pos){
    ll result=0;
    ll nearly_pos=0;
    nearly_pos = now_binary_search(shops,pos);
    result = min(abs(shops[nearly_pos]-pos),abs(pos-shops[nearly_pos-1]));
    return result;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // 一周の長さ
    // 本店を含むピザ屋の数(なので後で値を取る場合は、一回ループが少ない)
    // 客の位置
    ll d_all,shop_all,cost_all;
    ll result = 0;
    cin >> d_all >> shop_all >> cost_all;
    // 番兵として本店の情報を加えたい
    vector<ll> shop_pos(shop_all+1);
    for(ll j=0;j<shop_all-1;j++){
        cin >> shop_pos[j];
    }
    shop_pos[shop_all-1]=0;// 本店の位置
    shop_pos[shop_all]=d_all; // 最大として一周後の本店の位置 
    sort(shop_pos.begin(),shop_pos.end());
    for(ll j=0;j<cost_all;j++){
        ll cost_pos;
        cin >> cost_pos;
        result = result + solver(shop_pos,cost_pos);
    }
    cout << result << "\n" << flush;
    return 0;
}
