#include <iostream>
#include <stdexcept>
using namespace std;

class Game {
private:
  int playerCounter, heapCounter;
  int playerCount, heapCount;
  int *heaps;
  int *players;
  string *names;

public:
  Game(int h, int p): playerCounter(0), heapCounter(0), heapCount(h), playerCount(p) {
    heaps=new int[h];
    players=new int[p];
    names=new string[p];
  }
  ~Game() {
    delete heaps;
    delete players;
    //delete names; 
  }

  void addHeap(int coins) throw (logic_error) {
    if(heapCounter==heapCount) throw logic_error("limit reached");
    heaps[heapCounter++]=coins;
  }
  void addPlayer(Player *player) throw (logic_error) {
    if(playerCounter==playerCount) throw logic_error("limit reached");
    if(player->getType()=="No Type") {
      *(names+playerCounter)=player->getName();
      players[playerCounter++]=0;
    }
    if(player->getType()=="Greedy") {
      *(names+playerCounter)=player->getName();
      players[playerCounter++]=1;
      cout<<*player<<" joined the game"<<endl;
      }
    if(player->getType()=="Spartan") {
      *(names+playerCounter)=player->getName();
      players[playerCounter++]=2;
      cout<<*player<<" joined the game"<<endl;
    }
    if(player->getType()=="Sneaky") {
      *(names+playerCounter)=player->getName();
      players[playerCounter++]=3;
      cout<<*player<<" joined the game"<<endl;
    }
    if(player->getType()=="Righteous") {
      *(names+playerCounter)=player->getName();
      players[playerCounter++]=4;
      cout<<*player<<" joined the game"<<endl;
    }
  }
  void play(ostream &out) {
    State s(heapCount, heaps); int lastPlayer; bool over=false; string lastPlayerName;
    cout<<"State: "<<s<<endl<<endl; 
    while(!over) {
      for(int i=0; i<playerCount && !over; i++) {
        if(players[i]==0) {
          LegitPlayer *p=new LegitPlayer(*(names+i));
          cout<<"It's "<<p->getName()<<"'s turn:"<<endl;
          s.next(p->play(s));
          lastPlayer=i; lastPlayerName=p->getName();
          delete p;
        }
        if(players[i]==1) {
          GreedyPlayer *p=new GreedyPlayer(*(names+i));
          cout<<"It's "<<p->getName()<<"'s turn"<<endl;
          cout<<*p<<" ";
          s.next(p->play(s));
          lastPlayer=i; lastPlayerName=p->getName();
          delete p;
        }
        if(players[i]==2) {
          SpartanPlayer *p=new SpartanPlayer(*(names+i));
          cout<<"It's "<<p->getName()<<"'s turn"<<endl;
          cout<<*p<<" ";
          s.next(p->play(s));
          lastPlayer=i; lastPlayerName=p->getName();
          delete p;
        }
        if(players[i]==3) {
          SneakyPlayer *p=new SneakyPlayer(*(names+i));
          cout<<"It's "<<p->getName()<<"'s turn"<<endl;
          cout<<*p<<" ";
          s.next(p->play(s));
          lastPlayer=i; lastPlayerName=p->getName();
          delete p;
        }
        if(players[i]==4) {
          RighteousPlayer *p=new RighteousPlayer(*(names+i));
          cout<<"It's "<<p->getName()<<"'s turn"<<endl;
          cout<<*p<<" ";
          s.next(p->play(s));
          lastPlayer=i; lastPlayerName=p->getName();
          delete p;
       }
        cout<<"State: "<<s<<endl<<endl; 
        over=s.winning();
        if(over) cout<<lastPlayerName<<" wins!"<<endl<<endl;
      }
    }
    cout<<"GAME OVER"<<endl;
  }
};