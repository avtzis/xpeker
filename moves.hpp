#include <iostream>
using namespace std;

class Move {
private:
  int SourceHeap, SourceCoins, TargetHeap, TargetCoins;

public:
  Move(int sh, int sc, int th, int tc): SourceHeap(sh), SourceCoins(sc), TargetHeap(th), TargetCoins(tc) {}

  int getSource() const {return SourceHeap;}
  int getSourceCoins() const {return SourceCoins;}
  int getTarget() const {return TargetHeap;}
  int getTargetCoins() const {return TargetCoins;}

  friend ostream &operator<<(ostream &out, const Move &move) {
    cout<<"takes ";
    out<<move.SourceCoins; 
    cout<<" coin"; if(move.SourceCoins!=1) cout<<"s";
    if(move.SourceCoins!=0) {
      cout<<" from heap ";
      out<<move.SourceHeap+1; //-1
    }
    cout<<" and puts ";
    if(move.TargetCoins==0) cout<<"nothing";
    else { 
      out<<move.TargetCoins; 
      cout<<" coin"; if(move.TargetCoins!=1) cout<<"s";
      cout<<" to heap ";
      out<<move.TargetHeap+1; //-1
    }
    return out;
  } 
};