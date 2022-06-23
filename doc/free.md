# NAME

**saFree** - Free String Array

# SYNOPSIS

```C
void saFree (struct MIMIK_STRING_ARRAY s);
```

# DESCRIPTION

Free a string array

# USAGE

`struct MIMIK_STRING_ARRAY s` The array to be freed

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter
