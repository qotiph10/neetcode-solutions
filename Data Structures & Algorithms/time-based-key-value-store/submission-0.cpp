class TimeMap {
    map<string , map<int , string>> list;
public:
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        list[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = list[key].upper_bound(timestamp);
        return it == list[key].begin() ? "" : prev(it)->second;
            return list[key][timestamp-1];
        
    }
};
