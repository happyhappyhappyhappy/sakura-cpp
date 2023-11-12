#include<bits/stdc++.h>
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
template<class Monoid,class Action> struct LazySegmentTree{
    using FuncOperator=function<Monoid(Monoid,Monoid)>;
    using FuncMapping = function<Monoid(Action,Monoid)>;
    using FuncComposition=function<Action(Action,Action)>;
    int N;
    FuncOperator OP;
    FuncMapping MAPPING;
    FuncComposition COMPOSITION;
    Monoid IDENTITY_MONOID;
    Action IDENTITY_ACTION;
    int log,offset;
    vector<Monoid> dat;
    vector<Action> lazy;
    LazySegmentTree(){}
    LazySegmentTree(int n,
                    const FuncOperator op,
                    const FuncMapping mapping,
                    const FuncComposition composition,
                    const Monoid &identity_monoid,
                    const Action &identity_action){
                        init(n,op,mapping,composition,identity_action,identity_monoid);
                    }
    LazySegmentTree(const vector<Monoid> &v,
    const FuncOperator op,
    const FuncMapping mapping,
    const FuncComposition composition,
    const Monoid &identity_monoid,
    const Action &identity_action){
        init(v,op,mapping,composition,identity_monoid,identity_action);
    }
    void init(int n,
            const FuncOperator op,
            const FuncMapping mapping,
            const FuncComposition composition,
            const Monoid &identity_monoid,
            const Action &identity_action){
                N=n;
                OP=op;
                MAPPING=mapping;
                COMPOSITION=composition;
                IDENTITY_MONOID = identity_monoid;
                IDENTITY_ACTION = identity_action;
                log = 0;
                offset = 1;
                while(offset<N){
                    log=log+1;
                    offset=offset<<1;
                }
                dat.assign(offset*2,IDENTITY_MONOID);
                lazy.assign(offset*2,IDENTITY_ACTION);
            }
    void init(const vector<Monoid> &v,
    const FuncOperator op,
    const FuncMapping mapping,
    const FuncComposition composition,
    const Monoid &identity_monoid,
    const Action &identity_action){
        init((int)v.size,op,mapping,composition,identity_monoid,identity_action);
        build(v);
    }
    // TODO :: TODO ::2023-11-12 19:33:30 L65から
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
