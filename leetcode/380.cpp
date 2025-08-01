#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

// 重点在移除某个元素时，将最后一个元素换到该位置
class RandomizedSet {
  private:
    unordered_map<int, int> map;
    vector<int> values;

  public:
    RandomizedSet() {
        values.clear();
        map.clear();
    }

    bool insert(int val) {
        if (!map.count(val)) {
            values.push_back(val);
            map[val] = values.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (map.count(val)) {
            
            int idx = map[val];
            // 需要单独判断是否为尾部
            // 优化方法是直接和尾部交换
            // if(idx == values.size()-1){
            //     map.erase(val);
            //     values.pop_back();
            //     return true;
            // }else{
            //     map.erase(val);
            //     values[idx] = values.back();
            //     values.pop_back();
            //     map[values[idx]] = idx;
            //     return true;
            // }
            swap(values[idx], values.back());
            values.pop_back();
            map[values[idx]]=idx;
            map.erase(val);
            return true;


        }
        return false;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */