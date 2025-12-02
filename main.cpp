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
void help();//cout possible inputs
void drop();//remove item from player inv and add to room inv
void take();//opposite of drop
void goRoom();//switch current room, cout new room details
void quit();//delete vector objects and all that stuff, say goodbye
void numToItem();//when cout room details, take room item nums to items
void itemToNum();//take player input and change into num
void specialDia();//conditional text for rooms
//main class
int main()
{
  //hello, room vector!
  vector<Room*> rooms;
  mkRoom(rooms);
  cout << "Wakey wakey, friend\n No need to look around like that, you won't see me\n Why? Because I'm in your head, of course!"<<endl;
  return 0;
}


//functions
void mkRoom(vector<Room*>& r)
{
  //DESCRIPTIONS
  char d[300] = "[Root 1] Endless paths behind you, and all of them would lead up to here. Anyways, lemme describe this place! Dark, damp, and dusty! The air is thick. Lets take it one breath at a time, alright?";
  Room* ro = new Room();//just...gonna manually make all 15 rooms
  (*ro).setD(d);//1
  d[0] = '\0';
  strcpy(d, "[Root 2] Quite similar to the 1st-oh look, theres a little hand sticking out of the ground! Say hi!It seems like it likes to trade...");
  Room* ro1 = new Room();
  (*ro1).setD(d);//2
  
  //ITEMS
  //EXITS
  
}

void updateRooms()
{
}

void processComd()
{
}

void help()
{
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
