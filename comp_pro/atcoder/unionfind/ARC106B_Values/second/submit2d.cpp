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
int N;// 頂点の数
int M;// 辺の数
vector<ll> A;// 初期値
vector<ll> B;// 目標値

class UnionFind{
    public:
        UnionFind() = default;
        explicit
            UnionFind(size_t n)
                : m_parents(n),
                m_sizes(n,1)
                {
                    iota(m_parents.begin(),m_parents.end(),0);
                }
        int find(int j){
            if(m_parents[j]==j){
                return j;
            }
            int nowj=m_parents[j];
            m_parents[j] = find(nowj); // さらに上の親を探し、あてはめる
            return m_parents[j];
        }
        void merge(int a,int b){
            a = find(a);
            b = find(b);
            if(a!=b){
                // TODO: m_size->m_sizesに修正
                // 2023-08-10 19:30:00
                if(m_sizes[a]<m_sizes[b]){
                    debug("m_sizes[%d] = %d < m_sizes[%d] = %dのため,%d<->%d\n",
                    a,m_size[a],a,m_size[b],a,b);
                    swap(a,b);
                }
                m_sizes[a]=m_sizes[a]+m_sizes[b];
                m_parents[b]=a;
            }
        }
        bool same(int a,int b){
            bool ok = (find(a) == find(b));
            return ok;
        }
        int size(int j){
            return m_sizes[find(j)];
        }
    private:// 具体的な数と中身はクラスの初期化時にセットされる
        vector<int> m_parents;
        vector<int> m_sizes;
};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> M;
    A.resize(N);
    B.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    for(int j=0;j<N;j=j+1){
        cin >> B[j];
    }
    UnionFind uf = UnionFind(N);
    for(int j=0;j<M;j=j+1){
        int c,d;
        cin >> c >> d;
        uf.merge(c-1,d-1);
    }
    for(int j=0;j<N;j=j+1){
        int x = uf.find(j);
        debug("%3dの根->%3d\n",j,x);
    }
    return 0;
}
