#include <iostream>
#include <string>

using namespace std;


class IOutput 
{
public:
    virtual void Show() const = 0;
    virtual void Show(string info) const = 0;
};


class Array : public IOutput 
{
private:
    int* data;
    int size;

public:

    Array(int arr[], int s) : size(s) 
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }

    ~Array() 
    {
        delete[] data;
    }

    void Show() const override 
    {
        for (int i = 0; i < size; i++) 
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void Show(string info) const override
    {
        cout << info << endl;
        Show();
    }

};

int main()
{
    int initData[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(initData) / sizeof(initData[0]);
    Array arr(initData, size);

    cout << "Вывод массива:" << endl;
    arr.Show();

    cout << "Вывод массива с информационным сообщением:" << endl;
    arr.Show("Информация о массиве:");

    return 0;
}
