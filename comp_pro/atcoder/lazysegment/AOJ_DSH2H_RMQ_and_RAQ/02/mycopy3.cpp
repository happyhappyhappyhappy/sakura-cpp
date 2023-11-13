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
    void init(int n,
                const FuncOperator op,
                const FuncMapping mapping,
                const FuncComposition composition,
                const Monoid &identity_monoid,
                const Action &identity_action){
        N = n;
        OP = op;
        MAPPING = mapping;
        COMPOSITION = composition;
        IDENTITY_MONOID = identity_monoid,
        IDENTITY_ACTION = identity_action;
        log = 0;
        offset = 1;
        while(offset < N){
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
    void build(const vector<Monoid> &v){
        assert(N == (int)v.size());
        for(int j=0;j<N;j=j+1){
            dat[j+offset]=v[j];
        }
        for(int k=offset-1;k>0;k=k-1){
            pull_dat(k);
        }
    }
    int size() const{
        return N;
    }
    // この問題の場合は比較して小さい値を上へ渡す
    void pull_dat(int k){
        dat[k]=OP(dat[k*2],dat[k*2+1]);
    }
    void apply_lazy(int k,const Action &f){
        dat[k] = MAPPING(f,dat[k]);
        if(k < offset){
            lazy[k]=COMPOSITION(f,lazy[k]);
        }
    }
    void push_lazy(int k){
        if(lazy[k] == IDENTITY_ACTION){
            return;
        }
        // 下の値へ渡す
        apply_lazy(k*2,lazy[k]);
        apply_lazy(k*2+1,lazy[k]);
        lazy[k]=IDENTITY_ACTION;
    }
    void pull_dat_deep(int k){
        for(int h=1;h<=log;h=h+1){
            int pdd=k>>h;
            pull_dat(pdd);
        }
    }
    void push_lazy_deep(int k){
        for(int h = log;1 <= h;h=h-1){
            int pld=k>>h;
            push_lazy(pld);
        }
    }
    void set(int j,const Monoid &v){
        assert(0 <= j && j < N);
        int k=j+offset;
        push_lazy_deep(k);
        dat[k]=v;
        pull_dat_deep(k);
    }
    Monoid get(int j){
        assert(0 <= j && j < N);
        int k=j+offset;
        push_lazy_deep(k);
        return dat[k];
    }
    Monoid operator[](int j){
        return get(j);
    }
    void apply(int j,const Action &f){
        assert(0 <= j && j < N);
        int k=j+offset;
        push_lazy_deep(k);
        // ここでは区間和なので f(与えたい数) + dat[k]
        dat[k]=MAPPING(f,dat[k]);
        pull_dat_deep(k);
    }
    void apply(int l,int r,const Action &f){
        assert(0<=l && l <= r && r <= N);
        if(l==r)return;
        l = l+offset;
        r = r+offset;
        for(int h = log;1<= h;h=h-1){
            if(((l >> h)<<h)!=l){
                // lをビットと見た場合右から数えて h ビット目が0であるときです。
                push_lazy(l >> h);
            }
            if(((r >> h)<<h)!=r){
                // rをビットと見た場合右から数えて h ビット目が0であるときです。
                push_lazy((r-1)>>h);
            }
        }
        int original_l=l;
        int original_r=r;
        for(;l<r;l=l>>1,r=r>>1){
            if(l & 1)apply_lazy(l++,f);
            if(r & 1)apply_lazy(--r,f);
        }
        l = original_l;
        r = original_r;
        for(int h=1;h<=log;h=h+1){
            if(((l>>h)<<h)!=l){
                pull_dat(l>>h);
            }
            if(((r>>h)<<h)!=r){
                pull_dat((r-1)>>h);
            }
        }
    }
    Monoid prod(int l,int r){
        assert(0 <= l && l <= r && r <= N);
        if(l==r)return IDENTITY_MONOID;
        l=l+offset;
        r=r+offset;
        for(int h=log;1 <= h;h=h-1){
            if(((l>>h)<<h)!=l){
                push_lazy(l>>h);
            }
            if(((r>>h)<<h)!=r){
                push_lazy(r>>h);
            }
        }
        Monoid val_left=IDENTITY_MONOID;
        Monoid val_right=IDENTITY_MONOID;
        for(; l<r;l=l>>1,r=r>>1){
            if(l&1){
                // OPはここでは二つの最小値をval_leftに与える
                val_left=OP(val_left,dat[l++]);
            }
            if(r&1){
                val_right=OP(dat[--r],val_right);
            }
        }
        return OP(val_left,val_right);
    }
    Monoid all_prod(){
        return dat[1];
    }
    friend ostream& operator << (ostream &s,LazySegmentTree seg){
        for(int j=0;j<(int)seg.size();j=j+1){
            s << seg[j];
            if(j != (int)seg.size()-1){
                s << " ";
            }
        }
        return s;
    }
    void dump(){
        for(int j=0;j<=log;j=j+1){
            for(int k=(1<<j);k<(1<<(j+1));k=k+1){
                cout << "{" << dat[k] << "," << lazy[k] << "}";
            }
            cout << "\n" << flush;
        }
    }
};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    vector<long long> v(N,0);
    // identity_monoid 絶対正解にはならない答え。ここでは最小値
    const long long identity_monoid = (1LL<<31)-1;
    // identity_action lazyの初期値
    const long long identity_action = 0;
    // operation 最後に求めたい物->最小値
    auto op = [&](long long x,long long y){
        return min(x,y);
    };
    // mapping アクセスしたい物 指定した値fを 各データxに足す
    auto mapping = [&](long long f,long long x){
        return f+x;
    };
    // composition mapping との違いは? lazyを足し合わせる?
    auto composition = [&](long long g,long long f){
        return g+f;
    };
    LazySegmentTree<long long,long long> seg(v,op,mapping,composition,
    identity_monoid,identity_action);
    while(Q--){
        int type,s,t;
        cin >> type >> s >> t;
        t = t+1;
        if(type == 0){
            long long x;
            seg.apply(s,t,x);
        }else{
            long long val;
            val = seg.prod(s,t);
            cout << val << "\n" << flush;
        }
    }
    return 0;
}
