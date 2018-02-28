#include <iostream>
#include <cstdlib>
#include "../FHEW.h"
#include "common.h"

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

FHEW::EvalKey* EK;


void help(char* cmd) {
  cerr << "\nusage: " << cmd << "SecretKeyFileName EvalKeyFileName Input1 Input2 OutCTFileName  \n\n" 
       << "  Perform Homomorphic Addition\n\n";
  exit(0);
}


int main(int argc, char *argv[]) {
  if (argc != 6) help(argv[0]);
  char* sk_fn = argv[1];
  char* ek_fn = argv[2]; 
  int input1 = atoi(argv[3]);
  int input2 = atoi(argv[4]); 
  char* oct_fn = argv[5]; 

  int k;
  int bitswanted = 99;
  int *bits = (int*) malloc(sizeof(int) * bitswanted);
  for(k=0; k<bitswanted; k++){
  	int mask = 1 << k;
	int masked_n = input1 & mask;
	int thebit = masked_n >> k;

	cout << "the bit = " << thebit << "\n";
	bits[k] = thebit;
  }


  cout << "input1 bits = " << bits << "\n";
  FHEW::Setup();

  EK = LoadEvalKey(ek_fn);

  LWE::CipherText *ct1,*ct2,*ct3;

 
  ct3 = new LWE::CipherText;


  //TODO
  //perform homomorphic addition
  //FHEW::HomGate(ct3, AND, *EK,*ct1,*ct2);

  //SaveCipherText(ct3,oct_fn);
}
