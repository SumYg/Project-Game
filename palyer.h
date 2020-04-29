#ifndef PALYER_H
#define PALYER_H

struct Node {
  std::string hand;
  Node *next;
};

struct Palyers {
  std::string name;
  int won=0;
  Node *handcards=NULL;
  Node *tail=NULL;
};

#endif
