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
template<typename X,typename M>
struct SegTreeLazy{
    using FX = function<X(X,X)>;
    using FA = function<X(X,M)>;
    using FM = function<M(M,M)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazy(int n_,
                FX fx_,FA fa_,FM fm_,
                X ex_,M em_)
                : n(),fx(fx_),fa(fa_),fm(fm_),
                ex(ex_),em(em_),
                dat(n_ *4,ex),lazy(n_ *4,em){
                    int x=1;
                    while(x < n_){
                        x=x*2;
                    }
                    n = x;
                }
    void set(int j,X x){
        dat[(n-1)+j]=x;
    }
    void build(){
        for(int k=n-2;0<=k;k=k-1){
            dat[k]=fx(dat[2*k+1],dat[2*k+2]);
        }
    }
    void eval(int k){
        if(lazy[k]==em){
            return;
        }
        if(k<n-1){
            lazy[k*2+1]=fm(lazy[k*2+1],lazy[k]);
            lazy[k*2+2]=fm(lazy[k*2+2],lazy[k]);
        }
        dat[k]=fa(dat[k],lazy[k]);
        lazy[k]=em;
    }
    void update(int a,int b,M x,int k,int l,int r){
        eval(k);
        if(a<=l && r<= b){
            lazy[k]=fm(lazy[k],x);
            eval(k);
        }else if(a < r && l < b){
            int mid=(r+l)>>1;
            update(a,b,x,k*2+1,l,mid);
            update(a,b,x,k*2+2,mid,r);
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int a,int b,M x){
        update(a,b,x,0,0,n);
    }
    X query_sub(int a,int b,int k,int l,int r){
        eval(k);
        if(r <= a || b <= l){
            return ex;
        }
        else if(a <= l && r <= b){
            return dat[k];
        }else{
            int mid=(r+l)>>1;
            X vl=query_sub(a,b,2*k+1,l,mid);
            X vr=query_sub(a,b,2*k+2,mid,r);
            return fx(vl,vr);
        }
    }
    X query(int a,int b){
        return query_sub(a,b,0,0,n);
    }
    inline X operator[](int a){
        return query(a,a+1);
    }
    void print(){
        for(int j=0;j<n;j=j+1){
            cout << (*this)[j];
            if(j!=n-1)cout<<",";
        }
        cout << "\n" << flush;
    }
};
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int n,q;
    cin >> n >> q;
    using X = int;
    using M = int;
    auto fx = [](X x1,X x2)->
                X {
                    if(x1 < x2){
                        return x1;
                    }else{
                        return x2;
                    }
                };
    auto fa = [](X x,M m)-> X{return m;};
    auto fm = [](M m1,M m2)->M{return m2;};
    int ex = numeric_limits<int>::max();
    int em = numeric_limits<int>::max();
    SegTreeLazy<X,M> rmq(n,fx,fa,fm,ex,em);
    vector<int> ans;
    for(int j=0;j<q;j=j+1){
        int c;
        cin >> c;
        if(c==0){
            int s,t,val;
            cin >> s >> t >> val;
            rmq.update(s,t+1,val);
        }
        else{
            int s,t,val;
            cin >> s >> t;
            // rmq.print();
            val = rmq.query(s,t+1);
            ans.push_back(val);
        }
    }
    for(auto e:ans){
        cout << e << "\n" << flush;
    }
    return 0;
}
