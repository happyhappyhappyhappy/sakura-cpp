#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// #else
// #endif
}

int main(void){
    cout << fixed << setprecision(10);
    int problem_counts;
    cin >> problem_counts;
    for (int j = 0; j < problem_counts; j++)
    {
        vector<double> value(5);
        for(double& e: value){
            cin >> e;
        }
        sort(value.begin,value.end);
        double top1,top2;
        // 最後の一つだけ以外の平均＋最後の一つ
        double top4ave,top4all;
        top4ave = 0.0;
        top4sum = 0.0;
        for(int m;m<4;m=m+1){
            top4sum = top4sum+value[m];
        }
        top1 = top4sum / 4.0 + value[4];
        top3ave = 0.0;
        top3last2 = 0.0;
        top3sum = 0.0;
        top3last2sum = 0.0;
    }
    
}