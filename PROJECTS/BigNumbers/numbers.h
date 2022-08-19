#include <string>
#include <iostream>
using namespace std;
class Numbers
{
    // private:

public:
    int data[30];
    int len;

    Numbers();
    Numbers(string &data);
    void operator=(Numbers &num);
    friend istream &operator>>(istream &in, Numbers &num);
    friend ostream &operator<<(ostream &out, Numbers &num);
    friend Numbers operator+(Numbers &num1, Numbers &num2)
    {
        Numbers sum;
        int carry = 0, addn;
        for (size_t i = 30; i > 0; i--)
        {
            addn = num1.data[i] + num2.data[i] + carry;
            sum.data[i] = addn % 10;
            carry = addn / 10;
        }
        sum.len = 30;
        return sum;
    }
    void print();
};
typedef Numbers num;
Numbers::Numbers()
{
    for (size_t i = 0; i < 30; i++)
    {
        this->data[i] = 0;
    }
}
Numbers::Numbers(string &data)
{
    this->len = data.length();
    for (size_t i = len; i >= 30 - len; i--)
    {
        this->data[i - 1] = data[i - 1] - '0';
    }
    for (size_t i = 0; i < 30 - len; i++)
    {
        this->data[i] = 0;
    }
}

void Numbers::print()
{
    for (size_t i = 0; i < len; i++)
    {
        cout << this->data[i];
    }
}
istream &operator>>(istream &in, Numbers &num)
{

    string strnum;
    cin >> strnum;
    num.len = strnum.length();
    for (size_t i = num.len; i > 0; i--)
    {
        num.data[i - 1] = strnum[i - 1] - '0';
    }
    return in;
}

ostream &operator<<(ostream &out, Numbers &num)
{

    for (size_t i = 0; i < num.len; i++)
    {
        out << num.data[i];
    }
    return out;
}

void Numbers::operator=(Numbers &num)
{
    for (size_t i = 0; i < 30; i++)
    {
        this->data[i] = num.data[i];
        this->len = num.len;
    }
}