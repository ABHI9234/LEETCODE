class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);   // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        // union by size: attach smaller tree under larger
        if (sz[rx] < sz[ry]) swap(rx, ry);
        parent[ry] = rx;
        sz[rx] += sz[ry];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;   // email → index
        unordered_map<string, string> emailToName; // email → owner name

        int id = 0;
        // Phase 1 + 2: assign IDs and union
        for (auto& acc : accounts) {
            string& name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                if (!emailToId.count(acc[i])) {
                    emailToId[acc[i]] = id++;
                    parent.push_back(parent.size());
                    sz.push_back(1);
                }
                emailToName[acc[i]] = name;
                // union this email with the first email in the account
                unite(emailToId[acc[1]], emailToId[acc[i]]);
            }
        }

        // Phase 3: group emails by root
        unordered_map<int, vector<string>> rootToEmails;
        for (auto& [email, id] : emailToId)
            rootToEmails[find(id)].push_back(email);

        // Build result
        vector<vector<string>> result;
        for (auto& [root, emails] : rootToEmails) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[emails[0]]);
            result.push_back(emails);
        }
        return result;
    }
};