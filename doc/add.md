# NAME

**saJoin** - Insert item into string array

# SYNOPSIS

```C
void saAdd (struct MIMIK_STRING_ARRAY *s, char *item, size_t index);
```

# DESCRIPTION

Insert item into string array based on index

# USAGE

`struct MIMIK_STRING_ARRAY *s` The array to be edited

`char *item` The item to be inserted

`size_t index` The index where the item will be inserted

# EXAMPLES

```C
sa s = saSplit("\
Hello\n\
and\n\
World\n\
", '\n');

saAdd(&s, "Welcome", 2);

char* out = saJoin(s, ';');

puts(out);

free(out);

saFree(s);
```

# OTHER

**split** Split string into a string array, on delimiter

**free** Free string array

**remove** Remove item based on index from string array
