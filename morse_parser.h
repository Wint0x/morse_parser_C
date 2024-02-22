#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char* key;
	const char* value;

} morse;

morse* linear_search(morse* items, size_t size, const char* key) 
{
    for (size_t i=0; i<size; i++) 
    {
        if (strcmp(items[i].key, key) == 0) 
        {
            return &items[i];
        }
    }
    return NULL;
}

morse ascii_to_morse[] = 
{
{",", " "},
{".-","a"},
{"-...","b"},
{"-.-.","c"},
{"-..","d"},
{".","e"},
{"..-.","f"},
{"--.","g"},
{"....","h"},
{"..","i"},
{".---","j"},
{"-.-","k"},
{".-..","l"},
{"--","m"},
{"-.","n"},
{"---","o"},
{".--.","p"},
{"--.-","q"},
{".-.","r"},
{"...","s"},
{"-","t"},
{"..-","u"},
{"...-","v"},
{".--","w"},
{"-..-","x"},
{"-.--","y"},
{"--..","z"},
{".----","1"},
{"..---","2"},
{"...--","3"},
{"....-","4"},
{".....","5"},
{"-....","6"},
{"--...","7"},
{"---..","8"},
{"----.","9"},
{"-----","0"},
};

void display_hash_table(morse* items, size_t size);