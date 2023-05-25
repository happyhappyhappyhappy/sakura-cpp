#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

// 与えられた整数を文字列として取得しバラバラにする

template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){
    string X;
    cin >> X;
    // ただ出力するだけ
    const char *pX = X.c_str();
    debug("デバッグ内 -> %s\n",pX);
    cout << "標準出力 -> " << X  << "\n" << flush;
    // Xの長さをしらべて一つずつ出力する
    int len = (int)X.size();
    for(int j=0;j<len;j=j+1){
        char x = X.at(j);
        debug(" %c",x);
    }
    debug("\n");
    // 存在する数で組み合わせを作成する
    for(int j=((1<<len)-1);j>0;j=j-1){
        vector<bool> B; // B->Chainにしよう
        for(int k=0;k<len;k=k+1){
            if((j>>k) & 1){
                B.push_back(true);
            }
            else{
                B.push_back(false);
            }
        }
        debug("%d -> ",j);
        for(int k=0;k<len;k=k+1){
            if(B[k]){
                debug(" select");
            }
            else{
                debug(" unselect");
            }
        }
        debug("\n");
    }
    return 0;
}
