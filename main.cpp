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
void processE(char p, int& rn, vector<Room*>& r);//does exit exist --> move if so--> basically move rooms
void processD(char p[15], int& rn, vector<item*>& i, vector<Room*>& r);//does item exist in player inv --> drop if so
void processT(char p[15], int& rn, vector<item*>& i, vector<Room*>& r);//does item exist in room inv -- take if so
void help();//cout possible inputs
void drop();//remove item from player inv and add to room inv
void take();//opposite of drop
void quit();//delete vector objects and all that stuff, say goodbye


//main class
int main()
{
  vector<item*> playerInv;//player inventory
  item* test = new item;
  char test1[15] ="banana";
  (*test).name = new char[15];
  strcpy((*test).name, test1);
  playerInv.push_back(test);
  int playing = 0; 
  int roomN = 2; //current room number
  char playerInput[15];//player input
  char dir; //dir input
  //hello, room vector!
  vector<Room*> rooms;//room vector
  mkRoom(rooms);
  cout << "Wakey wakey, friend\n No need to look around like that, you won't see me\n Why? Because I'm in your head, of course!"<<endl;
  cout << "You seem confused. Ask me for [help] if you don't know what you're doing!"<<endl;
  descRoom(roomN, rooms);//print out first room
  while(playing == 0)
  {
    playerInput[0] = '\0';
    cout << endl;
    cout<<"do you want to do anything?" << endl;
    cin >> playerInput;
    cin.ignore(10, '\n');
    cin.clear();
    cout << endl;
    if(strcmp(playerInput, "quit")==0)
    {
      quit();
      playing = 1;
    }
    else if(strcmp(playerInput, "go")==0)
    {
      //ask dir
      cout << "Go where?"<<endl;
      cin >> dir;
      cin.ignore(10, '\n');
      cout.clear();
      //confirm if possible + act
      processE(dir, roomN, rooms);
    }
    else if(strcmp(playerInput, "drop")==0)
    {
      //ask what to drop
      cout << "current items:"<<endl;
      if (playerInv.empty() != true)
      {
	for (vector<item*>::iterator it = playerInv.begin(); it != playerInv.end(); ++it)
	{
	  cout << (*(*it)).name<<endl;
	}
      }
      cout<<"Room item:"<<endl;
      if((*((*(rooms.begin()+roomN))->getI())).empty() != true)
      {
	for (vector<item*>::iterator it = (*((*(rooms.begin()+roomN))->getI())).begin(); it != (*((*(rooms.begin()+roomN))->getI())).end(); ++it)
	  cout << (*(*it)).name<<endl;
      }
      cout << "Drop what?"<<endl;
      cin >> playerInput;
      cin.ignore(10, '\n');
      cin.clear();
      //check if in inv + act
      cout << "okay"<<endl;
      processD(playerInput, roomN, playerInv, rooms);
      //cout << (*((*((*(rooms.begin()+roomN))->getI())).begin()+1))->name<<endl;
      
    }
    else if(strcmp(playerInput, "take")==0)
    {
      cout << "current items:"<<endl;
      if (playerInv.empty() != true)
      {
        for (vector<item*>::iterator it = playerInv.begin(); it != playerInv.end(); ++it)
	{
          cout << (*(*it)).name<<endl;
        }
      }
      cout<<"Room item:"<<endl;
      if((*((*(rooms.begin()+roomN))->getI())).empty() != true)
      {
        for (vector<item*>::iterator it = (*((*(rooms.begin()+roomN))->getI())).begin(); it != (*((*(rooms.begin()+roomN))->getI())).end(); ++it)
          cout << (*(*it)).name<<endl;
      }
      //ask what
      cout << "Take what?"<<endl;
      cin >> playerInput;
      cin.ignore(10, '\n');
      cin.clear();
      //check room inv + act
      processT(playerInput, roomN, playerInv, rooms);
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
  //cout << "HELLO"<< endl;
  d[0]='\0';
  strcpy(d, "[Stump] Well. It's rather spacious here, which is nice. Not much easier to breathe, given how you look.");
  //cout << "HI"<<endl;
  Room* ro3 = new Room();
  (*ro3).setD(d);//4
  d[0] = '\0';
  //ITEMS
  item* i1 = new item;//random item object
  char n1[15] = "old_shield";//random array to hold item name
  (*i1).name = new char[15];//NEVER FORGET!!!!
  strcpy((*i1).name, n1);
  (*ro2).setI(i1);//r3 item
  //cout << "HIIIII"<<endl;
  //EXITS
  char* c = new char;
  (*c) = 'e';
  (*ro).setR(c, ro3);
  //(*ro1).setR('n', ro3);
  char* c2 = new char;
  (*c2) = 'w';
  (*ro2).setR(c2, ro3);
  char* c3 = new char;
  //PUSH BACK
  r.push_back(ro);
  r.push_back(ro1);
  r.push_back(ro2);
  r.push_back(ro3);
}

void updateRooms(vector<Room*>& r)
{
  
}

void descRoom(int n, vector<Room*>& r)
{
  cout << ((*(r.begin()+n))->getD())<< endl;//description
  cout << "ITEMS:" << endl;
  for (vector<item*>::iterator it =((*(*(r.begin()+n))).getI())->begin(); it != ((*(*(r.begin()+n))).getI())->end(); ++it)
  {
    cout << (*(*it)).name << endl;
  }
  cout << "EXITS:"<<endl;
  for(auto exits : ((*(r.begin()+n))->getR()))//learned about auto from https://www.w3schools.com/cpp/cpp_maps.asp 
  {
    cout << (*(exits.first)) << endl;
  }
}

//p is playerInput, rn is room number
void processE(char p, int& rn, vector<Room*>& r)
{
  int tempRoom = 0;
  int roomExist = 0;//room does exist = 0
  for(auto exits : ((*(r.begin()+rn))->getR()))//check all keys and see 
  {
    
    cout<<(exits.first);
    cout<<p;
    if((*(exits.first)) == p)//exit exists
    {
      //cout << "here";
      roomExist = 1;
      //find room number in room vector
      for(vector<Room*>::iterator it =r.begin(); it != r.end(); ++it)
      {
	//cout<<((*(r.begin()+rn))->getD());
	char d1[300];//just...make an array for safety reasons.
	strcpy(d1,(*it)->getD());
	//cout << ((*it)->getD())<<endl;
	char d2[300];
	strcpy(d2,(*(r.begin()+rn))->getD());
	//cout << d1;
	//cout << d2;
	if(strcmp(d1,d2))//if room is found, compare the room descriptions...find a better way if possible
	{
	  //cout<<"HERE";
	  rn = tempRoom;
	  descRoom(rn, r);
	}
	++ tempRoom;
      }
    }
  }
  if(roomExist == 0)//room doesn't exist
  {
    cout << "that doesn't exist."<<endl;
  }
}

void processD(char p[15], int& rn, vector<item*>& i, vector<Room*>& r)
{
  //cout << "HI";
  if(i.empty()==false)
  {
    //cout << (*(i.begin()))->name;
    for (vector<item*>::iterator it = i.begin(); it != i.end(); ++it)//go through player inventory
      {
	//cout << (*(*it)).name;
	//cout << p;
	if(strcmp((*(*it)).name, p)==0)
	  { 
	    //(*newI).name = new char[15];
	    //strcpy((*newI).name, p);//after setting name, push it into room next
	    (*(r.begin()+rn))->setI((*it));//give the room the pointer instead
	    i.erase(it);//erase the pointer from the players inventory 
	    cout <<"ROOM:"<<endl;
	    for (vector<item*>::iterator it = (*((*(r.begin()+rn))->getI())).begin(); it != (*((*(r.begin()+rn))->getI())).end(); ++it)
	    {
	      cout << (*(*it)).name<<endl;
	    }
	    if (i.empty()==false)
	    {
	      for (vector<item*>::iterator it = i.begin(); it != i.end(); ++it)
	      {
		cout << (*(*it)).name<<endl;
	      }
	    }
	    return;
	  }
      }
  }
  cout << "Oh ho ho, that doesn't seem to exist!"<<endl;
}

void processT(char p[15], int& rn, vector<item*>& i, vector<Room*>& r)//pretty much the opposite dir of drop, so code can be similar
{
    //cout << "HI";
  if((*((*(r.begin()+rn))->getI())).empty()==false)
  {
    //cout << (*(i.begin()))->name;
    for (vector<item*>::iterator it = (*((*(r.begin()+rn))->getI())).begin(); it != (*((*(r.begin()+rn))->getI())).end(); ++it)//go through room inventory
      {
        //cout << (*(*it)).name;
        //cout << p;
        if(strcmp(((*(*it)).name), p)==0)
          {
            i.push_back((*it));//give the player inventory the pointer instead
            (*((*(r.begin()+rn))->getI())).erase(it);//erase the pointer from the players inventory
	    cout <<"ROOM:"<<endl;
	    if ((*((*(r.begin()+rn))->getI())).empty() == false)
	    {
	      for (vector<item*>::iterator it = (*((*(r.begin()+rn))->getI())).begin(); it != (*((*(r.begin()+rn))->getI())).end(); ++it)
	      {
		cout << (*(*it)).name<<endl;
	      }
	    }
	    for (vector<item*>::iterator it = i.begin(); it != i.end(); ++it)
            {
	      cout << (*(*it)).name<<endl;
	    }
	    return;
          }
      }
  }
  cout << "Oh ho ho, that doesn't seem to exist!"<<endl;
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

void quit()
{
}
