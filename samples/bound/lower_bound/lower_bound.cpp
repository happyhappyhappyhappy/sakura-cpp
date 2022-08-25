#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    int key;
    key=12;
    // binary_search(a.begin(),a.end(),key);
    auto itr=lower_bound(a.begin(),a.end(),key);
    cout << key << " に近い配列の最小値は " <<  *itr << " です\n" << flush;
    size_t indexkey=distance(a.begin(),itr);
    cout << "配列番号は " << indexkey << " です\n" << flush;
    return 0;
}