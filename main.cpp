/*
Aparajita Baidya
12/5/2025

to do:
main functions:
- mkRooms
- updateRooms
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
void updateRooms(int& r10, int& r8, int& r11, int& r14, int& r15, vector<Room*>& r);//check certain room conditions
void descRoom(int n, vector<Room*>& r);//spit out that room description
void processE(char p, int& rn, vector<Room*>& r);//does exit exist --> move if so--> basically move rooms
void processD(char p[15], int& rn, vector<item*>& i, vector<Room*>& r);//does item exist in player inv --> drop if so
void processT(char p[15], int& rn, vector<item*>& i, vector<Room*>& r);//does item exist in room inv -- take if so
void help();//cout possible inputs
void quit(vector<item*>& i, vector<Room*>& r);//delete vector objects and all that stuff, say goodbye
void end();

//main class
int main()
{
  int openR10 = 0;//if greater than 0, then door is open
  int openR8 = 0;
  int openR11 = 0;
  int openR14 = 0;
  int openR15 = 0;
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
      playing = 1;
      quit(playerInv, rooms);
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
    updateRooms(openR10, openR8, openR11, openR14, openR15, rooms);
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
  strcpy(d, "[Root 2] Quite similar to the 1st-oh look, theres a little hand sticking out of the ground! Say hi! It seems like it likes to trade...");
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
  strcpy(d,"[Heart] Oh, look at this. The king is resting against the birch wood. Next to him...a pond that seems to really want a sword. Funky.");
  Room* ro4 = new Room();
  (*ro4).setD(d);//5
  d[0] = '\0';
  strcpy(d, "[Crown] Haha, I feel like I can almost see the sky beyond the leaves!");
  Room* ro5 = new Room();
  (*ro5).setD(d);//6
  d[0] = '\0';
  strcpy(d, "[1st Branch] A tall statue of a one-armed spearman wants its spear. He looks like you, hehe. You know what to do.");
  Room* ro6 = new Room();
  (*ro6).setD(d);//7
  d[0] = '\0';
  strcpy(d, "[2nd Branch] A bedchamber in a lake. In a tree. Okay, sure. Tell me, do you usually see beds like this in trees? Yeah, I didn't think so");
  Room* ro7 = new Room();//8
  (*ro7).setD(d);
  d[0] = '\0';
  strcpy(d, "[3rd Branch] Piles of cloth and armor lay at the foot of a door. Oh, uh, don't worry about the blood.");
  Room* ro8 = new Room();
  (*ro8).setD(d);//9
  d[0] = '\0';
  strcpy(d, "[4th Branch] A battlefield. Alrighty then! At least the fight is over! Mind your step, though. It's...a little bit messy...I don't really need to tell you that, though.");
  Room* ro9 = new Room();
  (*ro9).setD(d);//10
  d[0] = '\0';
  strcpy(d, "[5th Branch] Lonely, lonely, I feel so lonely-.");
  Room* ro10 = new Room();
  (*ro10).setD(d);//11
  d[0] = '\0';
  strcpy(d, "[6th Branch] A statue of a lady holds her hand out for some water.");
  Room* ro11 = new Room();
  (*ro11).setD(d);//12
  d[0] = '\0';
  strcpy(d, "[7th Branch] Ah, another statue of the spearman! And another door behing him! Hmm, you smell flowers? The sea? Okay then, not sure where that's coming from.");
  Room* ro12 = new Room();
  (*ro12).setD(d);//13
  d[0] = '\0';
  strcpy(d, "[The Garden] White flowers with a soft glow blanket the land before you. Oh, a third statue.\n Are you ready?");
  Room* ro13 = new Room();
  (*ro13).setD(d);//14
  d[0] = '\0';
  strcpy(d, "[To the Isle] The sea you mentioned is here. And so is the boat. Are you ready? Regardless, it's time.");
  Room* ro14 = new Room();
  (*ro14).setD(d);//15
  //ITEMS
  item* i1 = new item;//random item object
  char n1[15] = "old_shield";//random array to hold item name
  (*i1).name = new char[15];//NEVER FORGET!!!!
  strcpy((*i1).name, n1);
  (*ro2).setI(i1);//r3 item
  item* i2 = new item;
  char n2[15] = "torn_cloth";
  (*i2).name = new char[15];
  strcpy((*i2).name, n2);
  (*ro9).setI(i2);//r10 item
  item* i3 = new item;
  char n3[15] = "late_water";
  (*i3).name = new char[15];
  strcpy((*i3).name, n3);
  (*ro7).setI(i3);//r8 item
  item* i4 = new item;
  char n4[15] = "sacred_sword";
  (*i4).name = new char[15];
  strcpy((*i4).name, n4);
  (*ro11).setI(i4);//r11 item
  //get r2 item by trading with hand in r2;
  //cout << "HIIIII"<<endl;
  //EXITS
  //1
  char* c = new char;
  (*c) = 'e';
  (*ro).setR(c, ro3);
  //2
  char* c1 = new char;
  (*c1) = 'n';
  (*ro1).setR(c1,ro3);
  //3
  char* c2 = new char;
  (*c2) = 'w';
  (*ro2).setR(c2, ro3);
  //4
  char* c3 = new char;
  (*c3) = 'n';
  (*ro3).setR(c3, ro4);
  char* c4 = new char;
  (*c4) = 'e';
  (*ro3).setR(c4, ro2);
  char* c5 = new char;
  (*c5) = 's';
  (*ro3).setR(c5, ro1);
  char* c6 = new char;
  (*c6) = 'w';
  (*ro3).setR(c6, ro);
  //5
  char* c7 = new char;
  (*c7) = 'n';
  (*ro4).setR(c7, ro5);
  char* c8 = new char;
  (*c8) = 'w';
  (*ro4).setR(c8, ro6);
  char* c9 = new char;
  (*c9) = 'e';
  (*ro4).setR(c9, ro8);
  char* c10 = new char;
  (*c10) = 's';
  (*ro4).setR(c10, ro3);
  //6
  char* c11 = new char;
  (*c11) = 's';
  (*ro5).setR(c11, ro4);
  char* c12 = new char;
  (*c12) = 'n';
  (*ro5).setR(c12, ro11);
  char* c13 = new char;
  (*c13) = 'e';
  (*ro5).setR(c13, ro12);
  //7
  char* c14 = new char;
  (*c14) = 'e';
  (*ro6).setR(c14, ro4);
  //8
  char* c15 = new char;
  (*c15) = 'n';
  (*ro7).setR(c15, ro8);
  //9
  char* c16 = new char;
  (*c16) = 'w';
  (*ro8).setR(c16, ro4);
  //10
  char* c17 = new char;
  (*c17) = 's';
  (*ro9).setR(c17, ro6);
  //11
  char* c18 = new char;
  (*c18) = 'e';
  (*ro10).setR(c18, ro11);
  //12
  char* c19 = new char;
  (*c19) = 's';
  (*ro11).setR(c19, ro5);
  //13
  char* c20 = new char;
  (*c20) = 'w';
  (*ro12).setR(c20, ro5);
  //14
  char* c21 = new char;
  (*c21) = 's';
  (*ro13).setR(c21, ro11);
  //15, you can't go back when you get to room 15. the game ends here.
  //PUSH BACK
  r.push_back(ro);
  r.push_back(ro1);
  r.push_back(ro2);
  r.push_back(ro3);
  r.push_back(ro4);
  r.push_back(ro5);
  r.push_back(ro6);
  r.push_back(ro7);
  r.push_back(ro8);
  r.push_back(ro9);
  r.push_back(ro10);
  r.push_back(ro11);
  r.push_back(ro12);
  r.push_back(ro13);
  r.push_back(ro14);
}



void updateRooms(int& r10, int& r8, int& r11, int& r14, int& r15, vector<Room*>\
& r)
{
  
  //end();
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
    //cout<<(exits.first);
    //cout<<p;
    if((*(exits.first)) == p)//exit exists
    {
      //cout << "here";
      roomExist = 1;
      //find room number in room vector
      for(vector<Room*>::iterator it =r.begin(); it != r.end(); ++it)
      {
	cout << tempRoom;
	//cout<<((*(r.begin()+rn))->getD());
	char d1[300];//just...make an array for safety reasons.
	strcpy(d1,(*it)->getD());
	//cout << ((*it)->getD())<<endl;	
	//cout << d1;	
	if(strcmp(d1,((*(exits.second)).getD()))==0)//if room is found, compare the room descriptions...find a better way if possible
	{
	  //cout<<"HERE";
	  rn = tempRoom;
	  descRoom(rn, r);
	  return;
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

void quit(vector<item*>& i, vector<Room*>& r)
{
  if (i.empty()==false)
  {
    for (vector<item*>::iterator it = i.begin(); it != i.end(); ++it)
    {
      delete[] (*(*it)).name;//get rid of name
    }
  }
  i.clear();
  for (vector<Room*>::iterator it = r.begin(); it != r.end(); ++it)
  {
    delete (*it);
  }
}

void end()
{

}
