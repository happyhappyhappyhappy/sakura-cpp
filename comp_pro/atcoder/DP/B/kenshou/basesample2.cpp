#include<bits/stdc++.h>

using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    ll BUFFERSIZE=1LL<<15;
    char strbuf[BUFFERSIZE];
    const char STRFMT[]="%d and %d\n";
    int N,K;
    initial();
    cin >> N >> K;
    int tmp = snprintf(strbuf,sizeof(strbuf),STRFMT,N,K);
    cout << strbuf << "\n";
    cout << "tmp = " << tmp << "\n"; 
    return 0;
}