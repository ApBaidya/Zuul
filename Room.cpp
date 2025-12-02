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
  delete[] item;
  //how to deal with map?
}

void setD(char in_d[101])
{
  strcpy(description, in_d);
}
void setR(char exit, Room obj)
{
  neigh[exit] = obj;//add room to neigh with key exit
}
void setI(int in_i)
{
  items.push_back(in_i);
}

char* getD()
{
  return description;
}
map<char, Room*> getR()
{
  return neigh;
}
vector<int> getI()
{
  return items;
}

void updateI(int in_i2)
{
  int index;
  for(vector<int>::iterator it = items.begin(); it )
}
