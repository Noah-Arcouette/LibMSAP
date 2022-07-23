# NAME

**LibMSAP** - Mimik string array and parsing library

# SYNOPSIS

**LibMSAP** Include file is **msap.h** and library is **libmsap.a**

# DESCRIPTION

**LibMSAP** A string array and parsing library implemented in C

# EXAMPLES

```C
#include <stdio.h>
#include <stdlib.h>
#include "msap.h"

int main ()
{
	// split C file on newlines
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
\n\
main();\n\
\n\
", '\n');

	ssize_t *found = NULL;

	for (; 1; )
	{
		// find all " in split file
		free(found);
		found = saSubSearch(s, "\"", 1);

		// if found any
		if (*found < 0)
			break;

		// remove line
		saRemove(&s, *found);
	}

	// join with newlines
	char *out = saJoin(s, '\n');

	// print output
	puts(out);

	// free
	free(out);

	free(found);
	saFree(s);

	return 0;
}

```
