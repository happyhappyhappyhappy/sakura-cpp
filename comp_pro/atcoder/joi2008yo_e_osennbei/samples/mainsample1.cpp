#include<bits/stdc++.h>
#include <cassert>
#include <bitset>
using namespace std;

int main()
{
  std::bitset<4> bs("1010");

  bool result1 = bs.test(1);
//   if(result1){
//     cout << "一致しています\n" << fflush;
//   }
//   else{
//     cout << "一致していません\n" << fflush;
//   }
    assert(result1);
    bool result2 = bs.test(3);
    assert(result2);
//     if(result2){
//     cout << "一致しています\n" << fflush;
//   }
//   else{
//     cout << "一致していません\n" << fflush;
//   }
}
