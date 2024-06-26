#ifndef _ATOMIC_COUNTER_H_INCLUDED_
#define _ATOMIC_COUNTER_H_INCLUDED_

#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdint.h>

#define SHM_KEY 0xac00ac

#pragma pack(1)
typedef struct
{
    volatile uint32_t dwCounter;
} atomic_counter_t;

typedef struct
{
    atomic_counter_t *ptr;
} atomic_counter;
#pragma pack(0)

int atomic_counter_init(atomic_counter *ppstCounter, key_t shmkey, uint32_t iVal);

int atomic_counter_inc(atomic_counter *pstCounter);
int atomic_counter_dec(atomic_counter *pstCounter);

int atomic_counter_get(atomic_counter *pstCounter, uint32_t *pval);
int atomic_counter_set(atomic_counter *pstCounter, uint32_t val);

int atomic_counter_add(atomic_counter *pstCounter, uint32_t val);

#endif
