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
int N;
const int INF = INT_MAX/2;
vector<vector<int>> A(303,vector<int>(303,INF));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            cin >> A[j][k];
        }
    }
    vector<pair<ll,pair<int,int>>> v;
    for(int j=0;j<N;j=j+1){
        for(int k=j+1;k<N;k=k+1){
            v.push_back({-A[j][k],{j,k}});
            //    v.push_back({A[j][k],{j,k}});
        }
    }
    // sort(v.begin(),v.end(),comparePairs);
    // for(auto& p:v){
    //     ll a = p.first;
    //     int b = p.second.first;
    //     int c = p.second.second;
    //     debug("%d -> %d = %lld\n",b,c,a);
    // }
    sort(v.begin(),v.end());
    int ans=0;
    for(int j=0;j<N;j=j+1){
        for(int k=j+1;k<N;k=k+1){
            ans=ans+A[j][k];
        }
    }
    for(auto& p:v){
        int c = (-1)*p.first;
   //     int c = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if(A[a][b]==INF){
            continue;
        }
        for(int j=0;j<N;j=j+1){
            if(j!=a && j != b && A[a][j]!=INF && A[j][b]!=INF){
                if(A[a][j]+A[j][b]==c){
                    ans=ans-c;
                    A[a][b]=INF;
                    A[b][a]=INF;
                    break;
                }else if(A[a][j] + A[j][b] < c){
                    debug("(寄り道)%d->%d + %d->%d が (直接) %d より短いですNG\n",a,j,j,b,c);
                    cout << "-1\n" << flush;
                    return 0;
                }
            }
        }
    }
    cout << ans << "\n" << flush;
    return 0;
}
