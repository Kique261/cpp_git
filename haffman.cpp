#include <iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

#define MAX 100
#define LIMITW  10000;
typedef struct Haffman {
	int weight;
	char ch;	
	int parent;
	int leftchild;
	int rightchild;
} HaffmaNode;

typedef struct Code {	
	int code[MAX];
	int start;
} HaffmaCode;



class Huff{
	public:
		Huff(int n){
			H = n;
            auto start = system_clock::now();
			buildHaffman(H);
            auto end = system_clock::now();
            auto duration = duration_cast<nanoseconds>(end-start);
			// visCode(H);
			// for (int i = 0; i < H; ++i) {
			// 	std::cout << haffarr[i].ch << ": Haffman Code is:";
			// 	for (int j = code[i].start + 1; j < H; ++j) {
			// 		std::cout << code[i].code[j];
			// 	}
			// 	std::cout << std::endl;
			// }
            cout<<"There are "<<H<<" chars in it. "<<"\nHafftree-Building costs "<<double(duration.count())<<" ns."<<'\n';
	}

	private:
		    void Init(int n){
		        srand(time(nullptr));
		        for (int i = 0; i < n*2-1; ++i)
		        {
		        	haffarr[i].ch=(char)(rand()%(256));
		            haffarr[i].weight = rand()%29+1;
					haffarr[i].parent = -1;
					haffarr[i].leftchild = -1;
					haffarr[i].rightchild = -1;
		        }
		    }
		
		void buildHaffman(int H) {
			Init(H);
			int x1, x2, w1, w2;
			for (int i = 0; i < H - 1; ++i) {
				x1 = x2 = -1;
				w1 = w2 = LIMITW;
				for (int j = 0; j < H + i; ++j) {
					if (haffarr[j].parent == -1 && haffarr[j].weight < w1) {
						w2 = w1;
						x2 = x1;
						x1 = j;
						w1 = haffarr[j].weight;
					}
					else if(haffarr[j].parent == -1 && haffarr[j].weight < w2) {
						x2 = j;
						w2 = haffarr[j].weight;
					}
				}
				haffarr[H + i].leftchild = x2;
				haffarr[H + i].rightchild = x1;
				haffarr[H + i].weight = w1 + w2; 
				haffarr[x1].parent = H + i;
				haffarr[x2].parent = H + i;
			}
		}
		void visCode(int H) {
			HaffmaCode cur_code;
			int cur_parent;
			int c;
			for (int i = 0; i < H; ++i) {
				cur_code.start = H - 1;
				c = i; 
				cur_parent = haffarr[i].parent;
				while (cur_parent != -1) {
					if (haffarr[cur_parent].leftchild == c) {
						cur_code.code[cur_code.start] = 1;
					} else { 
						cur_code.code[cur_code.start] = 0;
					}
					cur_code.start--;
					c = cur_parent;
					cur_parent = haffarr[c].parent;
				}
				for (int j = cur_code.start + 1; j < H; ++j) {
					code[i].code[j] = cur_code.code[j];
				}
				code[i].start = cur_code.start;
			}
		}
	public:
		HaffmaNode haffarr[MAX];
		HaffmaCode code[MAX];
		int H;
		
}; 


int main() {
	Huff h0(5);
	Huff h1(10);
	Huff h2(15);
    Huff h3(20);
	Huff h4(30);
	Huff h5(40);
	Huff h6(80);
	return 0;	
}