#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include "picosha2.h"

using namespace std;
int boolean;
class Block{
public:
  string Name;
  int Age;
  string MedicalReport;
  string AccessibleNames;
  string PrevHash;
  string CurrHash;
  void Constructor(string F,string A,int B,string C,string D){
    PrevHash=F;
    Name=A;
    Age=B;
    MedicalReport=C;
    AccessibleNames=D;
  }
  string MineBlock(string A,int difficulty);
  string VerifyTransaction(long int A,long int B,long int p,long int h,long int s);
};
void verifyTransaction2(long int A,long int B,long int p,long int h){
  cout<<"Verifier's Part: "<<"Enter value of b(0/1): \n";
  cin>>boolean;
  return ;
}
//verify transaction is A and Prover is B(He is in N==4 and in else if)
string Block::VerifyTransaction(long int A,long int B,long int p,long int h,long int s){
  cout<<"Verifying the Transaction:\n";
  int b=boolean;
  long int val1=1,val2=1;
  for(long int k=0;k<s;k++){
    val1=val1*A;
    val1%=p;
    //cout<<B<<endl;
  }
  val2=(long int)(h*pow(B,b))%p;
  cout<<val1<<endl;
  cout<<val2<<endl;
  if(val1==val2){
    cout<<"This is verification part\n";
    return "YES";
  }
  else{
    cout<<"Wrong details entered\n";
    return "NO";
  }
//cout<<B<<endl;
}
string Block::MineBlock(string A,int difficulty){
  int nonce=0;
  string src_str=A;
  cout<<src_str<<endl;
  src_str+=to_string(nonce);
  cout<<src_str<<endl;
  src_str=picosha2::hash256_hex_string(src_str);
  //string r =Hash.substr(0, difficulty);
  cout<<src_str<<endl;
  string target;
  int len=src_str.size();
  for(int i=0;i<difficulty;i++){
    target+=to_string(0);
  }
  cout<<target<<endl;
  while((src_str.substr(0, difficulty)).compare(target)){
    src_str.clear();
    src_str=A;
    nonce++;
    src_str+=to_string(nonce);
    //cout<<"Inside While: "<<src_str<<endl;
    cout<<"Inside MineBlock While: "<<nonce<<endl;
    src_str=picosha2::hash256_hex_string(src_str);
  }
  cout<<"Nonce Value:(This is the key) "<<nonce<<endl;
  cout<<"Block Succesfully created\n";
  return src_str;
}
