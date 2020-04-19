#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void insert_card(int number, int index, struct Palyers *palyers) {
  if (palyers[index].tail == NULL) {
    palyers[index].handcards.card = number;
    palyers[index].tail = &palyers[index].handcards;
  }
  else {
    Node *p = new Node;
    p->next = NULL;
    p->card = number;
    palyers[index].tail->next =p;
    palyers[index].tail =p;
  }
}

void print_hand(int index, Palyers *palyers) {
  cout <<  "Your current hand cards:" << endl;
  if (palyers[index].tail == NULL)
    cout << endl;
  else {
    Node *head = & palyers[index].handcards;
    while (head != NULL) {
      cout << head->card << ' ';
      head = head->next;
    }
    cout << endl;
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
      if (i != 0)
        print_hand(order[j], palyers);
      cin>>option;
      if (option==1){
        int random=rand()%cards;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
        insert_card(random+1, order[j], palyers);
        print_hand(order[j], palyers);
