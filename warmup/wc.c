#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "wc.h"
#include <string.h>

#define INITIAL_TABLE_SIZE 1024

struct wc {
	/* you can define this struct to have whatever fields you want. */
	struct wc_entry *table; // pointer to the hash table (array of wc_entry)
	long table_size; // size of the hash table
	int num_entries; // number of entries in the hash table
};

struct wc_entry{
	char *word; // stores the word as a string; serves as the key
	int count;  // stores the number of occurences of the word; serves as the value 
	int occupied;  // 0 = empty; 1 = occupied; -1 = deleted
};

// Hash function to compute index for a given word 
// djb2 hash function (http://www.cse.yorku.ca/~oz/hash.html)
unsigned long hash(char*str){
	unsigned long hash = 5381;
	int c;

	while ((c = *str++)){
		hash = ((hash << 5) + hash) + c; // hash * 33 + c
	}
	return hash;
}

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
	
	wc->table = (struct wc_entry *)calloc(INITIAL_TABLE_SIZE, sizeof(struct wc_entry));
	wc->table_size = INITIAL_TABLE_SIZE;
	wc->num_entries = 0;
	assert(wc->table);

	// initialize all netries in the hash table to empty
	for (int i = 0; i < INITIAL_TABLE_SIZE; i++) {
        wc->table[i].word = NULL;
        wc->table[i].count = 0;
        wc->table[i].occupied = 0;
    } 

	// iterate through word_array to parse words
	long i = 0;
	while (i < size){
		// Skip whitespace characters
		while (i < size && isspace(word_array[i])){
			i++;
		}
		
		if(i >= size) break; // break if end of array is reached

		// parse word_array for each word and use isspace() to identify when a word ends 
		long start = i; // starting index of the word
		while (i < size && !isspace(word_array[i])){
			i++;
		}
		long end = i; // ending index of the word

		// extract the word from word_array
		int word_length = end - start;
		if (word_length == 0) continue; // skip if no word found

		char *word = (char *)malloc(word_length + 1); // +1 for null terminator
		// assert(word); // ensure memory allocation was successful
		strncpy(word, &word_array[start], word_length);
		word[word_length] = '\0'; // null terminate the string

		// Hash the word and use linear probing to find slot 
		unsigned long index = hash(word) % wc->table_size;
		int probe_count = 0; 

		while(probe_count < wc->table_size){
			if (wc->table[index].occupied == 0){ // empty slot found
				// insert the word into the hash table
				wc->table[index].word = word;
				wc->table[index].count = 1;
				wc->table[index].occupied = 1;
				wc->num_entries++;
				break;
			} else if (wc->table[index].occupied == 1 && strcmp(wc->table[index].word, word) == 0){
				// word already exists, increment count
				wc->table[index].count += 1;
				free(word); // free the newly allocated word as it's a duplicate
				break;
			} else {
				// collision occurred, probe to next index
				index = (index + 1) % wc->table_size;
				probe_count += 1;
			}

		}

	return wc;
	}
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
	
	for (long i = 0; i < wc->table_size; i++){
		if (wc->table[i].occupied == 1){
			printf("%s:%d\n", wc->table[i].word, wc->table[i].count);
		}
	}
}

void
wc_destroy(struct wc *wc)
{	/* Destroy all the data structures you have created, so you have no memory
 	loss. */
	// free each word in the hash table
	for (long i = 0; i < wc->table_size; i++){
		if (wc->table[i].occupied == 1){
			free(wc->table[i].word);
		}
	}

	// free the hash table
	free(wc->table);

	// free the wc structure 
	free(wc);
}
