#include <iostream>
#include "functions.h"
#include "palyer.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
  Palyers palyers[4];
  int n, *order,round=0;
  cout << "Welcome to group 87 game!" << endl;
  cout << "Please enter the number of players: ";
  cin >> n;
  cout << "Please enter your names seperated by space: " << endl;
  for (int i = 0; i < n; i++)
    cin >> palyers[i].name;

  while (result(n,palyers, order,round)) {
    round+=1;
    initialization(n, palyers, order);
    gamestage(n, palyers, order);
  }

  return 0;
}
