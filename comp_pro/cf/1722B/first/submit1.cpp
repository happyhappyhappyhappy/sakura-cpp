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

void strChanger(string &str,string fromStr,string toStr){
    std::string::size_type pos=0;
    while((pos=str.find(fromStr,pos))!=string::npos){
        str.replace(pos,fromStr.length(),toStr);
        pos=pos+toStr.length();
    }
}

string solver(string &first,string &second){
    // 文字列置換 G,B-> X
    strChanger(first,"G","X");
    strChanger(first,"B","X");
    strChanger(second,"G","X");
    strChanger(second,"B","X");
    int judge=first.compare(second);
    if(judge == 0){
        return "YES";
    }
    else{
        return "NO";
    }
    return "NO";
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int ie=0;ie<testcase;ie=ie+1)
    {
        int str_len;
        cin >> str_len;
        string prob_str1;
        string prob_str2;
        cin >> prob_str1;
        cin >> prob_str2;
        string answer;
        answer = solver(prob_str1,prob_str2);
        cout << answer << "\n" << flush;
    }
    return 0;
}
