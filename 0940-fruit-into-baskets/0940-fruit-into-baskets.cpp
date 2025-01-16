class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxWindowSize = 0;

        unordered_map<int, int> map;
        while (r < fruits.size()) { // upper bound
            map[fruits[r]]++;

            // if map size increases by 2 then reduce the fruits in the basket
            // if 0 then remove it from front
            while (map.size() > 2) {
                map[fruits[l]]--;

                if (map[fruits[l]] == 0)
                    map.erase(fruits[l]);

                l++;
            }

            maxWindowSize = std::max(maxWindowSize, r - l + 1);
            r++;
        }
        return maxWindowSize;
    }
};