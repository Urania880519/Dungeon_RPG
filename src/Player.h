#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;
class Room;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    int hunger;
    int thirst;
    int poison;
    bool wound;
public:
    Player();
    Player(string,int,int,int,int,int,int);
    void addItem(Item);
    void useItem(int);
    void increaseStates(int,int,int);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setHunger(int);
    void setThirst(int);
    void setPoison(int);
    void setWound(bool);

    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    int getHunger();
    int getThirst();
    int getPoison();
    bool getWound();
};

#endif // PLAYER_H_INCLUDED
