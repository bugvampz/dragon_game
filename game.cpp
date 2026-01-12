#include <iostream>
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
  } else {
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


}
