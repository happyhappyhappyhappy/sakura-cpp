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
vector<int> uniqueSet(vector<int> X){
    unordered_set<int> setX(X.begin(),X.end());
    vector<int> uX(setX.begin(),setX.end());
    return uX;
}
void bubbleSort(vector<int>& arr){
    int N=(int)arr.size();
    for(int k=0;k<N-1;k=k+1){
        for(int j=0;j<(N-k)-1;j=j+1){
            if(arr[j] < arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<int> A(N,0);
    for(auto& e:A){
        cin >> e;
    }
    vector<int> uA=uniqueSet(A);
    int M = (int)uA.size();
    bubbleSort(uA);
    cout << uA[1] << endl;
    return 0;
}
