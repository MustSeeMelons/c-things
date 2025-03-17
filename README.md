# A collection of C stuff

Just `cd` into a folder and have fun and do the `./xyz` to launch.

## GCC

- `gcc xyz.c` - compile into object format
- `gcc xyz.c -o xyz` - compile and link
- `gcc -Wall xyz.c -o xyz` - give me warnings
- `gcc -Wall -g xyz.c -o xyz` - include debugging information

## General Notes

- Check if pointers are NULL. Do not assume. Got it?
- Const usage:
  - `int const *ptr = &a;` Const data, `*ptr = 20` is forbidden, but `ptr = &b` is fine.
  - `int *const ptr = &a;` Const pointer, `*ptr = 20` is OK, but `ptr = &b` is not.
  - `int *const *const ptr=&a` This goes down levels as well.

## TODO Prioritized

- How to test for memory leaks? Valgrind?
- `merge/quick sort`
- `linear/binary search`
- `iterator`
- `thread safety`?
- Unit testing?
- Multi file build
- Makefile
- `deep copy` a list
