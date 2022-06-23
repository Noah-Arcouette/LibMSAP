# NAME

**saJoin** - Join string array

# SYNOPSIS

```C
char* saJoin (struct MIMIK_STRING_ARRAY s, char with);
```

# DESCRIPTION

Join string array into a string, with a character separating them

# USAGE

`struct MIMIK_STRING_ARRAY s` The array to join

`char with` The character to go in between the strings

***Return value must be freed***

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

char* out = saJoin(s, ';');

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**joinSub** Join with string in between 
