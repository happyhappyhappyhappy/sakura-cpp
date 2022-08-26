#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
void get_point(double left,double &gleft,
double &gright,double right){
    // 3分探索用仮の黄金比
    static double GOLD=2.0;
    static double DENOMI=pow((GOLD+1.0),-1.0);
    // static double GOLD= ここに本当の黄金比を入れる
    // 1:2になる点はgleftの中身になる
    gleft = (left*2+right)*DENOMI;
    // 2:1になる点はleftの中身になる
    gright = (left+right*2)*DENOMI;
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
        double g_left,g_right;
        cin >> left >> right;
        get_point(left,g_left,g_right,right);
        cout << left << " " << g_left << " " <<
        g_right << " " << right << "\n" << flush;
    }
    return 0;
}
