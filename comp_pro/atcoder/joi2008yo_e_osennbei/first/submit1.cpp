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


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<vector<int>> &G,int LINE,int COLUMN){
    int result = -1;
    for(int bit=0;bit<(1<<LINE);bit=bit+1){
        vector<vector<int>> sketchGrid(LINE,vector<int>(COLUMN));
        int zero_pos=0;
        // 検証環境のコピー
        for(int j=0;j<LINE;j=j+1){
            copy(G[j].begin(),G[j].end(),sketchGrid[j].begin());
        }
        // 行毎のひっくり返し
        for(int j=0;j<LINE;j=j+1){
            if((bit&(1<<j))!=0)
            {
                // ひっくり返す
                for(int k=0;k<COLUMN;k=k+1){
                    sketchGrid[j][k]=(sketchGrid[j][k]+1)%2;
                }
            }
        }
        // 列ごとの処理
        for(int k=0;k<COLUMN;k=k+1){
            int one_c=0;
            int zero_c=0;
            for(int j=0;j<LINE;j=j+1){
                if(sketchGrid[j][k]==0){
                    zero_c=zero_c+1;
                }
                else{
                    one_c=one_c+1;
                }
            }
            if(zero_c<one_c){
                for(int j=0;j<LINE;j=j+1){
                    // 列をひっくり返す
                    sketchGrid[j][k]=(sketchGrid[j][k]+1)%2;
                }
            }
        }
        // 結果の0を数える
        for(int j=0;j<LINE;j=j+1){
            for(int k=0;k<COLUMN;k=k+1){
                if(sketchGrid[j][k]==0){
                    zero_pos=zero_pos+1;
                }
            }
        }
        chmax(result,zero_pos);
    }
    return result;
}

int main(void){
    initial();
    int R,C;
    cin >> R >> C;
    int answer=-1;
    vector<vector<int>> main_grid(R,vector<int>(C));
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            cin >> main_grid[j][k];
        }
    }
    for(int bit=0;bit<(1<<R);bit=bit+1){
        int bitmax=0;
        vector<vector<int>> check_grid(R,vector<int>(C));
        for(int j=0;j<R;j=j+1){
            copy(main_grid[j].begin(),main_grid[j].end(),check_grid[j].begin());
        }
        for(int j=0;j<R;j=j+1)
        {
            if((bit&(1<<j))!=0){
                for(int k=0;k<C;k=k+1){
                    check_grid[j][k]=(check_grid[j][k]+1)%2;
                }
            }
        }
        // 列をひっくり返す
        for(int j=0;j<C;j=j+1){
            int one_c;
            int zero_c;
            one_c=0;
            zero_c=0;
            for(int k=0;k<R;k=k+1){
                if(check_grid[k][j]==1){
                    one_c=one_c+1;
                }
                else{
                    zero_c=zero_c+1;
                }
            }
            if(zero_c<one_c){// 1の方が多い→引っくり返す
                for(int k=0;k<R;k=k+1){
                    check_grid[k][j] = (check_grid[k][j]+1)%2;
                }
            }
        }
        for(int j=0;j<R;j=j+1){
            for(int k=0;k<C;k=k+1){
                if(check_grid[j][k]==0){
                    bitmax=bitmax+1;
                }
            }
        }
        chmax(answer,bitmax);
    }
    cout << solver(main_grid,R,C) << "\n" << flush;
    return 0;
}
