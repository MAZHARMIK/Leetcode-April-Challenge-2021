/*
    Solution-1 : DFS
*/
class Solution {
public:
    int deepest_depth = 0;
    int find_depth(TreeNode* root) {
        if(!root)
            return 0;
        
        return 1 + max(find_depth(root->left), find_depth(root->right));
    }
    
    void deepestSum(TreeNode* root, int& sum, int depth) {
        if(!root)
            return;
        if(depth == deepest_depth) {
            sum += root->val;
            return;
        }

        deepestSum(root->left, sum, depth+1);
        deepestSum(root->right, sum, depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        deepest_depth = find_depth(root);
        int sum = 0;
        deepestSum(root, sum, 1);
        return sum;
    }
};


/*
    Solution-2 : BFS
*/
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        
        int result = 0;
        while(!que.empty()) {
            int n = que.size();
            result = 0;
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                result += curr->val;
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
        }
        return result;
    }
};
