#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

// 重点在移除某个元素时，将最后一个元素换到该位置
class RandomizedSet {
private:
    unordered_map<int, int>map; // val2idx
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
    }
    
    bool remove(int val) {
        
    }
    
    int getRandom() {
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */