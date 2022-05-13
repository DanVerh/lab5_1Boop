//Vector3D.cpp

#include "Vector3D.hpp"
#include "Exc.hpp"
#include "ExcInh.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void Vector3D::Init(double x1, double y1, double z1){
    x = x1;
    y = y1;
    z = z1;
}

void Vector3D::Display(){
    cout << "Vector(" << x << ", " << y << ", " << z << ")" << endl;
}

void Vector3D::Read(){
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = "; cin >> z;
    if (!cin) throw Exc("input value needs to be double");
}

void Vector3D::ReadInh(){
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = "; cin >> z;
    if (!cin) throw ExcInh();
}

string Vector3D::toString() const{
    stringstream sout;
    sout << "Prod = " << prod << endl;
    return sout.str();
}

Vector3D Vector3D::Add(Vector3D a, Vector3D b){
    Vector3D c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

Vector3D Vector3D::Sub(Vector3D a, Vector3D b){
    Vector3D c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

Vector3D Vector3D::Prod(Vector3D a, Vector3D b){
    Vector3D c;
    c.prod = a.x*b.x + a.y*b.y + a.z*b.z;
    return c;
}


//2.3
Vector3D::Vector3D() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

Vector3D::Vector3D(const Vector3D& a) {
    *this = a;
}


Vector3D& Vector3D::operator =(const Vector3D& a)  {
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}


istream& operator >>(istream& in, Vector3D& a) {
    cout << "x: "; in >> a.x;
    cout << "y: "; in >> a.y;
    cout << "z: "; in >> a.z;
    if (!in) throw invalid_argument("input needs to be double");
    return in;
}

ostream& operator <<(ostream& out, Vector3D a) {
    out << "Vector(" << a.x << ", " << a.y << ", " << a.z << ")" << endl;
    return out;
}

Vector3D::operator string() const {
    Vector3D a = *this;
    stringstream ss;
    ss << a.x << ", " << a.y << ", " << a.z;
    return ss.str();
}

Vector3D& Vector3D::operator ++() {
    ++x;
    ++y;
    ++z;
    return *this;
}
Vector3D& Vector3D::operator --()  {
    --x;
    --y;
    --z;
    return *this;
}

Vector3D Vector3D::operator ++(int)  {
    Vector3D tmp = *this;
    this->x++;
    this->y++;
    this->z++;
    return tmp;
}

Vector3D Vector3D::operator --(int) {
    Vector3D tmp = *this;
    this->x--;
    this->y--;
    this->z--;
    return tmp;
}
