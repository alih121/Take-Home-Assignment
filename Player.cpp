#include "Player.h"
 

Player::Player(string typeID, int health, int speed, int x, int y) :
	GameObject(typeID, health, speed, x, y)
{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;

	srand(time(NULL)); //initialise seed generator
}

/*
	using random this will set players health between 140 - 170
*/
int Player::setHealth(int health) {
	health = 140 + (rand() % 31);
	
    m_health = health;

	return m_health;
}

/*
	randomly sets players speed between 2 and 4
*/
int Player::setSpeed(int speed) {
	speed = 2 + (rand() % 4);

	m_speed = speed;

	return m_speed;
}

/*
	updates movement of player every round

	user will type n,s,e,w for their preferred direction

	input n (north), player will move up or closer to 0 on y axis
	input s (south), player will move down or closer to 10 on y axis
	input e (east), player will move right or closer to 10 on x axis
	input w (west), player will move left or closer to 0 on y axis

	if player goes over 10 or goes under 0, aka hits a perimeter, deduct from health
*/
void Player::update() {
	cout << "To move your player, please provide an input of N, S, E, W (North, South, East, West)" << endl;

	char direction;

	cin >> direction;

	if (direction == 'N' || direction == 'n') {
		m_y -= 1;

		if (m_y <= 0) {
			m_y = 1;
			m_health -= (m_speed * 2);
		}
	}
	else if (direction == 'S' || direction == 's') {
		m_y += 1;

		if (m_y >= 11) {
			m_y = 10;
			m_health -= (m_speed * 2);
		}
	}
	else if (direction == 'E' || direction == 'e') {
		m_x += 1;

		if (m_x >= 11) {
			m_x = 10;
			m_health -= (m_speed * 2);
		}
	}
	else if (direction == 'W' || direction == 'w') {
		m_x -= 1;

		if (m_x <= 0) {
			m_x = 1;
			m_health -= (m_speed * 2);
		}
	}
}

void Player::render() const {
	cout << "			   Player Stats" << endl;
	cout << "			   Type ID: " << m_typeID << "\n";
	cout << "			      X: " << m_x << "\n";
	cout << "			      Y: " << m_y << "\n";
	cout << "" << endl;
}

void Player::stats() const {
	cout << "			   Player Stats" << endl;
	cout << "			   Type ID: " << m_typeID << "\n";
	cout << "			    Health: " << m_health << "\n";
	cout << "			     Speed: " << m_speed << "\n";
	cout << "			       X: " << m_x << "\n";
	cout << "			       Y: " << m_y << "\n";
	cout << "" << endl;
}