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
typedef pair<int,int> P;
int MAXSIDE=5100;
// 方眼紙
vector<vector<bool>> SQ(MAXSIDE,vector(MAXSIDE,false));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
// 事前に方眼紙の範囲に含まれているか確認
// ここにある座標は結局falseになるここと
// 方眼紙からはみ出たところをチェックしてエラーになることを排除
bool checkOutOfRange(int v){ 
    if(v < 0){              
        return true;
    }
    if(MAXSIDE <= v){
        return true;
    }
    return false;
}


bool exitCheck(P &A,P &B){
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
    // 方眼値内にあることを確認
    // 超えていたらこの段階でfalse
    if(checkOutOfRange(C.first) || checkOutOfRange(C.second) ||
    checkOutOfRange(D.first) || checkOutOfRange(D.second))
    {
        return false;
    }
    if(SQ[C.first][C.second] == true && 
    SQ[D.first][D.second] == true)
    {
        return true;
    }
    return false;
}

int solver(int pt,vector<P> &Point){
    int result = 0;
    sort(Point.begin(),Point.end());
    for(int j=0;j<pt;j=j+1){
        for(int k=j+1;k<pt;k=k+1){
            P A=Point[j];
            P B=Point[k];
            if(exitCheck(A,B)){
                int diffab=(A.first-B.first)*(A.first-B.first)+
                (A.second-B.second)*(A.second-B.second);
                chmax(result,diffab);
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
        SQ[Point[j].first][Point[j].second]=true;
    }
    cout << solver(coordpoint,Point) << "\n" << flush;
    return 0;
}
