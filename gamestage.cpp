#include <iostream>
#include <string>
#include <ctime>
#include "palyer.h"
#include <unistd.h>
using namespace std;

void insert_card(string number, int index, Palyers *palyers) {
  // this function is to add a card to a player's hand
  Node *p = new Node;
  p->next = NULL;
  p->hand = number;
  if (palyers[index].tail == NULL) {
    palyers[index].handcards = p;
    palyers[index].tail = p;
  }
  else {
    palyers[index].tail->next =p;
    palyers[index].tail =p;
  }
}

Node * find(Node *handcards,string discard){
  // this function is to find the pointer pointing to the discarded card in the player's hand
  Node * current=handcards;
  while (current !=NULL){
    if (current->hand == discard)
      return current;
    else
      current=current->next;}
  return NULL;// return null if not found
}

void delete_card(Node * &handcards, Node * &tail, string discard){
  // this fumction is to delete a certain card from a player's hand
  Node * current=handcards;
  if (current->hand == discard){
    handcards = handcards->next;
    if (tail == current)
      tail = tail->next;
    delete current;
    return;
  }
  while (current->next != NULL){
    if (current->next->hand == discard){
      if (current->next == tail)
        tail = current;
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
  // this function prints the hand of the player
  cout <<  "Your current hand cards:" << endl;
  if (palyers[index].tail != NULL)
    for (Node *head = palyers[index].handcards; head != NULL; head = head->next)
      cout << head->hand << ' ';
  cout << endl;
}

void gamestage(int n, Palyers* palyers, int* order) {
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
      while (option !=1 && option !=2 || palyers[order[j]].tail == NULL && option ==2){
        cout<<"Invalid option, please input your option again. "<<endl;
        cout<<"Enter 1 to draw a card "<<endl;
        cout<<"Enter 2 to discard a card "<<endl;
        cin>>option;
      }
      if (option==1){
        // if players choose to draw a card
        int random=rand()%cards;
        cout<<"Drawing a card......"<<endl;
        while (cardcheck[random] != 0)
          random=rand()%cards;
        cardcheck[random]=1;
        insert_card(transform(random % 13+1), order[j], palyers);
        usleep(500000);
        cout<<"You draw "<<transform(random%13+1)<<endl;
      }
      else if (option == 2){
        // if players choose to discard a card
        string discard;
        cout<<"Please enter the card you want to discard :";
        cin>>discard;
        while (find(palyers[order[j]].handcards, discard)==NULL){
          cout<<"Incorrect input, please enter the card you want to discard again"<<endl;
          cin>>discard;
        }
        delete_card(palyers[order[j]].handcards, palyers[order[j]].tail, discard);
      }
      print_hand(order[j], palyers);
      cout << endl;
      

    }
  }
delete[] cardcheck;}
