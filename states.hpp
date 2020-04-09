#include <iostream>
#include <stdexcept>
using namespace std;

class State {
private:
  int *coins, heaps;

public:
  State(int h=0, const int c[]=0) {
    coins=new int[h]; heaps=h;
    for(int i=0; i<h; i++) *(coins+i)=c[i];
  }
  ~State() {delete coins;}

  void next(const Move &move) throw(logic_error) {
    if(move.getTarget()<0 || 
       move.getTarget()>heaps || 
       move.getSource()<0 || 
       move.getSource()>heaps) 
     throw logic_error("invalid heap");
    if(coins[move.getSource()]<move.getSourceCoins())
     throw logic_error("too many coins to take");
    if(move.getSourceCoins()<=0 || move.getTargetCoins()<0)
     throw logic_error("invalid coin quantity");
    if(move.getSourceCoins()-1<move.getTargetCoins())
     throw logic_error("cannot put that many coins");
    
    coins[move.getSource()]-=move.getSourceCoins();
    coins[move.getTarget()]+=move.getTargetCoins();
    cout<<move<<endl<<endl<<endl;
  }
  bool winning() {
    for(int i=0; i<heaps; i++) if(coins[i]!=0) return false;
    return true;
  }
  
  int getHeaps() const {return heaps;}
  int getCoins(int h) const throw(logic_error) {
    if(h<0 || h>=heaps) throw logic_error("invalid heap");
    return *(coins+h);
  }
  int *getAllCoins() const {return coins;}

  friend ostream& operator<<(ostream &out, const State &s) {
    for(int i=0; i<s.heaps; i++) {
      out<<s.coins[i];
      if(i<s.heaps-1) cout<<", ";
    }
    return out;
  }
};