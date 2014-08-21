TreeNode* inOrderSuccessor(TreeNode *node) {
    if (!node)
        return NULL;
    
    if (node->right) {
        return leftMostNode(node->right);
    }
    
    TreeNode *p = node;
    TreeNode *e;
    
    while (e = p->parent()) {
        if (e->left == p)
            return e;
        p = e;
    }
    
    return NULL;
}