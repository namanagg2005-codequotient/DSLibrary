#ifndef HASHMAP_H
#define HASHMAP_H
#include <cstdlib>

template<typename K, typename V>
class HashNode
{
public:
    K key;
    V value;
    HashNode<K,V>* next;

    HashNode();
    HashNode(K key, V value);
    ~HashNode();
};

#include "hashMap.tpp"

#endif