/*
Aparajita Baidya
12/1/2025

to do:
Room Class
Parser -->
Verify command words -->
return commands - 2 seperate words (ex: "go west" --> "go" (action) "west" (direction)) for process command func
main functions:
- mkRooms
- updateRooms
- processComd
- showInventory
- help
- drop
- take
- goRoom
- quit
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <map>
//header files
#include "Room.h"

using namespace std;

//function defs
void mkRoom(vector<Room*>& r);//set up room vector
void updateRooms(vector<Room>* r);//check certain room conditions
void descRoom(int n, vector<Room*>& r);//spit out that room description
void processE();//does exit exist
void processD();//does item exist in player inv
void processT();//does item exist in room inv
void help();//cout possible inputs
void drop();//remove item from player inv and add to room inv
void take();//opposite of drop
void goRoom();//switch current room, cout new room details
void quit();//delete vector objects and all that stuff, say goodbye


//main class
int main()
{
  vector<item> playerInv;//player inventory
  int playing = 0; 
  int roomN = 2; //current room number
  int playInput[15];//player input
  //hello, room vector!
  vector<Room*> rooms;//room vector
  mkRoom(rooms);
  cout << "Wakey wakey, friend\n No need to look around like that, you won't see me\n Why? Because I'm in your head, of course!"<<endl;
  cout << "You seem confused. Ask me for [help] if you don't know what you're doing!"<<endl;
  descRoom(roomN, rooms);//print out first room
  while(playing == 0)
  {
    cout << endl;
    cout<<"do you want to do anything?" << endl;
    cin >> playInput;
    cin.ignore(10, '\n');
    cin.clear();
    cout << endl;
    if(strcmp(playInput, "quit"))
    {
      quit();
      playing = 1;
    }
    else if(strcmp(playerInput, "go"))
    {
      //ask dir
      cout << "Go where?";
      cin >> playerInput;
      cin.ignore(10, '\n');
      cout.clear();
      //confirm if possible
      //either ask again
    }
    else if(strcmp(playerInput, "drop"))
    {
      //ask what to drop
      cout << "Drop what?";
      //check if in inv
      //move to room if poss
    }
    else if(strcmp(playerInput, "take"))
    {
      //ask what
      //check room inv
      //move to player inv if poss
    }
  }
  return 0;
}


//functions
void mkRoom(vector<Room*>& r)
{
  //DESCRIPTIONS
  char d[300] = "[Root 1] Endless paths behind you, and all of them would lead up to here. Anyways, lemme describe this place! Dark, damp, and dusty!";
  Room* ro = new Room();//just...gonna manually make all 15 rooms
  (*ro).setD(d);//1
  d[0] = '\0';
  strcpy(d, "[Root 2] Quite similar to the 1st-oh look, theres a little hand sticking out of the ground! Say hi!It seems like it likes to trade...");
  Room* ro1 = new Room();
  (*ro1).setD(d);//2
  d[0]='\0';
  strcpy(d, "[Root 3] There really isn't much difference when it comes to the roots. The 1st looks like the 2nd, the 2nd like the 3rd...it is rather boring to be here, actually.");
 
  Room* ro2 =new Room();
  (*ro2).setD(d);//3
  cout << "HELLO"<< endl;
  d[0]='\0';
  strcpy(d, "[Stump] Well. It's rather spacious here, which is nice. Not much easier to breathe, given how you look.");
  Room* ro3 = new Room();
  (*ro3).setD(d);//4
  d[0] = '\0';
  //ITEMS
  item i1;//random item object
  char n1[15] = "old shield";//random array to hold item name
  i1.name = new char[15];//NEVER FORGET!!!!
  strcpy(i1.name, n1);
  (*ro2).setI(i1);//r3 item
  //EXITS
  char* c = new char;
  (*c) = 'e';
  (*ro).setR(c, ro3);
  //(*ro1).setR('n', ro3);
  char* c2 = new char;
  (*c2) = 'w';
  (*ro2).setR(c2, ro3);
  //PUSH BACK
  r.push_back(ro);
  r.push_back(ro1);
  r.push_back(ro2);
  r.push_back(ro3);
}

void updateRooms(vector<Room*>& r))
{
  
}

void descRoom(int n, vector<Room*>& r)
{
  cout << ((*(r.begin()+n))->getD())<< endl;//description
  cout << "ITEMS:" << endl;
  for (vector<item>::iterator it =(*((*(r.begin()+n))->getI())).begin(); it != (*((*(r.begin()+n))->getI())).end(); ++it)
  {
    cout << (*it).name << endl;
  }
  cout << "EXITS:"<<endl;
  for(auto exits : ((*(r.begin()+n))->getR()))//learned about auto from https://www.w3schools.com/cpp/cpp_maps.asp 
  {
    cout << (*(exits.first)) << endl;
  }
}
//p is playerInput, rn is room number
void processE(char p[15], int rn, vector<Room*>& r)
{
  
}
void processD(char p[15], int rn, vector<item>& i)
{
}
void processT(char p[15], int rn, vector<Room*>& r)
{
}

void help()
{
  cout << "type [go], enter, then type either [n][e][s][w] to move rooms."<<endl;
  cout << "type [take], enter, then the name of object to pick up item." << endl;
  cout << "type [drop], enter, then the name of object to drop it." << endl;
  cout << "type [quit] to end the game."<<endl;
}

void drop()
{
}

void take()
{
}

void goRoom()
{
}

void quit()
{
}
