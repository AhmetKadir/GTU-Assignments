/**
 * @file hw7_solution2.c
 * @author Ahmet Kadir Aksu
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20

void fix_spelling_error(char word[]);
char* find_best_correction(char word[]);

int main(){
    FILE * fp1;
	FILE * fp3;
	char word[N];
	int wordIndex = 0, i;
	int charSize = 0;

	fp3 = fopen("text_fixed.txt" , "w");
	fclose(fp3);

	for(i=0; i < 20; i++){
    	word[i] = 0;
	}		

	fp1 = fopen("the_text.txt" , "r");
	do
    {
        char ch = fgetc(fp1);
		
		/* If char is a whiteSpace character, then the word is over, send it to the find_best_correction function.*/ 
		if(isspace(ch) || ispunct(ch)){
			/*for(i = 0; i < strlen(word); i++){
				printf("%c", word[i]);
			}
			printf("\n");*/
			find_best_correction(word);
			if(ispunct(ch)){
				word[wordIndex] = ch;
			}
			if(isspace(ch)){
				word[wordIndex] = ch;
			}
			fix_spelling_error(word);
			/*for(i = 0; i < strlen(word); i++){
				printf("%c", word[i]);
			}
			printf("\n\n");*/
			for(i=0; i < N; i++){
    			word[i] = 0;
			}		
			wordIndex = 0;

		}
		else{
			word[wordIndex] = ch;
			wordIndex += 1;
			charSize += 1;
		}

        if (feof(fp1))
            break ;

    }  while(1);
 
	fclose(fp1);
	printf("\n\nFile written in a new file succesfully.\n\n");
    return 0;
}

void fix_spelling_error(char word[]){
	FILE * fp3;
	fp3 = fopen("text_fixed.txt" , "a");

	fwrite(word , 1 , strlen(word) , fp3);

	fclose(fp3);
}

char* find_best_correction(char word[]){
	FILE* fp2;
	char dictWord[N], temp[N];
	int dWordIndex = 0, i, found = 0;
	int difference = 0;

	fp2 = fopen("dictionary.txt", "r");

	do
    {
        char ch = fgetc(fp2);

		/*Compare every word in dictionary with the word*/
		if(isspace(ch)){
			if(strlen(dictWord) == strlen(word)){
				for(i =0; i< strlen(word); i++){
					if(word[i] != dictWord[i]){
						difference += 1;
						if(difference > 1) break;
					}
				}
				/*If there is one character difference between words, replace it.*/
				if(difference == 1){
					for(i = 0; i < strlen(word); i++){
						temp[i] = dictWord[i];
					}
				}
				if(difference == 0){
					found = 1;
					for(i = 0; i < strlen(word); i++){
						word[i] = dictWord[i];
					}
				}

			}
			for(i =0; i< N; i++){
				dictWord[i] = 0;
			}

			dWordIndex = 0;
			difference = 0;
		}
		else{
			dictWord[dWordIndex] = ch;
			dWordIndex += 1;
		}


		if(feof(fp2) || found == 1){
			break;
		}

	}while(1);	

	/*If there is no exact match, take the word most similar.*/
	if(found == 0){
		for(i = 0; i < strlen(word); i++){
			word[i] = temp[i];
		}
	}

	fclose(fp2);

	return word;
}