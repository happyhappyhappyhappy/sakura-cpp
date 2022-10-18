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
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
typedef pair<int,int> P;
// TODO: 最終チェック。問題サイトから問題を落としてあるのでチェックすること

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
bool exitCheck(P &A,P &B,set<P> HASHIRA){
    P C,D;
    ll x1,y1,x2,y2;
    x1 = A.first;
    y1 = A.second;
    x2 = B.first;
    y2 = B.second;
    C.first = x2 - (y2-y1);
    C.second= y2 + (x2-x1);
    D.first = x1 - ( y2-y1);
    D.second = y1 + (x2-x1);
    // 見つけるルーチン
    decltype(HASHIRA)::iterator it_c=HASHIRA.find(C);
    decltype(HASHIRA)::iterator it_d=HASHIRA.find(D);
    if(it_c != HASHIRA.end() && it_d != HASHIRA.end()){
        debug("C(%d,%d),D(%d,%d)はHASHIRAに登録されています\n",
        C.first,C.second,D.first,D.second);
        return true;
    }
    return false;
}

int solver(int pt,vector<P> &Point){
    int result = 0;
    sort(Point.begin(),Point.end());
    set<P> HASHIRA;
    for(int j=0;j<pt;j=j+1){
        HASHIRA.insert(Point[j]);
    }
    for(int j=0;j<pt;j=j+1){
        for(int k=j+1;k<pt;k=k+1){
            P A=Point[j];
            P B=Point[k];
            if(exitCheck(A,B,HASHIRA)){
                debug("(%d,%d)-(%d,%d)に対する柱は見つかりました\n",A.first,A.second,B.first,B.second);
                int diffab=(A.first-B.first)*(A.first-B.first)+
                (A.second-B.second)*(A.second-B.second);
                debug("面積は%dです\n",diffab);
                chmax(result,diffab);
            }
            else{
                debug("(%d,%d)-(%d,%d)に対する柱は見つかりませんでした\n",A.first,A.second,B.first,B.second);
            }
        }
    }
    return result;
}

int main(void){
    initial();
    int coordpoint; // 座標の数
    cin >> coordpoint;
    vector<P> Point(coordpoint);
    for(int j=0;j<coordpoint;j=j+1){
        cin >> Point[j].first >> Point[j].second;
    }
    cout << solver(coordpoint,Point) << "\n" << flush;
    return 0;
}
