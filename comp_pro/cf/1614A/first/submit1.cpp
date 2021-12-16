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
          cout << solver(base_d,price) << "\n" << flush;
    }
    return 0;
}
