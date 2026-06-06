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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
       return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,m);
    }
      TreeNode* build(vector<int>& inorder,int inStart,int inEnd,vector<int>& preorder,int preStart,int preEnd,unordered_map<int,int>& m){
        if(preStart>preEnd||inStart>inEnd)return nullptr;
          TreeNode* root=new TreeNode(preorder[preStart]);
         int inroot=m[root->val];
         int numsleft=inroot-inStart;
         root->left=build(inorder,inStart,inroot-1,preorder,preStart+1,preStart+numsleft,m);
         root->right=build(inorder,inroot+1,inEnd,preorder,preStart+numsleft+1,preEnd,m);
          return root;
      }


};
