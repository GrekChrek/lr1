#include <iostream>
#include <string>
using namespace std;

struct pipe
{
    string name;
    double length;
    int diametr;
    bool work;
};

struct cs
{
    string name;
    int quantity;
    int quantity_w;
    char class1;
};

template <typename T>
T proverka(double min, double max) {
    T tipe;
    while (!(cin >> tipe) || cin.peek() != '\n' || tipe < min|| tipe > max) {
        cout << "Enter the correct value:";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return tipe;
}


pipe cinpipe() {
    cout << "\nadd pipe:\n";
    pipe p;
    cout << "name:";
    getline(cin>>ws, p.name);
    cout << "length (double):";
    p.length = proverka<double>(0,10000);
    cout << "diametr (int):";
    p.diametr = proverka<int>(0, 10000);
    cout << "am i working? (1-yes 0-no)";
    p.work = proverka<bool>(0, 10000);
    return p;
}
cs cincs() {
    cout << "\nadd cs:\n";
    cs c;
    cout << "name:";
    getline(cin >> ws, c.name);
    cout << "the number of stations(int):";
    c.quantity = proverka<int>(0, 10000);
    cout << "number of workstations(int):";
    c.quantity_w = proverka<int>(0,c.quantity);
    cout << "station class(char):";
    c.class1 = proverka<char>(0,100000);
    return c;
}

void coutpipe(pipe p) {
    if (p.name != "") {
        cout << "\nthese pipes:\n";
        cout << "\nname:";
        cout << p.name;
        cout << "\nlength:";
        cout << p.length;
        cout << "\ndiametr:";
        cout << p.diametr;
        if (p.work) {
            cout << "\ni am working\n";
        }
        else {
            cout << "\ni do not work\n";
        }
    }
    else {
        cout << "\nFirst, enter the Pipe data\n";
    }
}

void coutcs(cs c) {
    if (c.name != "") {
        cout << "\nthese CS:\n";
        cout << "\nname:";
        cout << c.name;
        cout << "\nthe number of stations:";
        cout << c.quantity;
        cout << "\nthe number of operating stations:";
        cout << c.quantity_w;
        cout << "\nclass:";
        cout << c.class1 << "\n";
    }
    else {
        cout << "\nFirst, enter the CS data\n";
    }
}

pipe editPipe(pipe p) {
    if (p.name != "") {
        cout << "\nchange in the operating condition of the pipe:" << "\nEnter whether the pipe is working(1-yes, 0-no):";
        p.work = proverka<bool>(0,100000);    
    }
    else {
        cout << "\nFirst, enter the Pipe data\n";
    }
    return p;
}

cs editCS(cs c) {
    if (c.name != "") {
        cout << "\nchange in the number of operating stations" << "\nnumber of workstations(int):";
        c.quantity_w = proverka<int>(0,c.quantity);
    }
    else {
        cout << "\nFirst, enter the CS data\n";
    }
    return c;
}


int main()
{
    cout << "\namigas detka\n";
    string text = "\n 1. add pipe\n 2. add cs\n 3. view all objects\n 4. edit pipe\n 5. edit cs\n 6. save\n 7. upload\n 0. exit\n";
    pipe p;
    cs c;
    int t = true;
    while (t)
    {
        cout << text;
        int y;
        y = proverka<int>(0,7);
        switch (y) {
            case 1: {
                p = cinpipe();
                break;
            }
            case 2: {
                c = cincs();
                break;
            }
            case 3: {
                coutpipe(p);
                coutcs(c);
                break;
            }
            case 4: {
                p = editPipe(p);
                break;
            }
            case 5: {
                c = editCS(c);
                break;
            }
            case 6: {
                break;

            }
            case 7: {
                break;
            }
            case 0: {
                t=false;
                break;
            }
            default: {
                cout << "\ntype valid namber\n";
            }
        }
    }
    cout << "\narevuar detka\n";
}