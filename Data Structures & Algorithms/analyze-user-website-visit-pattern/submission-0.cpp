class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, vector<pair<int, string>>> userMap;
        for (int i = 0; i < username.size(); ++i) {
            userMap[username[i]].push_back({timestamp[i], website[i]});
        }

        map<vector<string>, int> mp;
        for (auto& [user, visits] : userMap) {
            sort(visits.begin(), visits.end());
            set<vector<string>> seen;
            int n = visits.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        vector<string> pattern = {visits[i].second, visits[j].second, visits[k].second};
                        seen.insert(pattern);
                    }
                }
            }
            for (auto& pattern : seen) mp[pattern]++;
        }

        vector<string> result;
        int maxCount = 0;
        for (auto& [pattern, count] : mp) {
            if (count > maxCount) {
                maxCount = count;
                result = pattern;
            } else if (count == maxCount) {
                if (result.empty() || pattern < result) result = pattern;
            }
        }
        return result;
    }
};