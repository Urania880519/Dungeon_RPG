#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

class Room
{
private:
    string name; //Forest Desert Swamp ordinary 
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
    
    int hunger_cost;
    int thirst_cost;
    

public:
    Room();
    Room(string, bool, int, vector<Object*>, int, int);
    
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setName(string);
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    void setHungerCost(int);
    void setThirstCost(int);
    
    string getName();
    bool getIsExit();
    int getIndex();
    int getHungerCost();
    int getThirstCost();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();

    
    Room(const Room& other){}
};

#endif // ROOM_H_INCLUDED
