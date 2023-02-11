#include <iostream>
#include <cstring>

using namespace std;
namespace A {int x=10;
    void f();};

class Hey{
    int a;
    int b;
public:
    int c;
    Hey(int a):a(a), b(a){}
};

int x;

int main() {
    std::cout << strlen("kjsbgijdsfhgij");
    {
        int x = 15;
        cout << x << A::x << ::x;
    }
    Hey a0(5);
    cout << a0.c;
}
