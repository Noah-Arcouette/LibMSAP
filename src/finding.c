#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msap.h"

ssize_t* saSearch (struct MIMIK_STRING_ARRAY s, char *find, ssize_t cont)
{
	ssize_t *found = (ssize_t*)malloc(1 * sizeof(ssize_t));
	size_t size = 1;

	if (cont < 0)
		cont = s.size;

	for (register size_t i = 0; i<s.size; i++)
	{
		if (!strcmp(s.items[i], find))
		{
			found = (ssize_t*)realloc(found, ++size * sizeof(ssize_t));
			found[size-2] = i;
		}

		if (size > (size_t)cont)
			break;
	}

	found[size-1] = -1;

	return found;
}

ssize_t* saSubSearch (struct MIMIK_STRING_ARRAY s, char *find, ssize_t cont)
{
	ssize_t *found = (ssize_t*)malloc(1 * sizeof(ssize_t));
	size_t size = 1;

	if (cont < 0)
		cont = s.size;

	for (register size_t i = 0; i<s.size; i++)
	{
		if (strstr(s.items[i], find))
		{
			found = (ssize_t*)realloc(found, ++size * sizeof(ssize_t));
			found[size-2] = i;
		}

		if (size > (size_t)cont)
			break;
	}

	found[size-1] = -1;

	return found;
}
