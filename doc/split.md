# NAME

**saSplit** - Split string based on delimiter

# SYNOPSIS

```C
struct MIMIK_STRING_ARRAY saSplit (char* string, char delim);
```

# DESCRIPTION

Split string into a string array based on delimiter

# USAGE

`char* string` The string to be split

`char delim` The delimiter to be split on

***The returned array must be freed with saFree***

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

saFree(s);
```

# OTHER

**free** Free string array
