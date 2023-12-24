
# Guess Word Game

This is a simple console-based Guess Word Game written in C++. The game allows the player to guess a word either randomly selected from a database or a word of the day. The game keeps track of the number of attempts made by the player.

# How to Play

1. Run the game and choose an option from the main menu:
```
Greetings in Guess Word Game!
1 - Random Word
2 - Word of the day
0 - Exit
Enter:
```
2. If you choose option 1, you will be prompted to guess a randomly selected word. Enter your guesses, and the game will provide feedback until you guess the correct word.

3. If you choose option 2, you can only play once a day. The word of the day is randomly selected from the database. Follow the same steps as in option 1.

4. The game keeps track of the number of tries you make to guess the word. The result and feedback are displayed after each attempt.

5. Exit the game by choosing option 0.

# File Descriptions

`WordDB.txt`: Database file containing a list of words.

`WordOfDay.txt`: File used to store the date when the word of the day was last played.

# Notes

The game uses C++ standard libraries and features.

Enjoy playing the Guess Word Game! Feel free to contribute and improve the game.

Here you can see some example:
```
Greetings in Guess Word Game!
1 - Random Word
2 - Word of the day
0 - Exit
Enter: 1

RESULT: *****
ENTER : aaaaa

RESULT: ***A*
ENTER : clear

RESULT: **EAr
ENTER : breaf

RESULT: *REA*
ENTER : dream

That's right!
You made 4 tries!

Greetings in Guess Word Game!
1 - Random Word
2 - Word of the day
0 - Exit
Enter:
```

