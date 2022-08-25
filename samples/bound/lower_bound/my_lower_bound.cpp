#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

bool isGood(vector<int> &a,int key,int pos){
    bool result=false;
    if(a[pos] >= key){
        result = true;
    }
    return result;
}

int my_binary_search(vector<int> &a,int key){
    int good=(int)a.size();
    int bad=-1;
    while(abs(good-bad)>1){
        cout << "Now Good: " << good << "\n";
        cout << "Now Bad : " << bad << "\n";

        int mid=(bad+good)/2;
        if(isGood(a,key,mid)){
            good=mid;
            cout << "Change Good " << good << "\n" << flush;
        }
        else{
            bad=mid;
            cout << "Change Bad " << bad << "\n" << flush;
        }
    }
    return good;
}

int main(void){
//    initial();
    vector<int> problem={1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
    int input;
    cin >> input;
    int result = my_binary_search(problem,input);
    cout << input << " -> Nearly is " << result << 
    " " << problem[result] << "\n" << flush;
    return 0;
}
