#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int input){
    int result = 0;
    int surplus=input % 7;
    if(surplus == 0){
        return input;
    }

    int base_digit=input - input%10;
    for(int j=0;j<10;j++){
        result = base_digit + j;
        if(result % 7 == 0){
            return result;
        }
    }
    return result;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        int input_data=0;
        cin >> input_data;
        cout << solver(input_data) << "\n" << flush;
    }
    return 0;
}
