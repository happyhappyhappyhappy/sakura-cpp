#include<bits/stdc++.h>
#include <atcoder/lazysegtree>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
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
struct S{
    long long value;
    int size;
};
using F = long long;
S op(S a,S b){
    return {a.value+b.value,a.size+b.size};
}
S e(){
    return {0,0};
}
S mapping(F f,S x){
    return {x.size*f+x.value,x.size};
}
F composition(F f,F g){
    return f+g;
}
F id(){return 0;}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    // vector<S> v(N,{0,1});
    // atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>seg(v);
    // atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    int N, Q;
    cin >> N >> Q;
    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    while(Q--){
        int tp;
        cin >> tp;
        if(tp==0){
            int s,t,x;
            cin >> s >> t >> x;
            s = s-1;
            t = t-1;
            seg.apply(s,t+1,x);
        }
        else{
            int s,t;
            cin >> s >> t;
            s = s-1;
            t = t-1;
            int val;
            val = seg.prod(s,t+1).value;
            cout << val << "\n" << flush;
        }
    }
    return 0;
}
