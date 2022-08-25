#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int lower_bound_m(vector<ll> &X,ll key){
    int right=X.size();
    int left=-1;
    while(abs(right-left)>1){
        int mid=(right+left)/2;
       // if(key < X[mid]){
if(key <= X[mid]){ // TODO これするとめぐる式lowになるので確認
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return right;
}

int main(void){
    initial();
    int N;
    ll M;
    vector<ll> P;
    P.push_back(0);
    cin >> N >> M;
    for(int j=0;j<N;j=j+1){
        ll num;
        cin >> num;
        P.push_back(num);
    }
    vector<ll> D2; // ダーツを二回投げて得られる点数
    for(int j=0;j<P.size();j=j+1){
        for(int k=0;k<P.size();k=k+1){
            D2.push_back(P[j]+P[k]);
        }
    }
    sort(D2.begin(),D2.end());
    ll answer=0;
    for(long long int j=0;j<D2.size();j=j+1){
        int pos=lower_bound_m(D2,M-D2[j]);
        if(pos==0){ // M突破しているから0点しかない
            continue;
        }
        pos = pos - 1;
        answer=max(answer,D2[j]+D2[pos]);
    }
    cout << answer << "\n" << flush;
    return 0;
}
