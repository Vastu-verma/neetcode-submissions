/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr)s+="#,";
            else {
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
         TreeNode* root=new TreeNode(stoi(str));
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
              TreeNode* nodeleft=new TreeNode(stoi(str));
              node->left=nodeleft;
                q.push(nodeleft);
            }
            getline(s,str,',');
            if(str!="#"){
               TreeNode* noderight=new TreeNode(stoi(str));
               node->right=noderight;
                q.push(noderight);
            }
         }
         return root;
    }
};
