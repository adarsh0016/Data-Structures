#include <iostream>

using namespace std;

template<typename T>
class array{
    private:
        int len = 0;
        int capacity = 0;
        T *arr;

        T* createArr(int capacity, T* oldArr){
            T* arr = new T[capacity];
            if(oldArr == NULL) return arr;
            for(int i = 0; i < capacity/2 ; i++){
                arr[i] = *(oldArr + i);
            }
            delete [] oldArr;
            return arr;
        }

    public:
        void append(T data){
            T* newArr;
            if(capacity == 0){
                capacity = 10;
                newArr = createArr(capacity, NULL);
                arr = newArr;
            }

            if(len == capacity){
                capacity *= 2;
                newArr = createArr(capacity, arr);
                arr = newArr;
                }

            newArr[len] = data;
            len++;
        }

        void Print(){
            for(int i = 0; i < len ; i++){
                cout<<*(arr + i)<<"  ";
            }
        }

        T& operator[](const int index){
            return *(arr + index);
        }

        int length(){
            return len;
        }
};

int main(){
    array<int> arr;
    arr.append(10);
    arr.append(45);
    arr.append(67);
    arr.append(0);
    arr.append(10);
    arr.append(45);
    arr.append(67);
    arr.append(0);
    arr.append(10);
    arr.append(45);
    arr.append(67);
    arr.append(0);
    arr.append(10);
    arr.append(45);
    arr.append(67);
    arr.append(0);
    arr[0] = 89;
    arr.Print();
    cout<<endl;
    cout<<arr[0];
    
    return 0;
}