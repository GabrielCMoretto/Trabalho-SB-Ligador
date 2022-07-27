#ifndef GLOBALVARS
#define GLOBALVARS

#define ADD_OP 1
#define SUB_OP 2
#define MUL_OP 3
#define DIV_OP 4
#define JMP_OP 5
#define JMPN_OP 6
#define JMPP_OP 7
#define JMPZ_OP 8
#define COPY_OP 9
#define LOAD_OP 10
#define STORE_OP 11
#define INPUT_OP 12
#define OUTPUT_OP 13
#define STOP_OP 14

#endif  // GLOBALVARS

#include <vector>
using namespace std;

int checkInstruction(int);
bool vectIntcontains(vector<int>, int);
