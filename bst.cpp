//
// Created by amir_poudel on 1/26/2022.
//

#include "iostream"

using namespace std;


//creating binary tree for nodes

template<typename T>
class BTNode{
public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;

    BTNode(T data){
        this->data=data;
        left = NULL;
        right = NULL;
    }
    //calling destructor recursive
    ~BTNode(){
        delete left;
        delete right;
    }


};

//creating pair class

class Pair{
public:
    BTNode<int> *head;
    BTNode<int> *tail;
};
//creating BST
class BST{
    BTNode<int>* root;
    //implementation important function

    //print the tree that is on binary tree and make this private
    void printTree(BTNode<int>* root){
        if(root==NULL)return;
        cout<<root->data<<": ";
        if(root->left!=NULL){
            cout<<"L"<<root->left->data;
        }
        if(root->right!=NULL){
            cout<<" R"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }

    //check the data is present or not

    bool hasData(BTNode<int>* node,int data){
        if(node==NULL){
            return false;
        }
        if(node->data>data){
            return hasData(node->left,data);
        } else{
            return hasData(node->right,data);
        }
    }
    //create the function for inserting a data

    BTNode<int>* insert(BTNode<int>*node ,int data){
        if(node ==NULL){//here node is null because we init our bst as root null;
            BTNode<int>* newNode = new BTNode<int>(data);
            return newNode;
        }
        if(node->data>data){
            node->left=insert(node->left,data);//here insert create a new node and put data when insert()function hit null condition;

        } else{
            node->right=insert(node->right,data);//here also insert function create new node and connect a node with root node;

        }
        return node;


    }

    //create the function for deleting a node

    BTNode<int>* deleteData(BTNode<int>*node,int data){
        if(node==NULL) return NULL;
        if(data>node->data){
            node->right=deleteData(node->right,data);
        } else if(data<node->data){
            node->left= deleteData(node->left,data);
        }else{
            if(node->left==NULL and node->right==NULL){
                delete node;
                return NULL;
            }else if(node->right==NULL){
                BTNode<int>* temp=node->left;
                node->left==NULL;
                delete node;
                return temp;
            } else if(node->left==NULL){
                BTNode<int>*temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            } else{
                BTNode<int>* minNode = node->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin = minNode->data;
                node->data=rightMin;
                node->right=deleteData(root->right,rightMin);
            }
        }

        return node;
    }
    //convert to Linked List
    Pair convertToLL(BTNode<int>*node){

        if(root->left==NULL&root->right==NULL){
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }else if(root->left!=NULL&&root->right==NULL){
            Pair leftLL=convertToLL(root->left);
            leftLL.tail=root;//check this
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = root;
            return ans;
        } else if(root->right!=NULL&& root->left==NULL){
            Pair rightLL=convertToLL(root->right);
            root->right=rightLL.head;
            Pair ans;
            ans.head=root;
            ans.tail=rightLL.tail;
            return ans;
        } else{
            Pair leftLL=convertToLL(root->left);
            Pair rightLL=convertToLL(root->right);

            leftLL.tail->right=root;
            root->right = rightLL.head;
        }



    }



public:
    BST(){
        root=NULL;
    }
    //delete entire tree recursively
    ~BST(){
        delete root;
    }

    //delete a data
    void deleteData(int data){
        root = deleteData(root,data);//we need to return root because root may delete and we need new root location
    }
    //insert a data
    void insertData(int data){
        root=insert(root,data);//new construct bst tree update new root so we return root;
    }
    //check hasData
    bool hasData(int data){
        return hasData(root,data);
    }

    //print the tree
    void print(){
        printTree(root);
    }

    BTNode<int>* convertToLL(){
        Pair pair = convertToLL(root);
        return pair.head;
    }


};

int main(){
    BST b;
    b.insertData(50);
    b.insertData(10);
    b.insertData(100);
    b.insertData(25);
    b.insertData(75);
    b.print();

    return 0;
}
