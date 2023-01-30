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

void nowFIXed(int bit,int R){
    debug("====--%d--ここで固定される物====\n",bit);

    for(int j=0;j<R;j=j+1){
        if((bit & (1<<j))!=0)
        {
            debug("%d行目をひっくり返し「ます」\n",j);
        }
        else{
            debug("%d行目はひっくり返し「ません」\n",j);
        }
    }
}

void debugGridShow(vector<vector<int>> &G,int &R,int &C){
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            debug("%d ",G[j][k]);
        }
        debug("\n");
    }
}

int main(void){
    initial();
    int R,C;
    cin >> R >> C;
    int answer=-1;
    vector<vector<int>> main_net(R,vector<int>(C));
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            cin >> main_net[j][k];
        }
    }
    // for(int j=0;j<R;j=j+1){
    //     for(int k=0;k<C;k=k+1){
    //         cout << main_net[j][k] << " ";
    //     }
    //     cout << "\n" << flush;
    // }
    for(int bit=0;bit<(1<<R);bit=bit+1){
        // nowFIXed(bit,R);
        // 一旦検査用にコピーする
        int bitmax=0;
        vector<vector<int>> check_grid(R,vector<int>(C));
        for(int j=0;j<R;j=j+1){
            copy(main_net[j].begin(),main_net[j].end(),check_grid[j].begin());
        }
        // 行単位で指定されればひっくり返す
        for(int j=0;j<R;j=j+1)
        {
            if((bit&(1<<j))!=0){
                // ひっくり返す
                for(int k=0;k<C;k=k+1){
                    check_grid[j][k]=(check_grid[j][k]+1)%2;
                }
            }
        }
        debug("---- bit = %d : 行のひっくり返し終了後 ----\n",bit);
        debugGridShow(check_grid,R,C);
        // 列をひっくり返す
        // 1(one_c)>0(zero_c)ならば反転((+1)%2)
        // 1(one_c)<0(zero_c)ならば何もしない
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
        debug("oooo bit = %d : 1が多い列のひっくり返し終了後 oooo\n",bit);
        debugGridShow(check_grid,R,C);
        for(int j=0;j<R;j=j+1){
            for(int k=0;k<C;k=k+1){
                if(check_grid[j][k]==0){
                    bitmax=bitmax+1;
                }
            }
        }
        debug("**** bit = %d : の最大可能値 [%d]****\n",bit,bitmax);
        chmax(answer,bitmax);
    }
    cout << answer << "\n" << flush;
    //     debug("%d番目のコピーしたせんべい図\n",bit);
    //     for(int j=0;j<R;j=j+1){
    //         for(int k=0;k<C;k=k+1){
    //             debug("%d ",check_grid[j][k]);
    //         }
    //         debug("\n");
    //     }
    // }
    return 0;
}
