#pragma once
#ifndef AVL.h
#define AVL.h

struct AVLTreeNode {
     AVLTreeNode* parent;
     AVLTreeNode* left;
     AVLTreeNode* right;
     int depth; //해당 노드의 높이
     int key; //해당 노드에 들어 있는 값

     AVLTreeNode(int n) : left(nullptr), right(nullptr), depth(1), key(n) {}
};


class AVLTree {
public:
     AVLTree() : root(nullptr), tree_size(0) {}

     //해당 Node의 key와 depth를 각각 출력
     void print_node(AVLTreeNode* x) {
          cout << x->key << " " << x->depth << "\n";
     }

     AVLTreeNode* minimum(AVLTreeNode* x) {
          //x의 subtree 중 가장 작은 node의 key
          AVLTreeNode* tempNode = x;
          while (tempNode->left != nullptr) {
               tempNode = tempNode->left;
          }

          return tempNode;
     }

     AVLTreeNode* maximum(AVLTreeNode* x) {
          //x의 subtree 중 가장 큰 node의 key
          AVLTreeNode* tempNode = x;
          while (tempNode->right != nullptr) {
               tempNode = tempNode->right;
          }

          return tempNode;
     }

     //set이 비어 있으면 1을 출력하고, 비어 있지 않으면 0을 출력
     void empty() {
          if (root == nullptr) {
               cout << 1;
          }
          else {
               cout << 0;
          }
          cout << "\n";
     }

     //set에 저장된 원소의 수를 출력
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


     //key가 k인 node
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
          //내부에서 LL, RR, LR, RL 회전 진행
          //node를 insert 할 때마다 tree_size를 증가시켜주어야 함
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

     //balance가 망가진 기준 노드를 A, 그 자식 노드를 B라고 가정.
     //LL 회전
     AVLTreeNode* rotate_ll(AVLTreeNode* A) {
          //B의 오른쪽 자식 = A
          //A의 왼쪽 자식 = B의 원래 오른쪽 자식
          AVLTreeNode *B = A->left;
          AVLTreeNode* C = B->right;

          B->right = A;
          A->left = C;

          //A,B의 높이 갱신
          A->depth = max(A->left->depth, A->right->depth)+ 1;
          B->depth = max(B->left->depth, B->right->depth) + 1;


          return B;
     }

     //LR 회전법
     AVLTreeNode* rotate_lr(AVLTreeNode* A) {
          //A의 왼쪽 자식 = RR(B)
          //LL(A)
          AVLTreeNode* B = A->left;
          B = rotate_rr(B);
          rotate_ll(A);

          return B;
     }

     //RL 회전법
     AVLTreeNode* rotate_rl(AVLTreeNode* A) {
          //A의 오른쪽 자식 = LL(B)
          //RR(A)
          AVLTreeNode* B = A->right;
          A = rotate_ll(B);
          rotate_rr(A);

          return B;
     }

     //RR 회전법
     AVLTreeNode* rotate_rr(AVLTreeNode* A) {
          //B의 왼쪽 자식 = A
          //A의 오른쪽 자식 = B의 원래 왼쪽 자식
          AVLTreeNode* B = A->right;
          AVLTreeNode* C = B->left;

          B->left = A;
          A->right = C;

          //A,B의 높이 갱신
          A->depth = max(A->left->depth, A->right->depth) + 1;
          B->depth = max(B->left->depth, B->right->depth) + 1;


          return B;
     }

private:
     AVLTreeNode* root;
     int tree_size;
};

#endif