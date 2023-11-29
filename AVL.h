#pragma once
#ifndef AVL.h
#define AVL.h

struct AVLTreeNode {
     AVLTreeNode* parent;
     AVLTreeNode* left;
     AVLTreeNode* right;
     int depth; //�ش� ����� ����
     int key; //�ش� ��忡 ��� �ִ� ��

     AVLTreeNode(int n) : left(nullptr), right(nullptr), depth(1), key(n) {}
};


class AVLTree {
public:
     AVLTree() : root(nullptr), tree_size(0) {}

     //�ش� Node�� key�� depth�� ���� ���
     void print_node(AVLTreeNode* x) {
          cout << x->key << " " << x->depth << "\n";
     }

     AVLTreeNode* minimum(AVLTreeNode* x) {
          //x�� subtree �� ���� ���� node�� key
          AVLTreeNode* tempNode = x;
          while (tempNode->left != nullptr) {
               tempNode = tempNode->left;
          }

          return tempNode;
     }

     AVLTreeNode* maximum(AVLTreeNode* x) {
          //x�� subtree �� ���� ū node�� key
          AVLTreeNode* tempNode = x;
          while (tempNode->right != nullptr) {
               tempNode = tempNode->right;
          }

          return tempNode;
     }

     //set�� ��� ������ 1�� ����ϰ�, ��� ���� ������ 0�� ���
     void empty() {
          if (root == nullptr) {
               cout << 1;
          }
          else {
               cout << 0;
          }
          cout << "\n";
     }

     //set�� ����� ������ ���� ���
     void size() {
          //cout << set_size(root) << "\n";
          cout << tree_size << "\n";
     }

     /*int set_size(avl_tree_node* x) {
          if (x == nullptr) {
               return 0;
          }

          int left_size = set_size(x->left);
          int right_size = set_size(x->right);

          return left_size + right_size + 1;
     }*/


     //key�� k�� node
     AVLTreeNode* find(AVLTreeNode*  x, int k) {
          if (x == nullptr || x->key == k) {
               return x;
          }
          if (x->key > k) {
               return find(x->left, k);
          }
          else {
               return find(x->right, k);
          }
     }

     AVLTreeNode* insert(AVLTreeNode* N, int k) {
          //���ο��� LL, RR, LR, RL ȸ�� ����
          //node�� insert �� ������ tree_size�� ���������־�� ��
          if (root == NULL) {
               AVLTreeNode* newNode;

               newNode->key = k;
               newNode->depth = 1;
               newNode->left = NULL;
               newNode->right = NULL;

               return newNode;
          }

          if (k < root->key) {
               root->left = insert(root->left, k);
          }
          else if (k > root->key) {
               root -> right = insert(root-> right, k)
          }
          else {
               return root
          }

          root->depth = max(root->left->depth, root->right->depth);

          int temp = (root == NULL) ? 0 : root->left->depth - root->right->depth;
          
          if (k < root->left->key && temp >1) {
               return rotate_ll(root);
          }
          else if (k > root->right->key && temp < -1) {
               return rotate_rr(root);
          }
          else if (k > root->left->key && temp > 1) {
               return rotate_lr(root);
          }
          else {
               return rotate_rl(root);
          }

          return root;
     }

     //balance�� ������ ���� ��带 A, �� �ڽ� ��带 B��� ����.
     //LL ȸ��
     AVLTreeNode* rotate_ll(AVLTreeNode* A) {
          //B�� ������ �ڽ� = A
          //A�� ���� �ڽ� = B�� ���� ������ �ڽ�
          AVLTreeNode *B = A->left;
          AVLTreeNode* C = B->right;

          B->right = A;
          A->left = C;

          //A,B�� ���� ����
          A->depth = max(A->left->depth, A->right->depth)+ 1;
          B->depth = max(B->left->depth, B->right->depth) + 1;


          return B;
     }

     //LR ȸ����
     AVLTreeNode* rotate_lr(AVLTreeNode* A) {
          //A�� ���� �ڽ� = RR(B)
          //LL(A)
          AVLTreeNode* B = A->left;
          B = rotate_rr(B);
          rotate_ll(A);

          return B;
     }

     //RL ȸ����
     AVLTreeNode* rotate_rl(AVLTreeNode* A) {
          //A�� ������ �ڽ� = LL(B)
          //RR(A)
          AVLTreeNode* B = A->right;
          A = rotate_ll(B);
          rotate_rr(A);

          return B;
     }

     //RR ȸ����
     AVLTreeNode* rotate_rr(AVLTreeNode* A) {
          //B�� ���� �ڽ� = A
          //A�� ������ �ڽ� = B�� ���� ���� �ڽ�
          AVLTreeNode* B = A->right;
          AVLTreeNode* C = B->left;

          B->left = A;
          A->right = C;

          //A,B�� ���� ����
          A->depth = max(A->left->depth, A->right->depth) + 1;
          B->depth = max(B->left->depth, B->right->depth) + 1;


          return B;
     }

private:
     AVLTreeNode* root;
     int tree_size;
};

#endif