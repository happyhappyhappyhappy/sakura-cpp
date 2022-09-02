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
    int N;
    int result=0;
    cin >> N;
    for(int ie=1;ie<N+1;ie=ie+1){
        if((ie % 2) == 1){
            vector<int> d_group =cnt_divisor(ie);
            if(d_group.size() == 8){
                answer=answer+1;
            }
        }
    }
    cout << answer << "\n" <<flush;
    return 0;
}
