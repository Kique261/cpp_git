#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

const unsigned int n=10;
const unsigned int m=2*n -1;

struct TreeNode {
    float weight;
    int parent;
    int leftChild;
    int rightChild;
};
class HuffmanTree {
    public:
        TreeNode hfmNodes[m+1];
    public:
        HuffmanTree(int weights[n]);
        void findMinNode(int k, int &s1, int &s2);
        void showInfo(){
            for(int i=0; i<m; i++) {
                cout<<hfmNodes[i].weight<<endl;
            }
        }
        void scan(int position){
            if(n==-1){
                return;
            }
            cout <<hfmNodes[position].weight;
            scan(hfmNodes[position].leftChild);
            scan(hfmNodes[position].rightChild);
        }
        void scan_all(){
            scan(m);
        }
};
HuffmanTree::HuffmanTree(int weights[n]) {
    int firstMin;
    int secondMin;
    for(int i = 1; i <= m; i++) {
        hfmNodes[i].weight = 0;
        hfmNodes[i].parent = -1;
        hfmNodes[i].leftChild = -1;
        hfmNodes[i].rightChild = -1;
    }
    for(int i = 1; i <= n; i++)
    hfmNodes[i].weight=weights[i-1];

    for(int i = n + 1; i <=m; i++) {
        this->findMinNode(i-1, firstMin, secondMin);
        hfmNodes[firstMin].parent = i;
        hfmNodes[secondMin].parent = i;
        hfmNodes[i].leftChild = firstMin;
        hfmNodes[i].rightChild = secondMin;
        hfmNodes[i].weight = hfmNodes[firstMin].weight + hfmNodes[secondMin].weight;
    }
}
void HuffmanTree::findMinNode(int k, int & firstMin, int & secondMin) {
    hfmNodes[0].weight = 1e9;
    firstMin=secondMin=0;
    for(int i=1; i<=k; i++) {
        if(hfmNodes[i].weight!=0 && hfmNodes[i].parent==-1) {
            if(hfmNodes[i].weight < hfmNodes[firstMin].weight) { 
                secondMin = firstMin;
                firstMin = i;
            } 
        else if(hfmNodes[i].weight < hfmNodes[secondMin].weight)
            secondMin = i;
        }
    }
}

void random(int* weights){
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        weights[i]=rand()%20;
    }
    
}

int main() {
    int weights[n];
    random(weights);
    //auto start1 = system_clock::now();
    HuffmanTree huffmanTree(weights);
    HuffmanTree.scan_all();
    //huffmanTree.showInfo();
    // auto end = system_clock::now();
    // auto duration = duration_cast<milliseconds>(end-start1);
    // cout<<"\nThere are "<<n<<" characters in array."<<"\nIt costs "<<double(duration.count())<<" ms."<<'\n';
    return 1;
}