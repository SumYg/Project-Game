#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void insert_card(int number, unsigned index, struct Palyers *palyers) {
  if (palyers[index].handcards.card == 87)
    palyers[index].handcards.card = number;
  else {
    Node *p = new Node;
    p->next = NULL;
    p->card = number;
    Node *head = &palyers[index].handcards;
    while (head->next != NULL)
      head = head->next;
    head->next = p;
  }
}

void gamestage(int n, struct Palyers* palyers, int* order) {
  int option;
  srand(time(NULL));
  int cards;
  if (n==2)
    cards=26;
  else
    cards=39;
  int *cardcheck= new int [cards];
  for (int i=0;i<cards;i++){
    cardcheck[i]=0;
  }
  for (int i=0;i<6;i++){
    for (int j=0;j<n;j++){

      cout<< palyers[order[j]].name << ", choose one of the following option: "<<endl;
      cout<<"Enter 1 to draw a card "<<endl;
      cout<<"Enter 2 to discard a card "<<endl;
      cin>>option;
      if (option==1){
        int random=rand()%cards;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
        insert_card(random, order[j], palyers);
