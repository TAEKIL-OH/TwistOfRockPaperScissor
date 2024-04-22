// Taekil Oh
// MJP Algorithm
// can I add a data structure that the com can predict the user's decision when the game is continuing?
// the thing like "AI" and increasing the difficulty to win against com
// showing the winning rate of the "com" when game is continuing 

#include <iostream>
#include <string>
#include <vector>
#include <map>


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
class Player : public user {
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
class Com : public user {
private:
	// adding AI like to learn the user's pattern
	std::vector<char> userInputs;

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

	char analyzeUser() {
		// adding analysis things
		std::map<char, int> userCount;
		for (char input : userInputs) {
			userCount[input]++;
		}

		// advanced decision required. 
		// for example find the frequence

		// apply decision in here
		return '0';
	}



public:
	void set_rps() {
		rps = randomSelect();
		// print com for check
		std::cout << "Com's Choice in com class: "<< rps << std::endl;
	}

	void recodeUserInput(char user) {
		userInputs.push_back(user);
	}

};

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
		else if (player == 'R' && com == 'S') {
			std::cout << "Player Rock crushes Com Scissors. Player Turn" << std::endl;
			return 1;
		}
		else if (player == 'S' && com == 'R') {
			std::cout << "Com Rock crushes Player Scissors. Com Turn" << std::endl;
			return -1;
		}
		else if (player == 'S' && com == 'P') {
			std::cout << "Player Scissors cut Com Paper. Player Turn" << std::endl;
			return 1;
		}
		else if (player == 'P' && com == 'S') {
			std::cout << "Com Scissors cut Player Paper. Com Turn" << std::endl;
			return -1;
		}
		else if (player == 'P' && com == 'R') {
			std::cout << "Player Paper covers Com Rock. Player Turn" << std::endl;
			return 1;
		}
		else if (player == 'R' && com == 'P') {
			std::cout << "Com Paper covers Player Rock. Com Turn" << std::endl;
			return -1;
		}
	}
};

int main() {
	std::cout << "START" << std::endl;

		// both User attack  are false
	// deciding attack by using RPS
	Player player;
	Com com;
	int turn = 0; // 0: draw status, 1: player win status, -1: com win status 
	std::cout << "-------------------------------" << std::endl; // seperation line
	// attacking Turn
	std::cout << "Attacking Turn Decision" << std::endl;

	// Decision game do-while loop
	// player's attack == false && com's attack == false && draw
	// repeat decision until one of players(player, com) being attack == true
	do {
		
		player.set_rps();
		com.set_rps();

		// operation check point
		std::cout << "player's chioce print in main: " << player.get_rps() << std::endl;
		std::cout << "com's chioce print in main: " << com.get_rps() << std::endl;

		RockPaperScissor Decision(player, com);
		turn = Decision.statusOfTurn();
		
		std::cout << "turn in Decision: " << turn << std::endl;

		// set attack
		if (turn == 1) {
			player.set_attack(true);
			com.set_attack(false);
		}
		else if (turn == -1) {
			player.set_attack(false);
			com.set_attack(true);
		}
		else {
			player.set_attack(false);
			com.set_attack(false);
		}

	} while (player.get_attack() == false && com.get_attack() == false && turn == 0);

	std::cout << "End of first Decision: " << turn << std::endl;
	std::cout << "-------------------------------" << std::endl; // seperation line
	std::cout << "Starting MJP Game: " << turn << std::endl;
	std::cout << "Player's turn: " << std::boolalpha << player.get_attack() << std::endl;
	std::cout << "com's turn: " << std::boolalpha << com.get_attack() << std::endl;
	std::cout << "-------------------------------" << std::endl; // seperation line
	// after doone decision game
	// starting main game
	do {

		player.set_rps();
		com.set_rps();
		
		RockPaperScissor main(player, com);

		int status = main.statusOfTurn();

		if (player.get_attack() == true && com.get_attack() == false && status == 1)
		{
			// player's attack == true && com's attack == false && player's win status(1)
			// repeat main game
			std::cout << "There is no winner, player attack again" << std::endl;
		}
		else if (com.get_attack() == true && player.get_attack() == false && status == -1)
		{
			// player's attack == false && com's attack == true && com's win status(-1)
			// repeat main game
			std::cout << "There is no winner, com attack again" << std::endl;
		}
		else if (player.get_attack() == true && com.get_attack() == false && status == 0)
		{
			// player's attack == true && com's attack == false && draw(0)
			// return player's win
			std::cout << "Player catches Com, Player's win" << std::endl;
			player.set_win(true);
		}
		else if (com.get_attack() == true && player.get_attack() == false && status == 0)
		{
			// player's attack == false && com's attack == true && draw
			// return com's win
			std::cout << "Com catches Player, Com's win" << std::endl;
			com.set_win(true);
		}
		else if (com.get_attack() == true && player.get_attack() == false && status == 1)
		{
			// player's attack == false && com's attack == true && player's win status
			// change player's attack == true && player's attack == false
			player.set_attack(true);
			com.set_attack(false);
			std::cout << "Player's get attacking turn" << std::endl;
		}
		else if (player.get_attack() == true && com.get_attack() == false && status == -1)
		{
			// player's attack == true && com's attack == false && com's win status
			// change player's attack == false && player's attack == win
			player.set_attack(false);
			com.set_attack(true);
			std::cout << "Com's get attacking turn" << std::endl;
		}

	} while (player.get_win() == false && com.get_win() == false);
	
	// asking repeating

	std::cout << "-------------------------------" << std::endl; // seperation line
	
	if (player.get_win() == true) {
		std::cout << "while loop end and player win" << std::endl;
	}
	else {
		std::cout << "while loop end and com win" << std::endl;
	}
	
	std::cout << "-------------------------------" << std::endl; // seperation line
	std::cout << "END" << std::endl;

	return 0;
}
