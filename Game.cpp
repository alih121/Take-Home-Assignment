#include "Game.h"

Game::Game()

{

}

void Game::init() {
	pPlayer = new Player();
	pEnemy1 = new Enemy();
	pEnemy2 = new Enemy();
	pEnemy3 = new Enemy();
	pEnemy4 = new Enemy();
	list<GameObject*>::const_iterator iter;
	list<GameObject*>::const_iterator iter2;

	pPlayer->setTypeID();
	pEnemy1->setTypeID();
	pEnemy2->setTypeID();
	pEnemy3->setTypeID();
	pEnemy4->setTypeID();

	pPlayer->setPosition();
	pEnemy1->setPosition();
	pEnemy2->setPosition();
	pEnemy3->setPosition();
	pEnemy4->setPosition();
	
	/*
		nested iterator for loops to make sure each object is on unique position
		do while loop broke program but this would be extra security if it worked...
	*/
	//do {
		for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter) {
			for (iter2 = lpGameObjects.begin(); iter2 != lpGameObjects.end(); ++iter2) {
				if ((*iter)->getX() == (*iter2)->getX() && (*iter)->getY() == (*iter2)->getY() && (*iter)->getTypeID() != (*iter2)->getTypeID()) {
					(*iter)->setPosition();
					(*iter2)->setPosition();
				}
			}
		}
	//} while ((*iter)->getX() == (*iter2)->getX() && (*iter)->getY() == (*iter2)->getY() && (*iter)->getTypeID() != (*iter2)->getTypeID());

	pPlayer->setHealth();
	pEnemy1->setHealth();
	pEnemy2->setHealth();
	pEnemy3->setHealth();
	pEnemy4->setHealth();

	pPlayer->setSpeed();
	pEnemy1->setSpeed();
	pEnemy2->setSpeed();
	pEnemy3->setSpeed();
	pEnemy4->setSpeed();

	lpGameObjects.push_back(pPlayer);
	lpGameObjects.push_back(pEnemy1);
	lpGameObjects.push_back(pEnemy2);
	lpGameObjects.push_back(pEnemy3);
	lpGameObjects.push_back(pEnemy4);
}

void Game::grid() {
	//2d array
	const int row = 11;
	const int col = 11;
	const char player = 'P';
	const char enemy = 'E';
	int gridxy[row][col];
	//int(*pGridxy)[row][col] = &gridxy;
	list<GameObject*>::const_iterator iter;

	/*
		this will check what positions the objects should take on the 10 x 10 grid
		it assigns the values of the x and y to the 2d array and save it there
		the empty spaces will be a default character
	*/
	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				if (j == (*iter)->getX() && i == (*iter)->getY() && (*iter) != lpGameObjects.front()) {
					gridxy[i][j] = enemy + ' ';
					//printf("%c", gridxy[i][j]);
				}
				
				if(j == (*iter)->getX() && i == (*iter)->getY() && (*iter) == lpGameObjects.front()) {
					gridxy[i][j] = player + ' ';
					//printf("%c", gridxy[i][j]);
				}
			}
		}
	}

	/*
		This prints 10 x 10 grid to user
		using spaces and nested for loops to create an organised and somewhat visually-appealing grid
	*/
	cout << "		  ";
	cout << "----------------------------------" << endl;
	cout << "		  ";
	cout << "    ";
	for (int i = 1; i < 11; i++) {
		cout << i << "  ";
	}
	cout << "\n";
	cout << "		  ";
	cout << "----------------------------------" << endl;

	for (int row = 1; row < 11; row++) {
		cout << "		  ";
		
		if (row == 10) {
			cout << row << "|";
		}
		else {
			cout << " " << row << "|";
		}

		cout << " ";
		for (int col = 1; col < 11; col++) {
			printf("%c", gridxy[row][col]);
			cout << "  ";
		}
		cout << "\n";
	}
}

void Game::render() const{
	list<GameObject*>::const_iterator iter;
	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{
		(*iter)->render();
	}
}

void Game::update() {
	list<GameObject*>::const_iterator iter;
	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{
		(*iter)->update();
	}
}

/*
	this battle function uses two nested iterator for loops
	in order to find the objects occupying the same coords

	if it finds the same coords on two objects, it puts them to a fight
	object with greater health automatically wins and use kill() function for other object

	calling clean() after the battle makes sure the same two objects dont fight again
	once it iterates over the next few objects

	however there is sometimes a program error when trying to clean which completely terminates the program...
	from tons of debugging it seems that after cleaning lpGameObjects, the iterators become invalidated
	will have to find a fix for this!!
*/
void Game::battle() {
	list<GameObject*>::const_iterator iter;
	list<GameObject*>::const_iterator iter2;

	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{		
		for (iter2 = lpGameObjects.begin(); iter2 != lpGameObjects.end(); ++iter2) {
			if ((*iter)->getX() == (*iter2)->getX() && (*iter)->getY() == (*iter2)->getY() && (*iter)->getTypeID() != (*iter2)->getTypeID()) {
				cout << "The object " << (*iter)->getTypeID() << " and the object " << (*iter2)->getTypeID() << " occupy the same grounds at X: " << (*iter)->getX() << " and Y: " << (*iter)->getY() << endl;
				cout << "A battle must take place!" << endl;
				
				if ((*iter)->getHealth() > (*iter2)->getHealth()) {
					cout << (*iter)->getTypeID() << " health: " << (*iter)->getHealth() << endl;
					cout << (*iter2)->getTypeID() << " health: " << (*iter2)->getHealth() << endl;
					cout << (*iter)->getTypeID() << " triumphs with the greater health!" << endl;
					cout << (*iter2)->getTypeID() << " must die now!" << endl;
					(*iter2)->kill();
					//clean();
				}
				else if((*iter2)->getHealth() > (*iter)->getHealth()) {
					cout << (*iter)->getTypeID() << " health: " << (*iter)->getHealth() << endl;
					cout << (*iter2)->getTypeID() << " health: " << (*iter2)->getHealth() << endl;
					cout << (*iter2)->getTypeID() << " triumphs with the greater health!" << endl;
					cout << (*iter)->getTypeID() << " must die now!" << endl;
					(*iter)->kill();
					//clean();
				}
			}
			/*else {
				cout << "Everyone is safe for now...." << endl;
			}*/
			clean();
		}
	}
}

void Game::stats() const{
	list<GameObject*>::const_iterator iter;
	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{
		(*iter)->stats();
	}
}

void Game::clean()
{
	list<GameObject*>::const_iterator iter;
	for (iter = lpGameObjects.begin(); iter != lpGameObjects.end(); ++iter)
	{
		if ((*iter)->isAlive() == false && (*iter) != lpGameObjects.front()) {
			cout << (*iter)->getTypeID() << " is Dead, removing it from the list" << endl;
			iter = lpGameObjects.erase(iter);
			//lpGameObjects.pop_front();
		}

		if ((*iter)->isAlive() == false && (*iter) == lpGameObjects.front()) {

			cout << "The player is dead! The game is over :(" << endl;
			exit(1);
		}
		//lpGameObjects.remove_if((*iter)->isAlive() == false);
	}

}

