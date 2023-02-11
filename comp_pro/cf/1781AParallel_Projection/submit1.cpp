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

int solver(int &w,int &d,int &h,int &a ,int &b,int &f,int &g){
    int ans=h;
    int x1 = abs(a-f);
    int x2 = 2*w-abs(a-f);
    int y1 = abs(b+g);
    int y2 = 2*d-b-g;
    ans = ans + min(x1,x2) + min(y1,y2);
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
        ans = solver(w,d,h,a,b,f,g);
        cout << ans << "\n" << flush;
    }
    return 0;
}

