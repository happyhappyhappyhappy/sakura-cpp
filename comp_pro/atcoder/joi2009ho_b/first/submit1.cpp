#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    cout << "店の位置一覧\n" << flush;
    for(ll j=0;j<N+1;j++){
        cout << shop_pos[j] << " ";
    }
    cout << "\n" << flush;
    cout << "客の位置一覧\n" << flush;
    for(ll j=0;j<M;j++){
        cout << cost_pos[j] << " ";
    }
    cout << "\n" << flush;

    cout << result << "\n" << flush;
    return 0;
}
