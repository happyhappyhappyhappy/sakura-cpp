#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__);

template<class X>bool chmin(X &a,const X &b)
{
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(vector<vector<ll>> &A,ll &N,ll &M){
    ll answer=0;
    for(ll sng1=0;sng1<M;sng1=sng1+1){
        for(ll sng2=sng1+1;sng2<M;sng2=sng2+1){
            ll nowScore=0;
            for(ll person=0;person<N;person=person+1){
                if(A[person][sng1] < A[person][sng2]){
                    nowScore=nowScore+A[person][sng2];
                }
                else{
                    nowScore=nowScore+A[person][sng1];
                }
            }
            chmin(answer,nowScore);
        }
    }
    return answer;
}

int main(void){
    initial();
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> A(N,vector<ll>(M));
    for(ll person=0;person<N;person=person+1){
        for(ll sng=0;sng<M;sng=sng+1){
            cin >> A[person][sng];
        }
    }
    cout << solver(A,N,M) << "\n" << flush;
    return 0;
}
