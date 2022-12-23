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

void showMap(vector<vector<char>> &G,int Hy,int Wx){

    for(int iy=0;iy<Hy;iy=iy+1){
        for(int jx=0;jx<Wx;jx=jx+1){
            cout << " " << G[iy][jx] ;
        }
        cout << "\n" << flush;
    }
}

int main(void){

    const int dy[4]={0,0,1,-1};
    const int dx[4]={1,-1,0,0};
    int Hy,Wx;
    int sy,sx;
    sy=510;
    sx=510;
    cin >> Hy >> Wx;
    vector<vector<char>> G(Hy,vector<char>(Wx));
    stack<pair<int,int>> S;
    for(int iy=0;iy<Hy;iy=iy+1){
        for(int jx=0;jx<Wx;jx=jx+1){
            char thing;
            cin >> thing;
            if(thing == 's'){
                sx = jx;
                sy = iy;
            }
            G[iy][jx]=thing;
        }
    }
    // showMap(G,Hy,Wx);
    // dis->探索確認
    vector<vector<int>> dis(Hy,vector<int>(Wx,-1));
    // TODO: ここから始める
    // https://atcoder.jp/contests/atc001/submissions/37391423
    return 0;
}
