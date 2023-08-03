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

class UnionFind{
    public:
        UnionFind() = default;
    explicit UnionFind(size_t n): m_parents(n)
    {
        std::iota(m_parents.begin(),m_parents.end(),0);
    }
    int find(int x){
        if(m_parents[x]==x){
            return x;
        }
        m_parents[x]=find(m_parents[x]);
        return m_parents[x];
    }
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if ( a != b){
            m_parents[b]=a;
        }
    }
    bool connected(int a,int b){
        int a_base=find(a);
        int b_base=find(b);
        bool ok = (a_base==b_base);
        return ok;
    }
    private:
        vector<int> m_parents;
};


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    return 0;
}
