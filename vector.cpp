#include <iostream>

using namespace std;

template <typename T>
class Vector{
    public:
        // Constructor
        Vector() : arr(nullptr), _size(0), _capacity(0){}

        // Destructor
        ~Vector() {
            delete[] arr;
        }

        // Copy Constructor
        Vector (const Vector& other){
            _size = other._size;
            _capacity = other._capacity;
            arr = new T[_capacity];

            for (size_t i = 0; i < other._size; i++){
                arr[i] = other.arr[i];
            }

        }
        
        //Copy assignment constructor
        Vector& operator=(const Vector& other){
            if (this == &other){
                return *this;
            }

            delete[] arr;
            _size = other._size;
            _capacity = other._capacity;
            arr = new T[_capacity];

            for (size_t i = 0; i < _size; i++){
                arr[i] = other.arr[i];
            }
            return *this;
        }

        void push_back(const T& value){
            if (_size == _capacity){
                size_t newCap = (_capacity == 0) ? 1 : _capacity * 2;
                T* temp = new T[newCap];
                
                _capacity = newCap;

                for (int i = 0; i < _size; i++){
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;

            }
            arr[_size] = value;
            _size += 1;   
        }
        T pop_back(){
            if (_size == 0){
                throw out_of_range("Vector is empty");
            }
            T lastItem = arr[_size - 1];
            _size -= 1;
            return lastItem;
            
        }
        size_t size(){
            return _size;
        }
        size_t capacity(){
            return _capacity;
        }
        bool empty(){
            return (_size == 0);
        }

    private:
        T* arr;
        size_t _size;
        size_t _capacity;

};

int main(){
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v.pop_back() << endl; 
    cout << v.pop_back() << endl; 
    cout << v.pop_back() << endl;
    return 0;
}
