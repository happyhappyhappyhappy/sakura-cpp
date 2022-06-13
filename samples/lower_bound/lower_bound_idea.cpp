#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void distant_check(ll pos){
    // problem配列と照合するには1000以上はないものとする
    vector<ll> problem={0,3, 14, 32, 51, 51, 51, 243, 419, 750, 910,1000};
    auto itr=lower_bound(problem.begin(),problem.end(),pos);
    ll pos_after=*itr;
    --itr;
    ll pos_before=*itr;
    cout << pos_before << " " << pos << " " << pos_after;

}

int main(void){
    initial();
    ll pos=2;
    distant_check(pos);
    return 0;
}
