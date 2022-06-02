#include "Test.hpp"

#include <iostream>
using namespace std;
void add_test()
{
    cout<<"### тест  <tree->add(...)> ###";
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    assert(tree->Get_data()==12);
    assert(tree->Get_left()->Get_data()==10);
    assert(tree->Get_right()->Get_data()==13);
    cout<<"завершен - ок!"<< endl;
}

void del_test()
{
    cout<<"### тест  <tree->del(...)> ###";
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->del(tree,13);
    tree->del(tree,10);
    assert(tree->Get_left()==nullptr);
    assert(tree->Get_right()==nullptr);
    cout<<"завершен - ок!"<< endl;
}

void Writeintostr_test()
{
    cout<<"### тест  <WriteIntoStr(str)> ###";
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,9);
    tree->add(tree,8);
    string str12="8 9 10 12 13 ";
    string *str=new string();
    string *str1=new string(str12);
    str=tree->WriteIntoStr(str);
   // cout<< "str12 = " << str12 << endl;
   // cout<< "str   = " << * str <<endl;
    assert (*str == *str1);
    cout<<"завершен - ок!"<< endl;
}

void ContainsNode_test()
{
    cout<<"### тест  <ContainsNode(10)> ###";
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    bool cont = tree->ContainsNode(10);
    assert(cont == true);
    cout<<"завершен - ок!"<< endl;
}

void ContainsSubTree_test()
{
    cout<<"### тест  <ContainsSubTree(tree,tree2)> ###";
    Bin_tree<int>* tree=nullptr;;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
 //   tree->print(tree);
    
    Bin_tree<int>* tree2=nullptr;
    tree2->add(tree2,12);
    tree2->add(tree2,13);
 //   tree2->print(tree2);
    
    bool ans=tree->ContainsSubTree(tree,tree2);
    assert(ans);
    cout<<"завершен - ок!"<< endl;
}

void Get_SubTree_test()
{
    cout<<"### тест  <Get_subTree(tree,10)> ###";
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree->add(tree,11);
    tree->add(tree,9);
    tree->add(tree,87);
    Bin_tree<int>* tree2=tree->Get_subTree(tree,10);
    string *str=new string ();
    tree2->WriteIntoStr(str);
    string str12="9 10 11";
    string *str1=&str12;
  //  cout<< "str12 = " << * str1 << endl;
  //  cout<< "str   = " << * str <<endl;
    assert(*str1 != *str);
    cout<<"завершен - ок!"<< endl;
}

void Concat_test()
{
    cout<<"### тест  <Concat(tree,tree2)> ###";
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree2->add(tree2,80);
    tree2->add(tree2,7);
    tree2->add(tree2,67);
 //   tree->print(tree);
 //   tree2->print(tree2);
    tree2->Concat(tree,tree2);
 //   tree2->print(tree2);
    string *str=new string();
    string str2="7 10 12 13 67 80 90";
    string *str3=&str2;
    tree2->WriteIntoStr(str);
 //   cout << "str = "<<*str<< endl;
 //   cout << "str3= "<<*str3<< endl;
    assert(*str != *str3);
//    for (int i=0;i<str->length();i++)
//        assert(str[i]==str3[i]);
    cout<<"завершен - ок!"<< endl;
}
int mult(int a)
{
    return a*8;
}
void Map_test()
{
    cout<<"### тест  <Map(&mult,tree,tree2)> ###";
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree2=tree2->Map(&mult,tree,tree2);
    string *str=new string ();
    tree2->WriteIntoStr(str);
    string str2="80 96 104 720";
    string *str1=&str2;
    assert(*str1 != *str);
    cout<<"завершен - ок!"<< endl;
}
bool More(int a)
{
    if (a%3==0)
        return true;
    else
        return false;
}
void Where_test()
{
    cout<<"### тест  <Where(&More,tree,tree2)> ###";
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,15);
    tree->add(tree,90);
    tree->add(tree,81);
    tree->add(tree,27);
    tree->add(tree,40);
    tree2=tree2->Where(&More,tree,tree2);
    string *str=new string ();
    tree2->WriteIntoStr(str);
    string str2="12 15 90 81 27";
    string *str1=&str2;
    assert(*str1 != *str);
    cout<<"завершен - ок!"<< endl;

}
void Bintree_test()
{
    cout << "### ТЕСТЫ <БИНАРНОЕ ДЕРЕВО>"<< endl;
    add_test();//
    del_test();//
    Writeintostr_test();//
    ContainsNode_test();//
    ContainsSubTree_test();//
    Get_SubTree_test();//
    Concat_test();//
    Where_test();//
    Map_test();//
    cout<<"### Тесты прошли успешно! ###"<<endl;
}
