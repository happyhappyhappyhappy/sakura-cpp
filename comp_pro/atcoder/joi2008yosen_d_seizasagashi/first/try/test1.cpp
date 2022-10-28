#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__);
#define ERRFLUSH setvbuf(stderr, (char *)NULL, _IONBF, 0); 
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){

    int figure_cnt;
    cin >> figure_cnt;
    vector<vector<int>> fig(figure_cnt,vector<int>(2,0));
    for(int j=0;j<figure_cnt;j=j+1){
        cin >> fig[j][0] >> fig[j][1];
    }
    int photo_cnt;
    cin >> photo_cnt;
    vector<vector<int>> photo(photo_cnt,vector<int>(2,0));
    for(int j=0;j<photo_cnt;j=j+1){
        cin >> photo[j][0] >> photo[j][1];
    }
    debug("星座の位置通常版\n");
    for(int j=0;j<figure_cnt;j=j+1){
        debug("%d : %d %d\n",j+1,fig[j][0],fig[j][1]);
    }
    sort(fig.begin(),fig.end());
    debug("星座の位置ソートしてみた\n");
    for(int j=0;j<figure_cnt;j=j+1){
        debug("%d : %d %d\n",j+1,fig[j][0],fig[j][1]);
    }
    return 0;
}
