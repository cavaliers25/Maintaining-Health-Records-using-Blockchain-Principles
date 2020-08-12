#include <iostream>
#include "picosha2.h"
#include "methods.h"

using namespace std;

int main(/*int argc, char* argv[]*/)
{
	// std::cout << "Input freely. To get hash, input \"hash!\". " << std::endl;
	// picosha2::hash256_one_by_one hasher;
	// while(true){
	// 	hasher.init(); //reset hasher state
	// 	while(true){
	// 		std::string line;
	// 		std::getline(std::cin, line);
	// 		if(line == "hash!"){
	// 			break;
	// 		}
	// 		hasher.process(line.begin(), line.end());
	// 	}
	// 	hasher.finish();
	// 	std::string hex_str;
	// 	picosha2::get_hash_hex_string(hasher, hex_str);
	// 	std::cout << hex_str << std::endl;
	// }
	// string src_str="Pavan";
	// string Hash=picosha::hash256_hex_string(src_str);
	// cout<<Hash<<endl;
	// stringstream ss;
	// Block obj1;
	// obj1.Constructor("0","Pavan",18,"Cold","Punith,Vishnu");
	// ss<<obj1.PrevHash<<obj1.Name<<obj1.Age<<obj1.MedicalReport<<obj1.AccessibleNames;
	// string Concat=ss.str();
	// cout<<Concat<<endl;
	// obj1.PrevHash="0";
	// cout<<obj1.Age<<endl;
	// cout<<obj1.AccessibleNames<<endl;
	// string random=obj1.MineBlock(Concat,5);
	// obj1.CurrHash=random;
	// cout<<obj1.CurrHash<<endl;
	// cout<<"random: "<<random<<endl;
  return 0;
}
