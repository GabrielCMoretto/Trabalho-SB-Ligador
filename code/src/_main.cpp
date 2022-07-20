#include <string.h>

#include <fstream>
#include <iostream>

#include "linkage.h"
using namespace std;

int main(int argc, char *argv[]) {
  string objCode1Name;
  string objCode2Name;

  if (argc != 2) {
    cout << "Voce precisa de dois argumentos para rodar o programa\n";
    // return 0;
  }
  objCode1Name = argv[1];
  objCode2Name = argv[2];

  linkCodes(objCode1Name, objCode2Name);

  // std::cout << "objcode1=" << argv[1] << "\n";
  // if (objCode1 == "cod1.o") {
  //   std::cout << "Parece que deu certo";
  // }
  return 0;
}
