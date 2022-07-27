#include "linkage.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "globalOps.h"
using namespace std;

vector<int> linkCodes(string objCode1Name, string objCode2Name) {
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
    // cout << "corFactor:" << corFactor << "\n";
    // cout << "Tabela uso1:\n";
    // for (auto const& pair : useTable1) {
    //   cout << "{" << pair.first << ": " << pair.second << "}\n";
    // }
    // cout << "Tabela def1:\n";
    // for (auto const& pair : defTable1) {
    //   cout << "{" << pair.first << ": " << pair.second << "}\n";
    // }
    // for (auto i : code1Int) {
    //   std::cout << i << ' ';
    // }
    // cout << "\n";

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
    // cout << "Tabela uso2:\n";
    // for (auto const& pair : useTable2) {
    //   cout << "{" << pair.first << ": " << pair.second << "}\n";
    // }
    // cout << "Tabela def2:\n";
    // for (auto const& pair : defTable2) {
    //   cout << "{" << pair.first << ": " << pair.second << "}\n";
    // }
    // for (auto i : code2Int) {
    //   cout << i << ' ';
    // }
    cout << "\n";
    objCode2.close();

  } else {
    cout << "Unable to open file\n";
  }
  int j = 0;
  vector<int> linkedCode;

  for (auto i : code1Int) {
    if (useTable1[j] != "") {
      for (auto const& pair : defTable2) {
        if (useTable1[j] == pair.second) {
          i = i + pair.first + corFactor;
          break;
        }
      }
    }
    linkedCode.push_back(i);
    j++;
  }
  int adressesToRead = 0;
  j = 0;
  vector<int> relAdresses;
  for (auto i : code2Int) {
    if (useTable2[j] != "") {
      for (auto const& pair : defTable1) {
        if (useTable2[j] == pair.second) {
          i = i + pair.first;
          if (adressesToRead == 1 || adressesToRead == 2) {
            adressesToRead--;
          }

          break;
        }
      }

    } else if (vectIntcontains(relAdresses, j)) {
      adressesToRead = -1;
    } else if (adressesToRead == 0 &&
               vectIntcontains(relAdresses, j) == false) {
      adressesToRead = checkInstruction(i);
    } else if (adressesToRead >= 0 &&
               vectIntcontains(relAdresses, j) == false) {
      relAdresses.push_back(j);
      adressesToRead--;
      i = i + corFactor;
    } else if (adressesToRead != 0 && vectIntcontains(relAdresses, j)) {
      adressesToRead = 0;
    }

    linkedCode.push_back(i);
    j++;
  }
  // for (auto i : linkedCode) {
  //   cout << i << ' ';
  // }
  // cout << "\n";
  // for (auto i : relAdresses) {
  //   cout << i << ' ';
  // }
  // cout << "\n";
  return linkedCode;
}
