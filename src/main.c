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

	saAdd(&s, "test", 5);

	for (size_t i = 0; i<s.size; i++)
	{
		printf("%s\n", s.items[i]);
	}

	saFree(s);

	return 0;
}
