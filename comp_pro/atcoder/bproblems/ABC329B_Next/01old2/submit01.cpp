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
    // unordered_set<int> setVec(X.begin(),X.end());
    // vector<int> res(setVec.begin(),setVec.end());
    unordered_set<int> setA(X.begin(),X.end());
    vector<int> setAB(setA.begin(),setA.end());

    return setAB;
}
// bool compareDescending(int a,int b){
//     return a>b || (a==b && a > b);
// }
bool compareDescending(int a,int b){
    return a>b ;
}

// int partition(vector<int>& arr,int low,int high){
//     int k=low-1;
//     int pivot=arr[high];
//     for(int j=low;j<=high;j=j+1){
//         if(compareDescending(arr[j],pivot)==true){
//             k=k+1;
//             swap(arr[k],arr[j]);
//         }
//     }
//     swap(arr[k+1],arr[high]);
//     return (k+1);
// }
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int k=low-1;
    for(int j=low;j<=high;j++){
        if(compareDescending(arr[j],pivot) == true){
            k++;
            swap(arr[k],arr[j]);
        }
    }
    swap(arr[k+1],arr[high]);
    return (k+1);
}

// void quicksort(vector<int>& arr,int low,int high){
//     if(high<=low){
//         return;
//     }
//     int pivotIndex=partition(arr,low,high);
//     quicksort(arr,low,pivotIndex-1);
//     quicksort(arr,pivotIndex+1,high);
//     return;
// }
void quicksort(vector<int>& arr,int low,int high){
    if(high <= low){
        return;
    }
    int pivotIndex=partition(arr,low,high);
    quicksort(arr,low,pivotIndex-1);
    quicksort(arr,pivotIndex+1,high);
    return;
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<int> X(N,0);
    for(auto& e:X){
        cin >> e;
    }
    debug("---ダブり消去前---\n");
    for(int j=0;j<N;j=j+1){
        if(j!=0){
            debug(" ");
        }
        debug("%d",X[j]);
    }
    debug("\n");
    vector<int> uniqX=uniqueSet(X);
    debug("---ダブり消去後---\n");
    for(int j=0;j<(int)uniqX.size();j=j+1){
        if(j!=0){
            debug(" ");
        }
        debug("%d",uniqX[j]);
    }
    debug("\n");
    quicksort(uniqX,0,(int)uniqX.size()-1);
    debug("---クイックソート後---\n");
    for(int j=0;j<(int)uniqX.size();j=j+1){
        if(j!=0){
            debug(" ");
        }
        debug("%d",uniqX[j]);
    }
    debug("\n");
    cout << uniqX[1] << endl;
    return 0;
}
