#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "wc.h"

struct wc {
	/* you can define this struct to have whatever fields you want. */

	// A hash table that stores words and their counts 
	// In the form of a linked list 

	struct wc_entry{
		char *word; // stores the word as a string; serves as the key
		int count;  // stores the number of occurences of the word; serves as the value 
		struct entry *next;  // pointer to the next entry in the linked list 
	}

	// pointer to the head of the linked list
	struct wc_entry *head;
};

struct wc * wc_init(char *word_array, long size)
{	/* Initialize wc data structure, returning pointer to it. The input to this
	function is an array of characters. The length of this array is size.  The
	array contains a sequence of words, separated by spaces. You need to parse
	this array for words, and initialize your data structure with the words in
	the array. You can use the isspace() function to look for spaces between
	words. You can use strcmp() to compare for equality of two words. Note that
	the array is read only and cannot be modified. */
	struct wc *wc;

	wc = (struct wc *)malloc(sizeof(struct wc));
	assert(wc);
	wc->head = NULL; // initialize head of linked list to NULL
	struct wc_entry *curr = wc->head; // pointer to track the current entry in the linked list

	// iterate through word_array to parse words
	long i = 0;
	while (i < size){
		// parse word_array for each word and use isspace() to identify when a word ends 
		long start = i; // starting index of the word
		while (i < size && !isspace(word_array[i])){
			i++;
		}
		long end = i; // ending index of the word

		// extract the word from word_array
		int word_length = end - start;
		char *word = (char *)malloc(word_length + 1); // +1 for null terminator
		// assert(word); // ensure memory allocation was successful
		strncpy(word, &word_array[start], word_length);
		word[word_length] = '\0'; // null terminate the string

		// insert the word into wc 
		curr = wc->head;
	}
	

	return wc;
}

void
wc_output(struct wc *wc)
{
	/* wc_output produces output, consisting of unique words that have been inserted
	in wc (in wc_init), and a count of the number of times each word has been
	seen.
	
	The output should be sent to standard output, i.e., using the standard printf
	function.
	
	The output should be in the format shown below. The words do not have to be
	sorted in any order. Do not add any extra whitespace.
	word1:5
	word2:10
	word3:30
	word4:1 */
	TBD();
}

void
wc_destroy(struct wc *wc)
{	/* Destroy all the data structures you have created, so you have no memory
 	loss. */
	TBD();
	free(wc);
}
