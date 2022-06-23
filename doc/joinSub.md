# NAME

**saJoinSub** - Join string array with string

# SYNOPSIS

```C
char* saJoinSub (struct MIMIK_STRING_ARRAY s, char* with);
```

# DESCRIPTION

Join string array into a string, with a string separating them

# USAGE

`struct MIMIK_STRING_ARRAY s` The array to join

`char with` The string to go in between the strings

***Return value must be freed***

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

char* out = saJoinSub(s, ":/");

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**join** Join with character in between 
