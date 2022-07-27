#include <string.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "linkage.h"
using namespace std;

int main(int argc, char *argv[]) {
  string objCode1Name;
  string objCode2Name;
  vector<int> linkedCode;

  if (argc < 2) {
    cout << "Voce precisa de dois argumentos para rodar o programa\n";
    return 0;
  }
  objCode1Name = argv[1];
  objCode2Name = argv[2];

  linkedCode = linkCodes(objCode1Name, objCode2Name);

  int j = 0;
  ofstream myfile;
  myfile.open("codr.o");
  for (auto i : linkedCode) {
    myfile << i;
    if (j < linkedCode.size() - 1) {
      myfile << " ";
    }
    j++;
  }
  myfile.close();
  return 0;
}
