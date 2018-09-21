#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

class OpenHashAlgorithms
{
public:
    OpenHashAlgorithms(uint32_t hashTableSize)
    {
        _hashTableSize = hashTableSize;
    }

    void setHashTableTwoDegree(uint32_t degree);

    uint32_t divisionalHash(uint32_t key);
    uint32_t multiplicativeHash(uint32_t key);
    uint8_t addictiveHash(uint8_t *str);
    uint8_t exclusiveHash(uint8_t *str);

private:
    void fillRandomArray();

    uint32_t _hashTableSize; // a raw value of hash table size
    uint32_t _hashTableTwoDegree; // degree of 2 to represent hash table size

    const double _goldenSection = 0.618033; // (sqrt(5) - 1) / 2
    static const size_t _randArraySize = 256;
    uint8_t _rand8[_randArraySize]; // an array with random numbers. 256 is a number of possible values
                                    // stored by uint8_t type variable.
};

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
    uint8_t hash = 0;
    while (*str)
    {
        hash = _rand8[hash ^ *str];
    }

    return hash;
}

class ClosedHashAlgorithms
{
public:
    ClosedHashAlgorithms(uint32_t tableSize)
    {
        _hashTableSize = tableSize;

        _hashTable = new (std::nothrow) uint32_t[_hashTableSize];
        _usedCells = new (std::nothrow) bool[_hashTableSize];

        for (uint32_t i = 0; i < _hashTableSize; ++i)
        {
            _usedCells[i] = false;
        }
    }

    void add(uint32_t key);
    bool find(uint32_t key);
    void remove(uint32_t key);


private:
    uint32_t _hashTableSize;
    uint32_t *_hashTable;
    bool *_usedCells;
};


