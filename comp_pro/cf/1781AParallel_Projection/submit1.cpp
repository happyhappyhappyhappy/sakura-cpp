#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/touristdebug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int tcase,int &w,int &d,int &h,int &a ,int &b,int &f,int &g){
    debug1("----- No. %d 計算部分 -----\n",tcase);
    int ans=0;
    int left=a+f+abs(b-g)+h;
    int right=(2*w-a-f)+abs(b-g)+h;
    int up = (2*d-b-g)+abs(a-f)+h;
    int down = (b+g)+abs(a-f)+h;
    debug(left);
    debug(right);
    debug(up);
    debug(down);
    int lr = min(left,right);
    int du = min(down,up);
    ans = min(lr,du);
    return ans;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1)
    {
        int ans=-1;
        int w,d,h,a,b,f,g;
        cin >> w >> d >> h;
        cin >> a >> b >> f >> g;
        ans = solver(j+1,w,d,h,a,b,f,g);
        cout << ans << "\n" << flush;
    }
    return 0;
}

