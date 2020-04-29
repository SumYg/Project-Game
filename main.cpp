#include <iostream>
#include "functions.h"
#include "palyer.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
  Palyers palyers[4];
  int n, round=0;
  cout << "Welcome to group 87 game!" << endl;
  cout << "Please enter the number of players: ";
  cin >> n;
  int *order= new int [n];
  
  for (int i=0;i<n;i++){
    order[i]=i;
  }
  
  cout << "Please enter your names seperated by space: " << endl;
  for (int i = 0; i < n; i++)
    cin >> palyers[i].name;
  initialization(n, palyers, order);
  gamestage(n, palyers, order);
  while (result(n,palyers, order,round)) {
    round+=1;
    initialization(n, palyers, order);
    gamestage(n, palyers, order);
  }

  return 0;
}
