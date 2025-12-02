//room header file: 12.1.2025 https://www.w3schools.com/cpp/cpp_maps.asp
#ifndef ROOM
#define ROOM

#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room
{
 private:
  char* description; //room description
  map<char, Room*> neigh;
  vector<int> items; //vector items: 3(old shield) 2(magic spear) 10(torn cloth) 8(lake water) 11(sacred sword)
 public:
  Room();//create
  ~Room();//death
  void setD(char in_d[101]);
  void setR(char exit, Room* o);
  void setI(int in_i);
  char* getD();
  map<char, Room*> getR();
  vector<int> getI();
  void updateI(int in_i2);
};

#endif //ROOM
