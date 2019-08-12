//
//  main.cpp
//  LRU
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Implement an LRU (Least Recently Used) cache. It should be
// able to be initialized with a cache size n, and contain the following methods:
//
// set(key, value): sets key to value. If there are already n items in the cache and we are adding a new   item, then it should also remove the least recently used item.
// get(key): gets the value at key. If no such key exists, return null.

// Each operation should run in O(1) time.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

template<size_t n, typename key, typename value>
class LRU {
    std::unordered_map<key, value> map;
    std::queue<std::pair<key, value> > queue;
    int count;
public:
    LRU() {
        count = 0;
    }
    
    void set(key k, value v) {
        std::pair<key, value> entry = std::make_pair(k, v);
        if (count >= n) {
            std::pair<key, value> &pop = queue.front();
            queue.pop();
            auto rm = map.find(pop.first);
            map.erase(rm);
        }
        
        queue.push(entry);
        map[entry.first] = entry.second;
        count++;
    }
    
    value get(key k) {
        if (map.find(k) != map.end())
            return map[k];
        else
            return NULL;
    }
};

int main() {
    LRU<5, int, char> cache;
    cache.set(1, 'A');
    cache.set(2, 'B');
    cache.set(3, 'C');
    cache.set(4, 'D');
    
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(5) << std::endl;
    
    cache.set(5, 'E');
    cache.set(6, 'F');
    
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(2) << std::endl;
}
