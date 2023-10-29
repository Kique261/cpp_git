#include <iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

#define MAXCODELEN 100
#define MAXHAFF 100
#define MAXCODE 100
#define MAXWEIGHT  10000;
typedef struct Haffman {
	int weight;
	char ch;	
	int parent;
	int leftchild;
	int rightchild;
} HaffmaNode;

typedef struct Code {	
	int code[MAXCODELEN];
	int start;
} HaffmaCode;



class Huff{
	public:
		Huff(int n){
			H = n;
            auto start = system_clock::now();
			buildHaffman(H);
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end-start);
			visCode(H);
			for (int i = 0; i < H; ++i) {
				std::cout << haffman[i].ch << ": Haffman Code is:";
				for (int j = code[i].start + 1; j < H; ++j) {
					std::cout << code[i].code[j];
				}
				std::cout << std::endl;
			}
            cout<<"There are "<<H<<" chars in it. "<<"\nHafftree-Building costs "<<double(duration.count())<<" us."<<'\n';
	}
	public:
		    void Init(int n){
		        srand(time(nullptr));
		        for (int i = 0; i < n*2-1; ++i)
		        {
		        	haffman[i].ch=(char)(rand()%(256));
		            haffman[i].weight = rand()%29+1;
					haffman[i].parent = -1;
					haffman[i].leftchild = -1;
					haffman[i].rightchild = -1;
		        }
		    }
		
		void buildHaffman(int H) {
			Init(H);
			int x1, x2, w1, w2;
			for (int i = 0; i < H - 1; ++i) {
				x1 = x2 = -1;
				w1 = w2 = MAXWEIGHT;
				for (int j = 0; j < H + i; ++j) {
					if (haffman[j].parent == -1 && haffman[j].weight < w1) {
						w2 = w1;
						x2 = x1;
						x1 = j;
						w1 = haffman[j].weight;
					}
					else if(haffman[j].parent == -1 && haffman[j].weight < w2) {
						x2 = j;
						w2 = haffman[j].weight;
					}
				}
				haffman[H + i].leftchild = x2;
				haffman[H + i].rightchild = x1;
				haffman[H + i].weight = w1 + w2; 
				haffman[x1].parent = H + i;
				haffman[x2].parent = H + i;
			}
		}
		void visCode(int H) {
			HaffmaCode cur_code;
			int cur_parent;
			int c;
			for (int i = 0; i < H; ++i) {
				cur_code.start = H - 1;
				c = i; 
				cur_parent = haffman[i].parent;
				while (cur_parent != -1) {
					if (haffman[cur_parent].leftchild == c) {
						cur_code.code[cur_code.start] = 1;
					} else { 
						cur_code.code[cur_code.start] = 0;
					}
					cur_code.start--;
					c = cur_parent;
					cur_parent = haffman[c].parent;
				}
				for (int j = cur_code.start + 1; j < H; ++j) {
					code[i].code[j] = cur_code.code[j];
				}
				code[i].start = cur_code.start;
			}
		}
	public:
		HaffmaNode haffman[MAXHAFF];
		HaffmaCode code[MAXCODE];
		int H;
		
}; 


int main() {
	Huff h(10);
    Huff h2(20);
    Huff h3(40);
    Huff h4(80);
    Huff h5(160);
	return 0;	
}