#include "MyGame.h"
#include "MyEngineSystem.cpp"




// Initalise each enemy instance
EnemyA t1;
EnemyB t2;
EnemyB t3;
EnemyA t4;
EnemyC t5;
EnemyD t6;
EnemyC t7;
EnemyE t8;

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(10), gameWon(false), box(5, 5, 30, 30) {
	TTF_Font* font = ResourceManager::loadFont("res/fonts/arial.ttf", 72);
	gfx->useFont(font);
	gfx->setVerticalSync(true);
	

	for (int i = 0; i < numKeys; i++) {
		std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
		k->isAlive = true;
		k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
		gameKeys.push_back(k);
	}

	// Set initial randomised location for each enemy
	t1.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t2.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t3.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t4.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t5.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t6.loc = Point2(getRandom(200, 650), getRandom(200, 450));
	t7.loc = Point2(getRandom(200, 750), getRandom(200, 550));
	t8.loc = Point2(getRandom(200, 650), getRandom(200, 450));
	
	

}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	int speed = 3;

	if (eventSystem->isPressed(Key::W) && lives > 0 && gameWon != true) {
		velocity.y = -speed;
	}

	if (eventSystem->isPressed(Key::S)&& lives > 0 && gameWon != true) {
		velocity.y = speed;
	}

	if (eventSystem->isPressed(Key::A) && lives > 0 && gameWon != true) {
		velocity.x = -speed;
	}

	if (eventSystem->isPressed(Key::D) && lives > 0 && gameWon != true) {
		velocity.x = speed;
	}

}



 void MyGame::update() {

	 int mo1 = -velocity.x;
	 int mo2 = -velocity.y;


	 // Gives EnemyA instances the players location for them to copy
	 t1.vx = -velocity.x;
	 t1.vy = -velocity.y;
	 t4.vx = -velocity.x;
	 t4.vy = -velocity.y;

	 // Makes EnemyA type do the opposite input of the player
	 t1.opposite(t1);
	 t4.opposite(t4);


	 //Makes EnemyC type move left/right
	 t5.movement(t5);
	 t7.movement(t7);

	 // Gives EnemyB type the players location to move towards
	 t2.tar.x = box.x;
	 t2.tar.y = box.y; 
	 t3.tar.x = box.x;
	 t3.tar.y = box.y;

	 // Tells EnemyB types to chase the player
	 t2.chase(t2);
	 t3.chase(t3);

	
	 // Gives EnemyC/D Types the players location
	 t6.tar.x = box.x;
	 t6.tar.y = box.y;
	 t8.tar.x = box.x;
	 t8.tar.y = box.y;

	 // Tells Enemy C/D types to run from the player when close
	 t6.run(t6);
	 t8.run(t8);

	// Removes all enemies when game ends to prevent a gameover
	if (gameWon == true) {
		t1.alive = false;
		t2.alive = false;
		t3.alive = false;
		t4.alive = false;
		t5.alive = false;
		t6.alive = false;
		t7.alive = false;
		t8.alive = false;

	};

	// Players movement input
	box.x += velocity.x; 
	box.y += velocity.y;

	int mo3 = t2.speed +0.5;
	int mo4 = t2.speed +0.5;
	int mo5 = t3.speed +0.5;
	int mo6 = t3.speed +0.5;


	// Colision for enemies
	int s = lives;
	if (box.contains(t1.loc) && t1.alive == true) {
		lives = s += t1.negative(0);
		t1.alive = false;	
	}

	int ss = lives;
	if (box.contains(t2.loc) && t2.alive == true) {
		lives = ss += t2.negative(0);
		t2.alive = false;
	}
	
	int sss = lives;
	if (box.contains(t3.loc) && t3.alive == true) {
		lives = sss += t3.negative(0);
		t3.alive = false;
	}

	int ssss = lives;
	if (box.contains(t4.loc) && t4.alive == true) {
		lives = ssss += t4.negative(0);
		t4.alive = false;
	}


	if (box.contains(t5.loc) && t5.alive == true) {
		lives = ssss += t5.negative(0);
		t5.alive = false;
	}

	

	if (box.contains(t6.loc) && t6.alive == true) {
		lives = ssss += t6.bonus(0);
		t6.alive = false;
	}

	if (box.contains(t7.loc) && t7.alive == true) {
		lives = ssss += t7.negative(0);
		t7.alive = false;
	}

	if (box.contains(t8.loc) && t8.alive == true) {
		lives = ssss += t8.bonus(0);
		t8.alive = false;
		
	}
	



	for (auto key : gameKeys) {
		if (key->isAlive && box.contains(key->pos)) {
			score += 200;	
			key->isAlive = false;
			numKeys--;
		}
	}

	velocity.x = 0;
	velocity.y = 0;

	if (score >= 2000) {
		gameWon = true; 
	}
}




void MyGame::render() {
	gfx->setDrawColor(SDL_COLOR_RED);
	gfx->setDrawColor(SDL_COLOR_ORANGE);
	gfx->drawRect(box);
	gfx->setDrawColor(SDL_COLOR_RED);

	if (t1.alive == true && lives >0 && gameWon != true) {
		gfx->drawCircle(t1.loc, 10);



	}


	if (t2.alive == true && lives > 0 && gameWon != true) {
		gfx->drawCircle(t2.loc, 10);



	}

	if (t3.alive == true && lives > 0 && gameWon != true) {
		gfx->drawCircle(t3.loc, 10);



	}


	if (t4.alive == true && lives > 0 && gameWon != true) {
		gfx->drawCircle(t4.loc, 10);



	}


	if (t5.alive == true && lives > 0 && gameWon != true) {

		gfx->setDrawColor(SDL_COLOR_RED); 
		gfx->drawCircle(t5.loc, 10);



	}

	if (t6.alive == true && lives > 0 && gameWon != true) {

		gfx->setDrawColor(SDL_COLOR_GREEN);
		gfx->drawCircle(t6.loc, 10);

	};

	if (t7.alive == true && lives > 0 && gameWon != true) {

		gfx->setDrawColor(SDL_COLOR_RED);
		gfx->drawCircle(t7.loc, 10);

	};

	if (t8.alive == true && lives > 0 && gameWon != true) {

		gfx->setDrawColor(SDL_COLOR_AQUA);
		gfx->drawCircle(t8.loc, 10);


	};


	
	
	gfx->setDrawColor(SDL_COLOR_YELLOW);
	for (auto key : gameKeys)
		if (key->isAlive)
			gfx->drawCircle(key->pos, 5);


	gfx->setDrawColor(SDL_COLOR_YELLOW);
	for (auto key : gameKeys)
		if (key->isAlive)
			gfx->drawCircle(key->pos, 5);

}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_ORANGE);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);


	std::string livesstr = std::to_string(lives);
	gfx->drawText(livesstr, 780 - livesstr.length() * 750, 25);

	if (lives <= 0) {

		gfx->drawText("YOU LOST", 250, 500);
	};

	// Draws easteregg when enemyE is no longer alive
	if (t8.alive != true) {
		gfx->drawText(t8.EasterEggStr, 250, 300);
	};
	

	if (gameWon && lives >0)
		gfx->drawText("YOU WON", 250, 500);
}
