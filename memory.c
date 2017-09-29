#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* Optionally, use the error module for reporting errors */
#ifdef USE_ERROR
    #include "error.h"
#endif

/*
 * Keep track of the and the number of malloc/realloc/free calls made
 * during the lifetime of the program.
 */
static long num_allocs = 0L;
static long num_reallocs = 0L;
static long num_frees = 0L;

void *memory_malloc(unsigned bytes)
{
    void *p = malloc(bytes);
    if (!p) {
        #ifdef USE_ERROR
        error("Failed to allocate %d bytes of memory.\n", bytes);
        #endif
        return NULL;
    } else {
        ++num_allocs;
    }
    return p;
}

void *memory_realloc(void *memory, unsigned bytes)
{
    void *p = realloc(memory, bytes);
    if (!p) {
        #ifdef USE_ERROR
        error("Failed to reallocate a memory block to %d bytes.\n", bytes);
        #endif
        return NULL;
    } else {
        ++num_reallocs;
    }
    return p;
}

void memory_free(void *p)
{
    if (p) {
        free(p);
        ++num_frees;
    } else {
        /* Calling free() on a NULL pointer is actually harmless, but
         * most likely indicates a programming error somewhere. */
        #ifdef USE_ERROR
        error("Attempted to free a NULL pointer.\n");
        #endif
    }
}

void memory_stats(long *allocs, long *reallocs, long *frees)
{
    *allocs = num_allocs;
    *reallocs = num_reallocs;
    *frees = num_frees;
}
