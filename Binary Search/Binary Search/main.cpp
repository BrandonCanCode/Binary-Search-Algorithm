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


	int entries = 10;
	char word[15];
	int word_entry;
	int lookup(const struct entry dictionary[], const char search[], const int entries);

	//Input
	printf("Enter a wacky word: ");
	gets_s(word);
	
	word_entry = lookup(dictionary, word, entries);

	//Output
	if (word_entry != -1)
		printf("\n%s\n", dictionary[word_entry].definition);
	else
		printf("\nSorry, %s is not in my wacky dicitonary. %d\n", word, word_entry);
	
	return 0;
}