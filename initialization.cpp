#include <iostream>
#include <ctime>
using namespace std;

void sorted(int* num, int n) {
  for (int i = 0; i < n; ++i)
    for (int j= i+1; j < n; ++j)
      if (num[j] > num[i]) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        --i;
        break;
      }
} // sort the given array with length n

int find(int target, int* list, int n) {
  for (int i = 0; i < n; ++i)
    if (list[i] == target)
      return i;
  return -1;
}// find target in the given array

int initialization(int n, struct Players* palyers, int* order) {
  int randomnum[10] = {};
  srand(time(NULL));
  int *num = new int [n];
  for (int i=0; i<n;i++)
    cin >> order[i];
  cout << "Drawing random cards......." << endl;
  for (int i=0; i< n; ++i) {
    int random = rand() %10;
    while (randomnum[random] !=0)
      random = rand() %10;
    randomnum[random] = 1;
    num[i] = random + 1;
    cout << palyers[order[i]].name << ": " << num[order[i]] << endl;
  }
  int *new_num = new int [n], *temp_order = new int [n];
  for (int i = 0; i < n; ++i) {
    new_num[i] = num[i];
    temp_order[i] = order[i];
  }
  sorted(new_num, n);
  for (int i = 0; i < n; ++i)
    order[i] = temp_order[find(new_num[i], num, n)];
  cout << "Order of players:" << endl;
  for (int i = 0; i < n; ++i)
    cout << palyers[order[i]].name << ((i < n-1)? " >> ": "\n");
  delete[] num, new_num, temp_order;
  // give random numbers to players
  return 0;
}
