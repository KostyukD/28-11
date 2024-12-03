
//Задание 1
/*#include <iostream>
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

}*/

//Задание 2
/*#include <iostream>
#include <string>
#include <climits>

using namespace std;


class IMath 
{
public:
    virtual int Max() const = 0;
    virtual int Min() const = 0;
    virtual float Avg() const = 0;
    virtual bool Search(int valueToSearch) const = 0;
};


class IOutput
{
public:
    virtual void Show() const = 0;
    virtual void Show(string info) const = 0;
};


class Array : public IMath, public IOutput 
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

    ~Array() {
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

    int Max() const override 
    {
        int maxVal = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (data[i] > maxVal) 
            {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    int Min() const override 
    {
        int minVal = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (data[i] < minVal)
            {
                minVal = data[i];
            }
        }
        return minVal;
    }

    float Avg() const override 
    {
        if (size == 0) return 0.0f;
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += data[i];
        }
        return static_cast<float>(sum) / size;
    }

    bool Search(int valueToSearch) const override 
    {
        for (int i = 0; i < size; i++) 
        {
            if (data[i] == valueToSearch) 
            {
                return true;
            }
        }
        return false;
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

    cout << "Max value: " << arr.Max() << endl;
    cout << "Min value: " << arr.Min() << endl;
    cout << "Average value: " << arr.Avg() << endl;
    cout << "Search for value 3: " << (arr.Search(3) ? "Found" : "Not Found") << endl;
    cout << "Search for value 10: " << (arr.Search(10) ? "Found" : "Not Found") << endl;

}*/

//Задание 3
#include <iostream>
#include <string>
#include <climits>

using namespace std;


class IMath 
{
public:
    virtual int Max() const = 0;
    virtual int Min() const = 0;
    virtual float Avg() const = 0;
    virtual bool Search(int valueToSearch) const = 0;
};


class IOutput 
{
public:
    virtual void Show() const = 0;
    virtual void Show(string info) const = 0;
};


class ISort
{
public:
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};


class Array : public IMath, public IOutput, public ISort 
{
private:
    int* data;
    int size;

    void bubbleSort(bool ascending) 
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++) 
            {
                if ((ascending && data[j] > data[j + 1]) || (!ascending && data[j] < data[j + 1])) 
                {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

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

    int Max() const override 
    {
        int maxVal = INT_MIN;
        for (int i = 0; i < size; i++) 
        {
            if (data[i] > maxVal) 
            {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    int Min() const override 
    {
        int minVal = INT_MAX;
        for (int i = 0; i < size; i++) 
        {
            if (data[i] < minVal)
            {
                minVal = data[i];
            }
        }
        return minVal;
    }

    float Avg() const override
    {
        if (size == 0) return 0.0f;
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += data[i];
        }
        return static_cast<float>(sum) / size;
    }

    bool Search(int valueToSearch) const override 
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == valueToSearch)
            {
                return true;
            }
        }
        return false;
    }

    void SortAsc() override 
    {
        bubbleSort(true);
    }

    void SortDesc() override 
    {
        bubbleSort(false);
    }

    void SortByParam(bool isAsc) override
    {
        bubbleSort(isAsc);
    }
};

int main() 
{
    int initData[] = { 5, 2, 3, 1, 4 };
    int size = sizeof(initData) / sizeof(initData[0]);
    Array arr(initData, size);

    cout << "Вывод массива:" << endl;
    arr.Show();

    cout << "Вывод массива с информационным сообщением:" << endl;
    arr.Show("Информация о массиве:");

    cout << "Max value: " << arr.Max() << endl;
    cout << "Min value: " << arr.Min() << endl;
    cout << "Average value: " << arr.Avg() << endl;
    cout << "Search for value 3: " << (arr.Search(3) ? "Found" : "Not Found") << endl;
    cout << "Search for value 10: " << (arr.Search(10) ? "Found" : "Not Found") << endl;

    cout << "Массив после сортировки по возрастанию:" << endl;
    arr.SortAsc();
    arr.Show();

    cout << "Массив после сортировки по убыванию:" << endl;
    arr.SortDesc();
    arr.Show();

    cout << "Массив после сортировки по параметру (по убыванию):" << endl;
    arr.SortByParam(false);
    arr.Show();

}


