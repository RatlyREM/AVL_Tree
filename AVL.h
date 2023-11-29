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

     void minimum(AVLTreeNode* x) {
          //x의 subtree 중 가장 작은 node의 key
     }

     void maximum(AVLTreeNode* x) {
          //x의 subtree 중 가장 큰 node의 key
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


     //key가 x인 node의 depth를 출력
     AVLTreeNode* find(int x) {

     }

     void insert(int x) {
          //내부에서 LL, RR, LR, RL 회전 진행
          //node를 insert 할 때마다 tree_size를 증가시켜주어야 함

     }

     //balance가 망가진 기준 노드를 A, 그 자식 노드를 B라고 가정.
     //LL 회전
     AVLTreeNode* rotate_ll(AVLTreeNode* node) {
          //B의 오른쪽 자식 = A
          //A의 왼쪽 자식 = B의 원래 오른쪽 자식
     }

     //LR 회전법
     AVLTreeNode* rotate_lr(AVLTreeNode* node) {
          //A의 왼쪽 자식 = RR(B)
          //LL(A)
     }

     //RL 회전법
     AVLTreeNode* rotate_rl(AVLTreeNode* node) {
          //A의 오른쪽 자식 = LL(B)
          //RR(A)
     }

     //RR 회전법
     AVLTreeNode* rotate_rr(AVLTreeNode* node) {
          //B의 왼쪽 자식 = A
          //A의 오른쪽 자식 = B의 원래 왼쪽 자식
     }

private:
     AVLTreeNode* root;
     int tree_size;
};

#endif