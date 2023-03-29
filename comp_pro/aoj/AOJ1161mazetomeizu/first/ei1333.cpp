#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define INF ( 1 << 30 )
#define fr first
#define sc second
typedef pair< int , int > Pt;
const int dx[] = { 0, 1, -1, 0}, dy[] = { 1, 0, 0, -1};
int w, h, cost[30][30];
bool mas[30][30][30][30];
int bfs(){
  fill_n(cost[0],900,0);
  queue<Pt> que;
  cost[0][0] = 1;
  que.push(Pt(0,0));
  while(!que.empty()){
    Pt p = que.front();
    que.pop();
    if(p.fr == h - 1 && p.sc == w - 1) break;
    for(int i = 0 ; i < 4 ; i++ ){
      int ny = p.fr + dy[i], nx = p.sc + dx[i];
      if(ny >= 0 && ny < h && nx >= 0 && nx < w && !cost[ny][nx] && !mas[p.fr][p.sc][ny][nx]  && !mas[ny][nx][p.fr][p.sc]){
        cost[ny][nx] = cost[p.fr][p.sc] + 1;
        que.push(Pt(ny,nx));
      }
    }
  }
  return cost[h-1][w-1];
}
int main(){
  while(cin >> w >> h , w){
    for(int i = 0 ; i < 2 * h - 1 ; i++ ){
      if(i % 2)
        for(int j = 0 ; j < w ; j++ ) cin >> mas[i/2][j][i/2+1][j];
      else
        for(int j = 0 ; j < w - 1 ; j++ ) cin >> mas[i/2][j][i/2][j+1];
    }
    cout << bfs() << endl;
  }
}
