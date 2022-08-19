#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Matrix
{
public:
    int n;
    int width;
    // int *matrix = new int[n*n];
    int *matrix;

    Matrix(int n)
    {
        matrix = new int[n * n];
        this->n = n;
    }

    friend ostream &operator<<(ostream &out, Matrix &Mat);
    friend istream &operator>>(istream &in, Matrix &Mat);
};

ostream &operator<<(ostream &out, Matrix &Mat)
{
    for (int i = 0; i < Mat.n * Mat.n; i++)
    {
        // out << std::setw(Mat.width);
        out << std::setw(Mat.width) << left << Mat.matrix[i];
        out << " ";

        if (!((i + 1) % Mat.n))
        {
            out << std::endl;
        }
    }
    return out;
}

istream &operator>>(istream &in, Matrix &Mat)
{
    int max;
    for (size_t i = 0; i < Mat.n * Mat.n; i++)
    {
        in >> Mat.matrix[i];
        if (i)
        {
            max = Mat.matrix[i] < Mat.matrix[i - 1] ? Mat.matrix[i - 1] : Mat.matrix[i];
        }
    }
    Mat.width = log10(max) + 1;
    return in;
}

int main()
{
    Matrix mat1(3);
    cin >> mat1;
    cout << mat1;
}


/*
using System;

namespace HelloWorld
{
  class Program
  {
    static void Main(string[] args)
    {
      Console.WriteLine("Hello World!");    
    }
  }
}
*/
