#ifndef HASHMAP_H
#define HASHMAP_H
#include <cstddef>

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

template<typename K>
class Hash
{
public:
    size_t operator()(const int& key) const;
    size_t operator()(const char& key) const;
    size_t operator()(const float& key) const;
};



#include "hashMap.tpp"

#endif