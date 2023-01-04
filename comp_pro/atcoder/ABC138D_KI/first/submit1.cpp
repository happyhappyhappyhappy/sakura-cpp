#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>> ;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

// グローバル変数
int N,Q;
Graph G;
// 興味用カウンター 提出時には消す
int counter;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(){
    debug("Gの今回の情報です\n");
    for(int j=0;j<G.size();j=j+1){
        debug("%d : ",j);
        for(int k=0;k<G[j].size();k=k+1){
            debug(" %d",G[j][k]);
        }
        debug("\n");
    }
}
void showRES(vector<ll> &X){
    debug("現在のRESの内容です\n");
    for(int j=0;j<X.size();j=j+1){
        debug("%lld ",X[j]);
    }
    debug("\n");
}

void solver(int now,int sended,vector<ll> &res){
    if(sended!=-1){
        res[now]=res[now]+res[sended];
        // debug("--- now %d の時の resの中身です ---\n",now);
        // showRES(res);
        counter = counter+1;
    }
    // 今の(now)根に繋がる根をチェックする。もし元の物と同じ場合はもう
    // 根がないので終了
    int next_seeds=G[now].size();
    for(int j=0;j<next_seeds;j=j+1){
        if(sended==G[now][j]){
            // debug("元の根にしかつながらないので完了します\n");
            continue;
        }
        // debug("次は %d から %d に伝播します\n",now,G[now][j]);
        solver(G[now][j],now,res);
    }
}

int main(void){
    initial();
    cin >> N >> Q;
    G.assign(N,vector<int>());
    for(int j=0;j<N-1;j=j+1){
        int a,b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // showG();
    vector<ll> RES(N,0);
    for(int j=0;j<Q;j=j+1){
        int a,b;
        cin >> a >> b;
        a = a-1;
        RES[a] = RES[a]+b;
    }
    // showRES(RES);
    solver(0,-1,RES);
    for(int j=0;j<N;j=j+1){
        cout << RES[j] << " " ;
    }
    cout << "\n" << flush;
    // debug("計算カウントの結果は %d 回でした\n",counter);
    return 0;
}

