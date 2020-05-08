#include <iostream>
#include "functions.h"
#include "palyer.h"
#include <string>
using namespace std;

int main() {
  Palyers palyers[4];
  int n, round=1;
  cout << "Welcome to group 87 game!" << endl;
  cout << "Please enter the number of players (2-4): ";
  cin >> n;
  int *order= new int [n];
  
  
  cout << "Please enter your names seperated by space: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> palyers[i].name;
    order[i]=i;
  }
  initialization(n, palyers, order);
  gamestage(n, palyers, order);
  while (result(n,palyers, order,round)) {
    round+=1;
    initialization(n, palyers, order);
    gamestage(n, palyers, order);
  }
  delete[] order;
  return 0;
}
