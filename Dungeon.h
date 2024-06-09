#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <condition_variable>
using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
    //int current_time;
    atomic<bool> timer_running;
    thread timer_thread;
    mutex timer_mutex;
    condition_variable timer_cv;
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(Object*);

    void handleRoomSettings();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction();

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();

    //
    void RandEvent_Desert(int, int);
    void RandEvent_Forest(int, int);
    void RandEvent_Swamp(int, int);
    void start_timer();
    void stop_timer();
    Dungeon(const Dungeon& other) {}
};


#endif // DUNGEON_H_INCLUDED
