#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmax(XXX &x,XXX y){
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
    // sort(T.begin(),T.end());
    for(int j=0;j<count;j=j+1){
        for(int k=j+1;k<count;k=k+1){
            int x1 = T[j][0];
            int y1 = T[j][1];
            int x2 = T[k][0];
            int y2 = T[k][1];
            int diff_x = x2 - x1;
            int diff_y = y2 - y1;
            int x3_1 = x1-diff_y;
            int y3_1 = y1+diff_x;
            int x4_1 = x2-diff_y;
            debug("1:C(%d,%d),D(%d,%d)\n",x3_1,y3_1,x4_1,x4_1);
            int y4_1 = y2+diff_x;
            int x3_2 = x1+diff_y;
            int y3_2 = y1-diff_x;
            int x4_2 = x2+diff_y;
            int y4_2 = y2-diff_x;
            if(
                (HASHIRA.find({x3_1,y3_1}) != HASHIRA.end() && HASHIRA.find({x4_1,y4_1}) != HASHIRA.end())
                || 
                (HASHIRA.find({x3_2,y3_2}) != HASHIRA.end() && HASHIRA.find({x4_2,y4_2}) != HASHIRA.end())
            )
            {
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
