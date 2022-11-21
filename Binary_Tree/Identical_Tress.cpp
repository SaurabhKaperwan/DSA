struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL or r2 == NULL)
            return (r1 == r2);
            
        return (r1->data == r2->data and isIdentical(r1 -> left , r2 -> left) and isIdentical(r1 -> right , r2 -> right)) ? true : false;
        
    }
};
