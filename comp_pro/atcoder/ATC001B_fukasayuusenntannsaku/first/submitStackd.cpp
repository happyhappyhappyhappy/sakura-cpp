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

bool inMap(int cy,int cx,int Hy,int Wx){ // 地図の中に次の点があるか
    if(cy < 0){
        return false;
    }
    if(cx < 0){
        return false;
    }
    if(Hy<=cy){
        return false;
    }
    if(Wx<=cx){
        return false;
    }
    return true;
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
    vector<vector<bool>> dis(Hy,vector<bool>(Wx,false));
    S.push(make_pair(sy,sx));
    dis[sy][sx]=true;
    int cy,cx;
    cy=sy;
    cx=sx;
    int ccy,ccx;
    ccy=0;
    ccx=0;
    bool looked=false;
    while(!S.empty()){
        pair<int,int> cp=S.top();// 取り出す
        cx=cp.second;
        cy=cp.first;
        S.pop(); // コンテナ末尾の削除
        for(int d=0;d<4;d=d+1){
            ccx = cx+dx[d];
            ccy = cy+dy[d];
            if(inMap(ccy,ccx,Hy,Wx)){
                if(G[ccy][ccx] == '.'){
                    if(!dis[ccy][ccx]){
                        dis[ccy][ccx] = true;
                        S.push(make_pair(ccy,ccx));
                    }
                }
                if(G[ccy][ccx] == 'g'){
                    looked=true;
                }
            }
        }
        if(looked){
            break;
        }
    }
    if(looked){
        cout << "Yes\n" << flush;
    }
    else{
        cout << "No\n" << flush;
    }
    return 0;
}
