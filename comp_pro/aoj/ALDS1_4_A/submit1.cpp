#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int solver(vector<int> &S,vector<int> &T){
    int result = 0;
    int s_num=S.size();
    int t_num=T.size();
    for(int j = 0;j<t_num;j=j+1){
        for(int k = 0;k < s_num;k = k+1){
            if(S[k] == T[j]){
                result=result+1;
            }
        }
    }
    return result;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    // 問題を入れる
    int n;
    cin >> n;
    vector<int> S(n);
    for(auto &x:S){
        cin >> x;
    }
    int q;
    cin >> q;
    vector<int> T(q);
    for(auto &x:T){
        cin >> x;
    }
    int result;
    result = solver(S,T);
    cout << result << "\n" << flush;
    return 0;
}
