#include<iostream>
#include<algorithm>
using namespace std;

template<typename Item>
class MaxHeap{
    private:
        Item* data;
        int count;
        int capacity;
        void shiftup(int k){
            while (k>1 && data[k/2]< data[k])
            {
                swap(data[k/2],data[k]);
                k = k/2;
            }
        }
        void shiftdown(int k){
            while (k*2 <= count)
            {
                int j = k*2;
                if (j+1<=count && data[j+1]>data[j])
                {
                    j++;
                }
                if (data[k>=data[j]])
                {
                    break;
                }
                swap(data[k],data[j]);
                k=j;
            }
        }
        public:
        MaxHeap(int capacity){
            data = new Item[capacity+1];
            count = 0;
            this->capacity = capacity;
        }

        int size(){
            return count;
        }

        bool isEmpty(){
            return count==0;
        }

        void insert(Item item){
            data[count+1]=item;
            count++;
            shiftup(count);
        }

        Item extractMax(){
            Item ret = data[1];
            swap(data[1],data[count]);
            count--;
            shiftdown(1);
            return ret;
        }

        Item getMax(){
            return data[1];
        }
};
