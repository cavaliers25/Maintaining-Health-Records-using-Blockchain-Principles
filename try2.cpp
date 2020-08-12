#include <bits/stdc++.h>

using namespace std;

long int integerfromstr(string S){
  vector<int> integer;
  long int N=0;
  for(int i=0;i<S.size();i++){
    if(!(S[i]=='a'||S[i]=='b'||S[i]=='c'||S[i]=='d'||S[i]=='e'||S[i]=='f'))
    integer.push_back(S[i]-48);
  }
  for(int i=0;i<integer.size();i++){
    cout<<integer[i];
  }
  cout<<endl;
  int k=integer.size();
  if(integer.size()>10){
    k=10;
  }
  for(int i=0;i<k;i++){
    N=N*10+integer[i];
  }
  cout<<N<<endl;
  return N;
}

int main(){
  long int N;
  string S;
  cin>>S;
  N=integerfromstr(S);
  return 0;
}
