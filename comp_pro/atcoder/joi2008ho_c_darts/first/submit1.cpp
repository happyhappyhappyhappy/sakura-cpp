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

int upper_bound2(vector<ll> &S,int key){
    int right=S.size();
    int left=-1;

    while(right-left>1){
        int mid = (right+left)*pow(2,-1);
        if(key < S[mid]){
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
    cin >> N >> M;
    vector<ll> P(N);

// 2回の合計は全部列挙する

    for(int j=0;j<N;j=j+1){
        cin >> P.at(j);
    }
    P.push_back(0);
    vector<ll> doubleP; // 2回Pに当てたときの結果一覧
    for(int j=0;j<P.size();j=j+1){
        for(int k=0;k<P.size();k=k+1){
            doubleP.push_back(P.at(j)+P.at(k));
        }
    }
    sort(doubleP.begin(),doubleP.end());
    ll answer=0;
    for(int j=0;j<doubleP.size();j++){
        ll a;
        a=doubleP[j];
        int pos;
        pos = upper_bound2(doubleP,M-a);
        if(pos == 0){
            continue;
        }
        answer = max(answer,doubleP[j]+doubleP[pos-1]);
    }
    cout << answer << "\n" << flush;
    return 0;
}

