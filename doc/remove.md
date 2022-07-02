# NAME

**saRemove** - Remove item from string array

# SYNOPSIS

```C
void saRemove (struct MIMIK_STRING_ARRAY *s, size_t index);
```

# DESCRIPTION

Remove item from string array based on index

# USAGE

`struct MIMIK_STRING_ARRAY *s` Pointer to string array to be edited

`size_t index` The index of the item to be removed

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
World\n\
", '\n');

saRemove(&s, 1);

char* out = saJoin(s, '\n');

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**add** Add item into string array based on index
