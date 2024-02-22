#include "morse_parser.h"
#include <ctype.h>

#define MAX_CHARS 255

int main(int argc, char **argv)
{
	const size_t morse_struct_size_t = sizeof(ascii_to_morse)/sizeof(ascii_to_morse[0]); 

	if (argc < 2)
	{
		printf("Example Usage:\n%s .... . .-.. .-.. .\n. = dot\n- = dash\nSeparate with space!\n%s\n", 
			argv[0], "You can use \",\" to indicate a space character!");
		printf("\nAlternatively, you can use the following:\n%s %s\nIn order to print a full morse code table!\n",
			argv[0], "--show");

		return EXIT_SUCCESS;
	}

	// Print full morse code table function...
	if (strcmp(argv[1], "--show") == 0)
	{
		printf("== [ Morse code table ] ==\n");

		display_hash_table(ascii_to_morse, morse_struct_size_t);
		return EXIT_SUCCESS;
	}

	// Calc total size
	char* my_message = NULL;
	size_t size_to_alloc = 0;
	for (int i = 1; i < argc; i++)
	{
		size_to_alloc += strlen(argv[i]);
		size_to_alloc++; // for a space!
	}

	my_message = (char*) malloc(size_to_alloc * sizeof(char));
	if (my_message == NULL)
	{
		fprintf(stderr, "malloc fail...\n");
		return 1;
	}

	// Create the message to parse
	for (int j = 1; j < argc; j++)
	{
		strcat(my_message, argv[j]);
		strcat(my_message, " ");
	}

	my_message[size_to_alloc] = '\0';

	// Begin parsing...
	char* morse_characters[MAX_CHARS]; // This assumes a maximum of MAX_CHARS user-provided morse characters
	char* tokenize = strtok(my_message, " ");

	int word_count = 0;

	// Store pointers to individual words in character_array;
	while (tokenize != NULL && word_count < MAX_CHARS)
	{
		morse_characters[word_count] = strdup(tokenize);
		++word_count;

		tokenize = strtok(NULL, " ");
	}

	// Compare tokens to the hash table keys and construct morse-to-plaintext
	morse* temp = NULL;
	for (int word = 0; word < word_count; word++)
	{
		if ((temp = linear_search(ascii_to_morse, morse_struct_size_t, morse_characters[word]))
			!= NULL)
		{
			printf("%s", temp->value);
		}
	}

	putchar('\n');

	// Cleanup
	free(my_message);

	for (int i = 0; i < word_count; i++) 
        free(morse_characters[i]);

	return 0;
}

void display_hash_table(morse* items, size_t size)
{
	for (int item = 0; item < size; item++)
	{
		printf("[%s] -> %s\n", items[item].value, items[item].key);
	}
}
