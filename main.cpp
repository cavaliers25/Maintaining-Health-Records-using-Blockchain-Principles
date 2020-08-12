#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "picosha2.h"
#include "methods.h"
#include <cmath>
#define INF -100000
#include <fstream>

using namespace std;

vector<string> StringTokenizer(string S){
vector <string> tokens;
stringstream check1(S);
string intermediate;
while(getline(check1, intermediate, ','))
{
  tokens.push_back(intermediate);
}
return tokens;
}
long int integerfromstr(string S){
  vector<int> integer;
  long int N=0;
  for(int i=0;i<S.size();i++){
    if(!(S[i]=='a'||S[i]=='b'||S[i]=='c'||S[i]=='d'||S[i]=='e'||S[i]=='f'))
    integer.push_back(S[i]-48);
  }
  // for(int i=0;i<integer.size();i++){
  //   cout<<integer[i];
  // }
  // cout<<endl;
  int k=integer.size();
  if(integer.size()>10){
    k=10;
  }
  for(int i=0;i<k;i++){
    N=N*10+integer[i];
  }
  return N;
}
long int gcd(long int i,long int prime,long int k){
  long int gcd=1;
  for(long int x=0;x<=k;x++){
    gcd=gcd*i;
    gcd%=prime;
    cout<<"Inside gcd Function: "<<gcd<<endl;
  }
  return gcd;
}

long int Generator(long int prime){
  vector<long int> random;
  long int number;
  long int k=0;
  int count=0;
  for(long int i=2;i<prime;i++){
    k=0;
    while(true){
      number=gcd(i,prime,k);
      if(random.size()==(prime-1)){
        // if(count==2)
        // return i;
        // count++;
        // break;
        return i;
      }
      auto it=find(random.begin(),random.end(),number);
      if(!(it==random.end())) {
        random.clear();
        break;
      }
      else{
        random.push_back(number);
        k++;
      }
    }
  }
}
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int N;
  Block obj[10000];
  int i=0;
  stringstream ss;
  string src_str,MedicalReport,AccessibleNames,PrevHash;
  int Age;
  string Concat[100000];
  string CurrentHash[100000];
  ifstream my_input_file;
  while(true){
    cout<<"Enter 1 for Creating a New User/ 2 for view the user/ 3 for Updating the User Details/ 4 Verifying the details if you are listed under Accessible Names\n";
    cin>>N;
    if(!(N==1||N==2||N==3||N==4))
    break;
    if(N==1){
      if(i==0){
        my_input_file.open("input.txt");
        cout<<"Enter Your Name\n";
        //cin>>src_str;
        my_input_file>>src_str;
        cout<<"Enter your Medical Report\n";
        //cin>>MedicalReport;
        my_input_file>>MedicalReport;
        cout<<"Enter the Accessible Names(In Encrypted Form)\n";
        //cin>>AccessibleNames;//These must be in Encrypted form for the user to know.
        my_input_file>>AccessibleNames;
        cout<<"Enter Your Age\n";
        //cin>>Age;
        my_input_file>>Age;
        PrevHash="0";
        string Name=picosha2::hash256_hex_string(src_str);
        obj[i].Constructor(PrevHash,Name,Age,MedicalReport,AccessibleNames);
        ss<<obj[i].PrevHash<<obj[i].Name<<obj[i].Age<<obj[i].MedicalReport<<obj[i].AccessibleNames;
        string A=ss.str();
        Concat[i]=A;
        //cout<<A<<endl;
        obj[i].CurrHash=obj[i].MineBlock(A,4);
        CurrentHash[i]=obj[i].CurrHash;
        //cout<<obj[i].CurrHash<<endl;
        i++;
      }
      else{
        cout<<"Enter Your Name\n";
        my_input_file>>src_str;
        //cin>>src_str;
        cout<<"Enter your Medical Report\n";
        my_input_file>>MedicalReport;
        //cin>>MedicalReport;
        cout<<"Enter the Accessible Names(In Encrypted Form)\n";
        my_input_file>>AccessibleNames;
        //cin>>AccessibleNames;//These must be in Encrypted form for the user to know.
        cout<<"Enter Your Age\n";
        my_input_file>>Age;
        //cin>>Age;
        PrevHash=obj[i-1].CurrHash;
        string Name=picosha2::hash256_hex_string(src_str);
        obj[i].Constructor(PrevHash,Name,Age,MedicalReport,AccessibleNames);
        ss<<obj[i].PrevHash<<obj[i].Name<<obj[i].Age<<obj[i].MedicalReport<<obj[i].AccessibleNames;
        string A=ss.str();
        //cout<<A<<endl;
        Concat[i]=A;
        obj[i].CurrHash=obj[i].MineBlock(A,4);
        CurrentHash[i]=obj[i].CurrHash;
        //cout<<obj[i].CurrHash<<endl;
        i++;
      }
    }else if(N==2){
      cout<<"Enter your key to view the details:\n";
      int count=0;
      int key;
      cin>>key;
      int index1=0,index;
      for(int k=0;k<i;k++){
        // ss<<Concat[k]<<key;
        // src_str=ss.str();
        src_str=Concat[k];
        src_str+=to_string(key);
        if(!(picosha2::hash256_hex_string(src_str).compare(CurrentHash[k]))){
          index1=k;
          count++;
          break;
        }
      }
      for(int k=0;k<i;k++){
        if(!(obj[k].Name.compare(obj[index1].Name))){
          index=k;
        }
      }
      if(index!=index1||count==0){
        cout<<"Entered an invalid key\n";
      }else{
        for(int k=0;k<i;k++){
          if(!(obj[k].Name.compare(obj[index].Name))){
            cout<<"Name: "<<obj[k].Name<<endl;
            cout<<"Medical Report: "<<obj[k].MedicalReport<<endl;
            cout<<"AccessibleNames: "<<obj[k].AccessibleNames<<endl;
            cout<<"Age: "<<obj[k].Age<<endl;
            cout<<"*************\n";
          }
        }
      }
    }
    else if(N==3){
      cout<<"Enter your key to update the details:\n";
      int key;
      cin>>key;
      int index1,index,count=0;
      string concattemp;
      for(int k=0;k<i;k++){
        //Concat[k]+=to_string(key);
        //src_str=Concat[k];
        concattemp=Concat[k];
        concattemp+=to_string(key);
        src_str=concattemp;
        //cout<<"Picosha output: "<<picosha2::hash256_hex_string(src_str)<<endl;
        //cout<<"Current Hash Value: "<<CurrentHash[k]<<endl;
        //cout<<"Stmt inside if:\n"<<picosha2::hash256_hex_string(src_str).compare(CurrentHash[k])<<endl;
        if(!(picosha2::hash256_hex_string(src_str).compare(CurrentHash[k]))){
          index1=k;
          count++;
          break;
        }
        src_str.clear();
      }
      //cout<<"Index value: "<<index1<<endl;
      for(int k=0;k<i;k++){
        if(!(obj[k].Name.compare(obj[index1].Name))){
          index=k;
        }
      }
       //cout<<"New Index value: "<<index<<endl;
       if(index!=index1||count==0){
        cout<<"Entered an invalid key\n";
      }else{
        src_str=obj[index].Name;
        int bull,flag=0;
        cout<<"Enter any number than 0 if you want to update MedicalReports:\n";
        cin>>bull;
        if(bull){
          cout<<"Enter the New Medical Report: \n";
          cin>>MedicalReport;
          flag=1;
        }
        else
        MedicalReport=obj[index].MedicalReport;
        cout<<"Enter any number than 0 if you want to update AccessibleNames:\n";
        cin>>bull;
        if(bull){
          cout<<"Enter New Accessible Names: \n";
          cin>>AccessibleNames;
          flag=1;
        }
        else
        AccessibleNames=obj[index].AccessibleNames;
        cout<<"Enter any number than 0 if you want to update Age:\n";
        cin>>bull;
        if(bull){
          cout<<"Enter your New Age value:\n";
          cin>>Age;
          flag=1;
        }
        else
        Age=obj[index].Age;
        if(flag==0){
          cout<<"You haven't updated any values:\n";
        }else{
          obj[i].Constructor(obj[i-1].CurrHash,src_str,Age,MedicalReport,AccessibleNames);
          ss<<obj[i].PrevHash<<obj[i].Name<<obj[i].Age<<obj[i].MedicalReport<<obj[i].AccessibleNames;
          string A=ss.str();
          Concat[i]=A;
          //cout<<A<<endl;
          obj[i].CurrHash=obj[i].MineBlock(A,3);
          CurrentHash[i]=obj[i].CurrHash;
          i++;
          cout<<"You have succesfully updated your details\n";
        }
      }
    }else if(N==4){
      cout<<"This is Prover's Part:\n";
      string input;
      string usr_name;
      cout<<"Enter your Name(Original one)\n";
      cin>>usr_name;
      src_str=usr_name;
      usr_name=picosha2::hash256_hex_string(src_str);
      cout<<"Enter the encrypted name of the user that you want to see the data of:\n";
      cin>>input;
      int index=INF;
      string Anames;
      for(int k=0;k<i;k++){
        if(!(input.compare(obj[k].Name))){
          index=k;
        }
      }
      if(index==INF){
        cout<<"The details that you have entered doesnot match any record.Please try again later\n";
      }
      else{
        Anames=obj[index].AccessibleNames;
        vector<string> Anamesvect=StringTokenizer(Anames);
        int flag=0;
        for(int i=0;i<Anamesvect.size();i++){
          if(!(Anamesvect[i].compare(usr_name))){
            flag=1;
            cout<<"You are one of the accessible users\n";
            break;
          }
        }
        if(flag==0){
          cout<<"You cant view the user's details\n";
        }else if(flag==1){
          cout<<"You have to prove to usr A that you have his encrypted name:(Zero Knowledge Proof)\n";
          long int r;
          long int h=1;
          long int x=integerfromstr(input);
          long int B=1;
          long int p;
          cout<<"Enter the prime p:\n";
          cin>>p;
          long int A=Generator(p);
          cout<<"A value: "<<A<<endl;
          for(long int k=0;k<x;k++){
            B=B*A;
            B%=p;
            //cout<<B<<endl;
          }
          cout<<"Enter random number between 2 and p-1: \n";
          cin>>r;
          for(long int k=0;k<r;k++){
            h=h*A;
            h%=p;
            //cout<<B<<endl;
          }
          verifyTransaction2(A,B,p,h);
          long int s=(r+boolean*x)%(p-1);
          string FinalOutput=obj[index].VerifyTransaction(A,B,p,h,s);
          cout<<FinalOutput<<endl;
          for(int k=0;k<i;k++){
            if(!(obj[k].Name.compare(input))){
              cout<<obj[k].Name<<endl;
              cout<<obj[k].MedicalReport<<endl;
              cout<<obj[k].AccessibleNames<<endl;
              cout<<obj[k].Age<<endl;
              cout<<"***********\n";
            }
          }
        }
      }
      //long int p=104157;
      //long int A=Generator(p);
    }
}
my_input_file.close();
  //cout<<obj[0].Name<<" "<<obj[0].MedicalReport<<" "<<obj[0].AccessibleNames<<" "<<obj[0].Age<<" "<<obj[0].PrevHash<<endl;
  return 0;
}
