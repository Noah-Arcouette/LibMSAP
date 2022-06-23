#ifndef __MIMIK_STRING_ARRAY_PARSING_LIBRARY_H__
#define __MIMIK_STRING_ARRAY_PARSING_LIBRARY_H__

#include <sys/types.h>

typedef struct MIMIK_STRING_ARRAY sa;

struct MIMIK_STRING_ARRAY
{
	char** items;
	size_t size;
};

struct MIMIK_STRING_ARRAY saSplit   (char*, char);
char*                     saJoin    (char);
char*                     saJoinSub (char*);
void                      saFree    (struct MIMIK_STRING_ARRAY);

void  saPush   (struct MIMIK_STRING_ARRAY*, char*);
char* saPop    (struct MIMIK_STRING_ARRAY*);
void  saRemove (struct MIMIK_STRING_ARRAY*, size_t);
void  saAdd    (struct MIMIK_STRING_ARRAY*, char*, size_t);

ssize_t* saSearch    (struct MIMIK_STRING_ARRAY*, char*);
ssize_t* saSubSearch (struct MIMIK_STRING_ARRAY*, char*);

#endif
