#include<vector>
TreeNode<int> *removeLeafNodes(TreeNode<int> *root){
    if(root == NULL || root->numChildren() == 0){
        return NULL;
    }
    vector<int> output;
    for(int i = 0;i < root->numChildren();i++){
        TreeNode<int> *childd = root->getChild(i);
        if(childd->numChildren() == 0){
            output.push_back(i);
        }
    }

    for(int j = output.size()-1;j>=0;j--){
        int p = output[j];
        root->removeChild(p);

    }

    for(int i = 0;i<root->numChildren();i++){
        TreeNode<int> *child = removeLeafNodes(root->getChild(i));

    }
    return root;
}
