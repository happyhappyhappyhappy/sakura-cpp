#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
long long int mypow(long long int p,long long int n){
    long long int res=1;
    while(0<n){
        int check1 = n & 1;
        if(check1 == 1){
            res=res*p;
        }
        p=p*p;
        n = n >> 1;
    }
    return res;
}
vector<long long int> makeList(long long int x){
    vector<long long int> res;
    res.push_back(-1);
    for(int j=1;j<=x;j=j+1){
        res.push_back(mypow(j,j));
    }
    return res;
}
int main(void){
    initial();
    vector<long long int> powList=makeList(15);
    // for(auto& e:powList){
    //     cout << e << endl;
    // }
    long long int N;
    cin >> N;
    int res = -1;
    for(int j=0;j<=15;j=j+1){
        if(N==powList[j]){
            res=j;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
