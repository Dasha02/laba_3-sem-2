

#include "Menu.hpp"
#include "Test.hpp"



int menu_var(int count)
{
    int v;
    cin>>v;
    while ( v < 0 || v > count) {
        cout<<("ошибка, попробуйте еще раз==>"); // выводим сообщение об ошибке
        cin>>v; // считываем строку повторно
    }
    return v;
}


int type_menu()
{
    int r;
    cout<<"МЕНЮ:"<<endl;
    cout<<"============================================================"<<endl;
    cout<<"BIN_TREE:\n"
    "1 - <double>\n"
    "2 - <int>\n"
    "0 - ВЫХОД ИЗ ПРОГРАММЫ!\n"
    "============================================================\n"
    "ВВЕДИТЕ ВЫБРАННЫЙ ВАРИАНТ: ";
    r=menu_var(2);
    return r;
}


int main_menu ()
{
    int r;
    cout<<"============================================================"<<endl;
    cout << "1 - ВСТАВИТЬ ЭЛЕМЕНТЫ В BIN_TREE\n"
            "2 - УДАЛИТЬ ЭЛЕМЕНТ ИЗ BIN_TREE\n"
            "3 - ПРОВЕРКА НА ВХОЖДЕНИЕ ЭЛЕМЕНТА В BIN_TREE\n"
            "4 - ОБХОД BIN_TREE\n"
            "5 - ВЫВОД BIN_TREE\n"
            "6 - ЗАПИСЬ BIN_TREE В СТРОЧКУ\n"
            "7 - РЕЗУЛЬТАТ ТЕСТОВ\n"
            "0 - ВОЗВРАТ К ВЫБОРУ ТИПА" << endl;
    cout<<"============================================================\n";
    cout<<"ВВЕДИТЕ ВЫБРАННЫЙ ВАРИАНТ:";
    r=menu_var(7);
    return r;
}


void Bin_Tree_double()
{
    Bin_tree<double> *tree = NULL;
    int i_double;
    while (1==1)
    {
        i_double = main_menu();
        switch (i_double) {
            case 0:
                return;
                
            case 1:
            {
                double s;
                int n;
                cout << "ВВЕДИТЕ КОЛ-ВО ДОБАВЛЯЕМЫХ ЭЛЕМЕНТОВ В BIN_TREE: " << endl;
                cin >> n;
                cout << "ВВЕДИТЕ ДОБАВЛЯЕМЫЕ ЭЛЕМЕНТЫ В BIN_TREE:"<<endl;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->add(tree,s);
                }
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ПОЛУЧЕННОЕ BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "ПОЛУЧЕННОЕ BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                
                break;
            case 2:
            {
                cout << "ВВЕДИТЕ ЭЛЕМЕНТ:" << endl;
                double p;
                cin >> p;
                tree->del(tree, p);
                cout << endl;
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ПОЛУЧЕННОЕ BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "ПОЛУЧЕННОЕ BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
                
            case 3:
                
            {
                double q;
                cout << "ВВЕДИТЕ ЭЛЕМЕНТ: " << endl;
                cin >> q;
                bool ans = tree->ContainsNode(q);
                if (ans == true)
                    cout << "ЭЛЕМЕНТ ПРИСУТСТВУЕТ В BIN_TREE" << endl;
                else
                    cout << "ЭЛЕМЕНТ ОТСУТСТВУЕТ В BIN_TREE" << endl;
                cout<<"____________________________________________________________\n"<<endl;
                cout << "BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
                break;
                
            }
        
                break;
                
            case 4:
            {
                cout << "ВЫБЕРИТЕ ОБХОД BIN_TREE:\n"
                "1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int var;
                cin >> var;
                switch (var) {
                    case 1:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ПКЛ:\n" << endl;
                        tree->PKL();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 2:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ПЛК:\n" << endl;
                        tree->PLK();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 3:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ЛПК:\n" << endl;
                        tree->LPK();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 4:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ЛКП:\n" << endl;
                        tree->LKP();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 5:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - КЛП:\n" << endl;
                        tree->KLP();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 6:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - КПЛ:\n" << endl;
                        tree->KPL();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                }
                cout << endl;
            }
                break;
                
            case 5:
            {
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ВЫВОД НА ПЕЧАТЬ BIN_TREE: " << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                
            }
                
                break;
                
            case 6:
            {
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ВЫВОД НА ПЕЧАТЬ (в строку) BIN_TREE: " << endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
                
            case 7:
            {
                cout<<"____________________________________________________________\n"<<endl;
                Bintree_test();
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
        }
    }
    return;
}


void Bin_Tree_int()
{
    Bin_tree<int> *tree = NULL;
    int i_int;
    while (true)
    {
        
        i_int = main_menu();
        switch (i_int) {
            case 0:
                return;
                
            case 1:
            {
                double s;
                int n;
                cout << "ВВЕДИТЕ КОЛ-ВО ДОБАВЛЯЕМЫХ ЭЛЕМЕНТОВ В BIN_TREE: " << endl;
                cin >> n;
                cout << "ВВЕДИТЕ ДОБАВЛЯЕМЫЕ ЭЛЕМЕНТЫ В BIN_TREE:"<<endl;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->add(tree,s);
                }
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ПОЛУЧЕННОЕ BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "ПОЛУЧЕННОЕ BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                
                break;
            case 2:
            {
                cout << "ВВЕДИТЕ ЭЛЕМЕНТ:" << endl;
                double p;
                cin >> p;
                tree->del(tree, p);
                cout << endl;
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ПОЛУЧЕННОЕ BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "ПОЛУЧЕННОЕ BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
                
            case 3:
                
            {
                double q;
                cout << "ВВЕДИТЕ ЭЛЕМЕНТ: " << endl;
                cin >> q;
                bool ans = tree->ContainsNode(q);
                if (ans == true)
                    cout << "ЭЛЕМЕНТ ПРИСУТСТВУЕТ В BIN_TREE" << endl;
                else
                    cout << "ЭЛЕМЕНТ ОТСУТСТВУЕТ В BIN_TREE" << endl;
                cout<<"____________________________________________________________\n"<<endl;
                cout << "BIN_TREE: \n" << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << "BIN_TREE (запись в строку):\n" << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
                break;
                
            }
        
                break;
                
            case 4:
            {
                cout << "ВЫБЕРИТЕ ОБХОД BIN_TREE:\n"
                "1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int var;
                cin >> var;
                switch (var) {
                    case 1:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ПКЛ:\n" << endl;
                        tree->PKL();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 2:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ПЛК:\n" << endl;
                        tree->PLK();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 3:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ЛПК:\n" << endl;
                        tree->LPK();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 4:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - ЛКП:\n" << endl;
                        tree->LKP();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 5:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - КЛП:\n" << endl;
                        tree->KLP();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                    case 6:
                        cout<<"____________________________________________________________\n"<<endl;
                        cout << "BIN_TREE - КПЛ:\n" << endl;
                        tree->KPL();
                        cout<<"\n____________________________________________________________\n"<<endl;
                        break;
                }
                cout << endl;
            }
                break;
                
            case 5:
            {
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ВЫВОД НА ПЕЧАТЬ BIN_TREE: " << endl;
                tree->print();
                cout<<"____________________________________________________________\n"<<endl;
                
            }
                
                break;
                
            case 6:
            {
                cout<<"____________________________________________________________\n"<<endl;
                cout << "ВЫВОД НА ПЕЧАТЬ (в строку) BIN_TREE: " << endl;
                string *line = new string();
                line = tree->WriteIntoStr(line);
                cout << *line << endl;
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
                
            case 7:
            {
                cout<<"____________________________________________________________\n"<<endl;
                Bintree_test();
                cout<<"____________________________________________________________\n"<<endl;
            }
                break;
        }
    
    }
    return;
}



int menu()
{
    while (true)
    {
        int t = type_menu();
    
        switch (t)
        {
            case 0:
                return 0;
            
            case 1:
                Bin_Tree_double();
                break;
 
            case 2 :
                Bin_Tree_int();
                break;
        }
    }
    return 0;
}
        

ostream& operator<<(ostream& out,string *str)
{
    for (int i=0;i<str->length();i++)
        out<<str[i];
    return out;
}

