#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define STREND std::string::npos

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool pinCheck(string &base,int j,int k,int m){
    std::string::size_type j_pos,k_pos,m_pos;
    string j_c = to_string(j);
    string k_c = to_string(k);
    string m_c = to_string(m);
    j_pos=base.find(j_c);
    if(j_pos==STREND){
        return false;
    }
    // kを検索
    k_pos=base.find(k_c,j_pos+j_c.length());
    if(k_pos==STREND){
        return false;
    }
    // m を検索
    m_pos=base.find(m_c,k_pos+k_c.length());
    if(m_pos==STREND){
        return false;
    }
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
