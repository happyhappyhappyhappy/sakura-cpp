#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(string s){
    int result=-1;
    vector<int> box(2);
    box[0] = 0;
    box[1] = 0;
    for(int j=0;j<s.size();j++){
        if(s.at(j) == '0'){
            box[0] = box[0] + 1;
        }
        else{
            box[1] = box[1] + 1;
        }
    }
    if(box[0] == box[1]){
        result = box[0] - 1;
    }
    else{
        if(box[0] > box[1])
        {
            result = box[1];
        }
        else{
        result = box[0];
        }
    }
    return result;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int t=0;t<testcase;t++){
        int answer=-1;
        string inputs;
        cin >> inputs;
        answer = solver(inputs);
        cout << answer << "\n" << flush;
    }
    return 0;
}
