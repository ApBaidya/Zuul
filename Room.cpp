//12.1.2025 Room Class over here
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room()
{
  description = new char[101]; //new description
  //lets just...remember the room map 
  //lets remember items vector
}
Room::~Room()
{
  delete[] description;
  items.clear();
  //how to deal with map?
}

void Room::setD(char in_d[101])
{
  strcpy(description, in_d);
}
void Room::setR(char exit, Room* o)
{
  neigh[exit] = o;//add room pointer to neigh with key exit
}
void Room::setI(int in_i)//for initial set and drop function
{
  items.push_back(in_i);
}

char* Room::getD()
{
  return description;
}
map<char, Room*> Room::getR()
{
  return neigh;
}
vector<int> Room::getI()
{
  return items;
}

void Room::updateI(int in_i2)//for take function
{
  int index;
  int i = 0;
  for(vector<int>::iterator it = items.begin(); it != items.begin(); ++it)
  {
    if ((*it) == in_i2)//if the int is the desired item num 
    {
      index = i; //set index to the index I want
    }
    ++i; //just continue to add to i
  }
  items.erase(items.begin()+index);
}
