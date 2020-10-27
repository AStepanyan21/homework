#include <iostream>
#include <vector> 
using namespace std;

class Bitset {
private:
        int array_length;
        vector<long long> bitset_array;
        int length;
public:
        Bitset(int array_length) {
            this->array_length = array_length;
            this->length = this->array_length / 64;
            this->iniVector();
        }
        void iniVector() {
            for (int i = 0; i <= this->length; i++) {
                this->bitset_array.push_back(0);
            }
        }
private:
    long long setMask(long long el) {
        return 1 << el-1;
    }
    long long getMask(long long el) {
        return 1 << el-1 ;
    }

    int elementInArray(int el) {
        return el / 64;
    }

    long long addNewObject(long long obj1, long long obj2) {
        return obj1 | obj2;
    }
public:
    void set(int el) {
        int index = this->elementInArray(el);
        long long value = el % 64;
        this->bitset_array[index] = this->addNewObject(this->bitset_array[index], this->setMask(value));
    }
    bool get(int el) {
        int index = this->elementInArray(el);
        long long value = el % 64;
        return this->bitset_array[index] & this->getMask(value);
    }
};

int main()
{
    Bitset test(1024);
    test.set(1);
    test.set(6);
    test.set(7);
    test.set(8);
    test.set(181);
   
    cout<<test.get(6);
    cout << test.get(181);

}
