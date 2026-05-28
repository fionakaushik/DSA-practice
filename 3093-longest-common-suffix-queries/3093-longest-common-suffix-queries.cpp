class Solution {
private:
    struct TrieNode {
        int children[26];
        int best_idx;

        TrieNode() {
            // Use -1 or 0 to signify an unallocated child node
            for (int i = 0; i < 26; i++) {
                children[i] = 0; 
            }
            best_idx = -1;
        }
    };

    // Your excellent logic for tie-breaking remains exactly the same!
    bool isBetter(int new_idx, int current_best_idx, const vector<string>& wordsContainer) {
        if (current_best_idx == -1) return true;
        if (wordsContainer[new_idx].length() != wordsContainer[current_best_idx].length()) {
            return wordsContainer[new_idx].length() < wordsContainer[current_best_idx].length();
        }
        return new_idx < current_best_idx;
    }

    // Memory pool acting as our tree allocator
    vector<TrieNode> trie;

    void insert(const string& word, int word_idx, const vector<string>& wordsContainer) {
        int curr = 0; // Index 0 is always the root node
        
        if (isBetter(word_idx, trie[curr].best_idx, wordsContainer)) {
            trie[curr].best_idx = word_idx;
        }

        for (int i = word.length() - 1; i >= 0; i--) {
            int char_idx = word[i] - 'a';
            
            // If the child doesn't exist, allocate a new node from the pool
            if (trie[curr].children[char_idx] == 0) {
                trie.push_back(TrieNode());
                trie[curr].children[char_idx] = trie.size() - 1;
            }
            
            curr = trie[curr].children[char_idx];
            
            if (isBetter(word_idx, trie[curr].best_idx, wordsContainer)) {
                trie[curr].best_idx = word_idx;
            }
        }
    }

    int search(const string& query) {
        int curr = 0;
        int last_valid_idx = trie[0].best_idx;

        for (int i = query.length() - 1; i >= 0; i--) {
            int char_idx = query[i] - 'a';
            if (trie[curr].children[char_idx] == 0) {
                break; 
            }
            curr = trie[curr].children[char_idx];
            last_valid_idx = trie[curr].best_idx;
        }
        return last_valid_idx;
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Clear and initialize pool with the root node at index 0
        trie.clear();
        trie.push_back(TrieNode());

        // 1. Build the Trie using our memory pool
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // 2. Process all queries
        vector<int> ans;
        ans.reserve(wordsQuery.size()); // Small optimization to avoid array resizing
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        return ans;
        
    }
};