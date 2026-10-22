class LRUCache {
public:
   list<pair<int, int>> dl;
   unordered_map<int ,list<pair<int , int>>::iterator> m;
   int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        dl.splice(dl.begin() , dl , m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            dl.splice(dl.begin(),dl,m[key]);
            m[key]->second = value;
            return;
        }
        if(dl.size()==size){
            int dl_key = dl.back().first;
            dl.pop_back();
            m.erase(dl_key);
        }
        dl.push_front({key , value});
        m[key] = dl.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */