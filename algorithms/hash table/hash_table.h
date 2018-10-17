#include <stdint.h>

/*
 * About hash table size choise
 * https://stackoverflow.com/a/22745283/2900264
 */

/*
 * A collection of hash algorithms
 * https://en.wikipedia.org/wiki/Jenkins_hash_function
 */


class OpenHashAlgorithms
{
public:
    OpenHashAlgorithms(uint32_t hashTableSize);

    void setHashTableTwoDegree(uint32_t degree);

    uint32_t divisionalHash(uint32_t key);
    uint32_t multiplicativeHash(uint32_t key);
    uint8_t addictiveHash(uint8_t *str);
    uint8_t exclusiveHash(uint8_t *str);
    uint16_t exclusiveHashExtended(uint8_t *str);

private:
    void fillRandomArray();

    uint32_t _hashTableSize; // a raw value of hash table size
    uint32_t _hashTableTwoDegree; // degree of 2 to represent hash table size

    static const double _goldenSection = 0.618033; // (sqrt(5) - 1) / 2
    static const uint32_t _randArraySize = 256;
    uint8_t _rand8[_randArraySize]; // an array with random numbers. 256 is a number of possible values
                                    // stored by uint8_t type variable.
};

class ClosedHashAlgorithms
{
public:
    ClosedHashAlgorithms(uint32_t tableSize);

    void add(uint32_t key);
    bool find(uint32_t key);
    void remove(uint32_t key);

private:
    uint32_t _hashTableSize;
    uint32_t *_hashTable;
    bool *_usedCells;
};