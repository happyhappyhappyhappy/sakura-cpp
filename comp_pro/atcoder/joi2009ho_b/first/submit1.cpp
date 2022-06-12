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
    ll suround_d=0;
    int shop_count_n=0;
    int pizza_count_m=0;
    cin >> suround_d >> shop_count_n >> pizza_count_m;
    vector<ll> shop_pos(shop_count_n+1,0);
    /** FIXME: ここはshop_pos=0の所にも店があることに注意
    for(auto x:shop_pos){
        cin >> x;
    }
    **/
    shop_pos[shop_count_n]=suround_d;



    cout << result << "\n" << flush;
    return 0;
}
