
#include<vector>
vector<int> *longestPath(BinaryTreeNode<int> *root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftans = longestPath(root->left);
    vector<int> *rightans = longestPath(root->right);

    if(leftans!=NULL && rightans !=NULL){
        if(leftans->size() > rightans->size()){
            leftans->push_back(root->data);
            return leftans;
        }
        else {
            rightans->push_back(root->data);
            return rightans;
        }
    }
    if(leftans == NULL){
        rightans->push_back(root->data);
        return rightans;
    }
    else {
        leftans->push_back(root->data);
        return leftans;
    }
}
