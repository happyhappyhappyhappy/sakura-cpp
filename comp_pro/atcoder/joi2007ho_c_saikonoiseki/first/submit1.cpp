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
            debug("J=%d,K=%dについて調査中\n",j,k);
            if(exitCheck(A,B,HASHIRA)){
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
    }
    cout << solver(coordpoint,Point) << "\n" << flush;
    return 0;
}
