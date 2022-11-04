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

int main(void){
    int N;
    cin >> N;
    int SUM;
    cin >> SUM;
    vector<int> vec(N,0);
    for(int j=0;j<N;j++){
        cin >> vec[j];
    }
    vector<int> result;
    for(int bit=0;bit<1<<N;bit=bit+1){
        int psum=0;
        vector<int> _vec;
        debug("--- %d の場合を調べます ---\n",bit);
        for(int j=0;j<N;j=j+1)
            {
                int value = bit & (1<<j);
                debug("%d  & 1<<%d = %d\n",bit,j,value);
                if(value!=0){
                    debug("%d ではif文に適応しました\n",value);
                    psum = psum + vec[j];
                    _vec.push_back(vec[j]);
                    }
                else{
                    debug("%d ではif文にはじかれました\n",value);
                    }
            }   
        if(psum==SUM){
            debug("合計と一致しました\n");
            result = _vec;
            break;
        }
    }
    for(auto &x:result){
        cout << x << " ";
    }
    cout << "\n" << flush;
    return 0;
}