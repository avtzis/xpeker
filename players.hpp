#include <iostream>
#include <string>
using namespace std;

class Player {
protected:
  string name;

public:
  Player(const string &n): name(n) {}
  virtual ~Player() {}

  virtual const string &getName() const {return name;}
  virtual const string &getType() const = 0;
  virtual Move play(const State &s) = 0;

  friend ostream& operator<<(ostream &out, const Player &player) {
    out<<player.getType()<<" player "<<player.name;
    return out;
  }
};