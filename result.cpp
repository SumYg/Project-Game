#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "palyer.h"
using namespace std;

void deletehand(Node * &handcards){
  // this function delete the handcards of a player by passing their handcards with references into this function 
  while (handcards!=NULL){
    Node *p= handcards;
    handcards=handcards->next;
    delete p;
  }
}

int transform1(string num) {
  // this function is to transform the cards to a score by passing a string into it, and the score will be returned as an integer
  if (num == "A")
      return 1;
  if (num == "J")
      return 11;
  if (num == "Q")
      return 12;
  if (num == "K")
      return 13;

  return stoi(num);
}

int calculate_mark(Node *handcards){
  // this function is to calculate the scores of players' handcards by passing their handcards into this function, the point will 
  // be returned as integer
  Node *current=handcards;
  int point=0;
  while (current!=NULL){
    point+=transform1(current->hand);
    current=current->next;
  }
  return point;
}

void coutwin(string namelist) {
   // this function output the winner by passing a string into this function 
   cout << "Winners of this round:" << endl;
   cout << namelist << endl;
}

bool result(int &n, Palyers* palyers, int* order,int round) {
  // this is the main function for the result part
  // this functions takes in the number of players (int &n), players' info (Palyers* palyers), order of players (int* order)and which round it is (int round)
  // the main purpose of this function is to find out who wins the game/round and output it
  // this function return false if there is only one winner. Otherwise, if there are no winner or more than one winners, it returns true.
  ofstream fout;
  fout.open("result.txt", ios::app);
  string finalwinner;
  int winner=0;
  for (int i=0;i<n;i++){
    int point=calculate_mark(palyers[order[i]].handcards);
    cout<<palyers[order[i]].name<<"'s hand cards have "<<point<<" points"<<endl;
    if (point==27){
      winner+=1;
      cout<<"You win this round!!"<<endl;
      palyers[order[i]].won+=1;
      finalwinner += palyers[order[i]].name + ", ";
    }
    palyers[order[i]].tail = NULL;
    usleep(870000);
  }
  
  if (winner > 1) {
    finalwinner.pop_back();
    finalwinner.pop_back();
    fout << finalwinner <<" win round "<< round << endl;
  }
  
  if (winner==0){
    for (int i=0;i<n;i++){
      palyers[order[i]].won+=1;
      deletehand(palyers[order[i]].handcards);
    }
    cout<<"No one wins this round"<<endl;
    cout<<"It is a draw for this round"<<endl;
    fout<<"Round "<<round<<" is a draw"<<endl;
    fout.close();
    return true;
  }
  
  if (winner==1){
    for (int i=0;i<n;i++){
      if (palyers[order[i]].won==round){
        ifstream fin;
        fin.open("result.txt");
        while (getline(fin, finalwinner))
          cout << finalwinner << endl;
        fin.close();
        fout.close();
        cout<<palyers[order[i]].name<<" is the final winner!! Congratulation !!"<<endl;
        return false;
      }
    }
  }
  
  if (winner == 2){
    if (n==2){
      cout<<"All players wins this round"<<endl;
      cout<<"It is a draw for this round"<<endl;
      fout<<"Round "<<round<<" is a draw"<<endl;
      for (int i=0;i<n;i++){
        deletehand(palyers[order[i]].handcards);
      }
      fout.close();
      return true;
    }
    else{
      int order1[2];
      int n1=0;
      for (int i=0;i<n;i++){
        if (calculate_mark(palyers[order[i]].handcards)==27){
          order1[n1]=order[i];
          n1+=1;
        }
      }
      for (int i=0;i<n;i++){
        deletehand(palyers[order[i]].handcards);
      }
      n=2;
      for (int i=0;i<n;i++){
        order[i]=order1[i];
      }
      coutwin(finalwinner);
      fout.close();
      return true;
    }
  }

  if (winner == 3){
    if (n==3){
      cout<<"All players wins this round"<<endl;
      cout<<"It is a draw for this round"<<endl;
      fout<<"Round "<<round<<" is a draw"<<endl;
      for (int i=0;i<n;i++){
        deletehand(palyers[order[i]].handcards);
      }
      fout.close();
      return true;
    }
    else{
      int order2[3];
      int n1=0;
      for (int i=0;i<n;i++){
        if (calculate_mark(palyers[order[i]].handcards)==27){
          order2[n1]=order[i];
          n1+=1;
        }
      }
      for (int i=0;i<n;i++){
        deletehand(palyers[order[i]].handcards);
      }
      n=3;
      for (int i=0;i<n;i++){
        order[i]=order2[i];
      }
      coutwin(finalwinner);
      fout.close();
      return true;
    }
  }
  
  if (winner==4){
    cout<<"All players wins this round"<<endl;
    cout<<"It is a draw for this round"<<endl;
    fout<<"Round "<<round<<" is a draw"<<endl;
    for (int i=0;i<n;i++){
        deletehand(palyers[order[i]].handcards);
    }
    fout.close();
    return true;
  }
}
