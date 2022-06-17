#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// 実は条件を満たす配列位置情報が整数値で取れる
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // 一周の長さ,ピザ屋の数(本店含む),顧客の数
    ll d_all,shop_all,cost_all;// d,n,m
    cin >> d_all >> shop_all >> cost_all;
    // COUTION: sortを使うならばvector列を使う
    //          構成数は'()'を使う
    vector<ll> shop_pos(shop_all+1);
    for(ll j=0;j<shop_all-1;j++){
        cin >> shop_pos[j];
    }
    shop_pos[shop_all-1]=0;// 本店の位置
    shop_pos[shop_all]=d_all;//番兵として「一周後の本店の位置」
    sort(shop_pos.begin(),shop_pos.end());
    vector<ll> cost_pos(cost_all);
    for(ll j=0;j<cost_all;j++){
        cin >> shop_pos[j];
    }
    sort(cost_pos.begin(),cost_pos.end());
    return 0;
}
