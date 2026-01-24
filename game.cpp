#include <iostream>
#include <fstream>
#include<iomanip>
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

string d1 = "welcome to a dragon’s adventure!! the problems of a dragon are somewhat unique (best location for a treasure stash, dutiful and murderous knights, cave comfort levels etc) but today, this dragon’s issues are closer to home. help this dragon become more swag-like in nature as you encounter shifty pirates and cute creatures together!!\n\nZombit, the Tender One woke up to another morning with a sore back and slimy scales. Zombit, the Tender One groaned, fluttered their wings, and got up. with no plans for the day, Zombit, the Tender One flew up to get a dragon’s eye view of the landscape. the beach beckoned! it seemed relaxed today. they could see a bunch of cute critters running about, it seemed like an excellent day for the beach! on the other hand, the regular hustle and bustle of the city seemed even more hustling and bustling. Zombit, the Tender One gasped as a fight broke out and a few buildings nearby crumbled slightly.\n\nwhere will Zombit, the Tender One go today?";
string c1 = "|| A - lets take a day off at the beach!\n|| B - i need to see what mishaps are going on in the city!";
string d2 = "the sun glittered pleasingly off Zombit, the Tender One’s scales. they buried themselves partially in the sand, keeping their head above while they pondered whether to go swimming or not. but before they got the chance to decide, a small binky cat came up to them! he looked upset and a little worried…a face a small cat should never be making. the cat started, “please! you seem wise. i need help finding my friend, we were meant to be hanging out today! my name is chococat, and my friends name is jinbe-san. meow!!!”\n\nZombit, the Tender One exclaimed, 'of course i can help!! where did your friend say to meet?'\n\nchococat cried one small tear… 'i cant remember exactly! all i can recall is they said the meeting place is somewhere we can smile together [musical note]'\n\nwhere should chococat go?";
string c2 = "|| A - jinbe-san is a whale shark right? u can smile together in the ocean !! lets fly and see if we can find jinbe-san out there\n|| B - u can smile together anywhere !!! lets have a good attitude and jinbe-san will come";
string d3 = "Zombit, the Tender One smiled. 'too easy! i know jinbe-san is a whale shark, so they must have meant the ocean.' they leapt out of the sand, and shook the sand off their back. 'climb on, lets see if we can find them out there!!'\n\nthey flew carefully for a few minutes, before spotting a cheerful head popping out of the water.\n\n'jinbe-san!!!' chococat was joyous to find his friend. Zombit, the Tender One lowered him gently on to jinbe-san’s back. they all played happily and drank lots of tea, before the evening grew imminent. Zombit, the Tender One and chococat waved goodbye to jinbe-san, before Zombit, the Tender One took chococat home. Zombit, the Tender One smiled happily once tucked in at their home, comfortable under their rock blanket. what a sweet day they had!\n\ncongratulations!!!! you have earned one out of two good endings.";
string c3 = "|| Q - to quit\n|| S - to start again";
string d4 = "chococat sat down uncertainly, but agreed to wait. he played with the sand as the hours passed before he started to burst into tears. Zombit, the Tender One attempted to comfort him, saying jinbe-san was surely here soon. at these words, a very beautiful and cool dragon trotted up to them. Zombit, the Tender One was immediately jealous at the effortless cool swagger of this dragon.\n\n'hey..are you guys looking for jinbe-san? i just passed them a few minutes ago, i can take you to them?'\n\nchococat immediately perked up, and climbed up on the nonchalant dragon’s back. Zombit, the Tender One watched them leave, with a mix of relieved and envious feelings. i wish i could be that cool and valiant, they thought to themselves…\n\noh no..this is a bad outcome!! try again?";
string d5 = "Zombit, the Tender One made it to the city just slightly too late. a pile of people wearing eye-patches and striped shirts lay in the dust. they recognised sanji and zoro standing above them, smirking. Zombit, the Tender One caught the end of their conversation as zoro said to sanji, 'yare yare..thats done. now back to putting up these posters.’ sanji nodded, 'let us cook..'\n\nwith the blink of Zombit, the Tender One’s massive glowing eyes, the walls were covered in posters that clumsily claimed the strawhats were looking for a new member!! wow!! Zombit, the Tender One had always wanted a life at sea, now is their chance!!\n\nhow should Zombit, the Tender One prove themselves to these pirates?";
string c4 = "|| A - i need to show off my unique dragon skills…let me breathe fire and fly around so cooly\n|| B - i need to do what a pirate would do..let me train a pigeon to sit on my shoulder like its a parrot";
string d6 = "Zombit, the Tender One first, to grab attention, moved and grooved past the strawhats. Zombit, the Tender One didn’t even give them a glance as Zombit, the Tender One walked past. then, with little else preamble, Zombit, the Tender One launched into the air. they did a series of flips, spirals, and wiggles, with greater and greater complexity. finally, they breathed fire into a cool edgy shape (knife) which floated in the air before exploding into a pile of petals.\n\nzoro and sanji stood with their mouths agape.\n\nsanji was the first to break the silence. 'A woman’s smile is the finest treasure a man can ever behold! however the second finest treasure is this performance.'\n\nzoro agreed, 'To face one who is extraordinary, I cannot allow myself to be ordinary. i must learn from you, please join the strawhats!'\n\nZombit, the Tender One of course, agreed!! the pirates life for me!!!!\n\ncongratulations!!!! you have earned one out of two good endings.";
string d7 = "finding a pigeon to train only took seconds. training the pigeon, proved harder. the pigeon failed to grasp that sitting on shoulder politely equalled treat, and instead clawed and bit at Zombit, the Tender One’s shoulder as if it was a treat dispenser. Zombit, the Tender One’s groans of pains finally drew the attention of zoro and sanji, who came over.\n\n'How are you feeling down there? The moment your hope turned into despair i noticed and laughed at you,' said zoro swagly.\n\n'They say laughter is the best medicine; I say, it pairs well with a good steak!' Sanji noted. Zombit, the Tender One tried to force a laugh, but didnt feel any better. Zoro and sanji grimaced openly, and turned away.\n\nConfused and defeated, Zombit, the Tender One flew home and lived the rest of their days lawfully, on ground.\n\noh no..this is a bad outcome!! try again?";


void fileVersion();

string wraptext(string input, int width);


int main() {
  char a;
  cout << endl << endl << endl;
  cout << "merry xmas Sam!! press any key to play ur game: ";
  cin >> a;
  cout << endl << endl << endl;
  int w = 90;
  Tree *L1 = new Tree(wraptext(d3, w), c3, NULL, NULL);
  Tree *L2 = new Tree(wraptext(d4, w), c3, NULL, NULL);
  Tree *P1 = new Tree(wraptext(d2, w), wraptext(c2, w), L1, L2);
  Tree *L3 = new Tree(wraptext(d6, w), c3, NULL, NULL);
  Tree *L4 = new Tree(wraptext(d7, w), c3, NULL, NULL);
  Tree *P2 = new Tree(wraptext(d5, w), wraptext(c4, w), L3, L4);
  Tree *R = new Tree(wraptext(d1, w), c1, P1, P2);
  Game *dragonGame = new Game(R);
  dragonGame->startGame();
}

void fileVersion() {

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

}

string wraptext(string input, int width) {
  int i = width;
  while (i < input.length()) {
    while (input[i] != ' ') {
      i--;
    }
    input.insert(i, "\n");
    input.erase(i + 1, 1);
    i = width + i;
  }
  return input;
}
