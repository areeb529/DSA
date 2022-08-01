class LRUCache {
public:
    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> iteratorMap;
    list<int> lru;
    int capacity;
    int size;
    LRUCache(int capacity) {
      this->capacity=capacity;  
      size=0;
    }
    int get(int key) {
        if(mp.count(key)==0)return -1;
        else{
            lru.erase(iteratorMap[key]);
            lru.push_front(key);
            iteratorMap[key]=lru.begin();
            return mp[key];
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)==0){
            mp[key]=value;
            if(size<capacity){
                lru.push_front(key);
                iteratorMap[key]=lru.begin();
                  size++;
            }
            else if(size==capacity){
                auto it=lru.end();
                it--;
                iteratorMap.erase(*it);
                mp.erase(*it);
                lru.pop_back();
                lru.push_front(key);
                iteratorMap[key]=lru.begin();
                mp[key]=value;
            }
          
        }
        else{
            lru.erase(iteratorMap[key]);
            lru.push_front(key);
            iteratorMap[key]=lru.begin();
            mp[key]=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */