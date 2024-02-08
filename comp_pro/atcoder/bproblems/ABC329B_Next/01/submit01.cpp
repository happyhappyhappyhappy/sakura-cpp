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
vector<int> uniqueSet(vector<int> X){
    unordered_set<int> setA(X.begin(),X.end());
    vector<int> setAB(setA.begin(),setA.end());
    return setAB;
}
bool compareDescending(int a,int b){
    return a < b;
}
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int k=low-1;
    for(int j=low;j<=high;j=j+1){
        if(compareDescending(arr[j],pivot)){
            k=k+1;
            swap(arr[k],arr[j]);
        }
    }
    swap(arr[k+1],arr[high]);
    return (k+1);
}
void quicksort(vector<int>& arr,int low,int high){
    if(high <= low){
        return;
    }
    int pivotIndex=partition(arr,low,high);
    quicksort(arr,low,pivotIndex-1);
    quicksort(arr,pivotIndex+1,high);
    return;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    int M=(int)uA.size();
    // quicksort(uA,0,M);
    // for(auto& e:uA){
    //     cout << e << " ";
    // }
    // cout << endl;
    sort(uA.begin(),uA.end());
    cout << uA[M-2] << endl;
    return 0;
}
