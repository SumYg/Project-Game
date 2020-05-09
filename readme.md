# Group 87
## Team Members
Name: Woo Nathan Hugo (nathanwooo) (3035683162)

Name: Yeung Sum (SumYg) (3035683150)

## Game Description
The game is a card text-based game. It is a player vs player game, which supports 2 to 4 players. At the beginning, a player need to type the number of players and their name. The system will help each player draw a number from 1 to 10 randomly, which decides the order of the player in the game (the player with the biggest number will start first). If there are 2 players, a card pool consists of two suits of cards from A to K will be generated, where there are totally 26 cards in the card pool. If there are 3 or 4 players, a card pool consists of three suits of cards from A to K will be generated, where there are 39 cards in the card pool. The cards from A to 10 represent 1 to 10 points, and J, Q, K represents 11, 12 ,13 points respectively. Each game consist of 6 rounds, in each round every players can choose to draw a card from the card pool, or discard a card from their hand. After 6 rounds, the player with exactly 27 points wins. If the game is a draw because two or more players meet the winning condition, the players who meet the winning condition will play another game to decide the winner. On the other hand, if the game is a draw because no one meet the winning condition, all players will play another game to decide the winner. The game will keep repeating until there is a winner. 

## Game Features
### Generation of random game sets or events
Players are given a random number from 1 to 10 at the beginning.

When playing the card game, the cards are also drawn from the card pool randomly.
### Data structures for storing game status
The name (string type) and hand of players (linked list structure), as well as the number of games won (int type) are stored in an array of structures.

The drawn cards and the order of player in the game are stored in dynamic arrays.
### Dynamic memory management
The hand cards of each player are stored in a linked list structure, each node stores 1 hand card. When a player draws a card, a new node will be created and inserted at the end of the list. When a player discards a card, the corresponding node will be deleted and the list will be relinked, thus memory is released.

The order of player and drawn cards are stored in dynamic arrays. The indexes of players in the array of structures are stored in an array sequentially according to the order decided before the game starts.
### File input/output
The winner message of each game is output to a file. In the end, when there is only 1 winner, the winners of each game and the final winner will be shown to the screen.

### Program codes in multiple files
There are three main parts in this program, initialization (i.e. input of the number of players and their names), game stage and checking for the winners/final winner after 6 rounds of the game (if there is only 1 player wins, print out the winning message, otherwise return to the game stage).

The codes corresponding to these three parts are separated into different files for better coding and debugging.

## Non-Standard C/C++ Libraries
There isn't any non-standard C/C++ libraries used in this project.
## Compilation and Execution Instructions
### Compilation
Enter the following command in the terminal to compile the program:
```
$ make gp87game
```
### Execution
Enter the following command in the terminal to execute:
```
$ ./gp87game
```
### Playing one more time
If you find the game interesting and want to play again, enter the following command in the terminal:
```
$ make again
```
### Cleaning up
If you want to delete all the files generated due to the compilation and program, please enter the following command line:
```
$ make clean
```
## Remarks
Some ideas of this card game come from Blackjack and Thirty-one.
