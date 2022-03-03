
int depth(BinaryTreeNode<int> *root,int num){
    if(root == NULL){
        return -1;
    }

    if(root->data == num){
        return 0;
    }

    int small1 = depth(root->left,num);
    int small2 = depth(root->right,num);
    if(small1!=-1){
        return 1+small1;
    }
    else {
        if(small2!=-1){
            return 1+small2;
        }
        else {
        return -1;
        }
    }
}

bool issibling(BinaryTreeNode<int> *root,int p,int q){
    if(root == NULL){
        return false;
    }
    if(root->left!=NULL && root->right!=NULL){
    if(root->left->data == p && root->right->data == q){
        return true;
    }
    else if(root->left->data == q && root->right->data == p){
        return true;
    }
    else {
        return false;
    }

    bool ans1 = issibling(root->left,p,q);
    bool ans2 = issibling(root->right,p,q);

    return ans1||ans2;
    }
    if(root->right!=NULL){
        return issibling(root->right,p,q);
    }
    else {
    return issibling(root->left,p,q);
    }

}

bool isCousin(BinaryTreeNode<int> *root,int p,int q){
    int depthofp = depth(root,p);
    int depthofq = depth(root,q);


    bool ans =  issibling(root,p,q);
    if(!ans && depthofp == depthofq){
        return true;
    }
    else {
        return false;
    }



}
