#include<bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
const long long INF=1LL<<60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long solver(int &N,vector<long long> &HIGH,vector<long long> &SPEED){
    long long result=0;
    long long top_pos=INF;
    long long low_pos=0;
    while(abs(top_pos-low_pos)>1){
        bool ok=true;
        long long mid=(top_pos+low_pos)/2;
        vector<long long> TIME(N,0);// midまでの残り時間
        for(int j=0;j<N;j++){
            if(mid<HIGH[j]){ // もうmidを超えている場合
                ok = false; // 初期化0のまま以降の処理は無効
            }
            {
                TIME[j]=(mid-HIGH[j])/SPEED[j];
            }
        }
        sort(TIME.begin(),TIME.end());
        for(int j=0;j<N;j++){ // 0[秒]からN-1[秒]まで打とうとしてみる
            if(TIME[j]<j){}// もし、もうリミットを TODO: この時false
        }
    }
    return result;
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<long long> H(N);
    vector<long long> S(N);
    for(int j=0;j<N;j++){
        cin >> H[j] >> S[j];
    }
    cout << solver(N,H,S);
    return 0;
}
