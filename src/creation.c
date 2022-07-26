#include "msap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MIMIK_STRING_ARRAY saSplit (char* string, char delim)
{
	struct MIMIK_STRING_ARRAY sarr;
	sarr.items   = (char**)malloc(1 * sizeof(char*));
	*sarr.items  = (char*)malloc(1 * sizeof(char));
	**sarr.items = (char)0;
	sarr.size   = 1;

	register size_t size = 1;

	for (; (*string)!=0; string++)
	{
		if (*string == delim)
		{
			move:
				sarr.items = (char**)realloc(sarr.items, (++sarr.size) * sizeof(char*));
				sarr.items[sarr.size-1]  = (char*)malloc(1 * sizeof(char));
				*sarr.items[sarr.size-1] = (char)0;
				size = 1;

			continue;
		}

		sarr.items[sarr.size-1] = realloc(sarr.items[sarr.size-1], ++size);
		sarr.items[sarr.size-1][size-1] = 0;
		sarr.items[sarr.size-1][size-2] = *string;

		if (*(string+1) == 0)
		{
			goto move;
		}
	}

	sarr.size--;

	return sarr;
}

void saFree (struct MIMIK_STRING_ARRAY sarr)
{
	while (sarr.size)
	{
		sarr.size--;

		free(sarr.items[sarr.size]);
	}
	free(sarr.items);
}

char* saJoin (struct MIMIK_STRING_ARRAY s, char with)
{
	register char  *out  = (char*)malloc(1 * sizeof(char));
	register size_t size = 1;
	*out = 0;

	for (register size_t i = 0; i<s.size; i++)
	{
		size += strlen(s.items[i]);
		out   = (char*)realloc(out, size * sizeof(char));

		strcat(out, s.items[i]);

		out = (char*)realloc(out, ++size * sizeof(char));

		if (i+1 < s.size)
		{
			out[size-1] = 0;
			out[size-2] = with;
		}
	}

	return out;
}

char* saJoinSub (struct MIMIK_STRING_ARRAY s, char* with)
{
	register char  *out   = (char*)malloc(1 * sizeof(char));
	register size_t size  = 1;
	const size_t withSize = strlen(with);
	*out = 0;

	for (register size_t i = 0; i<s.size; i++)
	{
		size += strlen(s.items[i]);
		out   = (char*)realloc(out, size * sizeof(char));

		strcat(out, s.items[i]);

		size += withSize;
		out   = (char*)realloc(out, size * sizeof(char));

		if (i+1 < s.size)
		{
			strcat(out, with);
		}
	}
	
	return out;
}
