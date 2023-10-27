#include<bits/stdc++.h>

using namespace std;

int N,Q;
const int INF = INT_MAX;
struct LazySegmentTree{
private:
    int n;
    vector<int> node;
    vector<int> lazy;
    vector<bool> lazyFlag;
public:
    LazySegmentTree(vector<int> v){
        int sz=(int)v.size();
        n=1;
        while(n<sz){
            n=n*2;
        }
        node.resize(2*n-1);
        lazy.resize(2*n-1,INF);
        lazyFlag.resize(2*n-1,false);
        for(int j=0;j<sz;j=j+1){
            node[(n-1)+j]=v[j];
        }
        for(int j=n-2;0<=j;j=j-1){
            node[j]=min(node[j*2+1],node[j*2+2]);
        }

    }
    void lazyEvaluate(int k,int l,int r){
        if(lazyFlag[k]==true){
            node[k]=lazy[k];
            if(1 < r - l){
                lazy[k*2+1]=lazy[k*2+2]=lazy[k];
                lazyFlag[k*2+1]=lazyFlag[k*2+2]=true;
            }
            lazyFlag[k]=false;
        }
    }
    void update(int a,int b,int x,int k=0,int l=0,int r=-1){
        if(r < 0){
            r = n;
        }
        lazyEvaluate(k,l,r);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k]=x;
            lazyFlag[k]=true;
            lazyEvaluate(k,l,r);
        }else{
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=min(node[2*k+1],node[2*k+2]);
        }
    }
    int find(int a,int b,int k=0,int l=0,int r=-1){
        if(r < 0){
            r = n;
        }
        lazyEvaluate(k,l,r);
        if(b <= l || r <= a){
            return INF;
        }
        if(a <= l && r <= b){
            return node[k];
        }
        int vl = find(a,b,2*k+1,l,(l+r)/2);
        int vr = find(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
};
int main(){
    cin >> N >> Q;
    LazySegmentTree seg(vector<int>(N,INF));
    for(int j=0;j<Q;j=j+1){
        int query;
        cin >> query;
        if(query == 0){
            int s,t,x;
            cin >> s >> t >> x;
            seg.update(s,t+1,x);
        }
        else{
            int s,t;
            cin >> s >> t;
            cout << seg.find(s,t+1) << endl;
        }
    }
    return 0;
}
