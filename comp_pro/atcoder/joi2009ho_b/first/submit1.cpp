#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(vector<ll> &S,ll key){
    ll result=0;
    ll size=S.size();
    if(S[size-1] == key){
        return 0;
    }
    auto itr=lower_bound(S.begin(),S.end(),key);
    ll after=*itr;
    --itr;
    ll before=*itr;
    result=min(abs(before-key),abs(key-after));
    return result;
}

int main(void){
    initial();
    ll result=0;
    ll D=0;
    ll N=0;
    ll M=0;
    cin >> D >> N >> M;
    vector<ll> shop_pos(N+1);
    vector<ll> cost_pos(M);
    for(ll j=0;j<N-1;j++){
        cin >> shop_pos[j];
    }
    // 本店を登録
    shop_pos[N-1]=D;
    shop_pos[N]=0;
    sort(shop_pos.begin(),shop_pos.end());
    for(auto &x:cost_pos){
        cin >> x;
    }
    for(ll j=0;j<M;j++){
        result = result + solver(shop_pos,cost_pos[j]);
    }
    cout << result << "\n" << flush;
    return 0;
}
