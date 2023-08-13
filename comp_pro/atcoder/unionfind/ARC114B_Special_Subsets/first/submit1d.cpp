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
const ll MOD=998244353
// グローバル変数
vector<ll> pow2tbl;

// UnionFindの定義
class UnionFind{
    public:
        UnionFind()=default;
        explicit UnionFind(size_t n)
            : m_parents(n)
            ,m_sizes(n,1)
            {
                iota(m_parents.begin(),m_parents.end(),0);
            }
        int find(int j){
            if(m_parents[j] == j){
                return j;
            }
            m_parents[j]=find(m_parents[j]);
            return m_parents[j];
        }
        int merge(int a,int b){
            a=find(a);
            b=find(b);
            if(a!=b){
                if(m_sizes[a]<m_sizes[b]){
                    swap(a,b);
                }
                m_sizes[a]=m_sizes[a]+m_sizes[b];
                m_parents[b]=a;
            }
        }
        bool connected(int a,int b){
            int aroot=find(a);
            int broot=find(b);
            bool ok = (aroot==broot);
            return ok;
        }
        int size(int j){
            return m_sizes[find(j)];
        }
    private:
        vector<int> m_parents;
        vector<int> m_sizes;
};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void mkPow2Tbl(int N){
    pow2tbl.resize(N);
    pow2tbl[0]=1;
    // TODO ここから2の階乗のテーブルを作っていく＋作成時に余りを求めオーバーフローを防ぐ
    // 2023-08-13 19:32:49
}
int main(void){
    initial();
    int N;
    cin >> N;
    mkPow2Tbl(N);
    return 0;
}
