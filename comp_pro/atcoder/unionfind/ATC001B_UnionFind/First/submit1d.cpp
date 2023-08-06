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


// UnionFind 1.3
class UnionFind{
    public:
        UnionFind() = default;
        explicit UnionFind(size_t n)
            :m_parents(n),m_sizes(n,1)
            {
                iota(m_parents.begin(),m_parents.end(),0);
            }
    int find(int j){
        if(m_parents[j]==j){
            return j;
        }
        return (m_parents[j]=find(m_parents[j]));
    }
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            // union by size 小さい方が子になる
            if(m_sizes[a] < m_sizes[b]){
                swap(a,b);
            }
            m_sizes[a]=m_sizes[a]+m_sizes[b];
            m_parents[b]=a;
        }
    }
    bool connected(int a,int b){
        return(find(a)==find(b));
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
/***
void showCont(int num,vector<int> &P,vector<int> &A,vector<int> &B){
    for(int j=0;j<num;j=j+1){
        if(P[j]==0){
            debug("* %d と %d を結合します\n",A[j],B[j]);
        }
        else{
            debug("* %d と %d が繋がっているか確認します\n",A[j],B[j]);
        }
    }
}
**/
int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    vector<int> P(Q);
    vector<int> A(Q);
    vector<int> B(Q);
    for(int j=0;j<Q;j=j+1){
        cin >> P[j] >> A[j] >> B[j];
    }
//    showCont(Q,P,A,B);
    UnionFind uf = UnionFind(N);
    for(int j=0;j<Q;j=j+1){
        if(P[j]==0){
            uf.merge(A[j],B[j]);
        }
        if(P[j]==1){
            bool ok=false;
            ok = uf.connected(A[j],B[j]);
            if(ok){
                cout << "Yes\n" << flush;
            }else{
                cout << "No\n" << flush;
            }
        }
    }
    return 0;
}
