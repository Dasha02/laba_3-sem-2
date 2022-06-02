

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <cassert>
#include "BinaryTree.hpp"

void add_test();             //Проверка добавления элемента
void del_test();             //Проверка удаления элемента дерева
void Writeintostr_test();    //Проверка записи дерева в строку
void ContainsNode_test();    //Тест функции проверки наличия элемента дерева
void ContainsSubTree_test(); //Тест функции проверки наличия поддерева дерева
void Get_SubTree_test();     //Тест получения поддерева дерева
void Concat_test();          //Тест слияния деревьев
void Where_test();
void Map_test();
void Bintree_test();         //Все тесты
bool More(int a);
int mult(int a);



#endif /* Test_hpp */
