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
    void update(int key){
        lru.erase(iteratorMap[key]);
        lru.push_front(key);
        iteratorMap[key]=lru.begin();
    }
    void evict(){
        int lruKey=lru.back();
        mp.erase(lruKey);
        iteratorMap.erase(lruKey);
        lru.pop_back();
    }
    int get(int key) {
        if(mp.count(key)==0)return -1;
        else{
            update(key);
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
                evict();
                lru.push_front(key);
                iteratorMap[key]=lru.begin();
                mp[key]=value;
            }
          
        }
        else{
            update(key);
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