//given two words,
//check they are anagram or not

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int is_anagram(char *word1, char *word2, int length);
void create_word(char *str, int index, int max_length, char *added_indexs);
int is_containing(char *added_indexs, int target, int count);

int count = 0; // how many words are created
int main(void){
	char w1[8];
	char w2[8];
	
	strcpy(w1, "bahriye");
	strcpy(w2, "harbiye");
	
	int anagram_test = is_anagram(w1, w2, strlen(w1));
	
	printf("%s and %s are ", w1, w2);
	if(anagram_test) printf("anagrams!\n");
	else printf("not anagrams!\n");
	
	//printf("%d\n", count);
	return 0;
}

int is_anagram_number = 0;
char *word;
char *word2;

int is_anagram(char *w1, char *w2, int length){
	char *new_word = malloc(length + 1);
	char *added_indexs = malloc(length + 1);
	word = w1;
	word2 = w2;
	memset(added_indexs, 0, length + 1);
	memset(new_word, 0, length + 1);
	create_word(new_word, 0, length, added_indexs);
	return is_anagram_number;
}

//creating words by the given word
//it's recursive function
void create_word(char *str, int index, int max_length, char *added_indexs){
	if(is_anagram_number == 1) return; // finish. because we determined they're anagram. nexts steps are unnecessary.
	for(int i = 0; i < max_length; ++i){
		if(is_containing(added_indexs, i, index)) continue; // if the letter to be added is already added, increase the i, so take the next letter
		str[index] = word[i];

		if(index == max_length - 1) {
			if(strcmp(str, word2) == 0) is_anagram_number = 1; // if it's anagram
			//printf("%s\n", str);// if word is created, then print to screen that word which is created
			count++;
		}
		else {
			added_indexs[index] = i;
		       	create_word(str, index + 1, max_length, added_indexs);
		}
	}
}

//basic .contains method
int is_containing(char *added_indexs, int target, int count){
	for(int i = 0; i < count; i++){
		if(added_indexs[i] ==  target) return 1;
	}
	return 0;
}
