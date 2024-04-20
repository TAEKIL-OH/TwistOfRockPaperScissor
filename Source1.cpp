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
			return 0;
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

	player.set_rps();
	com.set_rps();
	int turn = 0; // 0: draw status, 1: player win status, -1: com win status 

	// Decision game do-while loop
	// player's attack == false && com's attack == false && draw
	// repeat decision until one of players(player, com) being attack == true
	do {
		RockPaperScissor Decision(player, com);
		turn = Decision.statusOfTurn();
	} while (player.get_attack() == false && com.get_attack() == false && turn == 0);

	// after do decision game

	do {
		RockPaperScissor main(player, com);
	} while (true);

	// player's attack == true && com's attack == false && draw
	// return player's win

	// player's attack == false && com's attack == true && draw
	// return com's win

	// player's attack == false && com's attack == true && player's win
	// change player's attack == true && player's attack == false

	// player's attack == false && com's attack == true && com's win
	// repeat main game

	// player's attack == true && com's attack == false && player's win
	// repeat main game

	// player's attack == true && com's attack == false && com's win
	// change player's attack == false && player's attack == win


		std::cout << "END" << std::endl;

	return 0;
}
