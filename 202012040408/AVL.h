#pragma once
#include"Dormitory.h"
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#define NIL (&AVLnode::__NIL)//定义虚拟空节点简化操作
typedef struct AVLnode {
	Dormitory key;
	int h;
	AVLnode* lchild, * rchild;
	static AVLnode __NIL;
	AVLnode(Dormitory dorm = Dormitory(), int h = 0, AVLnode* lchild = NIL, AVLnode* rchild = NIL) : key(dorm), h(h), lchild(lchild), rchild(rchild) {}
};
class AVL
{
private:
	void update_height(AVLnode* root);
	AVLnode* predeccessor(AVLnode* root);
	AVLnode* left_rotate(AVLnode* root);
	AVLnode* right_rotate(AVLnode* root);
	AVLnode* maintain(AVLnode* root);
	AVLnode* getnewnode(Dormitory dorm);
	AVLnode* erase(AVLnode* root, string num);
	AVLnode* insert_AVL_grades(AVLnode* root, Dormitory&);
	AVLnode* insert_AVL_number(AVLnode* root, Dormitory&);
public:
	AVL();
	~AVL();
	void clear(AVLnode* root);
	AVLnode* build_AVL_grades(vector<Dormitory*>dorm);
	AVLnode* build_AVL_number(vector<Dormitory*>dorm);
	//void InorderTraversal_grades(AVLnode* root);
	//void InorderTraversal_number(AVLnode* root);
	void InorderTraversal(AVLnode* root);
	AVLnode* findMax(AVLnode* root);
	AVLnode* findMin(AVLnode* root);
	AVLnode* find(AVLnode* root, string Number);
	void display(AVLnode* root);
};

