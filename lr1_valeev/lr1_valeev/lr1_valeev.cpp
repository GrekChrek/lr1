#include <iostream>
#include <string>
#include <fstream>
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

template <typename t>
t proverka(double min, double max) {
    t tipe;
    while (!(cin >> tipe) || cin.peek() != '\n' || tipe < min|| tipe > max) {
        cout << "enter the correct value:";
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
        cout << "\nfirst, enter the pipe data\n";
    }
}

void coutcs(cs c) {
    if (c.name != "") {
        cout << "\nthese cs:\n";
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
        cout << "\nfirst, enter the cs data\n";
    }
}

pipe editpipe(pipe p) {
    if (p.name != "") {
        cout << "\nchange in the operating condition of the pipe:" << "\nenter whether the pipe is working(1-yes, 0-no):";
        p.work = proverka<bool>(0,100000);    
    }
    else {
        cout << "\nfirst, enter the pipe data\n";
    }
    return p;
}

cs editcs(cs c) {
    if (c.name != "") {
        cout << "\nchange in the number of operating stations" << "\nnumber of workstations(int):";
        c.quantity_w = proverka<int>(0,c.quantity);
    }
    else {
        cout << "\nfirst, enter the cs data\n";
    }
    return c;
}

void save(pipe p,cs c) {
    ofstream out("data.txt");
    if (!out) { cout << "\ncan not open file\n";}
    else {
        if (p.name != "") {
            out << "Pipe:";
            out << endl << p.name;
            out << endl << p.length;
            out << endl << p.diametr;
            out << endl << p.work;
        }
        else { out << "first, enter the pipe data\n"; }

        if (c.name != "") {
            out << "\ncs:";
            out << endl << c.name;
            out << endl << c.quantity;
            out << endl << c.quantity_w;
            out << endl << c.class1;
        }
        else { out << "\nfirst, enter the cs data"; }
    }
    out.close();
    cout << "\nsaved\n";

}

pipe loadPipe(ifstream& in) {
    string x;
    pipe p;
    getline(in, x);
    if (x == "Pipe:") {
        getline(in, p.name);
        in >> p.length;
        in.ignore();
        in >> p.diametr;
        in.ignore();
        in >> p.work;
        in.ignore();
        cout << "\nsaved\n";
    }
    return p;
}

cs loadCS(ifstream& in) {
    cs c;
    string x;
    getline(in, x);
    if (x == "cs:") {
        getline(in, c.name);
        in >> c.quantity;
        in.ignore();
        in >> c.quantity_w;
        in.ignore();
        in >> c.class1;
        in.ignore();
        cout << "\nsaved\n";
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
                p = editpipe(p);
                break;
            }
            case 5: {
                c = editcs(c);
                break;
            }
            case 6: {
                save(p, c);
                break;

            }
            case 7: {
                ifstream in("data.txt");
                if (!in) {
                    cout << "\nFile not found\n";
                    break;
                }
                p = loadPipe(in);
                c = loadCS(in);
                in.close();
                cout << "\nLoaded\n";
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
