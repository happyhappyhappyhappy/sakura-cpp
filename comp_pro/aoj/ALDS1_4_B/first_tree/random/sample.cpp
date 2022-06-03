#include<bits/stdc++.h>
#include<random>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// constexpr int MIN=1;
// constexpr int MAX=100;
// constexpr int RAND_NUMS_TO_GENERATE=20;

int main(void){
    cout << "MIN MAX COUNT\n" << flush;
    int MIN,MAX,RAND_NUMS_TO_GENERATE;
    cin >> MIN;
    cin >> MAX;
    cin >> RAND_NUMS_TO_GENERATE;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN,MAX);

    for(int j=0;j<RAND_NUMS_TO_GENERATE;j++){
        cout << distr(eng) << " ";
    }
    cout  << "\n" << flush;
    return 0;
}