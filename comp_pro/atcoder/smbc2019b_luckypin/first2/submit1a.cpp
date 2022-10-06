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

int solver(int &strleng,string &str){
    set<string> pins;
    for(int j=0;j<strleng;j=j+1){
        for(int k=j+1;k<strleng;k=k+1){
            for(int m=k+1;m<strleng;m=m+1){
                string make_now="";
                make_now=make_now+str.at(j);
                make_now=make_now+str.at(k);
                make_now=make_now+str.at(m);
                pins.insert(make_now);
            }
        }
    }
    return pins.size();
}

int main(void){
    initial();
    int strleng;
    string lucky;
    cin >> strleng;
    cin >> lucky;
    cout << solver(strleng,lucky) << "\n" << flush;    
    return 0;
}
