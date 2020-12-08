/*************************************************************************
	> File Name: BSTree.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月10日 星期一 10时52分07秒
 ************************************************************************/
#ifndef _BSTREE_H
#define _BSTREE_H

#include <memory>
#include <iostream>

namespace haizei {

template<typename T>
class BSNode {
public :
    BSNode(const T &data) 
    : data(data), lchild(nullptr), rchild(nullptr), father() {
        std::cout << "Node constuctor" << std::endl;
    }
    bool operator<(const BSNode<T> &obj) {
        return this->data < obj.data;
    }
    bool operator>(const BSNode<T> &obj) {
        return obj.data < this->data;
    }
    bool operator!=(const BSNode<T> &obj) {
        return (this->data < obj.data) || (obj.data < this->data);
    }
    bool operator==(const BSNode<T> &obj) {
        return !(*this != obj);
    }
    std::weak_ptr<BSNode<T> > father;//父节点的指针,此处用wake_ptr
    std::shared_ptr<BSNode<T>> lchild, rchild;
    ~BSNode() {
        std::cout << "destructor" << std::endl;
    }
    T data;
};

template<typename T>
class BSTree_helper {
public :
    static std::shared_ptr<BSNode<T> > get_next(std::shared_ptr<BSNode<T> > p) {
        if (p->rchild != nullptr) {//寻找后继
            p = p->rchild;
            while (p->lchild != nullptr) p = p->lchild;
            return p;
        }
        while (p->father.lock() != nullptr && p->father.lock()->rchild == p) p = p->father.lock();//往上找找到一个向左拐的点
        if (p->father.lock() == nullptr) return p;//只有虚拟根节点是父亲空
        return p->father.lock();
    }
};

template<typename T>
class BSTree_iterator {//支持++, *
    using helper = BSTree_helper<T>;
public :
    BSTree_iterator() : node(nullptr) {}//默认构造函数node指向nullptr
    BSTree_iterator(std::shared_ptr<BSNode<T> > node) : node(node) {}//有参构造函数,
    BSTree_iterator<T> &operator++() {//++a, 返回左值
        node = helper::get_next(node);//后继
        return *this;
    }
    BSTree_iterator<T> operator++(int) {//a++, 返回右值
        BSTree_iterator iter(*this);//先记录本结点
        node = helper::get_next(node);//后继
        return iter;
    }
    bool operator==(const BSTree_iterator<T> &iter) {
        return this->node == iter.node;
    }
    bool operator!=(const BSTree_iterator<T> &iter) {
        return this->node != iter.node;
    }
    T &operator*() {//因为值可以修改所以&,取值
        return node->data;
    }

private:
    std::shared_ptr<BSNode<T> > node;//相关迭代器指向的当前节点
};

template<typename T>
struct BSTree {
public :
    typedef BSTree_iterator<T> iterator;
    BSTree() : root(std::make_shared<BSNode<T> >(T())) {}
    void insert(const T &data) {
        std::shared_ptr<BSNode<T> > p = this->root;
        std::shared_ptr<BSNode<T> > new_node = std::make_shared<BSNode<T> >(data);
        if (p->lchild == nullptr) {
            p->lchild = new_node;
            new_node->father = p;
            return ;
        }
        p = p->lchild;
        while (*p != *new_node) {
            if (*p > *new_node) {
                if (p->lchild == nullptr) {
                    p->lchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->lchild;
            } else {
                if (p->rchild == nullptr) {
                    p->rchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->rchild;
            }
        }
        return ;
    }
    iterator begin() {//找root的左边的第一个值
        if (root->lchild == nullptr) return iterator(root);
        return iterator(root->lchild);
    }
    iterator end() {//end是虚拟根节点
        return iterator(root);
    }

private:
    std::shared_ptr<BSNode<T> > root;
};

}

#endif
