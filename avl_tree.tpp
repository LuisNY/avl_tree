// avl_tree.tpp

namespace avl_tree {

template <class T>
void TREE<T>::inOrderTraverse(NODE<T> *root){
    if(root == nullptr) { return; }
    inOrderTraverse(root->left);
    std::cout << root->val << std::endl;
    inOrderTraverse(root->right);
}

template <class T>
void TREE<T>::PostOrderTraverse(NODE<T> *root){
    if(root == nullptr) { return; }
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    std::cout << root->val << std::endl;
}

template <class T>
void TREE<T>::PreOrderTraverse(NODE<T>* root){
    if(root == nullptr){ return; }
    std::stack<NODE<T>*> stk;
    stk.push(root);
    while(!stk.empty()){
        NODE<T>* curr = stk.top();
        stk.pop();
        std::cout << curr->val << std::endl;
        if (curr->right != nullptr) {
            stk.push(curr->right);
        }
        if (curr->left != nullptr) {
            stk.push(curr->left);
        }
    }
}

template <class T>
int TREE<T>::getHeight(NODE<T>* root) {
    if(root == nullptr){
        return 0;
    }
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

template <class T>
int TREE<T>::difference(NODE<T>* root) {
    if(root==nullptr){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

template <class T>
NODE<T>* TREE<T>::rotateLeft(NODE<T>* root){
    NODE<T>* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    return new_root;
}

template <class T>
NODE<T>* TREE<T>::rotateRight(NODE<T>* root){
    NODE<T>* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    return new_root;
}

template <class T>
NODE<T>* TREE<T>::balance(NODE<T>* root) {

    int diff = difference(root);
    if (diff < -1) {
        if (difference(root->right) < 0) {
            root = rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }

    } else if (diff > 1) {
        if (difference(root->left) > 0) {
            root = rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    return root;
}

template <class T>
NODE<T>* TREE<T>::insert(NODE<T>* root, T val) {

    if(root==nullptr){
        root = new NODE<T>(val);
        return root;
    } else if(root->val > val){
        root->left = insert(root->left, val);
        root = balance(root);
    } else {  // root->val <= val
        root->right = insert(root->right, val);
        root = balance(root);
    }
    return root;
}

template <class T>
NODE<T>* TREE<T>::find(NODE<T>* root, T val){

    if(root==nullptr){
        return nullptr;
    }
    if(root->val == val){
        return root;
    }
    if(root->val > val){
        return find(root->left, val);
    } else {
        return find(root->right, val);
    }
}

template <class T>
NODE<T>* TREE<T>::deleteNode(NODE<T>* root, T val){

    if(root == nullptr){
        return root;
    }

    if(root->val == val) {
        if (root->left == nullptr) {
            NODE<T>* succ = root->right;
            delete root;
            return succ;
        } else if (root->right == nullptr) {
            NODE<T>* succ = root->left;
            delete root;
            return succ;
        }

        NODE<T>* succ = root->left;
        while(succ->right!=nullptr){
            succ = succ->right;
        }

        root->val = succ->val;
        root->left = deleteNode(root->left, root->val);
        root = balance(root);
        return root;
    }

    if(root->val > val){
        root->left = deleteNode(root->left, val);
        root = balance(root);
    } else {
        root->right = deleteNode(root->right, val);
        root = balance(root);
    }

    return root;
}

}