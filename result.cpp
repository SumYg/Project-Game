#include <iostream>
#include <string>
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
    score+=transform1(current->hand);
    current=current->next;
  }
  return point;
}
void result(int n, struct Palyers* palyers, int* order) {
  for (int i=0;i<n;i++){
    int point=calculate_mark(palyers[order[i]].handcards);
    cout<<palyers[order[i]].name<<"'s hand cards have "<<point<<" points"<<endl;
    if (point==27){
      
