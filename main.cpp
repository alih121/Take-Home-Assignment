#include "Enemy.h"
#include "Game.h"
#include "Player.h"

int main() {
	Game Game;
	Game.init();

	cout << "		Welcome to the battle of the brawns!			" << endl;
	cout << "	  The best fighters in one arena... Who will win?					" << endl;

	for (int i = 0; i < 30; i++) {
		cout << "------------------------------------------------------------------------" << endl;
		cout << "			Rendering characters...							 " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.render();
		cout << "------------------------------------------------------------------------" << endl;
		cout << "			Creating grid...							 " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.grid();
		cout << "------------------------------------------------------------------------" << endl;
		cout << "		  Updating characters positions...                     " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.update();
		cout << "------------------------------------------------------------------------" << endl;
		cout << "			Must a battle commence?                           " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.battle();
		cout << "------------------------------------------------------------------------" << endl;
		cout << "			  Characters stats...                             " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.stats();
		cout << "------------------------------------------------------------------------" << endl;
		cout << "			   Cleaning arena...                              " << endl;
		cout << "------------------------------------------------------------------------" << endl;
		Game.clean();
		
		
	}

	Game.stats();

	return 0;
}