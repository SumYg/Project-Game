#include <iostream>
using namespace std;

int initialization() {
  int n;
  cout << "Welcome to group 87 game!" << endl;
  cout << "Please enter the number of players: ";
  cin >> n;
  cout << "Please enter your names:" << endl;
  for (int i; i < n; i++) {
    cin >> palyers[i].name;
  }

}
