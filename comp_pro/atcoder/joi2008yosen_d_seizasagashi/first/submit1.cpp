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

typedef pair<int,int> PAIR; // typedef <標準> <新名称>;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


bool solver(int fig_cnt,int photo_cnt,vector<PAIR> fig,
vector<PAIR> photo,int &ans_x,int &ans_y){
    map<pair<int,int>,int> collate_map;
    for(int j=0;j<fig_cnt;j=j+1){
        for(int k=0;k<photo_cnt;k=k+1){
            int x_move,y_move;
            x_move = photo[k].first-fig[j].first;
            y_move = photo[k].second-fig[j].second;
            collate_map[{x_move,y_move}]++;
        }
    }
    for(auto &xy:collate_map){
        if(xy.second == fig_cnt){
            ans_x = xy.first.first;
            ans_y = xy.first.second;
            return true;
        }
    }
    return false;
}

int main(void){
    initial();
    int fig_cnt; // 図解上での星座の位置
    cin >> fig_cnt;
    vector<PAIR> FIG(fig_cnt);
    for(int j=0;j<fig_cnt;j=j+1){
        cin >> FIG[j].first >> FIG[j].second;
    } 
    int photo_cnt;
    cin >> photo_cnt; // 実際の星空
    vector<PAIR> PHOTO(photo_cnt);
    for(int j=0;j<photo_cnt;j=j+1){
        cin >> PHOTO[j].first >> PHOTO[j].second;
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
