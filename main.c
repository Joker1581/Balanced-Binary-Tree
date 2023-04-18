#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
  };
int depth (struct TreeNode* root){
    if (root == NULL) return 0;
    return fmax(depth(root->left), depth(root->right)) + 1;
}
bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    int left = depth (root->left);
    int right = depth(root->right);
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}