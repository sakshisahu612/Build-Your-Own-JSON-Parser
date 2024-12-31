#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;

node(int d){
	data = d;
	left = NULL;
	right = NULL;
}
};

int main(){
	struct node *root = new node(10);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	return 0;
}
