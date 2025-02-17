# Rock-Paper-Scissors Game

## Overview
This project implements a **Rock-Paper-Scissors (RPS) game** in C++. The game allows a player to compete against a computer opponent, with win statistics tracked over multiple rounds.

## Features
- **Basic Rock-Paper-Scissors Gameplay**
  - Player selects **Rock (R)**, **Paper (P)**, or **Scissors (S)**.
  - Computer selects a move randomly.
  - The game determines a winner based on standard RPS rules.

- **Turn-Based Game Flow**
  - The first RPS round decides **who gets the attack turn**.
  - The attacking player has a chance to **win instantly** by catching the opponent.
  - If the defender wins, they take over the attack.

- **Win Statistics Tracking**
  - The program keeps track of the **player's and computer's win rates**.
  - Displays the number of **total wins and losses**.

- **Replay System**
  - The game **asks the player if they want to continue playing**.
  - Win records persist until the program is restarted.

## Implementation Details
### **User Class (`user`)**
A base class for both the **Player** and **Com**, handling:
- Attack status (`attack`)
- Selected move (`rps`)
- Win status (`win`)

### **Player Class (`Player`)**
- Manages user input for **Rock, Paper, or Scissors**.
- Keeps track of **total wins and losses**.
- Ensures input validation.

### **Computer Class (`Com`)**
- Selects a move **randomly**.

### **Game Logic (`RockPaperScissor` class)**
- Determines the winner based on **RPS rules**.
- Manages turn-based attack mechanics.
- Alternates turns when necessary.

### **Main Game Loop (`main()`)**
- Handles **game flow, decision-making, and replay mechanics**.
- Displays **computer’s and player’s win rates**.
- Allows the player to continue playing or quit.

## Usage
1. **Run the Program**: Compile and execute the C++ code.
2. **Enter a Move**: Choose between Rock (R), Paper (P), or Scissors (S).
3. **Play Against Computer**: The computer selects its move and the game determines the winner.
4. **Track Stats**: Win and loss counts are displayed after each round.
5. **Continue or Quit**: The player can choose to play again or exit.

## Future Enhancements
- **Add Difficulty Levels**:
  - Easy Mode (random moves), Hard Mode (more strategic play).
- **Visual UI Enhancements**:
  - Add a **Graphical User Interface (GUI)** for better gameplay experience.
- **Multiplayer Mode**:
  - Allow two players to compete instead of playing against the computer.

## Conclusion
This project demonstrates a simple **Rock-Paper-Scissors** game implemented in C++. The game tracks wins and losses and allows replayability. Future improvements could include a more strategic AI and better user interface.

