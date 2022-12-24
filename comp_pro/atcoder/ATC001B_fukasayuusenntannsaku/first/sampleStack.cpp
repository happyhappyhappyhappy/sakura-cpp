#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int main(){
    const int dx[4]={1,0,-1,0};
    const int dy[4]={0,-1,0,1};
    int h,w,sx=500,sy=500;
    cin>>h>>w;
    char c[h][w];
    stack<pair<int,int>> s;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c[i][j];
            if(c[i][j]=='s'){
                sx=i;
                sy=j;
            }
        }
    }
    vector<vector<int>> dis(h,vector<int>(w,-1));
    s.push(make_pair(sx,sy));
    dis[sx][sy]=0;
    int cx=sx,cy=sy;
    int ccx,ccy,z=0;
    while(!s.empty()){
        pair<int,int> cp=s.top();
        cx=cp.first;
        cy=cp.second;
        s.pop();
        for(int d=0;d<4;d++){
            ccx=cx+dx[d];
            ccy=cy+dy[d];
            if((ccx>=0)&&(ccx<h)&&(ccy>=0)&&(ccy<w)){
                if(c[ccx][ccy]=='.'){
                    if(dis[ccx][ccy]==-1){
                        dis[ccx][ccy]=1;
                        s.push(make_pair(ccx,ccy));
                    }
                }
                if(c[ccx][ccy]=='g'){
                    z=1;
                }
            }
        }
        if(z==1){
            break;
        }
    }
    if(z==1){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
    return 0;
}
