#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void insert_card(int number, int index, struct Palyers *palyers) {
  // this function is used to add a card to a player's hand
  if (palyers[index].tail == NULL) {
    palyers[index].handcards.hand = number;
    palyers[index].handcards.next = NULL;
    palyers[index].tail = &palyers[index].handcards;
  }
  else {
    Node *p = new Node;
    p->next = NULL;
    p->hand = number;
    palyers[index].tail->next =p;
    palyers[index].tail =p;
  }
}

Node * find(Node *handcards,int discard){
  Node * current=handcards;
  while (current !=NULL){
    if (current.hand == discard)
      return current;
    else
      current=current.next;}
  return NULL;
}
      
    

string transform(int num) {
  // this function is to transform the number to a correct symbol for the cards
  switch (num) {
    case 1:
      return "A";
    case 11:
      return "J";
    case 12:
      return "Q";
    case 13:
      return "K";
    default:
      return to_string(num);
  }
}

void print_hand(int index, Palyers *palyers) {
  // this function print the hand of the player
  cout <<  "Your current hand cards:" << endl;
  if (palyers[index].tail != NULL) 
    for (Node *head = &palyers[index].handcards; head != NULL; head = head->next)
      cout << transform(head->hand) << ' ';
  cout << endl;
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
      while (options !=1 && option !=2 || i==0 && option==2){
        cout<<"Invalid option, please input your option again. "<<endl;
        cout<<"Enter 1 to draw a card "<<endl;
        cout<<"Enter 2 to discard a card "<<endl;
        cin>>option;
      }
      if (option==1){
        int random=rand()%cards;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
        insert_card(random % 13+1, order[j], palyers);
      }
      else if (option == 2){
        int discard;
        cout<<"Please enter the card you want to discard :";
        cin>>discard;
        while (find(＆palyers[order[j]].handcards, discard)==NULL){
          cout<<"Incorrect input, please enter the card you want to discard again"<<endl;
          cin>>discard;
        }
        
      }
      
      
      
        
    }
  }  
delete[] cardcheck;}
    
