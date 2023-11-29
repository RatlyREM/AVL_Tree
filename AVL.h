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

     void minimum(AVLTreeNode* x) {
          //x�� subtree �� ���� ���� node�� key
     }

     void maximum(AVLTreeNode* x) {
          //x�� subtree �� ���� ū node�� key
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


     //key�� x�� node�� depth�� ���
     AVLTreeNode* find(int x) {

     }

     void insert(int x) {
          //���ο��� LL, RR, LR, RL ȸ�� ����
          //node�� insert �� ������ tree_size�� ���������־�� ��

     }

     //balance�� ������ ���� ��带 A, �� �ڽ� ��带 B��� ����.
     //LL ȸ��
     AVLTreeNode* rotate_ll(AVLTreeNode* node) {
          //B�� ������ �ڽ� = A
          //A�� ���� �ڽ� = B�� ���� ������ �ڽ�
     }

     //LR ȸ����
     AVLTreeNode* rotate_lr(AVLTreeNode* node) {
          //A�� ���� �ڽ� = RR(B)
          //LL(A)
     }

     //RL ȸ����
     AVLTreeNode* rotate_rl(AVLTreeNode* node) {
          //A�� ������ �ڽ� = LL(B)
          //RR(A)
     }

     //RR ȸ����
     AVLTreeNode* rotate_rr(AVLTreeNode* node) {
          //B�� ���� �ڽ� = A
          //A�� ������ �ڽ� = B�� ���� ���� �ڽ�
     }

private:
     AVLTreeNode* root;
     int tree_size;
};

#endif