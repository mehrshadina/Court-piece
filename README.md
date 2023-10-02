# Court-piece Game (C Implementation)

Court-piece is a popular trick-taking card game in South Asia. This project is an implementation of the Court-piece game in C.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [How to Compile and Run](#how-to-compile-and-run)
- [Game Rules](#game-rules)
- [Contributing](#contributing)
- [License](#license)

## Description

This project provides a console-based implementation of the Court-piece card game using the C programming language. Court-piece is a trick-taking game that is played by four players in two teams.

## Features

- **Console-based Gameplay**: Play Court-piece in a terminal/console environment.
- **Two-Player Teams**: The game involves teams of two players each, playing against each other.
- **Interactive Interface**: The game provides an interactive interface for a seamless gaming experience.

## How to Compile and Run

To compile the Court-piece game, follow these steps:

1. Clone the repository:

   git clone <repository_url>
   cd court-piece-game-c

2. Compile the source code:

    gcc -o court_piece_game main.c game.c deck.c player.c -lm

3. Run the compiled executable:

    ./court_piece_game
    
## Game Rules

Court-piece is a trick-taking game played with a standard deck of cards. Here are the basic rules of the game:

    The game is played with a standard deck of 52 cards.
    Players form two teams, and teammates sit opposite each other.
    The objective is to win tricks containing valuable cards.

For detailed game rules, refer to RULES.md.

## Contributing

Contributions to this project are welcome. Feel free to open issues or submit pull requests to enhance the game or fix any bugs.

## License

This project is licensed under the MIT License.

Feel free to modify or extend this README based on your specific implementation, additional features, or any other details you want to include. If you have specific information you'd like to add or modify, please let me know!


