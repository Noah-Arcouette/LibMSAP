#include <stdio.h>
#include <stdlib.h>
#include "msap.h"

int main ()
{
	sa s = saSplit("\
#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <unistd.h>\n\
#include <string.h>\n\
#include <signal.h>\n\
#include \"conf.h\"\n\
#include \"settings.h\"\n\
#include \"reader.h\"\n\
#include \"styling.h\"\n\
#include \"split.h\"\n\
#include \"chars.h\"\n\
#include \"useful.h\"\n\
", '\n');

	ssize_t *found = NULL;

	for (; 1; )
	{
		free(found);
		found = saSubSearch(s, "#include \"", 1);

		if (*found < 0)
			break;

		// printf("%ld %s\n", *found, s.items[*found]);
		saRemove(&s, *found);
	}

	// for (size_t i = 0; i<s.size; i++)
	// 	printf("%ld %s\n", i, s.items[i]);

	char *out = saJoin(s, '\n');

	puts(out);

	free(out);

	free(found);
	saFree(s);

	return 0;
}
