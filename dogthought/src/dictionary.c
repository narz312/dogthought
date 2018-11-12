/*
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
#include <time.h>

#include <llist.h>

#include <dictionary.h>

struct word_s
{
	char * expression;
	char * definition;
};

struct dictionary_s
{

			char * name;
			llist_t content;
	    int entries;//Cantidad de elementos q tiene la lista
};


// assumption: line = "\" ... \", \" ... \"\n"
struct word_s line2word( char * line )
{
	struct word_s word;
	char * nextLine;
	char * curLine;
	curLine = line;
	nextLine = strchr(curLine, ',');
	if (nextLine) *nextLine = '\0';
	word.expression = line;
	word.definition = nextLine+1;
	return word;
}

// parse the buffer line by line converting the lines
// read into the words to be inserted in the dictionary
llist_t parse( char * buff ){
	char * nextLine;
	llist_t lista = make( );
	char * curLine = buff;
		   while(curLine)
		   {
		      char * nextLine = strchr(curLine, '\n');
		      if (nextLine) *nextLine = '\0';
		      add(lista,curLine);
		      if(curLine = nextLine){
		      	curLine = (nextLine+1);
		      }
		      else{
		      	curLine = NULL;
		      }
	   	}

	  return lista;
}

char  * file2str(char * file_name){
	char * buff = 0;
	long length;
	FILE * f = fopen (file_name, "r");//abro un nuevo archivo f, en modo a. se llama de nombre ext filename
	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell(f);//	POR QUE LENGTH ES 0 ??
		fseek (f, 0, SEEK_SET);
		buff = malloc(length);
	if (buff)
	  {
		fread (buff, 1, length, f);
	  }
	  fclose (f);
	}
	return buff;
}


struct dictionary_s load( char * file_name )
{
	char * buffer = file2str(file_name);
	struct dictionary_s dictionary ;
	dictionary.name = "shortDic";
	dictionary.content = parse(buffer);
  //dictionary.entries = 	(dictionary.content).size;
	print_word(random_word(dictionary));
	return dictionary;
}

struct word_s random_word( struct dictionary_s dictionary )
{
		return line2word(at( dictionary.content, 3 ));
}

void print_word( struct word_s word )
{
	printf( "  %s:", word.expression );
	printf( "\n  %s ", word.definition );
}
