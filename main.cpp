#include <iostream>
#include <initialization.h>
#include <gamestage.h>
#include <result.h>
using namespace std;

struct Node {
  int hand;
  Node *next;
};

struct Palyers {
  string name;
  int won;
  Node handcards;
};

int main() {
  Palyers palyers[4];
  initialization(palyers, 0);
  gamestage(palyers);
  if (result(palyers)) {
    initialization(palyers, 1);
    gamestage(palyers);
  }

  return 0;
}
