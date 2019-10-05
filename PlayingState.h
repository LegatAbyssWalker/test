#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "FPSCounter.h"
#include "Text.h"
#include "MoreInfo.h"
#include "Random.h"
#include "PlaySound.h"
#include "OStringText.h"
#include "Textbox.h"

#include "Player.h"
#include "PlayerBullet.h"
#include "InvaderManager.h"
#include "Shield.h"

#include "State.h"
#include "MainMenuState.h"
class StateMachine;

#include <iostream>
#include <fstream>
#include <array>
#include <memory>

class PlayingState : public State {
	public:
		PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

		void updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed);

		void updateEvents();
		void update();
		void removeEntities();
		void render();

	private:
		//Booleans and Variables
		static const int shieldCount = 4;
		int enemyKilled = 0;


		bool playerShooting = false;

		//Class objects
		std::unique_ptr<Player> player = nullptr;
		std::unique_ptr<PlayerBullet> pBullet = nullptr;

		std::vector<std::unique_ptr<Shield>> shieldVector;

		InvaderManager invaderManager;
		FPSCounter fpsCounter;
		Text versionText;


		//SFML
		std::array<sf::Texture, 3> invaderTexture;
		sf::Texture playerTexture, ufoTexture, shieldTexture, pBulletTexture;

		sf::Event sfEvent;
		sf::Clock dtClock;
		float	  dtTimer;
};


#endif