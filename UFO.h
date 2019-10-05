#ifndef UFO_H
#define UFO_H

#include "State.h"
#include "Entity.h"

class UFO : public Entity {
	public:
		UFO(sf::Texture texture);

		bool isOnScreen();
};

#endif