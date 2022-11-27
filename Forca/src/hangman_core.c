#include "../include/hangman_core.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void hgm_handle_attempt(const char* secret_word, 
                        size_t attempt_index, 
                        size_t error_count)
{
	draw_hangman(error_count);
    bool letter_found;

	for(size_t index = 0u; index < strlen(secret_word); ++index)
    {
		
		letter_found = hgm_check_attempt(secret_word[index], 
                                         attempt_index, 
                                         secret_word);

		if (letter_found)
			printf("%c ", secret_word[index]);
		else
			printf("_ ");
	}
    
	puts("");
}