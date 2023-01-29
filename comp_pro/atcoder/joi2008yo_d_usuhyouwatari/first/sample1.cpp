#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Grid(100, vector<int>(100, 0));
int max_area = -1;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int h, w;

void tansaku(vector<vector<int>>& Grid, int si, int sj, int cnt){
    Grid[si][sj] = 0;
    bool step_fg = false;
    for(int i=0;i<4;i++){
        int ni = si + dx[i];
        int nj = sj + dy[i];
        if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
        if(Grid[ni][nj]){
            tansaku(Grid, ni, nj, cnt+1);
            step_fg = true;
        }
    }
    if(step_fg==false){
        max_area = max(max_area, cnt);
    }
    cnt--;
    Grid[si][sj] = 1;
}

int main(){
    cin >> h >> w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;
            cin >> a;
            Grid[i][j] = a;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int cnt = 1;
            if(Grid[i][j]) tansaku(Grid, i, j, cnt);
        }
    }

    cout << max_area << endl;
    return 0;
}
