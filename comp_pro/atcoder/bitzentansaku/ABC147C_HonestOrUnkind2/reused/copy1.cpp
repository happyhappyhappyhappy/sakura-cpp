#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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

int N;
vector<int> honests[15];
vector<int> liars[15];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        int A;
        cin >> A;
        for(int k=0;k<A;k=k+1){
            int x;
            int y;
            cin >> x >> y;
            if(y==0){
                liars[j].push_back(x-1);
            }
            else{
                honests[j].push_back(x-1);
            }
        }
    }
    // TODO: 中身を見てください多分2次元になっていると思う
    debug("うその数 %d\n",(int)liars[1].size());
    debug("正直者の数 %d\n",(int)honests[1].size());
    return 0;
}
