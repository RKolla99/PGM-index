#include <list>
#include <unordered_map>
#include <iostream>

class LRUCache {
    std::list<std::pair<size_t, size_t>> queue;
 
    std::unordered_map<size_t, std::list<std::pair<size_t, size_t>>::iterator> hash_map;
    size_t size;
 
public:
    LRUCache() = default;

    LRUCache(size_t n)
    {
        size = n;
    }

    std::pair<size_t, bool> lookup(size_t key)
    {
        bool found = true;
        size_t pos = 0;

        if (hash_map.find(key) == hash_map.end()) {
            found = false;
            if (queue.size() == size) {
                size_t last = queue.back().first;
                queue.pop_back();
    
                hash_map.erase(last);
            }
        }
    
        else
        {
            pos = hash_map[key]->second;
            queue.erase(hash_map[key]);
        }
    
        queue.push_front(std::make_pair(key, pos));
        hash_map[key] = queue.begin();
        return std::make_pair(pos, found);
    }

    void add_pos(size_t pos)
    {
        queue.begin()->second = pos;
    }
};