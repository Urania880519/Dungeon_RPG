#include "Dungeon.h"
#include <time.h> 
#include <Windows.h>


using namespace std;
Dungeon::Dungeon() {}
/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer() {
	string n;
	char k= '0';
	cout << "Enter Player's name: " << endl;
	cin >> n;
	cout << "Choose Your Character: " << endl;
	cout << "A. Witcher" << endl;
	cout << "B. Mage" << endl;
	cin >> k;
	vector<Item> bag;
	if ((k == 'a') || (k == 'A')) {
		//string name, int max_h, int attack, int defense, int hun, int thir, int poi
		player = Player(n, 150, 10, 10, 100, 100, 0);
		player.setCurrentHealth(100);
		player.setInventory(bag);
		player.addItem(Item("Energy Drink", "Item", 15, 15, 0));
	}
	else if ((k == 'b') || (k == 'B')) {
		player = Player(n, 150, 15, 5, 100, 100, 0);
		player.setCurrentHealth(100);
		player.setInventory(bag);
		player.addItem(Item("Wand", "Item", 20, 10, 0));
	}
	
	if (rooms.empty() != 1) {
		player.setCurrentRoom(&rooms[0]);
	}
	else {
		cout << "empty map" << endl;
	}
	
	
	cout << "Your original status:\n";
	player.triggerEvent(&player);
	
}

/* Create a map, which include several different rooms */
void Dungeon::createMap() {
	
	for (int i = 0; i < 10; i++) {
		Room room;
		this->rooms.push_back(room);
	}
	vector<Object*> obj_0;
	rooms[0].setName("ordinary");
	rooms[0].setIndex(0);
	rooms[0].setIsExit(0);
	rooms[0].setHungerCost(5);
	rooms[0].setThirstCost(5);
	rooms[0].setObjects(obj_0);

	rooms[0].setUpRoom(&rooms[1]);
	rooms[0].setDownRoom(nullptr);
	rooms[0].setRightRoom(nullptr);
	rooms[0].setLeftRoom(nullptr);

	vector<Object*> obj_1;
	vector<Item> com;
	com.push_back(Item("Armour", "Weapon", 20, 0, 15));
	com.push_back(Item("Sword", "Weapon", 20, 15, 0));
	obj_1.push_back(new NPC("Loretta", "princess_script.txt", com));
	rooms[1].setName("ordinary");
	rooms[1].setIndex(1);
	rooms[1].setIsExit(0);
	rooms[1].setHungerCost(5);
	rooms[1].setThirstCost(5);
	rooms[1].setObjects(obj_1);
	rooms[1].setRightRoom(&rooms[2]);
	rooms[1].setUpRoom(&rooms[5]);
	rooms[1].setDownRoom(&rooms[0]);
	rooms[1].setLeftRoom(nullptr);

	vector<Object*> obj_2;
	rooms[2].setName("desert");
	rooms[2].setIndex(2);
	rooms[2].setIsExit(0);
	rooms[2].setHungerCost(5);
	rooms[2].setThirstCost(10);
	rooms[2].setObjects(obj_2);

	rooms[2].setDownRoom(nullptr);
	rooms[2].setRightRoom(nullptr);
	rooms[2].setUpRoom(&rooms[3]);
	rooms[2].setLeftRoom(&rooms[1]);

	vector<Object*> obj_3;
	obj_3.push_back(new Item("First Aid Kit", "Meds", 10, 0, 0));
	rooms[3].setName("ordinary");
	rooms[3].setIndex(3);
	rooms[3].setIsExit(0);
	rooms[3].setHungerCost(5);
	rooms[3].setThirstCost(5);
	rooms[3].setObjects(obj_3);

	rooms[3].setLeftRoom(&rooms[5]);
	rooms[3].setRightRoom(&rooms[4]);
	rooms[3].setDownRoom(&rooms[2]);
	rooms[3].setUpRoom(&rooms[6]);
	

	vector<Object*> obj_4;
	
	obj_4.push_back(new Monster("Vampire", 100, 20, 20));//need unique settings
	obj_4.push_back(new Item("Water", "Water", 0, 0, 0));//increase thirst status to 100
	rooms[4].setName("ordinary");
	rooms[4].setIndex(4);
	rooms[4].setIsExit(0);
	rooms[4].setHungerCost(5);
	rooms[4].setThirstCost(5);
	rooms[4].setObjects(obj_4);

	rooms[4].setLeftRoom(&rooms[3]);
	rooms[4].setDownRoom(nullptr);
	rooms[4].setRightRoom(nullptr);
	rooms[4].setUpRoom(nullptr);

	vector<Object*> obj_5;
	vector<Item> com_5;
	com_5.push_back(Item("Unicorn's blood", "Antidote", 10, 0, 10));
	obj_5.push_back(new NPC("Firenze", "centaur_script.txt", com_5));
	rooms[5].setObjects(obj_5);
	rooms[5].setName("forest");
	rooms[5].setIndex(5);
	rooms[5].setIsExit(0);
	rooms[5].setThirstCost(5);

	rooms[5].setHungerCost(10);
	rooms[5].setRightRoom(&rooms[3]);
	rooms[5].setDownRoom(&rooms[1]);
	rooms[5].setUpRoom(&rooms[7]);
	rooms[5].setLeftRoom(nullptr);

	vector<Object*> obj_6;
	vector<Item> com_6;
	com_6.push_back(Item("Butterbeer glazed bread", "Food", 20, 0, 0));
	com_6.push_back(Item("Chocolate frog", "Food", 10, 0, 0));
	obj_6.push_back(new NPC("Dobby", "elf_script.txt", com_6));
	rooms[6].setName("ordinary");
	rooms[6].setIndex(6);
	rooms[6].setIsExit(0);
	rooms[6].setHungerCost(5);
	rooms[6].setThirstCost(5);
	rooms[6].setObjects(obj_6);

	rooms[6].setRightRoom(nullptr);
	rooms[6].setUpRoom(nullptr);
	rooms[6].setLeftRoom(&rooms[7]);
	rooms[6].setDownRoom(&rooms[3]);

	rooms[7].setName("swamp");
	vector<Object*> obj_7;
	obj_7.push_back(new Monster("Swamp Thing", 100, 30, 10));
	rooms[7].setIndex(7);
	rooms[7].setIsExit(0);
	rooms[7].setHungerCost(5);
	rooms[7].setThirstCost(5);
	rooms[7].setObjects(obj_7);

	rooms[7].setUpRoom(nullptr);
	rooms[7].setLeftRoom(&rooms[8]);
	rooms[7].setDownRoom(&rooms[5]);
	rooms[7].setRightRoom(&rooms[6]);

	vector<Object*> obj_8;
	obj_8.push_back(new Item("First Aid Kit", "Meds", 10, 0, 0));
	rooms[8].setName("ordinary");
	rooms[8].setIndex(8);
	rooms[8].setIsExit(0);
	rooms[8].setHungerCost(5);
	rooms[8].setThirstCost(5);
	rooms[8].setObjects(obj_8);

	rooms[8].setRightRoom(&rooms[7]);
	rooms[8].setUpRoom(&rooms[9]);
	rooms[8].setLeftRoom(nullptr);
	rooms[8].setDownRoom(nullptr);

	vector<Object*> obj_9;
	obj_9.push_back(new Monster("Witch", 100, 35, 30));
	rooms[9].setName("ordinary");
	rooms[9].setIndex(9);
	rooms[9].setIsExit(0);
	rooms[9].setHungerCost(5);
	rooms[9].setThirstCost(5);
	rooms[9].setObjects(obj_9);

	rooms[9].setLeftRoom(nullptr);
	rooms[9].setUpRoom(nullptr);
	rooms[9].setRightRoom(nullptr);
	rooms[9].setDownRoom(&rooms[8]);

	//cout << rooms.size() << endl;
	//for (int i = 0; i < rooms.size(); i++) {
	//	cout << rooms[i].getName() <<" ";
	//	cout << rooms[i].getIndex() << " ";
	//	if (rooms[i].getDownRoom()) {
	//		cout << rooms[i].getDownRoom()->getIndex() << " ";
	//	}
		
	//	cout << rooms[i].getObjects().size() << endl;
	//}
	
}

/* Deal with player's moveing action */
void Dungeon::handleMovement() {
	Room* c_room = player.getCurrentRoom();

	// Display movement options
	if (c_room->getUpRoom() != NULL) {
		cout << "U. Go up" << endl;
	}
	if (c_room->getDownRoom() != NULL) {
		cout << "D. Go down" << endl;
	}
	if (c_room->getLeftRoom() != NULL) {
		cout << "L. Go left" << endl;
	}
	if (c_room->getRightRoom() != NULL) {
		cout << "R. Go right" << endl;
	}

	// Get user input for movement direction
	char r;
	cin >> r;

	// Update player's position based on input
	if ((r == 'u') || (r == 'U')) {
		player.setPreviousRoom(c_room);
		player.setCurrentRoom(c_room->getUpRoom());
	}
	else if ((r == 'd') || (r == 'D')) {
		player.setPreviousRoom(c_room);
		player.setCurrentRoom(c_room->getDownRoom());
	}
	else if ((r == 'l') || (r == 'L')) {
		player.setPreviousRoom(c_room);
		player.setCurrentRoom(c_room->getLeftRoom());
	}
	else if ((r == 'r') || (r == 'R')) {
		player.setPreviousRoom(c_room);
		player.setCurrentRoom(c_room->getRightRoom());
	}

	// Start the timer of the new room
	cout << "You're now in Room " << player.getCurrentRoom()->getIndex() << endl;
	

	start_timer();
	
	
	
	Sleep(2000);

	handleRoomSettings();
}

void Dungeon::handleRoomSettings() {
	if (player.getWound()) {
		cout << "You're wounded and the thirst cost is high under such state." << endl;
		player.getCurrentRoom()->setThirstCost(10);
		
	}

	if (player.getCurrentRoom()->getName() == "ordinary") {
		if (player.getCurrentRoom()->getObjects().size() == 1) {
			handleEvent(player.getCurrentRoom()->getObjects()[0]);
			if (player.getCurrentRoom()->getIndex() != 9) {
				player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
			}

		}
		else if (player.getCurrentRoom()->getObjects().size() > 1) {
			srand(time(NULL));
			int min = 0;
			int max = player.getCurrentRoom()->getObjects().size() - 1;
			int x = rand() % (max - min + 1) + min;
			handleEvent(player.getCurrentRoom()->getObjects()[x]);
			player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[x]);
		}
		else if (player.getCurrentRoom()->getObjects().size() == 0) {
			cout << "This is a safe room. Take a deep breath and go on..." << endl;
			Sleep(1000);
		}

	}
	else if (player.getCurrentRoom()->getName() == "desert") {
		cout << "It's desert!!It's going to be extremely hot..." << endl;
		Sleep(1000);
		RandEvent_Desert(3, 0);

	}
	else if (player.getCurrentRoom()->getName() == "forest") {
		cout << "It's forest!!Something unknown is waiting for you..." << endl;
		Sleep(1000);
		if (player.getCurrentRoom()->getObjects().size() == 1) {
			handleEvent(player.getCurrentRoom()->getObjects()[0]);
			player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
		}
		else if (player.getCurrentRoom()->getObjects().size() > 1) {
			srand(time(NULL));
			int min = 0;
			int max = player.getCurrentRoom()->getObjects().size() - 1;
			int x = rand() % (max - min + 1) + min;
			handleEvent(player.getCurrentRoom()->getObjects()[x]);
			player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[x]);

		}
		RandEvent_Forest(2, 0);
		RandEvent_Forest(2, 0);
	}
	else if (player.getCurrentRoom()->getName() == "swamp") {

		cout << "OMG swamp has been known as a place with so much trouble..." << endl;
		Sleep(1000);
		if (player.getCurrentRoom()->getObjects().size() == 1) {
			handleEvent(player.getCurrentRoom()->getObjects()[0]);
			player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
		}
		else if (player.getCurrentRoom()->getObjects().size() > 1) {
			srand(time(NULL));
			int min = 0;
			int max = player.getCurrentRoom()->getObjects().size() - 1;
			int x = rand() % (max - min + 1) + min;
			handleEvent(player.getCurrentRoom()->getObjects()[x]);
			player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[x]);
		}
		RandEvent_Swamp(0, 0);
		RandEvent_Swamp(2, 1);
	}

	

	Sleep(2000);
	cout << "\n" << endl;
	chooseAction();
}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object* obj) {

	if (obj->getTag() == "NPC") {
		NPC* npc = dynamic_cast<NPC*>(obj);
		npc->triggerEvent(&player);
	}
	else if (obj->getTag() == "Monster") {
		Monster* m= dynamic_cast<Monster*>(obj);
		
		if (m->getName() != "Vampire") {
			m->triggerEvent(&player);
		}
		else {
			m->triggerPoison(&player);
		}
	}
	else if ((obj->getTag() == "Antidote") || (obj->getTag() == "Water") || (obj->getTag() == "Food")) {
		Item* item= dynamic_cast<Item*>(obj);
		cout << "You found an item: " << item->getName() << "(" << item->getTag() << ")" << endl;
		player.addItem(*item);
	}
	else if (obj->getTag() == "Meds") {
		if (player.getWound()) {
			Item* item = dynamic_cast<Item*>(obj);
			cout<< "Lucky you! You found an item: " << item->getName() << "(" << item->getTag() << ")" << endl;
			player.setWound(false);
		}
		else {
			Item* item = dynamic_cast<Item*>(obj);
			cout << "You found an item: " << item->getName() << "(" << item->getTag() << ")" << endl;
			player.addItem(*item);
		}
	}

}

/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame() {
	createMap();
	createPlayer();
	
}

/* Deal with the player's action     */
/* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction() {
	if (checkGameLogic()) {
		cout << "====================Action Menu====================" << endl;
		cout << "What do you want to do?" << endl;
		cout << "A. Move" << endl;
		cout << "B. Check Status" << endl;
		cout << "C. Talk to Shop" << endl;
		cout << "D. Open Backpack" << endl;
		cout << "E. Eat Food" << endl;
		cout << "F. Drink Water" << endl;


		if (player.getHunger() < 20) {
			cout << "*******I recommend you to eat some food*******" << endl;
		}
		if (player.getThirst() < 20) {
			cout << "*******I recommend you to drink some water*******" << endl;
		}
		Sleep(1000);
		char k;
		cin >> k;

		if ((k == 'a') || (k == 'A')) {
			cout << "Choose your direction." << endl;
			handleMovement();

		}
		else if ((k == 'b') || (k == 'B')) {
			player.triggerEvent(&player);
			if (player.getPoison() > 0) {
				vector<Item*> antidotes;
				for (int i = 0; i < player.getInventory().size(); i++) {
					if (player.getInventory()[i].getTag() == "Antidote") {

						antidotes.push_back(&player.getInventory()[i]);
					}
				}
				if (antidotes.size() > 0) {
					cout << "Your poison state is " << player.getPoison() << endl;
					cout << "Do you want to use antidote in your backpack?" << endl;
					cout << "A. yes\nB. no(Not taking action is dangerous! Your health status will decrease.)" << endl;
					char k;
					cin >> k;
					if ((k == (char)'a') || (k == (char)'A')) {
						for (int i = 0; i < player.getInventory().size(); i++) {
							if (player.getInventory()[i].getTag() == "Antidote") {
								player.useItem(i);
								break;
							}

						}
					}
					else if ((k == (char)'b') || (k == (char)'B')) {
						player.setCurrentHealth(player.getCurrentHealth() - player.getPoison());
					}
				}
				else {
					cout << "You have no antidote in your back pack while you're poisoned." << endl;
					cout << "It's very dangerous! Your health status is decreasing." << endl;
					player.setCurrentHealth(player.getCurrentHealth() - player.getPoison());
				}
			}
			chooseAction();
		}
		else if ((k == 'c') || (k == 'C')) {
			cout << "This is Ollivander's shop. What do you want?" << endl;
			cout << "A. Potion: -10 health to get it. Useful to all kinds of poison." << endl;
			cout << "B. Water: -5 health to get it.Increase Thirst status to 100." << endl;
			cout << "C. Pinky candy: -8 health to get it.Increase Hunger status to 100." << endl;
			char k;
			cin >> k;
			if ((k == (char)'a') || (k == (char)'A')) {
				player.addItem(Item("Potion", "Antidote", 0, 0, 0));
				player.setCurrentHealth(player.getCurrentHealth() - 10);
			}
			else if ((k == (char)'b') || (k == (char)'B')) {
				player.addItem(Item("Water", "Water", 0, 0, 0));
				player.setCurrentHealth(player.getCurrentHealth() - 5);
			}
			else if ((k == (char)'c') || (k == (char)'C')) {
				player.addItem(Item("Pinky Candy", "Food", 0, 0, 0));
				player.setCurrentHealth(player.getCurrentHealth() - 8);
			}
			chooseAction();
		}
		else if ((k == 'd') || (k == 'D')) {
			cout << "=============BACKPACK=============" << endl;
			for (int i = 0; i < player.getInventory().size(); i++) {
				cout << i + 1 << ". " << player.getInventory()[i].getName() << endl;
				cout << "\thealth: " << player.getInventory()[i].getHealth() << endl;
				cout << "\tattack: " << player.getInventory()[i].getAttack() << endl;
				cout << "\tdefense: " << player.getInventory()[i].getDefense() << endl;
			}
		}
		else if ((k == 'e') || (k == 'E')) {
			vector<Item*> food;
			for (int i = 0; i < player.getInventory().size(); i++) {
				if (player.getInventory()[i].getTag() == "Food") {
					Item item = player.getInventory()[i];
					food.push_back(&item);
				}
			}
			if (food.size() == 0) {
				cout << "You have no food in your backpack!!!" << endl;
			}
			else {
				for (int i = 0; i < player.getInventory().size(); i++) {
					if (player.getInventory()[i].getTag() == "Food") {
						player.useItem(i);
						break;
					}
				}
			}
			
			chooseAction();
		}
		else if ((k == 'f') || (k == 'F')) {
			vector<Item*> water;
			for (int i = 0; i < player.getInventory().size(); i++) {
				if (player.getInventory()[i].getTag() == "Water") {
					Item item = player.getInventory()[i];
					water.push_back(&item);
				}
			}
			if (water.size() == 0) {
				cout << "You have no water in your backpack!!!" << endl;
			}

			else {
				for (int i = 0; i < player.getInventory().size(); i++) {
					if (player.getInventory()[i].getTag() == "Water") {
						player.useItem(i);
					}
				}
			}
			chooseAction();
		}
		chooseAction();
	}
	else {
	exit(0);
	}
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic() {
	if (player.getCurrentHealth() > 0) {
		
		if (player.getCurrentRoom()->getIndex() == 9) {
			
			Monster* final_monster = dynamic_cast<Monster*>(player.getCurrentRoom()->getObjects()[0]);
			
			if (final_monster->checkIsDead()) {
				cout << "===================CONGRATS TO YOUR VICTORY===================" << endl;
				cout << "==========================GAME OVER===========================" << endl;
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		cout << "==========================GAME OVER===========================" << endl;
		cout << "You're defeated." << endl;
		
		return 0;
	}
}

void Dungeon::RandEvent_Swamp(int max, int min) {
	int x = rand() % (max - min + 1) + min;
	if (x == 0) {
		cout << "Your instinct tells you that something dangerous is lurking in the mud..." << endl;
		Sleep(1000);
		cout << "ALLIGATOR..." << endl;
		Sleep(500);
		cout << "You've got biten and your blood is running.\nHEALTH -10\n" << endl;
		Sleep(500);
		cout << "You need something to heal your wound. Before getting healed, your thirst status will be dropping drastically.\n" << endl;
		Sleep(1000);
		player.getCurrentRoom()->setThirstCost(15);
		player.setCurrentHealth(player.getCurrentHealth() - 10);
		player.setWound(true);
		start_timer();
	}
	else if (x == 1) {
		cout << "Let's check if you have medications in your backpack." << endl;
		Sleep(1000);
		for (int i = 0; i < player.getInventory().size(); i++) {
			if (player.getInventory()[i].getTag() == "Meds") {
				cout << "You have a " << player.getInventory()[i].getName() << " in your backpack" << endl;
				player.useItem(i);
				player.setWound(false);
				player.getCurrentRoom()->setThirstCost(5);
				start_timer();
				break;
			}
			
			else {
				if (i == player.getInventory().size() - 1) {
					if (player.getInventory()[i].getTag() != "Meds") {
						cout << "You have no medications in your backpack." << endl;
						cout << "You need something to heal your wound. Your health will decrease by 10 and you can leave the swamp." << endl;
						player.setWound(true);
						Sleep(500);
						
					}
				}
			}
		}
		
	}
	else if (x == 2) {
		cout << "The PORTER is triggered." << endl;
		cout << "You're going to be transported to a secret place in the swamp with medications. Meanwhile, the drop of your thirst status will return to normal." << endl;
		
		Sleep(1000);
		cout << "WOUND HEALING" << endl;
		player.setWound(false);
		player.getCurrentRoom()->setThirstCost(5);
		start_timer();
	}
}

void Dungeon::RandEvent_Forest(int max, int min) {
	int x = rand() % (max - min + 1) + min;
	if (x == 0) {
		cout << "Unlucky you..." << endl;
		cout << "A serpent, an extremely toxic one saw you the second you enter this room.";
		Sleep(1000);
		cout << "It's coming after you!!" << endl;
		
		cout << "<-----#########" << endl;
		cout << "              ##            ######## " << endl;
		cout << "               ##           ##" << endl;
		cout << "                #############" << endl;
		cout << "You've got biten!!" << endl;
		player.setPoison(10);
		player.setCurrentHealth(player.getCurrentHealth() - 10);
		cout << "Your poison state: " << player.getPoison() << endl;
		cout << "HEALTH -" << player.getPoison() << endl;
		
	}
	else if (x == 1) {
		cout << "You found a lake in the forest." << endl;
		Sleep(1000);
		if (player.getThirst() < 100) {
			cout << "The water in the lake seemed to be clear." << endl;
			cout << "Your thirst state is reset after drinking some water from the lake." << endl;
			player.setThirst(100);
		}
		else if (player.getThirst() == 100) {
			cout << "You've taken out the bottle in your backpack and you decided to fill it up with the water." << endl;
			cout << "This may be helpful later!!" << endl;
			player.addItem(Item("Water", "Water", 0, 0, 0));
		}
		
	}
	else if (x == 2) {
		int f = rand() % 1 + 0;
		if (f == 0) {
			cout << "You're faced with one of the most serious threat since your journey had started..." << endl;
			Sleep(1000);
			cout << "Bear!!!" << endl;
			cout << "You are not allowed to surrender." << endl;
			Sleep(1000);
			cout << "A. Attack\nB. Lie down and pretend to be a dead body." << endl;
			char k;
			cin >> k;
			if ((k == (char)'A') || (k == (char)'a')) {
				
				if (player.getAttack() > 50) {
					cout << "=========BEAR -" << player.getAttack() <<"=========" << endl;
					cout << "You're strong enough to scare the bear away!!" << endl;
				}
				else {
					cout << "=========BEAR -" << player.getAttack() << "=========" << endl;
					cout << "The bear is furious now!! Be aware of its claw!!" << endl;
					cout << "=========PLAYER -20=========" << endl;
					player.setCurrentHealth(player.getCurrentHealth() - 20);
					cout << "Come on! Attack again!" << endl;
					cout << "=========BEAR -" << player.getAttack() << "=========" << endl;
					cout << "The bear is seriously hurt and got scared away. Good Job!" << endl;
				}
			}
			else if ((k == (char)'b') || (k == (char)'B')) {
				cout << "The bear is getting closer....You can even feel it smelling and breathing on your skin..." << endl;
				cout << "It decided to leave eventually but stepped on you accidentally." << endl;
				cout << "=========PLAYER -10=========" << endl;
				player.setCurrentHealth(player.getCurrentHealth() - 10);
			}
			
		}
		else if (f == 1) {
			cout << "No worries. Just a friendly deer." << endl;
			cout << "The deer can give you strength..." << endl;
			Sleep(1000);
			cout<<"PLAYER: INCREASE HEALTH +15" << endl;
			player.setCurrentHealth(player.getCurrentHealth() + 15);
		}
		
	}
}

void Dungeon::RandEvent_Desert(int max, int min) {
	int x = rand() % (max - min + 1) + min;
	if (x == 0) {
		cout << "You found a Camel." << endl;
		cout << "A. Ride it.\nB. Try to talk to the camel." << endl;
		char k;
		cin >> k;
		if ((k == (char)'a') || (k == (char)'A')) {
			RandEvent_Desert(max, 1);
		}
		else if ((k == (char)'b') || (k == (char)'B')) {
			RandEvent_Desert(max, 2); //x=2
		}
		
	}
	else if (x == 1) {
		cout << "Unfortunate you.... You've met a huge sand storm and it's going to be so hard to walk." << endl;
		Sleep(1000);
		cout << "Your Hunger and Thirst status will fall extremely from now." << endl;
		player.getCurrentRoom()->setThirstCost(20);
		player.getCurrentRoom()->setHungerCost(10);
		
		start_timer();
		Sleep(1000);
		cout << "It's going to be so hard. Do you want to go on this journey?\n" << endl;
		Sleep(500);
		cout << "A. Yes. I think I can find the oasis and get out of this place." << endl;
		cout << "B. I guess it's not wise to keep struggling. I want to go back to my previous room even though it's going to make my Defense status decrease by 5." << endl;
		char k;
		cin >> k;
		if ((k == (char)'a') || (k == (char)'A')) {
			RandEvent_Desert(2, 2); //x=2
		}
		else if ((k == (char)'b') || (k == (char)'B')) {
			player.changeRoom(player.getPreviousRoom());
			
			player.setDefense(player.getDefense() - 5);
		}
	}
	else if (x == 2) {
		cout << "You've been struggling in the desert for a while. Suddenly, you saw something..." << endl;
		Sleep(1000);
		cout << "It seemed to be an oasis!! You can't believe your eyes, and you can't help but move faster forward." << endl;
		player.getCurrentRoom()->setThirstCost(10);
		player.getCurrentRoom()->setHungerCost(5);
		
		start_timer();
		player.setThirst(100);
		
	}
	else if (x == 3) {
		cout << "You saw something buried under the sand. You're so curious that you decided to dig it out." << endl;
		Sleep(1000);
		cout << "It's a mystereous treasure box." << endl;
		Sleep(1000);
		int t = rand() % 2 + 0;
		Item treasure;
		if (t == 0) {
			treasure = Item("Diamond", "Fortune", 10, 0, 0);
		}
		else if (t == 1) {
			treasure = Item("Emerald", "Fortune", 5, 5, 0);
		}
		else if (t == 2) {
			treasure = Item("Gold", "Fortune", 5, 0, 5);
		}
		player.addItem(treasure);
		cout << "You've opened the treasure box and you found " << treasure.getName() << endl;
	}
}

void Dungeon::start_timer() {
	// Stop the current timer thread if it's joinable
	stop_timer();

	timer_running = true; // Set the flag to true to indicate that the timer thread is running

	// Start a new timer thread
	timer_thread = std::thread([this]() {
		while (true) {
			Room* current_room = player.getCurrentRoom();
			int sec = (current_room->getName() == "ordinary") ? 30 : 15; 

			{
				unique_lock<mutex> lock(timer_mutex);
				if (!timer_running) {
					break; 
				}
				timer_cv.wait_for(lock, std::chrono::seconds(sec)); 
			}

			if (!timer_running) {
				break; 
			}

			
			cout << "\nReminder: Staying in Room " << current_room->getIndex() << " will decrease your hunger and thirst status every " << sec << " seconds\n" << std::endl;
			int hunger_cost = player.getCurrentRoom()->getHungerCost();
			int thirst_cost = player.getCurrentRoom()->getThirstCost();
			cout << "Hunger -" << hunger_cost << endl;
			cout << "Thirst -" << thirst_cost << endl;
			player.setHunger(player.getHunger() - hunger_cost);
			player.setThirst(player.getThirst() - thirst_cost);
			cout << "Your Hunger and Thirst status now: " << player.getHunger() << "/" << player.getThirst() << endl;

			if (player.getHunger() <= 0) {
				cout << "Take action and eat food! Your health is decreasing!" << endl;
				player.setCurrentHealth(player.getCurrentHealth() - 10);
			}
			if (player.getThirst() <= 0) {
				cout << "Take action and drink water! Your health is decreasing!" << endl;
				player.setCurrentHealth(player.getCurrentHealth() - 10);
			}
		}
		});
}

void Dungeon::stop_timer() {
	if (timer_thread.joinable()) {
		{
			lock_guard<mutex> lock(timer_mutex);
			timer_running = false; 
		}
		timer_cv.notify_all(); 
		timer_thread.join();   
	}
}

/* Deal with the whole game process */
void Dungeon::runDungeon() {
	startGame();
	
	
	while (checkGameLogic()) {
		start_timer();
		chooseAction();
	}
	
	

}