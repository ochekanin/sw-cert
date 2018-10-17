#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>

#include "hash_table.h"

OpenHashAlgorithms::OpenHashAlgorithms(uint32_t hashTableSize)
{
    _hashTableSize = hashTableSize;
}

void OpenHashAlgorithms::setHashTableTwoDegree(uint32_t degree)
{
    _hashTableTwoDegree = degree;
}

uint32_t OpenHashAlgorithms::divisionalHash(uint32_t key)
{
    return key % _hashTableSize;
}

uint32_t OpenHashAlgorithms::multiplicativeHash(uint32_t key)
{
    static const uint32_t hashConstant = (2 ^ _hashTableTwoDegree) * _goldenSection; 

    static const uint32_t bits_width = 32;
    static const uint32_t shift =  bits_width - _hashTableTwoDegree;

    return (key * hashConstant) >> shift;
}

// Works good with variable-length strings
uint8_t OpenHashAlgorithms::addictiveHash(uint8_t *str)
{
    uint8_t hash = 0;
    while (*str)
    {
        hash += *str++;
    }

    return hash;
}

void OpenHashAlgorithms::fillRandomArray()
{
    srand(time(0));
    for (uint32_t i = 0; i < _randArraySize; ++i)
    {
        _rand8[i] = rand() % _randArraySize;
    }
}

uint8_t OpenHashAlgorithms::exclusiveHash(uint8_t *str)
{
    fillRandomArray();

    uint8_t hash = 0;
    while (*str)
    {
        hash = _rand8[hash ^ *str];
    }

    return hash;
}

uint16_t OpenHashAlgorithms::exclusiveHashExtended(uint8_t *str)
{
    fillRandomArray();

    uint8_t h1, h2;

    if (0 == *str) return 0;

    h1 = *str;
    h2 = *str + 1;

    ++str;

    while (*str)
    {
        h1 = _rand8[h1 ^ *str];
        h2 = _rand8[h2 ^ *str];
        ++str;
    }

    uint16_t out_hash = 0;
    out_hash = ((uint16_t)h1 << 8) | ((uint16_t)h2);

    return out_hash;
}

ClosedHashAlgorithms::ClosedHashAlgorithms(uint32_t tableSize)
{
    _hashTableSize = tableSize;

    _hashTable = new (std::nothrow) uint32_t[_hashTableSize];
    _usedCells = new (std::nothrow) bool[_hashTableSize];

    for (uint32_t i = 0; i < _hashTableSize; ++i)
    {
        _usedCells[i] = false;
    }
}

void ClosedHashAlgorithms::add(uint32_t key)
{
    
}

