#include <iostream>
#include "Vector3D.hpp"
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

void _unexpected_to_bad();


int main() {
    set_unexpected(_unexpected_to_bad);
    set_terminate(_unexpected_to_bad);

    Vector3D a;
    try {
        cin >> a;
        cout << a;
    }
    catch (Exc a){
        cerr << a.what() << endl;
    }

    try {
        Vector3D b;
        b.Read();
        cout << b;
    }
    catch (invalid_argument b) {
        cerr << b.what() << endl;
    }
    
    try {
        Vector3D c;
        c.ReadInh();
        cout << c;
    }
    catch (ExcInh &c) {
        cerr << c.what() << endl;
    }
    
    try {
        Vector3D c;
        c.ReadInh();
        cout << c;
    }
    catch (ExcInh *c) {
        cerr << c->what() << endl;
    }

    
    return 0;
}


void _unexpected_to_bad() {
    cerr << "bad_exception" << endl;
    throw;
}
