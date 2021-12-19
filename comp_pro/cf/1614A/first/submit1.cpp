#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void disp(int x){
    cout << x << " ";
}
// int solver(){
//     int result=0;


//     return result;
// }

int main(void){
    initial();
    int testcase=1;
    cin >> testcase;
    for(int j=1;j<=testcase;j=j+1){
        // 各テストケースの設定
        vector<int> base_d(4);
        for(int& e:base_d){
            cin >> e;
        }
        cout <<  j << " of " << testcase << " の基本設定\n" <<flush;
        for_each(base_d.begin(),base_d.end(),disp);
        cout << "\n" << flush;
        vector<int> prices(base_d[0]);
        for(int& e:prices){
            cin >> e;
        }
        cout << j << " of " << testcase << " の各値段\n" << flush;
        for_each(prices.begin(),prices.end(),disp);
        cout << "\n" << flush;
        // cout << solver(based_d,prices) << "\n" << flush;
    }
    return 0;
}
