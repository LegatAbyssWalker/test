#include "PlayingState.h"

#include "State.h"
#include "StateMachine.h"
class StateMachine;

#include "MoreInfo.h"

PlayingState::PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace },
	versionText(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 30, 25, ARIAL_FONT, "Version 0.0", sf::Color(255, 255, 0)) {
	
	//Player information
	playerTexture.loadFromFile(PLAYER_T);
	pBulletTexture.loadFromFile(PLAYER_BULLET_T);
	player = std::make_unique<Player>(playerTexture, PLAYER_SPEED);
	player->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 10, GROUND_HEIGHT));
	
	pBullet = std::make_unique<PlayerBullet>(pBulletTexture);
	pBullet->setPosition(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN));

	
	//Shield information
	shieldTexture.loadFromFile(SHIELD_T);

	for (int x = 0; x < shieldCount; x++) { shieldVector.emplace_back(new Shield(shieldTexture)); }
	shieldVector[0]->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT - 150));
	shieldVector[1]->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2 - 500, SCREEN_HEIGHT - 150));
	shieldVector[2]->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2 + 150, SCREEN_HEIGHT - 150));
	shieldVector[3]->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2 + 500, SCREEN_HEIGHT - 150));


}

void PlayingState::updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::Escape) { machine.run(machine.buildState<MainMenuState>(machine, window, true)); }
	if (key == sf::Keyboard::Space)  { playerShooting = isPressed; }
}

void PlayingState::updateEvents() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				updateKeyboardInputs(sfEvent.key.code, true);
				player->keyboardInputs(sfEvent.key.code, true);
				break;

			case sf::Event::KeyReleased:
				updateKeyboardInputs(sfEvent.key.code, false);
				player->keyboardInputs(sfEvent.key.code, false);
				break;
		}
	}
}

void PlayingState::update() {
	fpsCounter.updateCounter();

	/*-------------------------------------------------------------------------------------------------------------------*/
	//Player logic
	player->updateBorderBounds();
	player->updatePlayer();
	player->updateLives(3);
	pBullet->update(playerShooting, PLAYER_BULLET_SPEED, player->getX(), player->getY());

	/*-------------------------------------------------------------------------------------------------------------------*/
	//Invader information
	invaderManager.getInformation(enemyKilled);
	invaderManager.update();


	/*-------------------------------------------------------------------------------------------------------------------*/
	//Shield information
	for (auto& shield : shieldVector) {
		//Collision
		if (shield->getGlobalBounds().intersects(pBullet->getGlobalBounds())) {
			pBullet->setPosition(sf::Vector2<float>(BULLET_ORIGIN, BULLET_ORIGIN));
			shield->shieldProtection();
			//Collision with invader bullets
			//


			//Checking for shield damage
			if (shield->shieldProtectionNumber() <= 0) { shield->setPosition(sf::Vector2<float>(SHIELD_ORIGIN, SHIELD_ORIGIN)); }
		}
	}
	
	/*-------------------------------------------------------------------------------------------------------------------*/
	//Update removal of entities
	//removeEntities();
}

void PlayingState::removeEntities() {
	//Remove shields
	//auto shieldEnd = std::remove_if(shieldVector.begin(), shieldVector.end(), [](std::unique_ptr<Shield> & shield) {
	//	return !shield->isOnScreen();
	//});
	//shieldVector.erase(shieldEnd, shieldVector.end());

}

void PlayingState::render() {
	window.clear();

	//Render items
	fpsCounter.renderTo(window);
	versionText.renderTo(window);

	player->extraRenderTo(window);
	pBullet->renderTo(window);

	invaderManager.renderTo(window);
	
	for (auto& shield : shieldVector) { shield->renderTo(window); }

	window.display();
}
