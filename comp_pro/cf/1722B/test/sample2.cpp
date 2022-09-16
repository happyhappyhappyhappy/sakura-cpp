#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){
    string X;
    string org="A";
    string tgt="B";
    cin >> X;
    cout << "変更前: " << X << "\n" << flush;
    std::string::size_type pos=0;
    while((pos=X.find(org,pos))!=string::npos){
        X.replace(pos,org.length(),tgt);
        // 見つかった箇所,該当の長さ分,入れたい文字
        pos=pos+tgt.length(); // 入れた文字分記録して次を探しに行く
    }
    cout << "変更後: " << X << "\n" << flush;

    return 0;
}