#include <iostream>
#include <string>
#include <fstream>
#include "palyer.h"
using namespace std;

int transform1(string num) {
  // this function is to transform the cards to a score
  switch (num) {
    case "A":
      return 1;
    case "J":
      return 11;
    case "Q":
      return 12;
    case "K":
      return 13;
    default:
      return stoi(num);
  }
}
int calculate_mark(Node *handcards){
  // this function is to calculate the scores of players' handcards
  Node *current=handcards;
  int point=0;
  while (current!=NULL){
    point+=transform1(current->hand);
    current=current->next;
  }
  return point;
}
void result(int &n, Palyers* palyers, int* order,int round) {
  ofstream fout;
  fout.open("result.txt", ios::app);
  string finalwinner;
  int winner=0;
  for (int i=0;i<n;i++){
    int point=calculate_mark(palyers[order[i]].handcards);
    cout<<palyers[order[i]].name<<"'s hand cards have "<<point<<" points"<<endl;
    if (point==27){
      winner+=1
      cout<<"You win this round!!"<<endl;
      palyers[order[i]].won+=1;
      finalwinner += palyers[order[i]].name + ", ";
    }
  }
  if (winner > 1) {
    finalwinner.pop_back();
    finalwinner.pop_back();
    fout << finalwinner <<" win round "<< round << endl;
  }
  if (winner==0){
    for (int i=0;i<n;i++){
      palyers[order[i]].won+=1;
    }
    cout<<"No one wins this round"<<endl;
    cout<<"It is a draw for this round"<<endl;
    fout<<"Round "<<round<<" is a draw"<<endl;
    return true;
  }
  if (winner==1){
    for (int i=0;i<n;i++){
      if (palyers[order[i]].won==round){
        ifstream fin;
        fin.open("result.txt");
        while (getline(fin, finalwinner))
          cout << finalwinner;
        fin.close();
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
      return true;
    }
    else{
      int *order1= new int [n];
      int n1=0;
      for (int i=0;i<n;i++){
        if (calculate_mark(palyers[order[i]].handcards)==27){
          order1[n1]=order[i];
          n1+=1;
        }
      }
      n=2;
      for (int i=0;i<n;i++){
        order[i]=order1[i];
      }
      delete[] order1;
      return true;
    }
  } 
      
      
  
  if (winner == 3){
    if (n==3){
      cout<<"All players wins this round"<<endl;
      cout<<"It is a draw for this round"<<endl;
      fout<<"Round "<<round<<" is a draw"<<endl;
      return true;
    }
    else{
      int *order1= new int [n];
      int n1=0;
      for (int i=0;i<n;i++){
        if (calculate_mark(palyers[order[i]].handcards)==27){
          order1[n1]=order[i];
          n1+=1;
        }
      }
      n=3;
      for (int i=0;i<n;i++){
        order[i]=order1[i];
      }
      delete[] order1;
      return true;
    }
  }
  if (winner==4){
    
    cout<<"All players wins this round"<<endl;
    cout<<"It is a draw for this round"<<endl;
    fout<<"Round "<<round<<" is a draw"<<endl;
    return true;
  }
}

      
      
   
  
