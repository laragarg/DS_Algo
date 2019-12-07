void printLeft(Node* root){
    if(!root){
        return;
    }
    if(root->left){
        //to ensure top down, first print then recur
        cout<<root->data<<" ";
        printLeft(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeft(root->right);
    }
    return;
}
void printRight(Node* root){
    if(!root){
        return;
    }
    if(root->right){
        //To ensure bottom up, first recur then print
        printRight(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printRight(root->left);
        cout<<root->data<<" ";
    }
    return;
}
void printLeaf(Node* root){
    if(!root){
        return;
    }
    printLeaf(root->left);
    if(!root->left && !root->right){
        cout<<root->data<<" ";
    }
    printLeaf(root->right);
}
void print(Node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";

    //Left edge
    printLeft(root->left);
    
    //Left subtree ke leaves
    printLeaf(root->left);

    //Right subtree ke leaves
    printLeaf(root->right);
    
    //Right edge
    printRight(root->right);
    return;
}
void printBoundary(Node *root){
    if(!root){
        return;
    }
    print(root);
}