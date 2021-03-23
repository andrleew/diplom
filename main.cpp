#include <iostream>

using namespace std;

class A{
public:
    A(){}

    void X() {
        cout << "hello";
    }
private:
    size_t X;
};

int main() {
    A a;
    a.X();
    return 0;
}