#include "Room.h"

//Room::Room():timer_running(false){}
Room::Room() {}
//Room::Room(string name, bool exit, int room_idx, vector<Object*> obj, int h_cost, int t_cost) :name(name), isExit(exit), index(room_idx), objects(obj), current_time(0), hunger_cost(h_cost), thirst_cost(t_cost), timer_running(false){}
Room::Room(string name, bool exit, int room_idx, vector<Object*> obj, int h_cost, int t_cost) :name(name), isExit(exit), index(room_idx), objects(obj), hunger_cost(h_cost), thirst_cost(t_cost) {}
bool Room::popObject(Object* obj) {
    vector<Object*> objs;
    for (int i = 0; i < this->getObjects().size(); i++) {
        if (this->getObjects()[i] != obj) {
            Object* obj = this->getObjects()[i];
            objs.push_back(obj);
        }
    }
    this->setObjects(objs);
    return 1;
}
//setter

void Room::setName(string n) {
	name = n;
}
void Room::setUpRoom(Room* u) {
	this->upRoom = u;
}
void Room::setDownRoom(Room* d) {
	this->downRoom = d;
}
void Room::setLeftRoom(Room* l) {
	this->leftRoom = l;
}
void Room::setRightRoom(Room* r) {
	this->rightRoom = r;
}

void Room::setIsExit(bool exit) {
	this->isExit = exit;
}

void Room::setIndex(int idx) {
	this->index = idx;
}
void Room::setObjects(vector<Object*> obj) {
	this->objects = obj;
}
void Room::setHungerCost(int h_cost) {
    this->hunger_cost= h_cost;
}
void Room::setThirstCost(int t_cost) {
    this->thirst_cost = t_cost;
}
//void Room::setCurrentTime(int t) {
//    this->current_time = 0;
//}
//void Room::setTimerRunning(bool tf) {
//    this->timer_running = tf;
//}

//getter
string Room::getName() {
	return name;
}
bool Room::getIsExit() {
	return this->isExit;
}
int Room::getIndex() {
	return this->index;
}
vector<Object*> Room::getObjects() {
	return this->objects;
}
Room* Room::getUpRoom() {
	return this->upRoom;
}
Room* Room::getDownRoom() {
	return this->downRoom;
}
Room* Room::getLeftRoom() {
	return this->leftRoom;
}
Room* Room::getRightRoom() {
	return this->rightRoom;
}

int Room::getHungerCost() {
    return this->hunger_cost;
}
int Room::getThirstCost() {
    return this->thirst_cost;
}

