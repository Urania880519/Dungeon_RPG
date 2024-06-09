#include "Record.h"

ofstream out;
ifstream in;

Record::Record() {}

void Record::savePlayer(Player* p, ofstream& stream) {
	stream.open("player.txt");
	stream << p->getName() << endl;
	stream << p->getTag() << endl;
	stream<< p->getMaxHealth() << endl;
	stream << p->getCurrentHealth() << endl;
	stream << p->getAttack() << endl;
	stream << p->getDefense() << endl;
	
	stream << p->getInventory().size();
	for (int i = 0; i < p->getInventory().size(); i++) {
		stream << p->getInventory()[i].getName() << endl;
		stream << p->getInventory()[i].getTag() << endl;
		stream << p->getInventory()[i].getHealth() << endl;
		stream << p->getInventory()[i].getAttack() << endl;
		stream << p->getInventory()[i].getDefense() << endl;
	}
	stream << p->getHunger() << endl;
	stream << p->getThirst() << endl;
	stream << p->getPoison() << endl;

	stream << p->getCurrentRoom()->getIndex() << endl;
	stream << p->getPreviousRoom()->getIndex() << endl;
	
	stream.close();
}


void Record::saveRooms(vector<Room>& r, ofstream& stream) {
	stream.open("room.txt");
	stream << r.size() << endl;
	for (int i = 0; i < r.size(); i++) {
		
		stream << r[i].getName() << endl;
		stream << r[i].getIndex() << endl;
		stream << r[i].getHungerCost() << endl;
		stream << r[i].getThirstCost() << endl;

		stream << r[i].getObjects().size();
		for (int i = 0; i < r[i].getObjects().size(); i++) {
			stream << r[i].getObjects()[i]->getName() << endl;
			stream << r[i].getObjects()[i]->getTag() << endl;
		}	

	}

	for (int i = 0; i < r.size(); i++) {
		
		stream << r[i].getUpRoom()->getIndex() << endl;
		stream << r[i].getDownRoom()->getIndex() << endl;
		stream << r[i].getLeftRoom()->getIndex() << endl;
		stream << r[i].getRightRoom()->getIndex() << endl;
		
	}
	
	stream.close();
}

void loadRooms(vector<Room>& r, ifstream& stream) {
	stream.open("room.txt");
	int size;
	stream >> size;
	
	for (int i = 0; i < size; i++) {
		string n;
		int idx, obj_size, h_cost, t_cost= 0;
		stream >> n;
		stream >> idx;
		stream >> h_cost;
		stream >> t_cost;
		stream >> obj_size;
		vector<Object*> obj;
		for (int j = 0; j < obj_size; j++) {
			string obj_n, obj_t;
			stream >> obj_n;
			stream >> obj_t;
			Object* o = nullptr;
			o->setName(obj_n);
			o->setTag(obj_t);
			obj.push_back(o);
		}
		Room* room = new Room(n, 0, idx, obj, h_cost, t_cost);
		r.push_back(*room);
	}
	for (int i = 0; i < size; i++) {
		int up= 0;
		int down = 0;
		int right = 0;
		int left = 0;

		for (int j = 0; j < size; j++) {
			if (r[j].getIndex() == up) {
				Room* upR = &r[j];
				r[i].setUpRoom(upR);
			}
			if (r[j].getIndex() == down) {
				Room* downR = &r[j];
				r[i].setDownRoom(downR);
			}
			if (r[j].getIndex() == left) {
				Room* leftR = &r[j];
				r[i].setLeftRoom(leftR);
			}
			if (r[j].getIndex() == right) {
				Room* rightR = &r[j];
				r[i].setRightRoom(rightR);
			}
		}
		
		stream.close();
	}
}

void loadPlayer(Player* p, vector<Room>& r, ifstream& stream) {
	stream.open("player.txt");
	string n, t;
	int max_h, current_h, att, def;
	int inv_size;
	stream >> n;
	stream >> t;
	stream >> max_h;
	stream >> current_h;
	stream >> att;
	stream >> def;
	stream >> inv_size;
	vector<Item> backpack;
	for (int i = 0; i < inv_size; i++) {
		string item_n, item_t;
		int item_h, item_att, item_def;
		stream >> item_n;
		stream >> item_t;
		stream >> item_h;
		stream >> item_att;
		stream >> item_def;
		backpack.push_back(Item());
		backpack[i].setName(item_n);
		backpack[i].setTag(item_t);
		backpack[i].setHealth(item_h);
		backpack[i].setAttack(item_att);
		backpack[i].setDefense(item_def);
	}

	int hun, thir, poi;
	int current_r, prev_r;
	stream >> hun;
	stream >> thir;
	stream >> poi;
	stream >> current_r;
	stream >> prev_r;

	p->setName(n);
	p->setTag(t);
	p->setMaxHealth(max_h);
	p->setCurrentHealth(current_h);
	p->setAttack(att);
	p->setDefense(def);
	p->setInventory(backpack);
	p->setHunger(hun);
	p->setThirst(thir);
	p->setPoison(poi);
	for (int i = 0; i < r.size(); i++) {
		if (r[i].getIndex() == current_r) {
			p->setCurrentRoom(&r[i]);
		}
		if (r[i].getIndex() == prev_r) {
			p->setPreviousRoom(&r[i]);
		}
	}
}

