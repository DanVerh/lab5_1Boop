//Vector3D.hpp

#pragma once
#include <string>

using namespace std;

class Vector3D{
private:
    double x, y, z, prod;
public:
    void SetX (double x1){ x = x1; }
    void SetY (double y1){ y = y1; }
    void SetZ (double z1){ z = z1; }
    double GetX (){ return x; }
    double GetY (){ return y; }
    double GetZ (){ return z; }
    double GetProd(){ return prod; }
    void   Init(double x1, double y2, double z1);
    void Display();
    void Read ();
    void ReadInh ();
    string toString() const;
    
    static Vector3D Add(Vector3D a, Vector3D b);
    static Vector3D Sub(Vector3D a, Vector3D b);
    static Vector3D Prod(Vector3D a, Vector3D b);
    
    
    //2.3
    Vector3D();
    Vector3D(double, double, double);
    Vector3D(const Vector3D&);
    
    Vector3D& operator =(const Vector3D&);
    friend istream& operator >>(istream&, Vector3D&);
    friend ostream& operator <<(ostream&, Vector3D a);
    operator string() const;
    
    Vector3D& operator ++();
    Vector3D& operator --();
    Vector3D operator ++(int);
    Vector3D operator --(int);
};
