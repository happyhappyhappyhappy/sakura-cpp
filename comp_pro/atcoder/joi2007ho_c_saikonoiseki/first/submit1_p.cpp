#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int count,vector<vector<int>> &T,set<pair<int,int>> &HASHIRA){
    int answer=0;
    sort(T.begin(),T.end());
    for(int j=0;j<count;j=j+1){
        for(int k=j+1;k<count;k=k+1){
            int x1 = T[j][0];
            int y1 = T[j][1];
            int x2 = T[k][0];
            int y2 = T[k][1];
            int diff_x = x2 - x1;
            int diff_y = y1 - y2;
            int x3 = x1+diff_y;
            int y3 = y1+diff_x;
            int x4 = x2+diff_y;
            int y4 = y2+diff_x;
            decltype(HASHIRA)::iterator it_c=HASHIRA.find({x3,y3});
            decltype(HASHIRA)::iterator it_d=HASHIRA.find({x4,y4});
            if(it_c != HASHIRA.end() && it_d != HASHIRA.end()){
                debug("(%d,%d)と(%d,%d)で対応した柱(%d,%d)(%d,%d)が存在した\n",x1,y1,x2,y2,x3,y3,x4,y4);
                chmax(answer,diff_x*diff_x+diff_y*diff_y);
            } // if
        } // for k
    } // for j
    return answer;
}

int main(void){
    initial();
    int column_count;
    cin >> column_count;
    vector<vector<int>> trees(column_count,vector<int>(2,0));
    set<pair<int,int>> HASHIRA;
    for(int j=0;j<column_count;j=j+1){
        cin >> trees[j][0] >> trees[j][1];
        HASHIRA.insert({trees[j][0],trees[j][0]});
    }
    cout << solver(column_count,trees,HASHIRA) << "\n" << flush;
    return 0;
}
