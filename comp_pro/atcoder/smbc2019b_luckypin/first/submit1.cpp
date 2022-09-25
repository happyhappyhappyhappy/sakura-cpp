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

bool pinCheck(string &base,int j,int k,int m){
    int strLeng=base.length();
    int j_pos,k_pos,m_pos;
    string j_c = to_string(j);
    string k_c = to_string(k);
    string m_c = to_string(m);
    // cout << j_c << k_c << m_c << "\n" << flush;
    j_pos=base.find(j_c);
    if(j_pos==string::npos){
        return false;
    }
    // k,mを検索
    // TODO: pos = s.find(find_word, pos + find_word.length());
    return true;
    }

int solver(string &base){
    int result=0;
    for(int j=0;j<10;j=j+1){
        for(int k=0;k<10;k=k+1){
            for(int m=0;m<10;m=m+1){
                // PIN候補の作成
                // baseから作成出来るかチェック
                if(pinCheck(base,j,k,m)){
                    result=result+1;
                }
            }
        }
    }
    return result;
}

int main(void){
    initial();
    int N;
    string S;
    cin >> N >> S;
    cout << solver(S) << "\n" << flush; 
    return 0;
}
