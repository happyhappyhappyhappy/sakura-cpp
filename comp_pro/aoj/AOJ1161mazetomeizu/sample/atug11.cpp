#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){
    while(true){
        int w,h;
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        int wall_veri[30][30]={};
        int wall_hori[30][30]={};
        for(int j=0;j<h;j=j+1){
            for(int k=0;k<w-1;k=k+1){
                cin >> wall_veri[j][k];
            }
            if(j == h-1){
                debug("jが %d まで行きました。抜けます。\n",j);
                continue;
            }
            for(int k=0;k<w;k=k+1){
                cin >> wall_hori[j][k];
            }
        }
        debug("\n-----縦の情報-----\n");

        for(int j=0;j<h;j=j+1){
            for(int k=0;k<w-1;k=k+1){
                debug("%2d",wall_veri[j][k]);
            }
            debug("\n");
        }
        debug("\n-----横の情報-----\n");
        for(int j=0;j<h;j=j+1){
            for(int k=0;k<w;k=k+1){
                debug("%2d",wall_hori[j][k]);
            }
            debug("\n");
        }
        debug("\n");
    }
    return 0;
}
