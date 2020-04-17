#include <iostream>
#include <initialization.h>
#include <gamestage.h>
#include <result.h>
#include <string>
#include <fstream>
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
  int n;
  cout << "Welcome to group 87 game!" << endl;
  cout << "Please enter the number of players: ";
  cin >> n;
  cout << "Please enter your names:" << endl;
  for (int i; i < n; i++) {
    cin >> palyers[i].name;
  }
  int *order;
  initialization(n, palyers, order);
  gamestage(palyers, order)
  while (result(palyers, order)) {
    initialization(n, palyers, order);
    gamestage(palyers, order);
  }

  return 0;
}
