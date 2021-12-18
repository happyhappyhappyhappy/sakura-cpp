#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<int>& dataVec,vector<int>& prices){
    int result=0;
    int n=dataVec[0]; // チョコレートの数
    int l=dataVec[1]; // 購入する最低値段
    int r=dataVec[2]; // 購入する最高値段
    int k=dataVec[3]; // 所持金
    for(int j=0;j<prices.size();j=j+1){
        cout << prices.at(j) << "\n" ;
    }
    sort(prices.begin(),prices.end());
    cout << "\n" << flush;
    return result;
}


int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
          vector<int> base_d(4);
          for(int& e:base_d){
              cin >> e;
          }  
          vector<int> price;
          for(int& e:price){
              cin >> e;
          }
// todo int j=0は上で使ってます　k に修正してはどうか
            for(int j=0;j<price.size();j=j+1){
                cout << price.at(j) << "\n" ;
            }
          cout << solver(base_d,price) << "\n" << flush;
    }
    return 0;
}
