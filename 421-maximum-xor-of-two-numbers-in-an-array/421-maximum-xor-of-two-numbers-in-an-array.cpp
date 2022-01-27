class Solution {
private:
    class Node {
        public:
        Node* child[2];
        Node() {
            child[0] = child[1] = NULL;
        }
    };
private:
    void insert(Node* head, int x) {
        for(int i = 31; i>=0; i--) {
            int bit = (x&(1<<i)) != 0 ? 1 : 0;
            if(head->child[bit] == NULL) {
                head->child[bit] = new Node; 
            }
            head = head->child[bit];
        }
        
    }
    
private:
    int max_xor(Node* head, int num) {
        int ans = 0;
        for(int i = 31; i>=0; i--) {
            int bit = (num&(1<<i)) != 0 ? 0 : 1;
            if(head->child[bit] != NULL) {
                ans = (ans<<1) + 1;
                head = head->child[bit];
            }
            else {
                ans = (ans<<1) + 0;
                head = head->child[!bit] + 0;
            }
        }
        return ans;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node * head = new Node;
        for(int i = 0; i<n; i++) {
            insert(head, nums[i]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, max_xor(head, nums[i]));
        }
        return ans;
    }
};