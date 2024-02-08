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
void swap(vector<int>& arr,int k,int j){
    int temp=arr[k];
    arr[k]=arr[j];
    arr[j]=temp;
}
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int k=low-1;
    for(int j=low;j<high;j=j+1){
        if(pivot < arr[j]){
            k=k+1;
            swap(arr,k,j);
        }
    }
    swap(arr,k+1,high);
    return (k+1);
}
void quicksort(vector<int>& arr,int low,int high){
    if(low < high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void myqsort(vector<int>& arr){
    int N=(int)arr.size();
    quicksort(arr,0,N-1);
}
int main(void){
    initial();

    return 0;
}
