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
struct SegTreeProportinal{
    using FX = function<X(X,X)>;
    using FA = function<X(X,M)>;
    using FM = function<M(M,M)>;
    using FP = function<M(M,int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeProportinal(int n_,
                        FX fx_,FA fa_,FM fm_,FP fp_,
                        X ex_,M em_):
                        n(),fx(fx_),fa(fa_),fm(fm_),fp(fp_),
                        ex(ex_),em(em_),dat(n_ *4,ex),lazy(n_ *4,em)
                        {
                            int x=1;
                            while(x < n_){
                                x=x*2;
                            }
                            n=x;
                        }
    void set(int j,X x){
        dat[(n-1)+j]=x;
    }
    void build(void){
        for(int k=n-1;0<=k;k=k-1){
            dat[k]=fx(dat[2*k+1],dat[2*k+2]);
        }
    }
    void eval(int k,int len){
        if(lazy[k]==em){
            return;
        }
        if(k<n-1){
            lazy[k*2+1]=fm(lazy[k*2+1],lazy[k]);
            lazy[2*k+2]=fm(lazy[2*k+2],lazy[k]);
        }
        dat[k]=fa(dat[k],fp(lazy[k],len));
        lazy[k]=em;
    }
    void update(int a,int b,M x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]=fm(lazy[k],x);
            eval(k,r-l);
        }else if(a<r && l < b){
            int mid=(r+l)>>1;
            update(a,b,x,2*k+1,l,mid);
            update(a,b,x,2*k+2,mid,r);
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int a,int b,M x){
        update(a,b,x,0,0,n);
    }
    X query_sub(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r <= a || b <= l){
            return ex;
        }else if(a <= l && r <= b){
            return dat[k];
        }else{
            int mid=(l+r)>>1;
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
            if(j!=n-1)cout << ",";
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
    using X = long long;
    using M = long long;

    auto fx = [](X x1,X x2)->X{return x1+x2;};
    auto fa = [](X x,M m)->M{return m;};
    auto fm = [](M m1,M m2)->M{return m2;};
    auto fp = [](M m,long long n)->M {return m*n;};
    long long ex = 0;
    long long em = numeric_limits<int>::max();
    SegTreeProportinal<X,M> rsq(n,fx,fa,fm,fp,ex,em);
    vector<long long> ans;
    for(int j=0;j<q;j=j+1){
        int c;
        cin >> c;
        if(c==0){
            int s,t;
            long long val;
            cin >> s >> t >> val;
            rsq.update(s,t+1,val);
        }else{
            // rsq.print();
            int s,t;
            cin >> s >> t;
            long long val;
            val=rsq.query(s,t+1);
            ans.push_back(val);
        }
    }
    for(auto e:ans){
        cout << e << "\n" << flush;
    }
    return 0;
}
