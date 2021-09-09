#include<bits/stdc++.h>
using namespace std;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    int N,K;
    char strbuf[1LL<15];
    const char* STR="DP[%d]=DP[%d]+abs(H[%d]-H[%d])\n";
    cin >> N >> K;
    cout << N << K << "\n";
    for(int j=0;j<N;j=j+1){
        for(int m=0;m<K;m=m+1){
            cout << "ROOP\n";
            int return_tmp;
            int from_pos,to_pos;
            from_pos = j;
            to_pos = j + m + 1;
            return_tmp = snprintf(strbuf,sizeof(strbuf),
            STR,
            to_pos,from_pos,to_pos,from_pos);
            cout << strbuf <<  " " << return_tmp <<"  OK\n";            
        }
    }
}