class BST {
  private: 
    // attributes
    struct node {
      int key;
      node* left;
      node* right;
    };
    node* root;

    // methods
    void AddLeafPrivate(int key, node* ptr);
    void PrintInOrderPrivate(node* ptr);
    void PrintPreOrderPrivate(node* ptr);
    void PrintPostOrderPrivate(node* ptr);
    node* ReturnNodePrivate(int key, node* ptr);
    int SmallestKeyPrivate(node* ptr); // -> O(n)
                       //
  public:
    // constructor
    BST();

    // methods
    node* CreateLeaf(int key); // -> O(1)
    void AddLeaf(int key); // -> O(n)
    void PrintInOrder(); // -> O(n)
    void PrintPreOrder(); // -> O(n)
    void PrintPostOrder(); // -> O(n)
    node* ReturnNode(int key); // -> O(n)
    void PrintChildren(int key); // -> O(n)
    int SmallestKey(); // -> O(n)
};
