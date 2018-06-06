//
//
// Definition for binary tree:
// typedef struct tree_##name {
//   type value;
//   struct tree_##name *left;
//   struct tree_##name *right;
// } tree_##name;
//
// tree_##name *alloc_tree_##name(type v) {
//   tree_##name *t = calloc(1, sizeof(tree_##name));
//   t->value = v;
//   return t;
// }
bool hasPathWithGivenSum(tree_integer * t, int s) {
    if(t == NULL)
        return s == 0;
    
    if(t->left == NULL && t->right == NULL)
        return t->value == s;
    
    if(t->right != NULL && t->left == NULL)
        return hasPathWithGivenSum(t->right, s - t->value);
    if(t->right == NULL && t->left != NULL)
        return hasPathWithGivenSum(t->left, s - t->value);
    
    return hasPathWithGivenSum(t->left, s - t->value) || hasPathWithGivenSum(t->right, s - t->value);
}
