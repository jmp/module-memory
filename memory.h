#ifndef MEMORY_H
#define MEMORY_H

/*
 * Allocate memory. This is just a wrapper around malloc(), also keeping track
 * of the number of allocations for debugging purposes. If there is not enough
 * memory, an error message is shown and the program will exit.
 */
extern void *memory_malloc(unsigned bytes);

/*
 * Reallocates memory. This is a wrapper around realloc(), but also does some
 * book-keeping for debugging purposes. If there is not enough memory, an
 * error message is shown and the program will exit.
 */
extern void *memory_realloc(void *memory, unsigned bytes);

/*
 * Free a previously allocated block of memory. Also counts the number of
 * times free() has been called. It also hrows an error if we accidentally
 * try to free a NULL pointer.
 */
extern void memory_free(void *memory);

/*
 * Get some useful statistics about memory, for debugging purposes.
 */
extern void memory_stats(long *allocs, long *reallocs, long *frees);

#endif /* MEMORY_H */
