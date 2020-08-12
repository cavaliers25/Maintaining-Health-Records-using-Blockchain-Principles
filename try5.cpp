#include <bits/stdc++.h>
//#include "methods.h"
#include "picosha2.h"
using namespace std;

int main(){
  string S;
  cin>>S;
  string src_str=S;
  src_str=picosha2::hash256_hex_string(S);
  cout<<src_str<<endl;
  return 0;
}
