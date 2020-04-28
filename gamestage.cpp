#include <iostream>
#include <string>
#include <ctime>
#include "palyer.h"
#include <unistd.h>
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
  // this function is to find the pointer pointing to the discarded card in the player's hand
  Node * current=handcards;
  while (current !=NULL){
    if (current->hand == discard)
      return current;
    else
      current=current->next;}
  return NULL;// return null if not found
}
      
void delete_card(Node * handcards, int discard){
  // this function is used to discard a chosen card from a player's hand
  Node * current=handcards;
  while (current!=NULL){
    if (handcards->hand == discard){
      handcards=handcards->next;
      delete current;
      return ;
    }
    else{
      if (current->next->hand == discard){
        Node *p = current->next;
        current->next=p->next;
        delete p;
        return ;
      }
      else{
        current=current->next;
      }
    }
  }
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
      if (i != 0) {
        cout<<"Enter 2 to discard a card "<<endl;
        print_hand(order[j], palyers);
      }
      cin>>option;
      while (option !=1 && option !=2 || palyers[order[j]].tail == NULL && option ==2){
        cout<<"Invalid option, please input your option again. "<<endl;
        cout<<"Enter 1 to draw a card "<<endl;
        cout<<"Enter 2 to discard a card "<<endl;
        cin>>option;
      }
      if (option==1){
        int random=rand()%cards;
        cout<<"Drawing a card......"<<endl;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
        insert_card(random % 13+1, order[j], palyers);
        usleep(500000);
        cout<<"You draw "<<transform(random%13+1)<<endl;
      }
      else if (option == 2){
        int discard;
        cout<<"Please enter the card you want to discard :";
        cin>>discard;
        while (find(&palyers[order[j]].handcards, discard)==NULL){
          cout<<"Incorrect input, please enter the card you want to discard again"<<endl;
          cin>>discard;
        }
        delete_card(&palyers[order[j]].handcards, discard);
      }
      print_hand(order[j], palyers);
      cout << endl;      
      
        
    }
  }  
delete[] cardcheck;}
    
