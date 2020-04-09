#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>
#include "moves.hpp"
#include "states.hpp"
#include "players.hpp"
#include "ai.hpp"
#include "game.hpp"
using namespace std;

string getRandomType() {
  map<int, string> botType;  
    botType[0]="Greedy";
    botType[1]="Spartan";
    botType[2]="Sneaky";
    botType[3]="Righteous";

  int random=(rand()%4);
  return botType[random];
}
string getRandomName() {
  map<int, string> botName; 
    botName[0]="Jeremy";
    botName[1]="Joshua";
    botName[2]="Jordan";
    botName[3]="Jonathan";
    botName[4]="Joah";
    botName[5]="Jimmy";
    botName[6]="Jeffrey";
    botName[7]="Jeff";
    botName[8]="Joe";
    botName[9]="Jendi";

  int random=(rand()%10);
  return botName[random];
}

int main() {
  cout<<"Welcome to xPeker!"<<endl<<endl<<endl;
  int option;
  do {
    cout<<"Preparing the table:"<<endl<<endl;

    //heaps
    cout<<"Heaps: "; int heaps; cin>>heaps; int heap[heaps];
    for(int i=0; i<heaps; i++) {
      cout<<"Heap "<<i+1<<", coins: ";
      cin>>heap[i];
    }
    //AI
    cout<<endl<<"Bots: "; int bots; cin>>bots;
    //players
    cout<<endl<<"Players: "; int players; cin>>players;

    //game setup
    Game g(heaps, players+bots);
    while (getchar()!='\n');
    for(int i=0; i<players; i++) {
      cout<<"Player("<<i+1<<")'s name: "; 
      string playerName; getline(cin, playerName);
      g.addPlayer(new LegitPlayer(playerName));
    }
    cout<<endl;
    srand((unsigned) time(0));
    string lastName; string lastType;
    for(int i=0; i<bots; i++) { 
      string botName(getRandomName()); string botType(getRandomType());
      if(botName==lastName || botType==lastType) {i--; continue;}
      if(botType=="Greedy") g.addPlayer(new GreedyPlayer(botName));
      if(botType=="Spartan") g.addPlayer(new SpartanPlayer(botName));
      if(botType=="Sneaky") g.addPlayer(new SneakyPlayer(botName));
      if(botType=="Righteous") g.addPlayer(new RighteousPlayer(botName));
      lastName=botName; lastType=botType;
    }
    for(int i=0; i<heaps; i++) g.addHeap(heap[i]);


    //game
    do {
      cout<<endl<<"Press enter to start..."; while (getchar()=='\0');
      cout<<endl<<endl<<"Game begins!"<<endl<<endl<<endl;
      g.play(cout);
      cout<<endl<<endl<<"What would you like to do?"<<endl;
      cout<<endl<<"1. Play again"<<endl<<"2. Back to game setup"<<endl<<"3. Exit"<<endl;
      cin>>option;
      while (getchar()!='\n');
    } while(option==1);
  } while(option==2);
}