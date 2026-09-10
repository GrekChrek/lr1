// lr1_valeev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

bool t = true;
struct Pipe
{
    string name;
    double length;
    int diametr;
    bool work;
};

struct CS
{
    string name;
    unsigned int quantity;
    unsigned int quantity_w;
    char class1;
};

Pipe komand1() {
    cout << "\nadd pipe:\n";
    Pipe p{};
    cout << "say my name:\n";
    cin >> p.name;
    cout << "check my length:\n";
    cin >> p.length;
    cout << "check my diametr:\n";
    cin >> p.diametr;
    cout << "am i working? (1-yes 0-no)\n";
    cin >> p.work;
    return p;
    
}
void komand0() {
    t=false;
}
void navig(int x) {
    Pipe trubi = { };
    CS cs;
    switch (x) {
        case 1:{
            Pipe p1;
            p1 = komand1();
            break;
        }
        case 2: {
            komand1();
            break;
        }
        case 3: {
            komand1();
            break;
        }
        case 4: {
            komand1();
            break;
        }
        case 5: {
            komand1();
            break;
        }
        case 6: {
            komand1();
            break;

        }
        case 7: {
            komand1();
            break;
        }
        case 0: {
            komand0();
            break;
        }
        default:{
            cout << "\ntype valid namber\n7878";
        }
    }
}

int main()
{
    cout << "\nAmigas detka\n";
    string text = "\n 1. Add pipe\n 2. Add CS\n 3. View all objects\n 4. Edit pipe\n 5. Edit CS\n 6. Save\n 7. Upload\n 0. Exit\n";
    while (t)
    {
        cout << text;
        int y;
        cin >> y;
        navig(y);

    }
    cout << "\nArevuar detka\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
