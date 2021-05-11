#include<iostream>
#include<cmath>
long long usepow(long long x,long long y){
    return std::pow(x,y);
}
int main(int argc, const char** argv) {
    long long x;
    x = 2;
    for (int i = 2; i < 10; i++)
    {
        long long result = usepow(x,i);
        std::cout << x << "no" << i << "jou" << "=" << result<< std::endl;
    }
    return 0;
}