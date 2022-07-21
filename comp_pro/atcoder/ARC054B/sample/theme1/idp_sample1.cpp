#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
void get_point(double left,double *gleft,
double *gright,double right){
    // 3分探索用仮の黄金比
    static double GOLD=2.0 
    // static double GOLD= ここに本当の黄金比を入れる
    // TODO: ここに内分点の公式を当てはめる 2022/07/21
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(10) << setiosflags(ios::fixed);
}

int main(void){
    initial();
    int tc=0;
    cin >> tc;
    while(tc--){
        double left,right;
        double *g_left,*g_right;// 内分点はポインタにする
        cin >> left >> right;
        get_point(left,g_left,g_right,right);
        cout << left << " " << g_left << " " <<
        g_right << " " << right << "\n" << flush;
    }
    return 0;
}
