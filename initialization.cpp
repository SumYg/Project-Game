#include <iostream>
#include <ctime>
#include <unistd.h>
#include "palyer.h"
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
} // sort the given array in descending order with length n, the array is passed by pointer and no return for this function

int find(int target, int* list, int n) {
  for (int i = 0; i < n; ++i)
    if (list[i] == target)
      return i;
  return 87;
}// find target in the given array with length n, the array is passed by pointer and return the index of target in the array

void initialization(int n, Palyers* palyers, int* order) {
  // this function is to draw random cards to each players of the next round and rearrange their order according to their card distributed
  // the rank of their cards and the order of next round are shown to the screen
  // this functions takes in the number of players (int n), players' info (Palyers* palyers) and order of players (int* order)
  bool randomnum[10] = {};
  srand(time(NULL));
  int *num = new int [n];

  cout << "Drawing random cards......." << endl;
  for (int i = 0; i < n; ++i) {
    sleep(1);
    int random = rand() %10;
    while (randomnum[random] !=0)
      random = rand() %10;
    randomnum[random] = 1;
    num[i] = random + 1;
    cout << palyers[order[i]].name << ": " << num[i] << endl;
  }// distribute random cards to all the players to determine their order
  sleep(1);
  cout << endl;

  int *new_num = new int [n], *temp_order = new int [n];
  for (int i = 0; i < n; ++i) {
    new_num[i] = num[i];
    temp_order[i] = order[i];
  }//replicate arrays
  sorted(new_num, n);
  cout << "Order of players:" << endl;
  for (int i = 0; i < n; ++i) {
    order[i] = temp_order[find(new_num[i], num, n)];
    cout << palyers[order[i]].name << ((i < n-1)? " >> ": "\n");
  }
  cout << endl;
  sleep(1);

  delete[] num, new_num, temp_order;
}
