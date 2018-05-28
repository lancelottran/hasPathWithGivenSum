//
// Definition for binary tree:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }
boolean hasPathWithGivenSum(Tree<Integer> t, int s) {
    if(t == null && s == 0)
        return true;
    
    if(t == null && s != 0)
        return false;
    
    return hasPath(t, s, 0);
}


boolean hasPath(Tree<Integer> t, int s, int sum){
    boolean res = false;
    sum += t.value;
    
    
    if(sum == s && t.left == null && t.right == null)
        return true;
    
    if(t.left != null)
    {
        res = res || hasPath(t.left, s, sum);
    }
    
    if(t.right != null)
    {
        res = res || hasPath(t.right, s, sum);
    }
    
    return res;
}
