#include "Enemy.h"

Enemy::Enemy(string typeID, int health, int speed, int x, int y) :
	GameObject(typeID, health, speed, x, y)
{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;

	srand(time(NULL));
}

/*
	using random this will set enemies health between 90 - 150
*/
int Enemy::setHealth(int health) {
	health = 90 + (rand() % 61);

	m_health = health;

	return m_health;
}

/*
	randomly sets enemies speed between 1 and 3
*/
int Enemy::setSpeed(int speed) {
	speed = 1 + (rand() % 4);

	m_speed = speed;

	return m_speed;
}

/*
	updates movement of enemies every round

	a random decision of 1-10 will determine enemy y axis movement

	anything below 9 will bring the enemy closer to 0 or up on the y axis
	a value of 9 or 10 will not change enemy movement on y axis

	if player goes over 10 or goes under 0, aka hits a perimeter, deduct from health
*/
void Enemy::update() {
	//srand((int)time(0));
	int randomDecision = (rand() % 10) + 1;

	if (randomDecision < 9) {
		m_y -= 1;
		
		if (m_y <= 0) {
			m_y = 1;
			m_health -= (m_speed * 3);
		}
	}
	else if (randomDecision == 9 || randomDecision == 10) {
		m_y = m_y;
	}
}

void Enemy::render() const{
	cout << "			   Enemy Stats" << endl;
	cout << "			   Type ID: " << m_typeID << "\n";
	cout << "			      X: " << m_x << "\n";
	cout << "			      Y: " << m_y << "\n";
	cout << "" << endl;
}

void Enemy::stats() const{
	cout << "			   Enemy Stats" << endl;
	cout << "			   Type ID: " << m_typeID << "\n";
	cout << "			    Health: " << m_health << "\n";
	cout << "			     Speed: " << m_speed << "\n";
	cout << "			       X: " << m_x << "\n";
	cout << "			       Y: " << m_y << "\n";
	cout << "" << endl;
}