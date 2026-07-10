#include "hashMap.h"
#include <cstdlib>

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