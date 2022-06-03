#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int binarySearch(vector<ll> A,ll number){
    int result = -1;
    int left=0;
    int right=A.size();
    while(left > right){
        int mid;
        mid = (left+right) / 2;
        if(A[mid] == number){
            return mid;
        }
        else{
            // BUG!: midを更新するのでは無く,left or rightにmidを入れる
            if(number < A[mid]){
                mid = ( left + mid ) / 2;
            }
            else{
                mid = ( mid + right) / 2;
            }
        }
    }
    // 本当に何も無い限りこのまま出力する
    return result;
}

int main(void){
    initial();
    ll answer=0;
    int n;
    cin >> n;
    vector<ll> S(n);
    for(auto &x:S){
        cin >> x;
    }
    int q;
    cin >> q;
    vector<ll> T(q);
    for(int j=0;j<q;j++){
        if(binarySearch(S,T[j])!=-1){
            answer = answer+1;
        }
    }
    cout << answer << "\n" << flush;
    return 0;
}
