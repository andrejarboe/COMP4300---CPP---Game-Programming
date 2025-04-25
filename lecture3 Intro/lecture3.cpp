#include <iostream>

void pp(int & i)
{
    std::cout << &i << " " << i << " " << sizeof(i) << '\n';
}

template <typename T>

class DynamicArray
{
    size_t m_size;
    T* m_arr;

public:
    DynamicArray(size_t size)
        : m_size(size)
        , m_arr (new T[size])
    {
        // m_arr = new int[size];
        std::cout << "Array Constructor\n";
    }

    ~DynamicArray()
    {
        delete [] m_arr;
        std::cout << "Array Destructor\n";
    }

    T get(size_t index) const
    {
        return m_arr[index];
    }

    void set(size_t index, T val)
    {
        m_arr[index] = val;
    }

    void print() const
    {
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << i << " " << m_arr[i] << "\n";
        }
    }

    const T & operator [](size_t index) const
    {
        return m_arr[index];
    }

    T & operator [](size_t index)
    {
        return m_arr[index];
    }
};

int main(int argc, char * argv[])
{

    int a = 10;
    int b = 25694652;
    int c = -7;

    pp(a);
    pp(b);
    pp(c);


    int arr[10] = {};

    for(size_t i = 0; i < 10; i++)
    {
        pp(arr[i]);
    }

    int* heapArr = new int[10];

    for(size_t i = 0; i < 10; i++)
    {
        pp(heapArr[i]);
    }

    int n = 10;
    int r = 25;
    int* pn = &n;
    int* pr = &r;

    // *pn = 17;
    // *(&r) = 42;

    //bad
    *(pr-1) = 42;

    pp(n);
    pp(r);

    DynamicArray<float> myArray(10);
    myArray.set(4, 7.65659);
    myArray.set(1, 9999.42);
    myArray[3] = 3.1459;
    myArray[2] = 2.78;
    myArray.print();

    std::cout << myArray[2] << "\n";

    return 0;
}