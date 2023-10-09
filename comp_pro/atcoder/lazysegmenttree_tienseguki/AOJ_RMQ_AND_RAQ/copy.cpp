#include<bits/stdc++.h>
using namespace std;
template<class Monoid,class Action> struct LazySegmentTree {
    using FuncOperator = function<Monoid(Monoid,Monoid)>;
    using FuncMapping = function<Monoid(Action,Monoid)>;
    using FuncComposition = function<Action(Action,Action)>;
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
                        init(n,op,mapping,composition,identity_monoid,identity_action);
                    }
    LazySegmentTree(const vector<Monoid> &v,
                    const FuncOperator op,
                    const FuncMapping mapping,
                    const FuncComposition composition,
                    const Monoid &identity_monoid,
                    const Action &identity_action){
                        init(v,op,mapping,composition,identity_monoid)
                    }
    void init(int n,
            const FuncOperator op,
            const FuncMapping mapping,
            const FuncComposition composition,
            const Monoid &identity_monoid,
            const Action &identity_action){
                N = n,
                OP = op,
                MAPPING = mapping,
                COMPOSITION = composition,
                IDENTITY_MONOID = identity_monoid,
                IDENTITY_ACTION = identity_action;
                log = 0,oppset = 1;
                while(offset < N) ++log,offset <<= 1;
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
        void build(const vector<Monoid> &v){
            assert(N == (int)v.size());
            for(int i=0;i<N;++i) dat[i+offset]=v[i];
            for(int k=offset-1;k>0;--k)pull_dat(k);
        }
        int size() const{
            return N;
        }
    void pull_dat(int k){
        dat[k]=OP(dat[k*2],dat[k*2+1])
    }
    void apply_lazy(int k,const Action &f){
        dat[k]=MAPPING(f,dat[k]);
        if(k < offset) lazy[k]=COMPOSITION(f,lazy[k]);
    }
    void push_lazy(int k){
        if(lazy[k]==IDENTITY_ACTION)return;
        apply_lazy(k*2,lazy[k]);
        apply_lazy(k*2+1,lazy[k]);
        lazy[k]=IDENTITY_ACTION;
    }
    void pull_dat_deep(int k){
        for(int h=1;h<=log;++h) pull_dat(k>>h);
    }
    void push_lazy_deep(int k){
        for(int h=log;h>=1;--h) push_lazy(k>>h);
    }
    void set(int i,const Monoid &v){
        assert(0<=i && i < N);
        int k=i+offset;
        push_lazy_deep(k);
        dat[k]=v;
        pull_dat_deep(k);
    }
    Monoid get(int i){
        assert(0 <= i && i < N);
        int k=i+offset;
        push_lazy_deep(k);
        return dat[k];
    }
    Monoid operator [] (int i){
        return get(i);
    }
    void apply(int i,const Action &f){
        assert(0 <= i && i < N);
        int k=i+offset;
        push_lazy_deep(k);
        dat[k]=MAPPING(f,dat[k]);
        pull_dat_deep(k);
    }
    void apply(int l,int r,const Action &f){
        assert(0 <= l && l <= r && r<=N);
        if ( l == r)return;
        l=l+offset,r=r+offset;
        // PEND:2023-10-09 12:12:02
    }
}
