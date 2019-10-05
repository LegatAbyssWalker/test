#include "UFO.h"

#include "MoreInfo.h"

UFO::UFO(sf::Texture texture) : Entity(texture) {

	entity.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	entity.setScale(1 * 1.5, 1 * 1.5);
}

bool UFO::isOnScreen() {
	if (getX() <= SCREEN_WIDTH && getX() >= 0) {
		return true;
	}
	return false;
}