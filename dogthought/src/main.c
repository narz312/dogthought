/*
 * DOGSAY:
 *
 * The program generates an ASCII picture of a dog with a word of day
 * message. The program is inspired by the classic 'cowsay'; of which
 * you can some info on https://en.wikipedia.org/wiki/Cowsay
 *
 * Copyright (c) 2018 Valentin Cassano.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dictionary.h>
#include <llist.h>
/*
 * The dictionaries for this project where obtained from the
 * OmegaWiki project <http://www.omegawiki.org/Special:Ow_downloads>
*/

#define DEFAULT_DICTIONARY "data/def_short.csv"
struct dictionary_s
{

	 char * name;
llist_t content;
	    int entries;//Cantidad de elementos q tiene la lista
};
// ASCII picture of the dog
void draw_dog( void );
int main( int argc, char ** argv )
{
	char * dictionary_name = DEFAULT_DICTIONARY;

	// TO COMPLETE
	// change the default dictionary
		struct dictionary_s  dictionary;
		dictionary.content = NULL;
		dictionary = load( dictionary_name );
	if ( dictionary.content == NULL){
		printf("nonull\n");
	}else{

			draw_dog();
			return -1;
	}
	// uncomment once solved
	// print_word( random_word( dictionary ) );

//	draw_dog();

	return 0;
}

void draw_dog( void )
{
	/* This ASCII pic can be found at
     * <https://asciiart.website/index.php?art=animals/dogs> */

	printf( "\n  ------------------------------  ");
	printf( "\n                     __      /    ");
	printf( "\n   ,               ,''e`--o /     ");
	printf( "\n  ((             (  | __,'        ");
    printf( "\n   \\\\~----------' \\_;/         ");
	printf( "\n   (                /             ");
	printf( "\n   /) .__________.  )             ");
	printf( "\n  (( (           (( (             ");
	printf( "\n   ``-'           ``-'          \n");

}
