#ifndef INVADERMANAGER_H
#define INVADERMANAGER_H

#include "Invader.h"
#include "InvaderBullet.h"
#include "Random.h"

#include "State.h"
#include "MoreInfo.h"

#include <iostream>
#include <array>

class InvaderManager {
	public:
		InvaderManager();
		
		void getInformation(int enemyKilled);
		void update();
		void renderTo(sf::RenderWindow& window);

		int collision(sf::FloatRect bounds);


	private:
		//Class objects
		Random<> randomInvader;
		std::array<sf::Texture, 3> invaderTexture;
		sf::Texture iBulletTexture;

		std::vector<std::unique_ptr<Invader>> invaderVector;
		std::unique_ptr<InvaderBullet> iBullet = nullptr;
		
		//Variables and Booleans
		int enemyKilled = 0;

		static const int invaderCount = 55;
		static const int shieldCount = 4;
		static const int soundCount = 5;
		static const int rowCount = 5;
		float invaderSwitchTimer = 0.45;
		unsigned int pBulletCount = 0;
		const int initialInvaderX = 100;
		int changedInvaderX = 100;

		int invaderShooter = 0;
		int invaderSoundTick = 0;
		int invaderDownTick = 0;
		int invaderDownTickNum = 100;

		bool invaderLeft = false;
		bool invaderDown = false;

};

#endif