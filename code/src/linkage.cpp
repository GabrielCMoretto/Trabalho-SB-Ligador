#include "linkage.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void linkCodes(string objCode1Name, string objCode2Name) {
  string line;
  string auxString;
  string auxStringNumber;
  int corFactor = 0;
  vector<int> code1Int;
  int number = 0;
  map<int, string> useTable1;
  map<int, string> defTable1;
  int useTableCount = 0;
  int defTableCount = 0;
  vector<int> auxVector;

  ifstream objCode1(objCode1Name);
  if (objCode1.is_open()) {
    while (getline(objCode1, line)) {
      // cout << line << '\n';
      if (line == "TABELA USO") {
        useTableCount++;
      }
      if (useTableCount != 0 && line != "TABELA USO") {
        if (line == "") {
          useTableCount = 0;
        } else {
          auxString = line.substr(0, line.find(" "));
          auxStringNumber = line.substr(line.find(" "), line.size());
          cout << "aha:" << auxStringNumber << "\n";
          stringstream auxStringNumberChar(auxStringNumber);
          while (auxStringNumberChar >> number) {
            auxVector.push_back(number);
          }
        }
      }
    }
    stringstream code1Char(line);
    while (code1Char >> number) {
      code1Int.push_back(number);
      corFactor++;
    }
    cout << "corFactor:" << corFactor << "\n";
    // for (auto const &pair : useTable1) {
    // cout << "{" << pair.first << ": " << pair.second << "}\n";
    //}
    objCode1.close();

  } else
    cout << "Unable to open file";
}
