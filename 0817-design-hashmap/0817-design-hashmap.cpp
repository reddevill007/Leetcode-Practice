class MyHashMap {
public:
    vector<int> my_hash_map;
    MyHashMap() {
        int size = 1e6 + 1;
        my_hash_map.resize(size);
        fill(my_hash_map.begin(), my_hash_map.end(), -1);
    }
    
    void put(int key, int value) {
        my_hash_map[key] = value;
    }
    
    int get(int key) {
        return my_hash_map[key];
    }
    
    void remove(int key) {
        my_hash_map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */