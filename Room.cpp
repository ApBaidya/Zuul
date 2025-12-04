//12.1.2025 Room Class over here
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include <iostream>
using namespace std;



Room::Room()
{
  description = new char[300]; //new description
  //lets just...remember the room map 
  //lets remember items vector
}
Room::~Room()
{
  delete[] description;
  items.clear();
  //how to deal with map?
}

void Room::setD(char in_d[300])
{
  strcpy(description, in_d);
  //cout << description;
}
void Room::setR(char* exit, Room* o)
{
  neigh[exit] = o;//add room pointer to neigh with key exit
}
void Room::setI(item* i)//for initial set and drop function
{
  items.push_back(i);
}

char* Room::getD()
{
  //cout << description;
  return description;
}
map<char*, Room*> Room::getR()
{
  return neigh;
}
vector<item*>* Room::getI()
{
  return &items;//use & to return a pointer for any object!
}

void Room::updateI(char in_i[15])//for take function
{
  for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
  {
    if(strcmp((*(*it)).name, in_i)==0)
    {
      delete[] (*(*it)).name;
      items.erase(it);
      return;
    }
  }
}
