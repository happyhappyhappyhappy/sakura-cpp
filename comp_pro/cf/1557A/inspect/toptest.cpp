#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<algorithm>
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
        sort(value.begin(),value.end());
        double top1,top2;
        // 最後の一つだけ以外の平均＋最後の一つ
        double top4ave,top4all;
        double top4sum = 0.0;
        for(int m=0;m<4;m=m+1){
            top4sum = top4sum+value[m];
        }
        top1 = top4sum / 4.0 + value[4];
        double top3ave = 0.0;
        double top3last2 = 0.0;
        double top3avesum = 0.0;
        double top3last2sum = 0.0;
        for(int m=0;m<3;m=m+1){
            top3avesum = top3avesum + value[m];
        }
        for(int m=3;m<value.size();m=m+1){
            top3last2sum = top3last2sum + value[m];
        }
        top2 = (top3avesum / 3.0) + (top3last2sum / 2.0);
        cout << top2 << " ? " << top1 << "\n";
        if( top2 < top1){
            cout << "This case is top1 max\n";
        }
        else{
            cout << "This case is top2 max\n";
        }
    }
    
}