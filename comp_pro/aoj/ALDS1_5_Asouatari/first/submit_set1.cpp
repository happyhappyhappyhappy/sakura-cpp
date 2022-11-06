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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void initialSum(int count,vector<int> &A,set<int> &sumSet){
    for(int bit=0;bit < (1<<count);bit=bit+1){
        int inQ=0;
        for(int pos=0;pos<count;pos=pos+1){
            int filterCheck;
            filterCheck = bit & (1<<pos);
            if(filterCheck!=0){
                inQ = inQ + A[pos];
            }
        }
        sumSet.insert(inQ);
    }

}
int main(void){
    initial();
    int elem;
    cin >> elem;
    vector<int> A(elem);
    for(int j=0;j<elem;j=j+1){
        cin >> A[j];
    }
    set<int> sumSet;
    initialSum(elem,A,sumSet);
    int q_num;
    cin >> q_num;
    while(q_num--){
        int q;
        cin >> q;
        if(1 <= sumSet.count(q)){
            cout << "yes\n" << flush;
        }
        else{
            cout << "no\n" << flush;
        }
    }
    return 0;
}
