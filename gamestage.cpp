#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void gamestage(int n, struct Palyers* palyers, int* order) {
  int option;
  srand(time(NULL));
  int cards;
  if (n==2)
    cards=26;
  else
    cards=39;
  int *cardcheck= new int [cards];
  for (int i=0;i<6;i++){
    for (int j=0;j<n;j++){
      
      cout<< palyers[order[i]].name << ", choose one of the following option: "<<endl;
      cout<<"Enter 1 to draw a card "<<endl;
      cout<<"Enter 2 to discard a card "<<endl;
      cin>>option;
      if (option==1){
        int random=rand()%cards;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
  
  
