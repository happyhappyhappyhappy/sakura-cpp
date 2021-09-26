#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;
// 全探索検索→TLE狙い

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    ll goods,maxlimit;
    cin >> goods >> maxlimit;
    ll w[goods]={0};
    ll v[goods]={0};
    for(ll j=0;j<goods;j++){
        cin >> w[j] >> v[j];
    }
    ll result = 0;
    for(ll bit=0;bit < (1<<goods);bit=bit+1){
        ll this_weight=0;
        ll this_value=0;
        for(ll goodsselect=0;goodsselect < goods;goodsselect=goodsselect+1){
            if(bit & (1 << goodsselect)){
                this_weight = this_weight + w[goodsselect];
                this_value = this_value + v[goodsselect];   
            }
        }
        if(this_weight <= maxlimit) {
            if(result <= this_value)
            {
                result = this_value;
            }
        }
    }
    cout << result << "\n";
}