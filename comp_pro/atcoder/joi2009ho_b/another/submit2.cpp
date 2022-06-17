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

ll solver(vector<ll> &dist,ll pos){ // 参照渡しをしないとコピーに時間食う
    ll result=0;
    ll nearly_pos=lower_bound(dist.begin(),dist.end(),pos) - dist.begin();
    result = min(abs(dist[nearly_pos]-pos),abs(pos-dist[nearly_pos-1]));
    return result;
}

int main(void){
    initial();
    // 一周の長さ,ピザ屋の数(本店含む),顧客の数
    ll d_all,shop_all,cost_all;// d,n,m
    ll result=0;
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
        cin >> cost_pos[j];
    }
    for(ll j=0;j<cost_all;j++){
        result = result+solver(shop_pos,cost_pos[j]);
    }
    cout << result << "\n" << flush;
    return 0;
}
