#include "GameObject.h"

GameObject::GameObject(string typeID, int health, int speed, int x, int y)

{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;

	srand(time(NULL));
}

/*
	sets random typeID for each object
	random number up to 500 will be assigned

	typeID is string so have to convert int to string
	using stringstream
*/
string GameObject::setTypeID(string typeID) {
	int x = rand() % 500;
	stringstream k;

	k << x;
	k >> typeID;

	m_typeID = typeID;

	return m_typeID;
}

/*
	sets position of object 
	random x and y value from 1 - 10
*/
int GameObject::setPosition(int x, int y) {
	x = (rand() % 10) + 1;
	y = (rand() % 10) + 1;

	m_x = x;
	m_y = y;

	return m_x, m_y;
}

int GameObject::setHealth(int health) {
	m_health = health;

	return m_health;
}

int GameObject::setSpeed(int speed) {
	m_speed = speed;

	return m_speed;
}

string GameObject::getTypeID() const{
	return m_typeID;
}

int GameObject::getHealth() const{
	return m_health;
}

int GameObject::getX() const{
	return m_x;
}

int GameObject::getY() const {
	return m_y;
}

int GameObject::kill() {
	m_health = 0;
	
	return m_health;
}

/*
	returns true if health is greater than 0
*/
bool GameObject::isAlive() const
{
	return(m_health > 0);
}