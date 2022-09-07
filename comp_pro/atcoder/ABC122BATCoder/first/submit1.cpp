#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

const string STR="ACGT";

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(string &inStr){
    int result=0;
    int strlen=inStr.length();
    /** for(int ie=0;ie < strlen;ie=ie+1){
        for(int j=ie;j<strlen;j=j+1){
            // 文字列の調査開始
            bool ok=true;
            for(int k=j;k<strlen;k=k+1){
                if(STR.find(inStr[k])==string::npos){
                    ok=false;
                }
            }
            if(ok){
                int strleng=j-ie+1;
                if(result<strleng)
                    {
                        result=strleng;
                    }
            }
        }
    }**/
    for(int L=0;L<strlen;L=L+1){
        for(int R=L;R<strlen;R=R+1){
            bool ok=true;
            for(int pos=L;pos<=R;pos=pos+1){
                if(STR.find(inStr[pos])==string::npos){
                    ok=false;
                }
            }
            if(ok){
                if(result < R-L+1){
                    result = R-L+1;
                }
            }
        }
    }
    return result;
}


int main(void){
    initial();
    string inStr;
    cin >> inStr;
    cout << solver(inStr) << "\n" << flush;
    return 0;
}
