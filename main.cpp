#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



class binaryTree
{
public:
	int data;
	binaryTree* left;
	binaryTree* right;
	binaryTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binaryTree(){
		delete left;
		delete right;
	}
	
};

binaryTree* builtTree(){

	int rootData;
	cin>>rootData;
	binaryTree* root = new binaryTree(rootData);

	queue<binaryTree*> node;
	node.push(root);

	while(!node.empty()){

		binaryTree* ptr = node.front();
		node.pop();

		int val;
		cin>>val;

		if( val != -1){
			ptr->left = new binaryTree(val);
			node.push(ptr->left);
		}

		cin>>val;

		if(val != -1){
			ptr->right = new binaryTree(val);
			node.push(ptr->right);
		}

	}

	return root;
}

// Level Order Traversal
void levelOrderTraversal(binaryTree* root){

	if(!root) return;

	queue<binaryTree*> node;

	node.push(root);

	while(!node.empty()){

		int count = node.size();

		while(count--){
			binaryTree* ptr = node.front();
			node.pop();

			cout<<ptr->data<<" ";

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";

	} 
}

// Preorder - Traversal
void inorderTraversal(binaryTree* root){

	if(!root) return;

	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}

void createLinkList(binaryTree* root, binaryTree** head){

	if( !root) return ;

	static binaryTree* prev = NULL;

	createLinkList(root->left,head);

	if( prev == NULL){
		*head = root;
	}else{

		root->left = prev;
		prev->right = root;
	}

	prev = root;

	createLinkList(root->right, head);
}

void printList(binaryTree *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
void treeToDoublyLinkList(binaryTree* root){

	if( !root) return ;

	binaryTree* head = NULL;

	createLinkList(root,&head);
	printList(head);

}

    
int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
 
  	binaryTree* root  = builtTree();


    
    cout<<"\n Inorder Traversal : ";
	inorderTraversal(root);
	cout<<"\n\n Level Order Traversal : ";
	cout<<"\n";
	levelOrderTraversal(root);

	cout<<"\nConverting To Doubly LinkList :";
	treeToDoublyLinkList(root);

return 0;

}


/*
Input:
1 2 3 4 5 6 7 -1 -1 -1 -1  8 9 -1 -1 -1 -1 -1 -1 -1

output:
 Inorder Traversal : 4 2 5 1 8 6 9 3 7 

 Level Order Traversal : 
1 
2 3 
4 5 6 7 
8 9 

Converting To Doubly LinkList :4 2 5 1 8 6 9 3 7 

*/
