The project can be used in many ways some of them are listed below
- to increase the vocabulary
- to sharpen the mind and skills 
- as a time pass

The project contain following technical details
- A class ‘word_guess_game’ that captures the following data members and functions
	- char array[8][12]; /* memory array that stores 8 words of max 12 characters */
	- int read_count; /* counts the number of words read */
	- ifstream inputFile; /* input file stream pointer */
	- word_guess_game(); - /* constructor that initializes read_count */
	- void rdf(char *file); /* function that reads the data in memory ‘array’ from a file */
	- void start_text(); /* prints the starting text to prompt user to play the game */

- This is a very basic game and has following limitations
	- The word must be less than or equal to 12 characters
	- No blank lines permitted in the input file
	- for now the name of the input file is fixed as "input.txt"
	- maximum number of words supported is 8
	- all the characters that you guess in the word must be entered in capital letters

- Screen output is given to allow user to enter the option for playing or exit the game

- Once user start the playing part the word is shown hidden by the character ‘*’ with number of characters in the word guess

- User presses the characters and if that character exists in the word then its place is updated by that character

- The number of characters in the word is the binding limit of entering the characters

- At the end the word is shown and your score of how many characters in the word you guessed right is also shown

- The number of attempts a person can play this game has been fixed at 5 as of now
