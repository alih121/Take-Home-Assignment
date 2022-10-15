#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(string typeID = "", int health = 0, int speed = 0, int x = 0, int y = 0);
	int setHealth(int health);
	int setSpeed(int speed);
	void render() const; 
	virtual void update();
	void stats() const;
};
#endif
