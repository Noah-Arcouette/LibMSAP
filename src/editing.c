#include "msap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saPush (struct MIMIK_STRING_ARRAY *s, char *item)
{
	struct MIMIK_STRING_ARRAY
	{
		char** items;
		size_t size;
	};

	s->size++;
	s->items = (char**)realloc(s->items, s->size * sizeof(char*));

	s->items[s->size-1] = (char*)malloc((strlen(item)+1) * sizeof(char));

	strcpy(s->items[s->size-1], item);
}

char* saPop (struct MIMIK_STRING_ARRAY *s)
{
	char *out = NULL;

	if (!s->size)
		return out;

	s->size--;

	out = (char*)malloc((strlen(s->items[s->size])+1) * sizeof(char));
	strcpy(out, s->items[s->size]);

	free(s->items[s->size]);
	s->items = (char**)realloc(s->items, s->size * sizeof(char*));

	return out;
}

void saRemove (struct MIMIK_STRING_ARRAY *s, size_t index)
{
	// start shifting up. starting at index
	for (size_t i = index; i<(s->size-1); i++)
	{
		s->items[i] = (char*)realloc(s->items[i], (strlen(s->items[i+1])+1)*sizeof(char));
		strcpy(s->items[i], s->items[i+1]);
	}

	// resize sa
	s->size--;
	s->items = (char**)realloc(s->items, s->size * sizeof(char*));
}

void saAdd (struct MIMIK_STRING_ARRAY *s, char *item, size_t index)
{
	// resize sa
	s->size++;
	s->items = (char**)realloc(s->items, s->size * sizeof(char*));

	s->items[s->size-1] = NULL;

	// shift items down. starting at bottom
	for (size_t i = s->size-1; i; i--)
	{
		// insert into index
		if (i == index)
		{
			s->items[index] = (char*)realloc(s->items[index], (strlen(item)+1)*sizeof(char));
			strcpy(s->items[index], item);

			break;
		}

		s->items[i] = (char*)realloc(s->items[i], (strlen(s->items[i-1])+1)*sizeof(char));
		strcpy(s->items[i], s->items[i-1]);
	}
}
