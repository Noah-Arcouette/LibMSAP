# NAME

**MIMIK_STRING_ARRAY** **sa** - String array structure

# SYNOPSIS

```C
typedef struct MIMIK_STRING_ARRAY sa;

struct MIMIK_STRING_ARRAY
{
	char** items;
	size_t size;
};
```

# DESCRIPTION

The Mimik String Array and Parsing Library structure for storing String Arrays in C

# USAGE

`typedef struct MIMIK_STRING_ARRAY sa;` Set 
`MIMIK_STRING_ARRAY` type to `sa` for convenience

`char **items` The items in the array

`size_t size` The amount of items in the array

# EXAMPLES

```
# s is an initialized sa structure

printf("first item is %s\n", s.item[0]);
```

# OTHER

**saSplit** Split string into string array

**saFree** Free string array sturcture
