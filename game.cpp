#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;


class Tree {
private:
  string desc, choice;
  Tree *left, *right;
public:
  Tree(string d, string c, Tree *L, Tree *R);
  ~Tree() {}
  string getDesc() { return desc; }
  string getChoice() { return choice; }
  Tree* getLeft() { return left; }
  Tree* getRight() { return right; }
};

Tree::Tree(string d, string c, Tree *L, Tree *R) {
  desc = d;
  choice = c;
  left = L;
  right = R;
}

class Game {
private:
  Tree *root, *current;
public:
  Game(Tree *R);
  bool playGame();
  void startGame();
};

Game::Game(Tree *R) {
  root = R;
  current = R;
}

bool Game::playGame() {
  char opt;
  cout << current->getDesc();
  cout << endl << endl;
  cout << current->getChoice();
  cout << endl << endl;
  cin >> opt;
  if (opt == 'A' || opt == 'a') {
    current = current->getLeft();
  } else if (opt == 'B' || opt == 'b') {
    current = current->getRight();
  } else if (opt == 'S' || opt == 's') {
    current = root;
  } else {
    cout << endl << endl;
    cout << "quitting game...";
    return false;
  }
  return true;
}

void Game::startGame() {
  bool continueGame;
  continueGame = true;
  while (continueGame) {
    continueGame = playGame();
  }
}

int main() {
  string desc[20], choice[20];
  string line;
  string findnewline, replacenewline;
  int i = 0;
  ifstream txtfile ("writing.txt");
  if (txtfile.is_open()) {
    while (getline(txtfile, line)) {
      if (line[0] == '|') {
        choice[i] = line;
        i++;
      } else {
        desc[i] = line;
      }
    }
    txtfile.close();
  } else {
    cout << "error - file did not open";
    exit(10);
  }
  findnewline = "\\n";
  replacenewline = "\n";
  for (i = 0; i <= 6; i++) {
    size_t pos = desc[i].find(findnewline);
    while (pos != string::npos) {
      desc[i].replace(pos, findnewline.size(), replacenewline);
      pos = desc[i].find(findnewline, pos + replacenewline.size());
    }
    pos = choice[i].find(findnewline);
    while (pos != string::npos) {
      choice[i].replace(pos, findnewline.size(), replacenewline);
      pos = choice[i].find(findnewline, pos + replacenewline.size());
    }
  }
  Tree *L1 = new Tree(desc[2], choice[2], NULL, NULL);
  Tree *L2 = new Tree(desc[3], choice[3], NULL, NULL);
  Tree *P1 = new Tree(desc[1], choice[1], L1, L2);
  Tree *L3 = new Tree(desc[5], choice[5], NULL, NULL);
  Tree *L4 = new Tree(desc[6], choice[6], NULL, NULL);
  Tree *P2 = new Tree(desc[4], choice[4], L3, L4);
  Tree *R = new Tree(desc[0], choice[0], P1, P2);
  Game *dragonGame = new Game(R);
  dragonGame->startGame();
}
