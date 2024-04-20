// Taekil Oh
// MJP Algorithm

#include <iostream>
#include <string>

class user;

// R: Rock,  P: Paper, S: Scissor
class RockPaperScissor {
	// (Rock & Scissor) || (Scissor & Rock) -> Rock
	// (Scissor & Paper) || (Scissor & Paper) -> Scissor
	// (Paper & Rock) || (Rock & Paper) -> Paper
	// Rock & Rock -> draw
	// Scissor & Scissor -> draw
	// Paper & Paper -> draw
private:
	char player;
	char com;

public:
	RockPaperScissor(user player, user com) {
		this->player = player.get_rps();
		this->com = com.get_rps();
	}

	int statusOfTurn() {
		if (player == com) {
			std::cout << "player = com" << std::endl;
			return 0;
		}
		else if ((player == 'R' && com == 'S') || (player == 'S' && com == 'R')) {
			std::cout << "Rock crushes Scissors. Player Turn" << std::endl;
			return 1;
		}
		else if ((player == 'S' && com == 'P') || (player == 'P' && com == 'S')) {
			std::cout << "Scissors cut Paper. Player Turn" << std::endl;
			return 1;
		}
		else if ((player == 'P' && com == 'R') || (player == 'R' && com == 'P')) {
			std::cout << "Paper covers Rock. Player Turn" << std::endl;
			return 1;
		}
		else {
			std::cout << "Com Turn" << std::endl;
			return -1;
		}
	}
};

class user {

protected:
	bool attack = false;
	bool win = false;
	char rps;

public:
	virtual ~user() {}

	bool get_attack() const {
		return attack;
	}

	void set_attack(bool attack) {
		this->attack = attack;
	}

	char get_rps() {
		return rps;
	}

	bool get_win() {
		return win;
	}

	void set_win(bool win) {
		this->win = win;
	}
};

// Player
class Player: public user {
private:
public:
	void set_rps() {

		// Ask the user for input
		std::cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
		char choice;
		std::cin >> choice;

		// Validate the input
		while (choice != 'R' && choice != 'P' && choice != 'S') {
			std::cout << "Invalid choice. Please enter R, P, or S: ";
			std::cin >> choice;
		}

		rps = choice;
	}
};

// Com
class Com: public user {
private:
	char randomSelect() {
		// Generate a random choice for the computer
		srand(time(0)); // Seed for random number generation
		int random = rand() % 3; // Generate a random number between 0 and 2
		if (random == 0) {
			return 'R'; // Rock
		}
		else if (random == 1) {
			return 'P'; // Paper
		}
		else {
			return 'S'; // Scissors
		}
	}
public:
	void set_rps() {
		rps = randomSelect();
	}

};

int main() {
	std::cout << "START" << std::endl;

	// attacking Turn
	std::cout << "Attacking Turn" << std::endl;
	// both User attack  are false
	// deciding attack by using RPS
	Player player;
	Com com;
	int turn = 0; // 0: draw status, 1: player win status, -1: com win status 

	// Decision game do-while loop
	// player's attack == false && com's attack == false && draw
	// repeat decision until one of players(player, com) being attack == true
	do {
		player.set_rps();
		com.set_rps();
		RockPaperScissor Decision(player, com);
		turn = Decision.statusOfTurn();
	} while (player.get_attack() == false && com.get_attack() == false && turn == 0);

	// after doone decision game
	// starting main game
	do {

		player.set_rps();
		com.set_rps();
		
		RockPaperScissor main(player, com);

		// player's attack == true && com's attack == false && player's win status(1)
		// repeat main game
		if (player.get_attack() == true && main.statusOfTurn() == 1)
		{
			std::cout << "There is no winner, player attack again" << std::endl;
			continue;
		}

		// player's attack == false && com's attack == true && com's win status(-1)
		// repeat main game
		if (com.get_attack() == true && main.statusOfTurn() == -1)
		{
			std::cout << "There is no winner, com attack again" << std::endl;
			continue;
		}

		// player's attack == true && com's attack == false && draw(0)
		// return player's win
		if (player.get_attack() == true && main.statusOfTurn() == 0)
		{
			std::cout << "Player catches Com, Player's win" << std::endl;
			player.set_win(true);
		}
			
		// player's attack == false && com's attack == true && draw
		// return com's win
		if (com.get_attack() == true && main.statusOfTurn() == 0)
		{
			std::cout << "Com catches Player, Com's win" << std::endl;
			com.set_win(true);
		}

		// player's attack == false && com's attack == true && player's win status
		// change player's attack == true && player's attack == false
		if (com.get_attack() == true && main.statusOfTurn() == 1)
		{
			player.set_attack(true);
			com.set_attack(false);
			std::cout << "Player's get attacking" << std::endl;
		}

		// player's attack == true && com's attack == false && com's win status
		// change player's attack == false && player's attack == win
		if (player.get_attack() == true && main.statusOfTurn() == -1)
		{
			player.set_attack(false);
			com.set_attack(true);
			std::cout << "Com's get attacking" << std::endl;
		}

	} while (player.get_win() != true || com.get_win() != true);
	
	// asking repeating

	std::cout << "END" << std::endl;

	return 0;
}
