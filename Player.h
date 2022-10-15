#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject {
public:
	Player(string typeID = "", int health = 0, int speed = 0, int x = 0, int y = 0);
	int setHealth(int health);
	int setSpeed(int speed);
	void render() const;
	virtual void update();
	void stats() const;
};
#endif 