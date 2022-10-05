#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){

    string str="123456789";
    for(int ie=0;ie<str.length();ie=ie+1){
        char nowStr = str.at(ie);
        // int atoi_str = str.at(ie) - '0' - 1;
        char atoi_str = str.at(ie)-'0'-1+'a';
        cout << nowStr << " => " << atoi_str << "\n" << flush;
    }
    return 0;
}