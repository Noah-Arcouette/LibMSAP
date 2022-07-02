# NAME

**saSearch** - Search for exact match in string array

# SYNOPSIS

```C
ssize_t* saSearch (struct MIMIK_STRING_ARRAY s, char *find, ssize_t cont);
```

# DESCRIPTION

Search for exact match in string array and return an array of indexes ending at -1

# USAGE

`struct MIMIK_STRING_ARRAY s` The array to search

`char *find` The string to search for

`ssize_t cont` The amount of found items allowed `-1` for all

**Return** The return value is an array of indexes end at -1

***Return value must be freed***

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

// find all `Hello`s
ssize_t *found = saSearch(s, "Hello", -1);

for (size_t i = 0; found[i]>=0; i++)
{
	printf("%ld %s\n", found[i], s.items[found[i]]);
}

free(found);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**subSearch** Search for sub-string in string array 
