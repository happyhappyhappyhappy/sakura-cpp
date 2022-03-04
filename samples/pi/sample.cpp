#include<bits/stdc++.h>
#include<math>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int counter=10;
    int j=counter;
    //for(int j=1;j<=counter;j=j+1){
    double answer;
    answer = circleference(j);
    cout << answer << "\n" << flush;
    // }
    return 0;
}
