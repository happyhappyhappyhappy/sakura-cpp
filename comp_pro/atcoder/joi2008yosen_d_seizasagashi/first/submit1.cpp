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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


bool solver(int fig_cnt,int photo_cnt,vector<vector<int>> FIG,
vector<vector<int>> PHOTO,int &ans_x,int &ans_y){
    map<pair<int,int>,int> collate_map;
    for(int j=0;j<fig_cnt;j=j+1){
        for(int k=0;k<photo_cnt;k=K+1){
            // TODO: ここに星座座標と地図座標との移動長さを
            // 求めてcollate_mapにcollate_map[{x,y}]++;と入れる
        }
    }
    ans_x=fig_cnt;
    ans_y=photo_cnt;
    return true;
}

int main(void){
    initial();
    int fig_cnt; // 図解上での星座の位置
    cin >> fig_cnt;
    vector<vector<int>> FIG(fig_cnt,vector<int>(2,0));
    for(int j=0;j<fig_cnt;j=j+1){
        cin >> FIG[j][0] >> FIG[j][0];
    } 
    int photo_cnt;
    cin >> photo_cnt; // 実際の星空
    vector<vector<int>> PHOTO(photo_cnt,vector<int>(2,0));
    for(int j=0;j<photo_cnt;j=j+1){
        cin >> PHOTO[j][0] >> PHOTO[j][1];
    }
    int ans_x,ans_y;
    if(solver(fig_cnt,photo_cnt,FIG,PHOTO,ans_x,ans_y)){
        cout << ans_x << " " << ans_y << "\n" << flush;
    }
    else{
        cout << "0 0\n" << flush;
    }
    return 0;
}
