// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
vector<int> v;
vector<int> l;
void in(Node* root){
    if(!root){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        l.push_back(root->data);
    }
    in(root->left);
    v.push_back(root->data);
    in(root->right);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    v.clear();
    v.push_back(0);
    l.clear();
    
    in(root);
    v.push_back(INT_MAX);
    for(auto x:l){
        int i = find(v.begin(),v.end(),x) - v.begin();
        if(v[i+1]==x+1 && v[i-1]==x-1){
            return true;
        }
    }
    return false;
    
}