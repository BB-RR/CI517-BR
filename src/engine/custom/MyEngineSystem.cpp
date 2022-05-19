#include "MyEngineSystem.h"
#include "GraphicsEngine.h" 
#include "MyGame.h"
#include <cstdlib>


// Type A does opposite of you, lose a life if you hit them
// done

class EnemyA {	
public:
	Point2 player;
	Point2 loc;
	
	bool alive = true;
	int speed = 2;

	int vx;
	int vy;

	auto opposite(EnemyA) {	
		int mo1 = -vx;
		int mo2 = -vy;
		EnemyA::loc.x = EnemyA::loc.x - mo1;
		EnemyA::loc.y = EnemyA::loc.y - mo2;	
	};
	Point2 getLoc() {
		return loc;
	};	
	int negative(int) {
		return -1;
	};
};

// EnemyB chases you, lose x lives if hit
// done
class EnemyB {
public:
	// x and y cords of this enemy
	Point2 loc;
	// x and y of the player
	Point2 tar;
	bool alive = true;
	int speed = 2;

	auto chase(EnemyB) {
		int mo3 = speed + 0.5;
		int mo4 = speed + 0.5;
		if (EnemyB::tar.x + 10 < EnemyB::loc.x) {
			EnemyB::loc.x = EnemyB::loc.x - mo3;
		};
		if (EnemyB::tar.x + 10 > EnemyB::loc.x) {
			EnemyB::loc.x = EnemyB::loc.x + mo3;
		};
		if (EnemyB::tar.y + 10 > EnemyB::loc.y) {
			EnemyB::loc.y = EnemyB::loc.y + mo4;
		};	 
		if (EnemyB::tar.y + 10 < EnemyB::loc.y) {
			EnemyB::loc.y = EnemyB::loc.y - mo4;
		};	
	};
	Point2 getLoc(void) {
		return loc;
	};
	int negative(int) {
		return -2;
	};
};

// EnemyC slides from left to right
// done but change colour in render
class EnemyC {
public:

	int negative(int) {
		return -2;
	};

	Point2 loc;
	Point2 des;

	bool left = false;
	bool alive = true;

	Point2 getLoc(void) {
		return loc;
	};
	int bonus(int) {
		return +600;
	};

	auto movement(EnemyC) {
		if (EnemyC::loc.x > 50 && EnemyC::left == true) 	{
			EnemyC::loc.x = EnemyC::loc.x - 2;

		};
		if (EnemyC::loc.x >= 750) {
			EnemyC::left = true;

		};
		if (EnemyC::loc.x <= 50) {
			EnemyC::left = false;
		};
		if (EnemyC::loc.x < 750 && EnemyC::left == false) {
			EnemyC::loc.x = EnemyC::loc.x + 5;
		};
	};
};
//restores a life
// should run away from player
// need to store player loc
// if player within 100 x y then move away slowly  but stop at map edges

// compare players loc (tar) if within 100 then start movement

class EnemyD {
public:

	Point2 loc;
	bool alive = true;
	Point2 tar;
	int length = -100;
	int speed = 1;

	auto run(EnemyD) {
	
		int mo3 = speed + 0.5;
		int mo4 = speed + 0.5;

		int xdiff = std::abs(EnemyD::loc.x - EnemyD::tar.x); 
		int ydiff = std::abs(EnemyD::loc.y - EnemyD::tar.y);

		if (xdiff < 50 || ydiff < 50) {
			std::cout << xdiff << std::endl;

				int mo3 = speed + 0.5;
				int mo4 = speed + 0.5;

				if (EnemyD::tar.x + 10 < EnemyD::loc.x) {
					EnemyD::loc.x = EnemyD::loc.x + mo3;
				};
				if (EnemyD::tar.x + 10 > EnemyD::loc.x) {
					EnemyD::loc.x = EnemyD::loc.x - mo3;
				};
				if (EnemyD::tar.y + 10 > EnemyD::loc.y) {
					EnemyD::loc.y = EnemyD::loc.y - mo4;
				};
				if (EnemyD::tar.y + 10 < EnemyD::loc.y) {
					EnemyD::loc.y = EnemyD::loc.y + mo4;
				};		
		};
	};
	Point2 getLoc(void) {
		return loc;
	};
	int bonus(int) {
		return +1;
	};
};



class EnemyE {
public:

	Point2 loc;
	bool alive = true;
	Point2 tar;
	int length = -100;
	int speed = 1;
	bool egg = false;

	std::string EasterEggStr = "CIWhatever";
	
	auto run(EnemyE) {

		int mo3 = speed + 0.5;
		int mo4 = speed + 0.5;

		int xdiff = std::abs(EnemyE::loc.x - EnemyE::tar.x);
		int ydiff = std::abs(EnemyE::loc.y - EnemyE::tar.y);

		    if (xdiff < 50 || ydiff < 50) {
			std::cout << xdiff << std::endl;
			int mo3 = speed + 0.5;
			int mo4 = speed + 0.5;
			if (EnemyE::tar.x + 10 < EnemyE::loc.x) {
				EnemyE::loc.x = EnemyE::loc.x + mo3;
			};
			if (EnemyE::tar.x + 10 > EnemyE::loc.x) {
				EnemyE::loc.x = EnemyE::loc.x - mo3;
			};
			if (EnemyE::tar.y + 10 > EnemyE::loc.y) {
				EnemyE::loc.y = EnemyE::loc.y - mo4;
			};
			if (EnemyE::tar.y + 10 < EnemyE::loc.y) {
				EnemyE::loc.y = EnemyE::loc.y + mo4;
			};
		};
	};
	Point2 getLoc(void) {
		return loc;
	};
	int bonus(int) {
		return +1;
	};
	auto EasterEgg(EnemyE) {
	EnemyE::egg == true;
	};
};