class LRUCache {
public:
    unordered_map<int,int> mp;
    unordered_map<int,list<int> :: iterator> address;
    int capacity;
    list<int> l;
    int size;
    LRUCache(int capacity) {
        this->capacity=capacity;
        size=0;
    }
    
    int get(int key) {
        if(mp.count(key)==0)return -1;
        l.erase(address[key]);
        l.push_front(key);
        address[key]=l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.count(key)==0){
            if(size==capacity){
                int leastRecentlyUsedKey=l.back();
                mp.erase(leastRecentlyUsedKey);
                address.erase(leastRecentlyUsedKey);
                l.pop_back();
                size--;
            }
            l.push_front(key);
            mp[key]=value;
            address[key]=l.begin();
            size++;
        }
        else{
            l.erase(address[key]);
            l.push_front(key);
            address[key]=l.begin();
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