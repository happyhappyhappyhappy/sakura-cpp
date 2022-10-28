#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__);
#define ERRFLUSH setvbuf(stderr, (char *)NULL, _IONBF, 0); 

typedef pair<int,int> POS;

template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){

    int figure_cnt;
    cin >> figure_cnt;
    vector<POS> fig(figure_cnt);
    for(int j=0;j<figure_cnt;j=j+1){
        cin >> fig[j].first >> fig[j].second;
    }
    int photo_cnt;
    cin >> photo_cnt;
    vector<POS> photo(photo_cnt);
    for(int j=0;j<photo_cnt;j=j+1){
        cin >> photo[j].first >> photo[j].second;
    }
    map<POS,int> check;
    for(int j=0;j<figure_cnt;j=j+1){
        for(int k=0;k<photo_cnt;k=k+1){
            int photo_x=photo[k].first;
            int photo_y=photo[k].second;
            int fig_x=fig[j].first;
            int fig_y=fig[j].second;
            debug("(%d,%d) => (%d,%d) ",fig_x,fig_y,photo_x,photo_y);
            int move_x = photo_x-fig_x;
            int move_y = photo_y-fig_y;
            debug(" x: %d , y: %d\n",move_x,move_y);
            check[{move_x,move_y}]++;
        }
    }
    for(auto &e:check){
        debug("x: %d,y: %d -> %d\n",e.first.first,e.first.second
        ,e.second);
    }
    for(auto &e:check){
        if(e.second == figure_cnt){
            debug("answer: x = %d, y = %d\n",e.first.first,e.first.second);
            break;
        }
    }
    return 0;
}
