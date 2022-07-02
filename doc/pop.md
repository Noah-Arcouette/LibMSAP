# NAME

**saPop** - Pop item from string array

# SYNOPSIS

```C
char* saPop (struct MIMIK_STRING_ARRAY *s);
```

# DESCRIPTION

Pop item from string array, first in last out format

# USAGE

`struct MIMIK_STRING_ARRAY *s` The array to be popped from

***Return value must be freed***

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

free(saPop(&s));

char* out = saJoin(s, ';');

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**push** Push item onto string array
