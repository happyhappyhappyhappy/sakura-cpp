#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
template< class T >
struct CumulativeSum {
  vector< T > data;

  CumulativeSum() = default;

  explicit CumulativeSum(size_t sz) : data(sz + 1, 0) {}

  void add(int k, const T &x) {
    data[k + 1] += x;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
    // for(int j=0;j<data.size();j=j+1){
    //     debug("%d ",data[j]);
    // }
    // debug("\n");
  }

  T fold(int r) const {
    if(r < 0) return 0;
    return data[min(r, (int) data.size() - 1)];
  }

  T fold(int l, int r) const {
    return fold(r) - fold(l);
  }
};

int main(void){
    int elemn ;
    cin >> elemn;
    vector<int> A(elemn);
    CumulativeSum<int> cs(elemn);
    for(int j=0;j<elemn;j=j+1){
        cin >> A[j];
        cs.add(j,A[j]);
    }
    cs.build();
    // for(int j=0;j<elemn;j=j+1){
    //     cout << A[j] << " ";
    // }
    // cout << "\n" << flush;
    int f1=cs.fold(3); // 2+7+8=17かな
    int f2=cs.fold(2,4); // 8+4=12かな
    cout << "cs.fold(3) = " << f1 << "\n" << flush;
    cout << "cs.fold(2,4) = " << f2 << "\n" << flush;
    return 0;
}

