# NAME

**saPush** - Push item onto end of string array

# SYNOPSIS

```C
void saPush (struct MIMIK_STRING_ARRAY *s, char *item);
```

# DESCRIPTION

Push item onto end of string array, first in last out format.

# USAGE

`struct MIMIK_STRING_ARRAY *s` The array to be edited

`char *item` The item to be pushed

# EXAMPLES

```C
sa s = saSplit("\
Hello\
", '\n');

saPush(&s, "World");

char* out = saJoin(s, '\n');

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**pop** Pop item from bottom of string array
