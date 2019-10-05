#include "InvaderManager.h"



InvaderManager::InvaderManager() {
	//Invader information
	//Invader information
	iBulletTexture.loadFromFile(INVADER_BULLET_T);
	iBullet = std::make_unique<InvaderBullet>(&iBulletTexture, sf::Vector2<unsigned>(2, 1), 0.1, INVADER_BULLET_SPEED);
	iBullet->setPosition(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN));

	invaderTexture[0].loadFromFile(INVADER_T3); //Squid
	invaderTexture[1].loadFromFile(INVADER_T1); //Crab
	invaderTexture[2].loadFromFile(INVADER_T2); //Octopus

	//Invader creation
	for (int x = 0; x < invaderCount; x++) {
		if (x < (invaderCount / rowCount) * 1) { invaderVector.emplace_back(new Invader(&invaderTexture[0], sf::Vector2<unsigned>(2, 1), invaderSwitchTimer, 0.0f)); invaderVector[x]->setType("squid"); }
		if (x >= (invaderCount / rowCount) * 1 && x < (invaderCount / rowCount) * 2) { invaderVector.emplace_back(new Invader(&invaderTexture[1], sf::Vector2<unsigned>(2, 1), invaderSwitchTimer, 0.0f)); invaderVector[x]->setType("crab"); }
		if (x >= (invaderCount / rowCount) * 2 && x < (invaderCount / rowCount) * 3) { invaderVector.emplace_back(new Invader(&invaderTexture[1], sf::Vector2<unsigned>(2, 1), invaderSwitchTimer, 0.0f)); invaderVector[x]->setType("crab"); }
		if (x >= (invaderCount / rowCount) * 3 && x < (invaderCount / rowCount) * 4) { invaderVector.emplace_back(new Invader(&invaderTexture[2], sf::Vector2<unsigned>(2, 1), invaderSwitchTimer, 0.0f)); invaderVector[x]->setType("octopus"); }
		if (x >= (invaderCount / rowCount) * 4 && x < (invaderCount / rowCount) * 5) { invaderVector.emplace_back(new Invader(&invaderTexture[2], sf::Vector2<unsigned>(2, 1), invaderSwitchTimer, 0.0f)); invaderVector[x]->setType("octopus"); }
	}

	//Invader positioning 
	//Row 5
	for (int x = (invaderCount / rowCount) * 0; x < (invaderCount / rowCount) * 1; x++) { invaderVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 0 + changedInvaderX, 150)); changedInvaderX += 80; }
	changedInvaderX = initialInvaderX;

	//Row 4
	for (int x = (invaderCount / rowCount) * 1; x < (invaderCount / rowCount) * 2; x++) { invaderVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 0 + changedInvaderX, 220)); changedInvaderX += 80; }
	changedInvaderX = initialInvaderX;

	//Row 3
	for (int x = (invaderCount / rowCount) * 2; x < (invaderCount / rowCount) * 3; x++) { invaderVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 0 + changedInvaderX, 290)); changedInvaderX += 80; }
	changedInvaderX = initialInvaderX;

	//Row 2
	for (int x = (invaderCount / rowCount) * 3; x < (invaderCount / rowCount) * 4; x++) { invaderVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 0 + changedInvaderX, 360)); changedInvaderX += 80; }
	changedInvaderX = initialInvaderX;

	//Row 1
	for (int x = (invaderCount / rowCount) * 4; x < (invaderCount / rowCount) * 5; x++) { invaderVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 0 + changedInvaderX, 430)); changedInvaderX += 80; }
	changedInvaderX = initialInvaderX;


}

void InvaderManager::getInformation(int enemyKilled) {
	this->enemyKilled = enemyKilled;
}

void InvaderManager::update() {
	//Bullet logic
	//Movement
	sf::Vector2<float> iBulletMovement(0.f, 0.f);
	iBulletMovement.y += INVADER_BULLET_SPEED;
	iBullet->move(sf::Vector2<float>(iBulletMovement));

	if (iBullet->getY() >= GROUND_HEIGHT + 10) { iBullet->setPosition(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN)); }


	//Invader logic 
	//Collisions and Movements 
	for (auto& invader : invaderVector) {
		//Movements
		sf::Vector2<float> invaderMovement(0.f, 0.f);
		if (invader->getX() <= SCREEN_WIDTH * 0 + 40) { invaderLeft = false; invaderDown = true; }
		if (invader->getX() >= SCREEN_WIDTH) { invaderLeft = true; invaderDown = true; }

		//Slow invader
		if (enemyKilled < invaderCount - 1) {
			if (invaderLeft == false) { invaderMovement.x += INVADER_SPEED; }
			if (invaderLeft == true) { invaderMovement.x -= INVADER_SPEED; }
		}
		

		//Fast invader
		else {
			invaderDownTickNum = 300;
			invaderSoundTick++;

			if (invaderSoundTick <= 5) {  }

			if (invaderLeft == false) { invaderMovement.x += HYPER_INVADER_SPEED; }
			if (invaderLeft == true) { invaderMovement.x -= HYPER_INVADER_SPEED; }
		}

		if (invaderDown == true) {
			invaderDownTick++;
			invaderMovement.y += INVADER_SPEED;
			if (invaderDownTick >= invaderDownTickNum) {
				invaderDown = false;
				invaderDownTick = 0;
				invaderMovement.y = 0;
			}
		}

		if (invader->isInvaderDead() == false) {
			invader->move(invaderMovement);
			invader->update();
		}

		//Player collision
		//if (player->collisionWithInvaders(*invader)) { playerLives = 0; }

		//Bullet collision
		/*
		if (pBullet.collisionWithInvaders(*invader)) {
			invader->setInvaderPos(sf::Vector2<float>(invader->getX(), invader->getY() - INVADER_ORIGIN));
			pBullet.setBulletPos(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN));
			playSound[1].setSound(INVADER_KILLED_FX, 20, false);
			enemyKilled++;
			playerScore += invader->returnPointType();
		}
		*/

		//Invader touches ground
		//if (invader->getY() >= GROUND_HEIGHT) { playerLives = 0; }
	}

	//Shooting
	invaderShooter = randomInvader.getInt(1, invaderCount - 1);

	//Determining which invader is shooting (random)
	//If the invader chosen is not dead, and if the bullet is at its origin, shoot the bullet at given invader position
	if (invaderVector[invaderShooter]->isInvaderDead() == false) {
		if (iBullet->getX() == BULLET_ORIGIN) {
			iBullet->setPosition(sf::Vector2<float>(invaderVector[invaderShooter]->getX(), invaderVector[invaderShooter]->getY()));
		}
	}
	//Else, if the invader shooter is the same as invadercount, then incriment invadershooter by 1 to find new invader. Else, invadershooter = 1;
	else {
		if (invaderShooter == invaderCount) { invaderShooter++; }
		else { invaderShooter = 1; }
	}

	//Collision with player
	/*
	if (iBullet->collisionWithPlayer(*player)) {
		iBullet->setBulletPos(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN));
		player->setPlayerPos(sf::Vector2<float>(SCREEN_WIDTH / 10, GROUND_HEIGHT));
		playSound[2].setSound(EXPLOSION_FX, 25, false);
		playerLives--;
	}*/

}

void InvaderManager::renderTo(sf::RenderWindow& window) {
	for (auto& invader : invaderVector) { invader->renderTo(window); }
	iBullet->renderTo(window);
}

int InvaderManager::collision(sf::FloatRect bounds) {
	return 0;
}
