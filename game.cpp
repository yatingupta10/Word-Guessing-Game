/* include library access files */
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>

/* max allowed attempts is 5 */
#define Max_Play_Count 5                  

/* class for the word game */
class word_guess_game                       
{
 public:
  		char array[8][12];
  		Int read_count;
  		ifstream inputFile;
  	
public:
 		 word_guess_game();
  		void rdf(char *file);
  		void start_text();
};

/* constructor : to initialize member variables */
word_guess_game::word_guess_game()    
{
 read_count = 0;
}

/* member function : to open the input file and read the words
	line by line.
	Limitations : The word must be less or equal to 12 chars.
No blanc lines permitted in the input file.
			For now the name of the input file is fixed as "input.txt".
			The number of words supported is 8.
			All the words must be in capital letters.
*/
void word_guess_game::rdf (char *file)
{
	inputFile.open(file);
	while(!inputFile.eof())
	{
	  	inputFile.getline(array[read_count], 16, '\n');
	  	read_count++;
	}
}

/* member function : to display the starting text for the game */
void word_guess_game::start_text()
{
	 clrscr();
	 cout << "************************************************************";
	 cout << setw(55) << "  GUESS GAME\n";
	 cout << "************************************************************";
	 cout << "\n\n" << setw(40) << " 1. Play the game";
	 cout << "\n" << setw(31) << " 2. Exit";
	 cout << "\n\n\n Please enter your choice : ";
}

/* main function that calls the class and its functions */
void main()
{
 	 clrscr();
 int ch;

/* number of words supported 8 max 12 characters */
 	 char arr[8][12];      
  	
char arr1[10];
 	 int i, j=0, k=0, l=0, c=0, r=0;
 	 int me, game_played=0, option, len;
 	 word_guess_game wgg;
  	ifstream inputFile;        /* not used but can be used */

 	 /* read data from file "file.txt" */
 	 wgg.rdf("file.txt");

  	/* copy the data in a local array */
 	 for (me = 0 ; me<wgg.read_count; me++)
 {
		 strcpy(arr[me],wgg.array[me]);
  }

  /* randomize the data in the local array */
 	 randomize();

  	/* play the game loop */
  	do
  	{
	 	game_played++;
		 wgg.start_text();
	 	option = getch();
		 cout << (char) option;

		 if(option=='1')
	 	{ 	
/* play the game */
cout << "\nGuess the letters of the word one by one (letters are in caps):\n";
			i=random(6);

			/* hide the word characters by showing '*' */
			while(arr[i][j] != '\0')
			{
				cout<<"*";
				arr1[j]='*';
				j++;
			}
			j=0;
			len = strlen(arr[i]);
			while(arr[i][k]!= '\0')
			{
				if (len == k)
			  	break;
				cout<<"\n";
				ch = getch();
				while(arr[i][l]!= '\0')
				{
					if(arr[i][l] == (char )ch)
					{
				 		 arr1[l]= (char )ch;
						  cout<<arr1[l];
				  		r++;
				  		c++;
					}
					else
					{
				  		cout<<arr1[l];
					}
					l++;
				}
				if(r>1)
				{
					k=k+r;
					r=0;
					continue;
				}
				l=0;
				r=0;
				k++;
			}
			c=k-c;
			k=0;
			cout << "\n\n Actual Word : ";
			cout << arr[i];
			cout << "\n No. of mishits : " << c;
			c=0;
			cout << "\n\n Press any key to continue";
			getch();
		 }

	 	else if(option=='2')
		 { 	
/* exit the game */
			exit(0);
	 	}

	 	else
		 {
			cout << "\n\nInvalid Option !!!!";
			cout << "\nPlease enter a valid character." << endl;
			option=4;
			// delay(2500);
		 }

 	 } 
while((option=='1'||option=='2'||option==4)&&(game_played < Max_Play_Count));
  	cout << " \n \n you have played the game " << game_played << " times";
  	cout << "\n allowed attempts " << (int) Max_Play_Count;
  	getch();

}

