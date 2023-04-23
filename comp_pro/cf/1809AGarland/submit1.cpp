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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(string X){
    vector<int> B(10,0);
    for(int j=0;j<(int)X.size();j=j+1){
        int num = (X.at(j))-'0';
        B[num] = B[num]+1;
    }
    int mymax=-1;
    for(int j=0;j<10;j=j+1){
        if(mymax < B[j]){
            mymax = B[j];
        }
    }
    if(mymax == 4){
        return -1;
    }
    if(mymax == 3){
        return 6;
    }
    // 1か2の場合
    return 4;
}

int main(void){
    initial();
    int tc;
    cin >> tc;
    while(tc--){
        string str="";
        cin >> str;
        int answer=0;
        answer = solver(str);
        cout << answer << "\n" << flush;
    }
    return 0;
}
