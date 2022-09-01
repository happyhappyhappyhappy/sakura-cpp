#include<bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)


int solver(int &n,int &x){
    int answer = 0;
    for(int ie=1;ie<= n;ie=ie+1){
        for(int j=ie+1;j <= n ; j=j+1){
            for(int k=j+1;k<=n;k++){
                int sum = ie + j + k;
                if(sum == x){
                    answer = answer+1;
                }
            }
        }
    }
    return answer;
}
int main(void){
    vector<int> N;
    vector<int> X;
    // データ入力
    while(1){
        int n_e;
        int x_e;
        cin >> n_e >> x_e;
        if(n_e == 0 && x_e == 0)
        {
            break;
        }
        N.push_back(n_e);
        X.push_back(x_e);
    }
    int size = N.size();
    for(int j=0;j<size;j=j+1){
        cout << solver(N[j],X[j]) << "\n" << flush;
    }
    return 0;
}
