#include "Shield.h"


Shield::Shield(sf::Texture texture) 
	: Entity(texture) {

	entity.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Shield::shieldProtection() {
	shieldProtectionAccount--;

	std::cout << shieldProtectionAccount << '\n';
}

int Shield::shieldProtectionNumber() {
	return shieldProtectionAccount;
}

bool Shield::isOnScreen() {
	if (getX() >= SCREEN_WIDTH || getX() <= 0 || getY() >= SCREEN_HEIGHT || getY() <= 0) {
		return false;
	}
	return false;
}
