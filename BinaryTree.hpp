#ifndef BinaryTree_hpp
#define BinaryTree_hpp


#include <iostream>
#include <cstring>
#include "NodeBinaryTree.hpp"

using namespace std;

template <class T>
class Bin_tree
{
private:
    T data;// значение в дерево
    Bin_tree* left; // указатель на левый
    Bin_tree* right; // указатель на правый
public:
    Bin_tree();
    Bin_tree(T data);
    Bin_tree* Get_left();
    Bin_tree* Get_right();
    T Get_data();
    Bin_tree<T>* find(T a);
    void del(Bin_tree<T>* tree, T b,Bin_tree<T>* prev = nullptr);
    void PKL();
    void PLK();
    void KLP();
    void KPL();
    void LPK();
    void LKP();
    void add(Bin_tree<T>*& Tree, T k);
    void print();
    void del_tree(Bin_tree<T>* tree);
    bool ContainsNode(T value);
    bool ContainsSubTree(Bin_tree<T>* Tree,Bin_tree<T>* SubTree);
    Bin_tree<T>* Get_subTree(Bin_tree<T>* Tree,T a);
    void Concat(Bin_tree<T>* tree1,Bin_tree<T>* tree2);
    string* WriteIntoStr(string *res);
    Bin_tree<T>* Where(bool (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res);
    Bin_tree<T>* Map(T (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res);
};
template <class T>
Bin_tree<T>::Bin_tree(T data)
{
    this->data= data;
    this->left=nullptr;
    this->right=nullptr;
}
template <class T>
Bin_tree<T>::Bin_tree()
{
    this->left=nullptr;
    this->right=nullptr;
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_left()
{
    return this->left;
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_right()
{
    return this->right;
}
template <class T>
T Bin_tree<T>::Get_data()
{
    return this->data;
}
template <class T>
string* Bin_tree<T>::WriteIntoStr(string* res)
{
    if (this == nullptr)
        return nullptr;
//   *res= *res+ to_string(tree1->Get_data());
//    *res= *res + " ";
    if (this->Get_left()!= nullptr)
    {
        this->Get_left()->WriteIntoStr(res);
    }
    *res= *res+ to_string(this->Get_data());
    *res= *res + " ";
    
    if (this->Get_right()!= nullptr)
    {
        this->Get_right()->WriteIntoStr(res);
    }
    return res;
}

template <class T>
Bin_tree<T>* Bin_tree<T>::Where(bool (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res)
{
    if (tree1!=nullptr)
    {
        if (f(tree1->Get_data()))
            res->add(res,tree1->Get_data());
        if (tree1->Get_left()!=nullptr)
            Where(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Where(f,tree1->Get_right(),res);
    }
    return res;
}

template <class T>
Bin_tree<T>* Bin_tree<T>::Map(T (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res)
{
    if (tree1== nullptr)
        return nullptr;
    if (tree1!=nullptr)
    {
        if (tree1->Get_data())
            res->add(res, f(tree1->Get_data()));
        if (tree1->Get_left()!=nullptr)
            Map(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Map(f,tree1->Get_right(),res);
    }
    return res;
}

template <class T>
void Bin_tree<T>::Concat(Bin_tree<T>* tree1,Bin_tree<T>* tree2)
{

    if (tree1->Get_left()!=nullptr)
        Concat(tree1->left,tree2);
    if (tree1->Get_right()!=nullptr)
        Concat(tree1->Get_right(),tree2);
    tree2->add(tree2,tree1->Get_data());
}
template <class T>
bool Bin_tree<T>::ContainsNode(T value)
{
    Bin_tree<T> *nwtree=nullptr;
    nwtree=this->find(value);

    if (nwtree==nullptr)
        return false;
    else
        return true;
}
template <class T>
bool Bin_tree<T>::ContainsSubTree(Bin_tree<T>* Tree,Bin_tree<T>* SubTree)
{

    bool cont=Tree->ContainsNode(SubTree->Get_data());
    if (cont == false)
        return false;
    if (SubTree->Get_left()!= nullptr) {
        cont = ContainsSubTree(Tree, SubTree->Get_left());
        if (cont == false)
            return false;
    }
    if (SubTree->Get_right()!= nullptr){
        cont=ContainsSubTree(Tree,SubTree->Get_right());
         if (cont==false)
            return false;
    }
    if (cont==true)
    {
        return true;
    }
    return false;
}

template <class T>
Bin_tree<T>* getmin(Bin_tree<T>* Tree, Bin_tree<T>*& prev)
{
    if (Tree == nullptr)
    {
        return nullptr;
    }
    if (Tree->Get_left() != nullptr)
    {
        Bin_tree<T>* tmp =  getmin(Tree->Get_left(), Tree);
        prev = Tree;
        return tmp;
    }
    else
    {
        return Tree;
    }
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_subTree(Bin_tree<T>* Tree,T a)
{
    Bin_tree<T>* res=this->find(a);
    return res;
}
// поиск
template <class T>
Bin_tree<T>* Bin_tree<T>::find(T a)
{
    if (this != nullptr)
    {
        if (this->data == a)
        {
            return this;
        }
        else if (a < this->data)
        {
            return this->left->find(a);
        }
        else if (a > this->data)
        {
            return this->right->find(a);
        }

    }
    else
        return nullptr;
    
    return nullptr;
}

// удаление элем
template <class T>
void Bin_tree<T>::del(Bin_tree<T>* tree, T b ,Bin_tree<T>* prev)
{

    if (tree != nullptr)
    {
        if (b == tree->data)
        {
            if ((tree->left == nullptr) && (tree->right == nullptr))
            {
                if (prev != nullptr && prev->data <= tree->data)
                    prev->right = nullptr;
                else
                    prev->left = nullptr;
                delete tree;
            }
            else if (tree->left == nullptr && tree->right != nullptr)
            {
                if (prev != nullptr && prev->data <= tree->data)
                    prev->right = tree->right;
                else
                    prev->left = tree->right;
                delete tree;
            }
            else if (tree->left != nullptr && tree->right == nullptr) {
                if (prev != nullptr && prev->data <= tree->data)
                    prev->right = tree->left;
                else
                    prev->left = tree->left;
                delete tree;

            }
            else if (tree->left != nullptr && tree->right != nullptr)
            {
                Bin_tree<T>* prev = nullptr;
                Bin_tree<T>* ptr = getmin(tree->right, prev);
                if (ptr->right == nullptr) {
                    if (prev != nullptr)
                        prev->left = nullptr;
                }
                else {
                    if (prev != nullptr)
                        prev->left = ptr->right;
                }
                tree->data = ptr->data;
                delete ptr;
            }

        }
        else if (b < tree->data)  //   c помощью 1 и 2 if идем влево
            //потом вправо пока не найдем нужный элемент и не вызовем рекурсивную функцию
        {
            del(tree->left, b, tree); // рекурсия
        }
        else if (b > tree->data)
        {
            del(tree->right, b, tree); // рекурсия
        }
    }
    else
    {
        cout << "ЭЛЕМЕНТ ОТСУТСТВУЕТ" << endl;
    }
}
// обход клп
template <class T>
void Bin_tree<T>::KLP()
{
    if (this != nullptr)
    {
        cout << this->data << "\t";
        this->left->KLP();
        this->right->KLP();
    }
}
// обход кпл
template <class T>
void Bin_tree<T>::KPL()
{
    if (this != nullptr)
    {
        cout << this->data << "\t";
        this->right->KPL();
        this->left->KPL();
    }
}
//обход лпк
template <class T>
void Bin_tree<T>::LPK()
{
    if (this != nullptr)
    {
        this->left->LPK();
        this->right->LPK();
        cout << this->data << "\t";

    }
}
// обход лкп
template <class T>
void Bin_tree<T>::LKP()
{
    if (this != nullptr)
    {
        this->left->LKP();
        cout << this->data << "\t";
        this->right->LKP();
    }
}
// обход пкл
template <class T>
void Bin_tree<T>::PKL()
{
    if (this != nullptr)
    {
        this->right->PKL();
        cout << this->data << "\t";
        this->left->PKL();
    }

}
// обход пкл
template <class T>
void Bin_tree<T>::PLK()
{
    if (this != nullptr)
    {
        this->right->PLK();
        this->left->PLK();
        cout << this->data << "\t";
    }
}


// вставка элемента
template <class T>
void Bin_tree<T>::add(Bin_tree<T>*& Tree, T k)
{

    if (Tree == nullptr)
    {
        Tree = new Bin_tree<T>;
        Tree->data = k;
        Tree->left = nullptr;
        Tree->right = nullptr;
        return;
    }

    if (k < Tree->data)
    {
        if (Tree->left != nullptr) add(Tree->left, k);
        else
        {
            Tree->left = new Bin_tree<T>;
            Tree->left->left = nullptr;
            Tree->left->right = nullptr;
            Tree->left->data = k;
        }

    }
    if (k >= Tree->data)
    {
        if (Tree->right != nullptr) add(Tree->right, k);
        else
        {
            Tree->right = new Bin_tree<T>;
            Tree->right->right = nullptr;
            Tree->right->left = nullptr;
            Tree->right->data = k;
        }
    }
}

template <class T>
void Bin_tree<T>::print() {
    if (this != nullptr)
    {

        this->left->print();// переходим в левое поддерево пока не дойдем до конца слева
        cout << this->data << " __ "; // печатаем с левого конца поддерева
        this->right->print();
        cout << endl;
    }

}

//удаление бин дерева
template <class T>
void Bin_tree<T>::del_tree(Bin_tree<T>* tree)
{
    if (tree != nullptr)
    {
        del_tree(tree->Get_left());
        del_tree(tree->Get_right());

        delete tree;
        tree = nullptr;
    }

}


#endif // BinaryTree_hpp
