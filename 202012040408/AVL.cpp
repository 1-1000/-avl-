#include "AVL.h"
AVLnode AVLnode::__NIL;
AVL::AVL() {}
AVL::~AVL(){}
AVLnode* AVL::getnewnode(Dormitory dorm) {
	return new AVLnode(dorm, 1);
}

void AVL::clear(AVLnode* root) {
	if (root == NIL)return;
	clear(root->lchild);
	clear(root->rchild);
	//cout << "delete:" << root->key.getNumber() << " " << root->key.getSum_grades()<<"\n";
	delete root;
	return;
}

void AVL::update_height(AVLnode* root) {
	root->h = max(root->lchild->h, root->rchild->h) + 1;
	return;
}

AVLnode* AVL::predeccessor(AVLnode* root) {
	AVLnode* temp = root->lchild;
	while (temp->rchild != NIL) {
		temp = temp->rchild;
	}
	return temp;
}

AVLnode* AVL::left_rotate(AVLnode* root) {
	AVLnode* new_root = root->rchild;
	root->rchild = new_root->lchild;
	new_root->lchild = root;
	update_height(root);
	update_height(new_root);
	return new_root;
}

AVLnode* AVL::right_rotate(AVLnode* root) {
	AVLnode* new_root = root->lchild;
	root->lchild = new_root->rchild;
	new_root->rchild = root;
	update_height(root);
	update_height(new_root);
	return new_root;
}

AVLnode* AVL::maintain(AVLnode* root) {
	if (abs(root->lchild->h - root->rchild->h) < 2)return root;
	if (root->lchild->h > root->rchild->h) {
		if (root->lchild->rchild->h > root->lchild->lchild->h) {
			root->lchild = left_rotate(root->lchild);
		}
		root = right_rotate(root);
	}
	else {
		if (root->rchild->lchild->h > root->rchild->rchild->h) {
			root->rchild = right_rotate(root->rchild);
		}
		root = left_rotate(root);
	}
	return root;
}

AVLnode* AVL::erase(AVLnode* root, string num) {
	if (root == NIL)return root;
	if (num < root->key.getNumber()) {
		root->lchild = erase(root->lchild, num);
	}
	else if (num>root->key.getNumber()) {
		root->rchild = erase(root->rchild, num);
	}
	else {
		if (root->lchild == NIL || root->rchild == NIL) {
			AVLnode* temp = (root->lchild == NIL ? root->rchild : root->lchild);
			delete root;
			return temp;
		}
		else {
			AVLnode* temp = predeccessor(root);
			root->key = temp->key;
			root->lchild = erase(root->lchild, temp->key.getNumber());
		}
	}
	update_height(root);
	return root;
}

AVLnode* AVL::insert_AVL_grades(AVLnode* root, Dormitory& dorm) {
	if (root == NIL)return getnewnode(dorm);
	if (root->key.getSum_grades() == dorm.getSum_grades())return root;
	if (root->key.getSum_grades() > dorm.getSum_grades()) {
		root->lchild = insert_AVL_grades(root->lchild, dorm);
	}
	else {
		root->rchild = insert_AVL_grades(root->rchild, dorm);
	}
	update_height(root);
	return maintain(root);
}
AVLnode* AVL::insert_AVL_number(AVLnode* root, Dormitory& dorm) {
	if (root == NIL)return getnewnode(dorm);
	if (root->key.getNumber() == dorm.getNumber())return root;
	if (root->key.getNumber() > dorm.getNumber()) {
		root->lchild = insert_AVL_number(root->lchild, dorm);
	}
	else {
		root->rchild = insert_AVL_number(root->rchild, dorm);
	}
	update_height(root);
	return maintain(root);
}
AVLnode* AVL::build_AVL_grades(vector<Dormitory*>dorm) {
	AVLnode* root_grades=NIL;
	for (auto m : dorm) {
		root_grades = insert_AVL_grades(root_grades, *m);
	}
	return root_grades;
}
AVLnode* AVL::build_AVL_number(vector<Dormitory*>dorm) {
	AVLnode* root_number=NIL;
	for (auto m : dorm) {
		root_number = insert_AVL_number(root_number, *m);
	}
	return root_number;
}

//void AVL::InorderTraversal_grades(AVLnode* root) {
//	if (root != NIL) {
//		InorderTraversal_grades(root->lchild);
//		cout << root->key.getSum_grades() << " ";
//		InorderTraversal_grades(root->rchild);
//	}
//}
//
//void AVL::InorderTraversal_number(AVLnode* root) {
//	if (root != NIL) {
//		InorderTraversal_number(root->lchild);
//		cout << root->key.getNumber() << " ";
//		InorderTraversal_number(root->rchild);
//	}
//}

void AVL::InorderTraversal(AVLnode* root) {
	if (root != NIL) {
		InorderTraversal(root->lchild);
		cout << left << setw(8) << root->key.getFloor_grades() << "     ";
		cout << left << setw(8) << root->key.getBed_grades() << "     ";
		cout << left << setw(8) << root->key.getItems_grades() << "     ";
		cout << left << setw(4) << root->key.getOther_grades() << "     ";
		cout << left << setw(4) << root->key.getSum_grades() << "     ";
		cout << left << setw(6) << root->key.getNumber() << "     ";
		cout << left << setw(8) << root->key.getMember()[0] << "     ";
		cout << left << setw(8) << root->key.getMember()[1] << "     ";
		cout << left << setw(8) << root->key.getMember()[2] << "     ";
		cout << left << setw(8) << root->key.getMember()[3] << endl;
		InorderTraversal(root->rchild);
	}
}

AVLnode* AVL::findMin(AVLnode* root) {
	if (root == NIL) {
		return NULL;
	}
	if (root->lchild == NIL) {
		return root;
	}
	return findMin(root->lchild);
}
AVLnode* AVL::findMax(AVLnode* root) {
	if (root == NIL) {
		return NULL;
	}
	if (root->rchild==NIL) {
		return root;
	}
	return findMax(root->rchild);
}
AVLnode* AVL::find(AVLnode* root, string Number) {
	if (root == NIL) {
		return NIL;
	}
	if (Number < root->key.getNumber())
		return find(root->lchild, Number);
	else if (Number > root->key.getNumber())
		return find(root->rchild, Number);
	else
		return root;
}
void AVL::display(AVLnode* root) {
	if (root == NIL) {
		cout << "Not find!\n";
	}
	else {
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "地面卫生     床铺卫生     物品摆放     其他     总和     宿舍号     宿舍成员     宿舍成员     宿舍成员     宿舍成员\n";
		cout << left << setw(8) << root->key.getFloor_grades() << "     ";
		cout << left << setw(8) << root->key.getBed_grades() << "     ";
		cout << left << setw(8) << root->key.getItems_grades() << "     ";
		cout << left << setw(4) << root->key.getOther_grades() << "     ";
		cout << left << setw(4) << root->key.getSum_grades() << "     ";
		cout << left << setw(6) << root->key.getNumber() << "     ";
		cout << left << setw(8) << root->key.getMember()[0] << "     ";
		cout << left << setw(8) << root->key.getMember()[1] << "     ";
		cout << left << setw(8) << root->key.getMember()[2] << "     ";
		cout << left << setw(8) << root->key.getMember()[3] << endl;
	}
}