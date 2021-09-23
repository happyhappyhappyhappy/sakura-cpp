#include<iostream>
#include<array>
#include<vector>
#include<cstdio>
#include<chrono>
using namespace std;
using namespace std::chrono;
using li=long int;

int main(void){
    system_clock::time_point start,end;
    double elaspd;
    const li MAX=100000;
    vector<li> b1(MAX);
    cout << "Vector:配列と同じ扱い\n";
    start = chrono::system_clock::now();
    for(li j=0;j<MAX;j++){
        b1[j] = j;
    }
    li sum=0;
    for (li j = 0; j < MAX; j=j+1)
    {
        sum = sum + b1[j];
    }
    end = system_clock::now();
    elaspd = chrono::duration_cast<microseconds>(end-start).count();
    cout << elaspd << " μs\n";
    return 0;   
}