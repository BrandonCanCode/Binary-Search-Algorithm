//Binary Search Algorithm in C

#include <stdio.h>
#include <string.h>

// Structor for all entries in dicitonary
struct entry {
	char word[15];
	char definition[60];
};

// Function prototype to look up a word from our dictionary
int lookup(const struct entry dictionary[], const char search[], const int entries) {
	int low = 0;
	int mid, result;
	int high = entries - 1;
	
	while (low <= high) {

		//Algorithm
		mid = (low + high) / 2;
		result = strcmp(search, dictionary[mid].word);

		if (result < 0)
			high = mid - 1;
		else if (result > 0)
			low = mid + 1;
		else return mid;
	}

	// If not found
	return -1;
}


int main(void) {
	
	// The Information
	// The small wacky dictionary
	const struct entry dictionary[100] =
	{   {	"bumfuzzle",	"to confuse or fluster"	},
		{	"canoodle",		"to caress, fondle, or pet amorously"	},
		{	"cattywampus",	"askew or awry" },
		{	"crapulence",	"sick from excessive drinking or eating"	},
		{	"discombobulate", "to confuse, upset, or frustrate"	},
		{	"kerfuffle",	"a fuss; commotion"	},
		{	"shivoo",		"boisterous party or celebration" },
		{	"snark",		"mysterious, imaginary animal"	},
		{	"snollygoster",	"clever, inscrupulous person"	},
		{	"widdershins",	"to go counterclockwise or in a oppopsite of usual direction"	} };

	// Decleration of Variables

	int again = 1;
	int entries = 10;
	char word[15];
	int word_entry;

	// Menu
	// Intro
	printf("\n+ - - - - - - Welcome to the binary search! - - - - - - +");
	printf("\n+ - - - - Type a word to find its definition  - - - - - +");
	printf("\n| Searchable words:\t\t\t\t\t|");
	printf("\n|\t\t\t\t\t\t\t|");
	
    // Loops to display avaliable words 
	for (int i = 0; i < entries; i++) {
		printf("\n| %-53s |", dictionary[i].word);
	}
	printf("\n|\t\t\t\t\t\t\t|");
	printf("\n+ - - - - - - - - - - - - - - - - - - - - - - - - - - - +");



	int lookup(const struct entry dictionary[], const char search[], const int entries);

	//Loop
	while (again == 1) {

		//Input
		printf("\n\nEnter a wacky word: ");
		//gets_s(word);
		scanf_s("%15s", word, (unsigned)sizeof(word));

		word_entry = lookup(dictionary, word, entries);

		//Output
		if (word_entry != -1)
			printf("\n\n--> %s", dictionary[word_entry].definition);
		else
			printf("\n\nSorry, %s is not in my wacky dicitonary.", word);

		//Again question
		printf("\n\nWant to go again? (1 for yes or anything else for no): ");
		scanf_s("%d", &again, sizeof(int));
	}
	
	return 0;
}