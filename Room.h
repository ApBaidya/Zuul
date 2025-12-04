//room header file: 12.1.2025 https://www.w3schools.com/cpp/cpp_maps.asp
#ifndef ROOM
#define ROOM

#include <cstring>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//item struct
struct item
{
  char* name;//item name
};

class Room
{
 private:
  char* description; //room description
  map<char*, Room*> neigh;
  vector<item*> items; //vector items: 3(old shield) 2(magic spear) 10(torn cloth) 8(lake water) 11(sacred sword)
 public:
  Room();//create
  ~Room();//death
  void setD(char in_d[300]);
  void setR(char* exit, Room* o);
  void setI(item* i);
  char* getD();
  map<char*,Room*> getR();
  vector<item*>* getI();
  void updateI(char in_i[15]);//name of item
};

#endif //ROOM
