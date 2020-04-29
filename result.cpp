#include <iostream>
#include <string>
#include <fstream>
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
  fout.open("result.txt");
  string finalwinner;
  int winner=0;
  for (int i=0;i<n;i++){
    int point=calculate_mark(palyers[order[i]].handcards);
    cout<<palyers[order[i]].name<<"'s hand cards have "<<point<<" points"<<endl;
    if (point==27){
      winner+=1
      cout<<"You win this round!!"<<endl;
      palyers[order[i]].won+=1;
      fout<<palyers[order[i]].name<<" wins round "<<palyers[order[i]].won<<endl;
    }
  }
  if (winner==0){
    for (int i=0;i<n;i++){
      palyers[order[i]].won+=1;
    }
    cout<<"It is a draw for this round"<<endl;
    return true;
  }
  if (winner==1){
    
    return false;
  }
  if (winner == 2){
    
  
