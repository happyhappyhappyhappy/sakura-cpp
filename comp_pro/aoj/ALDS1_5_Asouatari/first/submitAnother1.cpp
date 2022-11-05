#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

/**
  事前に全部の作成可能な数をセットする流れ
  https://qiita.com/Johannyjm/items/00a98ad0667aecbc0e26#10%E6%97%A5%E7%9B%AE-aoj-alds1_5_a-exhaustive-search
**/

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void makeAllSum(set &sums,vector &A){
    
}

int main(void){
    initial();
    int a_count;
    cin >> a_count;
    vector<int> A(a_count);
    for(int j=0;j<a_count;j=j+1){
        cin >> A[j];
    }
    set allSum;


    return 0;
}
