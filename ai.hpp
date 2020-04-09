#include <iostream>
#include <string>
using namespace std;

int min(int *c, int n) {
  int result; int *p=c;
  while(*p==0) p++;
  result=*p;
  for(int i=0; i<n; i++) if(c[i]<result && c[i]!=0) result=c[i];
  return result;
}
int minPlace(int *c, int n) {
  for(int i=0; i<n; i++) {
    if(c[i]==min(c, n)) return i;
  }
  return 0;
}
int max(int *c, int n) {
  int result=0;
  for(int i=0; i<n; i++) if(c[i]>result) result=c[i];
  return result;
}
int maxPlace(int *c, int n) {
  for(int i=0; i<n; i++) {
    if(c[i]==max(c, n)) return i;
  }
  return 0;
}
int min0(int *c, int n) {
  int result=*c;
  if(result!=0) for(int i=0; i<n; i++) if(c[i]<result) result=c[i];
  return result;
}
int min0Place(int *c, int n) {
  for(int i=0; i<n; i++) {
    if(c[i]==min0(c, n)) return i;
  }
  return 0;
}

class GreedyPlayer: public Player {
private:
  string type;

public:
  GreedyPlayer(const string &n): Player(n), type("Greedy") {} 
  ~GreedyPlayer()  {}

  const string &getType() const override {return type;}
  Move play(const State &s) override {
    // Move(from, take, to, put)
    return Move(maxPlace(s.getAllCoins(), s.getHeaps()), max(s.getAllCoins(), s.getHeaps()), 0, 0);
  }
};

class SpartanPlayer: public Player {
private:
  string type;

public:
  SpartanPlayer(const string &n): Player(n), type("Spartan") {}
  ~SpartanPlayer()  {}

  const string &getType() const override {return type;}
  Move play(const State &s) override {
    // Move(from, take, to, put)
    return Move(maxPlace(s.getAllCoins(), s.getHeaps()), 1, 0, 0);
  }
};

class SneakyPlayer: public Player {
private:
  string type;

public:
  SneakyPlayer(const string &n): Player(n), type("Sneaky") {}
  ~SneakyPlayer()  {}

  const string &getType() const override {return type;}
  Move play(const State &s) override {
    // Move(from, take, to, put)
    return Move(minPlace(s.getAllCoins(), s.getHeaps()), min(s.getAllCoins(), s.getHeaps()), 0, 0);
  }
};

class RighteousPlayer: public Player {
private:
  string type;

public:
  RighteousPlayer(const string &n): Player(n), type("Righteous") {}
  ~RighteousPlayer()  {}

  const string &getType() const override {return type;}
  Move play(const State &s) override {
    // Move(from, take, to, put)
    if(max(s.getAllCoins(), s.getHeaps())/2!=0) return Move(maxPlace(s.getAllCoins(), s.getHeaps()), max(s.getAllCoins(), s.getHeaps())/2, min0Place(s.getAllCoins(), s.getHeaps()), max(s.getAllCoins(), s.getHeaps())/2-1);
    else return Move(maxPlace(s.getAllCoins(), s.getHeaps()), max(s.getAllCoins(), s.getHeaps()), minPlace(s.getAllCoins(), s.getHeaps()), 0);
  }
};

class LegitPlayer: public Player {
private:
  string type;

public:
  LegitPlayer(const string &n): Player(n), type("No Type") {}
  ~LegitPlayer()  {}

  const string &getType() const override {return type;}
  Move play(const State &s) override {
    string approval; int take, from, put, to;
    do { 
      from=0; put=0; to=0;
      int CoinsTaken=0;
      cout<<"How many coins do you take? "; cin>>take; CoinsTaken+=take;
      if(take>0) {cout<<"From which heap? "; cin>>from; from--;}
      if(CoinsTaken-1>0) {
        cout<<"How many do you put? (you can put up to "<<CoinsTaken-1; 
        if(CoinsTaken-1!=1) cout<<" coins) "; else cout<<" coin) ";
        cin>>put; 
        CoinsTaken-=put;
        if(put!=0) {cout<<"On which heap? "; cin>>to; to--;}
      }
      while (getchar()!='\n');
      cout<<"Are you sure? "; getline(cin, approval);
    } while(approval=="no" || approval=="No");
    cout<<endl<<name<<" ";
    return Move(from, take, to, put);
  }
};