#include "globalOps.h"

#include <algorithm>
#include <vector>
using namespace std;

int checkInstruction(int token) {
  if (token == ADD_OP || token == JMPP_OP || token == SUB_OP ||
      token == JMPZ_OP || token == MUL_OP || token == INPUT_OP ||
      token == DIV_OP || token == LOAD_OP || token == JMP_OP ||
      token == STORE_OP || token == JMPN_OP || token == OUTPUT_OP) {
    return 1;
  } else if (token == COPY_OP) {
    return 2;
  } else if (token == STOP_OP) {
    return 0;
  } else
    return -1;
}

bool vectIntcontains(vector<int> vec, int elem) {
  bool result = false;
  if (find(vec.begin(), vec.end(), elem) != vec.end()) {
    result = true;
  }
  return result;
}