#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// void disp(int x){
//     cout << x << " ";
// }
int solver(vector<int>& base_d,vector<int>& prices){
    int result=0;
    // base_dの内容
    // 0:並んでいるチョコレートバーの数
    // 1:これ以下のバーは安すぎて買わない(現在はこの数字は含まない)
    // 2:これ以上のバーは高すぎるので買わない(現在はこの数字は含まない)
    // 3:所持金
    // cout << "base_dのデータ内容\n" << flush;
    // for(int& e:base_d){
    //     cout << e << " ";
    // }
    // cout << "\n" << flush;
    sort(prices.begin(),prices.end());
    // cout << "pricesのデータ内容\n" << flush;
    // for(int& e:prices){
    //     cout << e << " ";
    // }
    // cout << "\n" << flush;
    int have_money = base_d[3];
    for(int j=0;j<base_d.at(0);j=j+1){
        // もしこれを買って0未満になったらループ終了
        if((have_money-prices[j])<0){
            break;
        }
        if((base_d[1] < prices[j]) && (prices[j]< base_d[2] ))
        {
            // OK 
            result = result + 1;
            have_money = have_money-prices[j];
            // TODO :実行確認
        }
    }
    return result;
}

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
        // cout << j << " of " << testcase << "の設定\n" << flush; 
        // cout <<  j << " of " << testcase << " の基本設定\n" <<flush;
        // for_each(base_d.begin(),base_d.end(),disp);
        // cout << "\n" << flush;
        vector<int> prices(base_d[0]);
        for(int& e:prices){
            cin >> e;
        }
        // cout << j << " of " << testcase << " の各値段\n" << flush;
        // for_each(prices.begin(),prices.end(),disp);
        // cout << "\n" << flush;
        cout << solver(base_d,prices) << "\n" << flush;
    }
    return 0;
}
