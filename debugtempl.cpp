#include <iostream>
#include <stack>
#include <string_view>
// 注意 このマクロはstdがc++17以降になってから使えます
// string_view が c++17 で使えるため
// このstdはg++ 11.1以降の場合デフォルトで使えるようになる
using namespace std;

#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)

template <typename T, typename... Rest>
void debug_func(string_view name, const T &a, Rest &&...rest) {
  stack<char> brackets;
  string_view left_brackets = "({[<";
  string_view right_brackets = ")}]>";
  int end = name.size();
  for ( int i = 0; i < (int)name.size(); i++ ) {
    if ( left_brackets.find(name[i]) != string::npos ) {
      brackets.push(name[i]);
    }
    if ( right_brackets.find(name[i]) != string::npos ) {
      if ( !brackets.empty() ) brackets.pop();
    }
    if ( name[i] == ',' && brackets.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << endl;
  } else {
    cerr << ' ';
    debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<Rest>(rest)...);
  }
}

int main() {
  int aaa = 10;
  debug(10, aaa, max(10, 4), min(10, 1));
}