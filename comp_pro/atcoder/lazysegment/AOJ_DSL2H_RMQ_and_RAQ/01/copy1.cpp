#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct RMQ{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat,lazy;
    RMQ(int n_):n(),dat(n_ *4,INF),lazy(n_ *4,0){
        int x = 1;
        while(x < n_){
            x = x*2;
        }
        n = x;
    }
    void set(int i,T x){
        dat[i+(n-1)]=x;
    }
    void build(){
        for(int k = n-1;0 <= k;k=k-1){
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    void eval(int k){
        if(lazy[k]==0){
            return;
        }
        if(k < n-1){
            lazy[k*2+1]=lazy[k*2+1]+lazy[k];
            lazy[k*2+2]=lazy[k*2+2]+lazy[k];
        }
        dat[k]=dat[k]+lazy[k];
        lazy[k]=0;
    }
    void add(int a,int b,T x,int k,int l,int r){
        eval(k);
        if(a <= l && r <= b){
            lazy[k]=lazy[k]+x;
            eval(k);
        }
        else if(a < r && l < b){
            add(a,b,x,k*2+1,l,(l+r)/2);
            add(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    void add(int a,int b,T x){
        add(a,b,x,0,0,n);
    }
    T query_sub(int a,int b,int k,int l,int r){
        eval(k);
        if(r <= a || b <= l){
            return INF;
        }else if(a<=l && r <= b){
            return dat[k];
        }
        else{
            T vl=query_sub(a,b,k*2+1,l,(l+r)/2);
            T vr=query_sub(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    T query(int a,int b){
        return query_sub(a,b,0,0,n);
    }
    T find_rightest(int a,int b,int x){
        return find_rightest_sub(a,b,x,0,0,n);
    }
    T find_leftest(int a,int b,int x){
        return find_leftest_sub(a,b,x,0,0,n);
    }
    T find_rightest_sub(int a,int b,int x,int k,int l,int r){
        eval(k);
        if(x < dat[k] || r <= a || b <= l){
            return a-1;
        }else if(n-1 <= k){
            return (k-(n-1));
        }
        else{
            int vr = find_rightest_sub(a,b,x,2*k+2,(l+r)/2,r);
            if(vr != a-1){
                return vr;
            }else{
                return find_rightest_sub(a,b,x,2*k+1,l,(l+r)/2);
            }
        }
    }
    T find_leftest_sub(int a,int b,int x,int k,int l,int r){
        eval(k);
        if(x < dat[k] || r <= a || b <= l){
            return b;
        }
        else if(n-1 <= k){
            return (k-(n-1));
        }else{
            int vl =find_leftest_sub(a,b,x,2*k+1,l,(r+l)/2);
            if (vl != b){
                return vl;
            }else{
                return find_leftest_sub(a,b,x,2*k+2,(r+l)/2,r);
            }
        }
    }
    inline T operator[](int a){
        return query(a,a+1);
    }
    void print(){
        for(int i=0;i<n;i=i+1){
            cout << (*this)[i];
            if(i!=n){
                cout << ",";
            }
        }
        cout << "\n" << flush;
    }
};

int main(){
    int n,q;
    cin >> n >> q;
    RMQ<int> rmq(n);
    for(int i=0;i<n;i=i+1){
        rmq.set(i,0);
    }
    rmq.build();
    vector<int> ans;
    for(int i=0;i<q;i=i+1){
        int c;
        cin >> c;
        if(c == 0){
            int s,t,x;
            cin >> s >> t >> x;
            rmq.add(s,t+1,x);
        }else if(c == 1){
            int s,t;
            cin >> s >> t;
            int x;
            x = rmq.query(s,t+1);
            ans.push_back(x);
        }
    }
    for(auto i:ans){
        cout << i << "\n" << flush;
    }
}
