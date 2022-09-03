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


int devCounter(int &X){
    vector<int> D;
    for(int ei=1;ei <= int(sqrt(X));ei=ei+1){
        if(X%ei==0){
            D.push_back(ei);
            if(ei*ei!=X){
                D.push_back(X/ei);
            }
        }
    }
    sort(D.begin(),D.end());
    return int(D.size());
}

int main(void){
    initial();
    int N;
    int result=0;
    cin >> N;
    for(int ie=1;ie<N+1;ie=ie+2)
    {
        int check;
        check=devCounter(ie);
        if(check==8){
            result = result+1;
        }
    }
    cout << result << "\n" <<flush;
    return 0;
}
