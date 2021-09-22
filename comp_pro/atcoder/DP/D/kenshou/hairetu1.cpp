#include<iostream>
#include<array>
#include<vector>
#include<cstdio>
#include<chrono>
using namespace std;
using li = long int;

int main(void)
{
    chrono::system_clock::time_point start,end;
    double elaspd;
    const li MAX=100000;
    li a[MAX]={};
    cout << "配列:基本型の場合\n";
    start = chrono::system_clock::now();
    for (li j = 0; j < MAX; j=j+1)
    {
        a[j] = j;
    }
    li sum=0;
    for (li j = 0; j < MAX; j++)
    {
        sum = sum + a[j];
    }
    end = chrono::system_clock::now();
    elaspd = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout << elaspd << " μs\n" ;
    
    
    return 0;
}
