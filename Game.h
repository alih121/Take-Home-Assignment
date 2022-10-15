#ifndef GAME_H
#define GAME_H
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <list>

class Game : public GameObject {
public:
	Game();
	void init(); 
	void grid(); // creates a grid
	void render() const; // cycle through list of GameObjects and render each object
	void update(); // cycle through list of GameObjects and update each object
	void battle(); // checks list to see if two objects have same coords, if true then battle
	void stats() const; // cycle list and output stats for each object
	void clean(); // remove objects from list with 0 or less health

private:
	GameObject* pPlayer; //Player
	GameObject* pEnemy1; //Enemy1
	GameObject* pEnemy2; //Enemy2
	GameObject* pEnemy3; //Enemy3
	GameObject* pEnemy4; //Enemy4
	list<GameObject*> lpGameObjects; //created a list of gameobjects pointers
	//int gridxy[11][11];
	//int (*pGridxy)[11][11];
};
#endif
