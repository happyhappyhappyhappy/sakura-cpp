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

int main(void){
    initial();
    int n;
    int x;
    int answer;
    cin >> n >> x;
    bool flag = true;
    while(flag){
        for(int j=1;j<=n;j=j+1){
            for(int k=j+1;k<=n;k=k+1){
                for(int m=k+1;m<=n;m=m+1){
                    int sum=j+k+m;
                    if(sum==x){
                        answer=answer+1;
                    }
                }
            }
        }
        // TODO: ここに答えを書く
        cin >> n >> x;
        if(n==0 && x==0){
            flag=false;
        }    
    }
    return 0;
}
