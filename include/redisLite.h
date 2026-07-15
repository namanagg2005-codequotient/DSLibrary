#ifndef REDISCLI_H
#define REDISCLI_H

#include <string>
#include "HashMap.h"

class RedisCLI
{
public:
    
    void run();

private:
    
    HashMap<std::string, std::string> store;

    void handleSet(const std::string& key, const std::string& value);
    void handleGet(const std::string& key);
    void handleDel(const std::string& key);
    void handleExists(const std::string& key);
    void handleCount();
    void handleClear();

    

};

#include "redisLite.cpp"
#endif