#include "hashMap.h"
#include <cstddef>
#include <cstring>

template<typename K,typename V>
HashNode<K,V>::HashNode(){
    key = K();
    value = V();
    next = NULL;
}

template<typename K,typename V>
HashNode<K,V>::HashNode(K key, V value){
    this->key = key;
    this->value = V();
    next = NULL;
}

template<typename K,typename V>
HashNode<K,V>::~HashNode(){

}

template<typename K>
size_t Hash<K>::operator()(const int & key) const{
    if(typeof(key) == int){
        uint32_t x = static_cast<uint32_t>(key);

        x = (x ^ 61) ^ (x >> 16);
        x += x << 3;
        x ^= x >> 4;
        x *= 0x27d4eb2d;
        x ^= x >> 15;

        return static_cast<size_t>(x);
    }
}

template<typename K>
size_t Hash<K>::operator()(const char & key) const{
    if(typeof(key) == int){
        uint32_t x = static_cast<uint32_t>(key);

        x = (x ^ 61) ^ (x >> 16);
        x += x << 3;
        x ^= x >> 4;
        x *= 0x27d4eb2d;
        x ^= x >> 15;

        return static_cast<size_t>(x);
    }
}
template<typename K>
size_t Hash<K>::operator()(const char& key) const
    {
        uint32_t x = static_cast<unsigned char>(key);
        x *= 2654435761u;
        return static_cast<size_t>(x);
    }

template<typename K>
size_t Hash<K>::operator()(const float& key) const
{
    uint32_t bits;
    std::memcpy(&bits, &key, sizeof(float));

    bits = (bits ^ 61) ^ (bits >> 16);
    bits += bits << 3;
    bits ^= bits >> 4;
    bits *= 0x27d4eb2d;
    bits ^= bits >> 15;

    return static_cast<size_t>(bits);
}