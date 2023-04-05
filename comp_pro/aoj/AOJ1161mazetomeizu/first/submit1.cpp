#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using POS=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

// 大域変数
// 垂直方向の壁 W-1個
vector<vector<int>> wall_vert(40,vector<int>(40,yamaMAX_INT));
// 水平方向の壁 H個
vector<vector<int>> wall_hori(40,vector<int>(40,yamaMAX_INT));
// 距離
vector<vector<int>> dist;
// 上下左右12時から右回り90度
vector<int> dh={1,0,-1,0};
vector<int> dw={0,1,0,-1};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
// 高さ,幅
int H,W;

bool canGo1(int posh,int posw,int dh2,int dw2){
    // 枠外に出てしまうケース
    int nexth = posh + dh2;
    int nextw = posw + dw2;
    if(nexth < 0 || H<= nexth){
        return false;
    }
    if(nextw < 0 || W <= nextw){
        return false;
    }
    debug("(%d,%d)から進行(%d,%d)で枠内にはできます\n",posh,posw,dh2,dw2);
    // すでに値が埋まっている場合ケース
    if(dist[nexth][nextw]!=yamaMAX_INT){
        return false;
    }
    return true;
}

bool canGo2(int posh,int posw,int dh2,int dw2){
// 行きたいのだが行けない
    // 右に行きたい
    if(dw2 == 1 && dh2 == 0  ){
        if(wall_vert[posh][posw]==1){
            return false;
        }
    }
    // 下に行きたい
    if(dw2 == 0 && dh2 == 1){
        if(wall_hori[posh][posw]==1)
        {
            return false;
        }
    }
    // 左に行きたい
    if(dw2 == -1 && dh2 == 0){
            if(wall_vert[posh][posw-1]==1){
                return false;
            }
        }
    // 上に行きたい
    if(dw2 == 0 && dh2 == -1){
        if(wall_hori[posh-1][posw]==1){
            return false;
            }
    }
    debug("(%d,%d)から進行(%d,%d)で行けます\n",posh,posw,dh2,dw2);
    return true;
}
/** 参考 chatGPTにリファクタリングして貰った
 *
以下のようにリファクタリングできます：

1. 冗長なコメントの削除

関数名や変数名から、すでに何をしているかが明示されているので、不要なコメントを削除しましょう。

2. 変数名の修正

わかりにくい変数名を見つけたら、意味のある名前に修正しましょう。例えば、"dh2"や"dw2"は、何の略称か分からないので、適切な名前に変更します。

3. 関数を単純化

`canGo1`と`canGo2`は、ほとんど同じことをしています。そこで、`canGo`という名前の新しい関数を作成し、これらの関数を置き換えます。また、引数の順序を"posh"、"posw"、"dh"、"dw"に変更します。

新しいコード：

bool canGo(int posh, int posw, int dh, int dw)
{
    // 枠外に出てしまうケース
    int nexth = posh + dh;
    int nextw = posw + dw;
    if (nexth < 0 || nexth >= H || nextw < 0 || nextw >= W) {
        return false;
    }
    // 壁で行けないケース
    if ((dw == 1 && dh == 0 && wall_vert[posh][posw] == 1) || // 右
        (dw == 0 && dh == 1 && wall_hori[posh][posw] == 1) || // 下
        (dw == -1 && dh == 0 && wall_vert[posh][posw - 1] == 1) || // 左
        (dw == 0 && dh == -1 && wall_hori[posh - 1][posw] == 1)) // 上
    {
        return false;
    }
    // すでに値が埋まっている場合ケース
    if (dist[nexth][nextw] != yamaMAX_INT) {
        return false;
    }
    return true;
}
-- 完了 --

**/

int main(void){
    initial();
    while(true){
        cin >> W >> H;
        if(H == 0 && W == 0){
            break;
        }
        dist.assign(40,vector<int>(40,yamaMAX_INT));
        for(int j=0;j<H;j=j+1){
            for(int k=0;k<W-1;k=k+1){
                cin >> wall_vert[j][k];
            }
            if(j == H-1){
                // debug("jが %d まで行きました。抜けます。\n",j);
                continue;
            }
            for(int k=0;k<W;k=k+1){
                cin >> wall_hori[j][k];
            }
        }
        queue<POS> Q;
        POS p = make_pair(0,0);
        Q.push(p);
        dist[p.first][p.second]=1;
        while(Q.empty()==false){
            POS np = Q.front();Q.pop();
            int ph = np.first;
            int pw = np.second;
            for(int j=0;j<4;j=j+1){
                if(canGo1(ph,pw,dh[j],dw[j])==false){
                    continue;
                }
                if(canGo2(ph,pw,dh[j],dw[j])==false){
                    continue;
                }
                else{
                    // 行けると分かった
                    int nh = ph+dh[j];
                    int nw = pw+dw[j];
                    dist[nh][nw]=dist[ph][pw]+1;
                    POS npos=make_pair(nh,nw);
                    Q.push(npos);
                }
                }
            }
            for(int h=0;h<H;h=h+1){
                for(int w=0;w<W;w=w+1){
                    int num=dist[h][w];
                    if(num == yamaMAX_INT){
                        debug(" *");
                    }
                    else{
                        debug("%2d",num);
                    }
                }
                debug("\n");
            }
            debug("\n");
            int last = dist[H-1][W-1];
            if(last==yamaMAX_INT){
                cout << "0\n" << flush;
            }
            else{
                cout << last << "\n" << flush;
            }
        }
}
