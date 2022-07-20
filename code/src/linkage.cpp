#include "linkage.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void linkCodes(string objCode1Name, string objCode2Name) {
  string line;
  string auxString;
  string auxStringNumber;
  int corFactor = 0;
  vector<int> code1Int;
  vector<int> code2Int;
  int number = 0;
  unordered_map<int, string> useTable1;
  unordered_map<int, string> defTable1;
  unordered_map<int, string> useTable2;
  unordered_map<int, string> defTable2;
  int useTableCount = 0;
  int defTableCount = 0;
  vector<int> auxVector;

  ifstream objCode1(objCode1Name);
  ifstream objCode2(objCode2Name);
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
          stringstream auxStringNumberChar(auxStringNumber);
          while (auxStringNumberChar >> number) {
            auxVector.push_back(number);
          }
          for (auto& it : auxVector) {
            useTable1.emplace(it, auxString);
          }
          auxString.clear();
          auxStringNumber.clear();
          auxStringNumberChar.clear();
          auxVector.clear();
          number = 0;
        }
      }
      if (line == "TABELA DEF") {
        defTableCount++;
      }
      if (defTableCount != 0 && line != "TABELA DEF") {
        if (line == "") {
          defTableCount = 0;
        } else {
          auxString = line.substr(0, line.find(" "));
          auxStringNumber = line.substr(line.find(" "), line.size());
          stringstream auxStringNumberChar(auxStringNumber);
          while (auxStringNumberChar >> number) {
            auxVector.push_back(number);
          }
          for (auto& it : auxVector) {
            defTable1.emplace(it, auxString);
          }
          auxString.clear();
          auxStringNumber.clear();
          auxStringNumberChar.clear();
          auxVector.clear();
          number = 0;
        }
      }
    }
    stringstream code1Char(line);
    while (code1Char >> number) {
      code1Int.push_back(number);
      corFactor++;
    }
    cout << "corFactor:" << corFactor << "\n";
    for (auto const& pair : useTable1) {
      cout << "{" << pair.first << ": " << pair.second << "}\n";
    }

    for (auto const& pair : defTable1) {
      cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    objCode1.close();

  } else {
    cout << "Unable to open file";
  }
  if (objCode2.is_open()) {
    while (getline(objCode2, line)) {
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
          stringstream auxStringNumberChar(auxStringNumber);
          while (auxStringNumberChar >> number) {
            auxVector.push_back(number);
          }
          for (auto& it : auxVector) {
            useTable2.emplace(it, auxString);
          }
          auxString.clear();
          auxStringNumber.clear();
          auxStringNumberChar.clear();
          auxVector.clear();
          number = 0;
        }
      }
      if (line == "TABELA DEF") {
        defTableCount++;
      }
      if (defTableCount != 0 && line != "TABELA DEF") {
        if (line == "") {
          defTableCount = 0;
        } else {
          auxString = line.substr(0, line.find(" "));
          auxStringNumber = line.substr(line.find(" "), line.size());
          stringstream auxStringNumberChar(auxStringNumber);
          while (auxStringNumberChar >> number) {
            auxVector.push_back(number);
          }
          for (auto& it : auxVector) {
            defTable2.emplace(it, auxString);
          }
          auxString.clear();
          auxStringNumber.clear();
          auxStringNumberChar.clear();
          auxVector.clear();
          number = 0;
        }
      }
    }
    stringstream code2Char(line);
    while (code2Char >> number) {
      code2Int.push_back(number);
    }
    for (auto const& pair : useTable2) {
      cout << "{" << pair.first << ": " << pair.second << "}\n";
    }

    for (auto const& pair : defTable2) {
      cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    objCode2.close();

  } else {
    cout << "Unable to open file";
  }
}
