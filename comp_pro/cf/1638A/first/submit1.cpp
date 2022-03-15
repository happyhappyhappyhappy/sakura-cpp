#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool okperm(vector<int>& v){

    bool result=true;
    for(auto x:v){
        cout << x << " " ;
    }
    cout << "\n" << flush;
    int v_size=v.size();
    // vector<int> answer(v_size);
    for(int j = 0;j<v_size;j++){
        if(v.at(j) != j+1){
            cout << "要素 :" << v.at(j) << " が " << j+1
            << "ではありません";
            result = false;
            break;
        }
    }
    return result;
}
void solve(vector<int>& v){
    int v_size=v.size();
}
int main(void){
    initial();
    int testcase=1;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        int element;
        cin >> element;
        vector<int> v(element);
        // TODO: 値を入れる処理を行ってください
        bool needmod=false;
        needmod = okperm(v);
        /**
        if(needmod){
            solve(v);
            }
        for(auto x:v){
            cout << x << " ";
        }
        cout << "\n" << flush;
        v.clear();
        }
        **/
       if(needmod!=true){
           cout << "入れ替えが「必要」です" << "\n" << flush;
       }else{
           cout << "入れ替えは「要りません」" << "\n" << flush;
       }
    }
    return 0;
}
