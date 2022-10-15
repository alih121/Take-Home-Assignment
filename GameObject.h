#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream> 
#include <sstream>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>
#include <functional>

using namespace std;

//abstract class 
class GameObject {
public:
	GameObject(string typeID = "", int health = 100, int speed = 5, int x = 0, int y = 0);
	string setTypeID(string typeID = "");
	int setPosition(int x = 0, int y = 0);
	virtual int setHealth(int health = 0);
	virtual int setSpeed(int speed = 0);
	void spawn(string typeID, int health, int speed, int x, int y);
	string getTypeID() const;
	int getX() const;
	int getY() const;
	int getHealth() const;
	int kill();
	virtual void render() const = 0; //print to screen typeID and coordinates 
	virtual void update()=0; //pure virtual member function
	virtual void stats() const = 0; //prints stats of referenced object
	bool isAlive() const; //returns true if health is greater than 0

protected:
	string m_typeID;
	int m_health;
	int m_speed;
	int m_x;
	int m_y;
};
#endif