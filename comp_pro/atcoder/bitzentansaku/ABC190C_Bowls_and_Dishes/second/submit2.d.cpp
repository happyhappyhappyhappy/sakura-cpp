#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}

// 大域変数→変数は問題に従う
int N; // 皿の数
int M; // 条件の数
int K; // 参加者の人数
vector<int> A; // 条件確認皿1
vector<int> B; // 条件確認皿2
// 同一要素番号 で A < B
vector<int> C; // 参加者がボールを置く皿1
vector<int> D; // 参加者がボールを置く皿2
// 同一要素番号で C < D

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showData(void){
    debug("----条件一式----\n");
    for(int j=0;j<M;j=j+1){
        debug("%d -> %d and %d\n",j+1,A[j],B[j]);
    }
    debug("----投入皿一式(ママ)----\n");
    for(int j=0;j<K;j=j+1){
        debug("%d -> %d or %d \n",j+1,C[j],D[j]);
    }
}
string bitPat(int X){
    string ans="";
    for(int j=0;j<K;j=j+1){
        int bitFlag=(X>>j)&1;
        if(bitFlag){
            ans=ans+"D";
        }
        else{
            ans=ans+"C";
        }
    }
    return ans;
}
int solver(void){
    int ans=0;
    // showData();
    for(int bit=0;bit<(1<<K);bit=bit+1){
        // K 人ボックス投入
        // 具体的な皿。Dにすると別の大域変数になるのでNG
        // また各自が入れる皿、条件の皿を0-indexにするとややこしいため1-indexにする
        // 0 番はダミー
        vector<int> BOX(N+1,0);
        string bitp=bitPat(bit);
        debug("bit パターン : %s\n",bitp.c_str());
        for(int j=0;j<K;j=j+1){
            int selFlug=(bit>>j)&1;
            if(selFlug==1){
                debug("%d番目の人は Dのさらに入れる\n",j+1);
                BOX[D[j]]=BOX[D[j]]+1;
            }
            else{
                debug("%d番目の人は Cのさらに入れる\n",j+1);
                BOX[C[j]]=BOX[C[j]]+1;
            }
        }
        debug("%s 投入完了\n",bitp.c_str());
        debug("中身を見ます\n");
        for(int j=1;j<=N;j=j+1){
            debug(" %3d",BOX[j]);
        }
        debug("\n");
        int count=0;
        for(int j=0;j<M;j=j+1){
            if(BOX[A[j]]!=0 && BOX[B[j]]!=0){
                debug("%d 番目の条件が一致しました\n",j+1);
                count=count+1;
            }
        }
        chmax(ans,count);
    }
    return ans;
}
int main(void){
    initial();
    cin >> N >> M;
    A.assign(M,0);
    B.assign(M,0);
    for(int j=0;j<M;j=j+1){
        cin >> A[j] >> B[j];
    }
    cin >> K;
    C.assign(K,0);
    D.assign(K,0);
    for(int j=0;j<K;j=j+1){
        cin >> C[j] >> D[j];
    }
    cout << solver() << "\n" << flush;
    return 0;
}
