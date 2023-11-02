#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<chrono>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

class Knap{
    public:
        Knap(int nums,int capicity){
            n=nums;
            W=capicity;
            random(n);
            Knapsack(W,n);
        }
    private:
        void random(int n){
            srand(time(nullptr));
            for(int i=0;i<n;i++){
                v.push_back(rand()%29+1);
                w.push_back(rand()%19+1);
                x.push_back(0);
                bestx.push_back(0);
            }
        }

        double Bound(int i){
            int rest_value=0;
            while(i<=n){
                rest_value+=v[i];
                i++;
            }
            return cur_value+rest_value;
        }
        
        void Backtrack(int t){
            if(t>n){
                for(int j=1;j<=n;j++)
                {
                    bestx[j]=x[j];
                }
                bestp=cur_value;
                return;
            }
        
            if(cur_weight+w[t]<=W){
                x[t]=1;
                cur_weight+=w[t];
                cur_value+=v[t];
                Backtrack(t+1);
                cur_weight-=w[t];
                cur_value-=v[t];
            }
        
            if(Bound(t+1)>bestp){
                x[t]=0;
                Backtrack(t+1);
            }
        }
        
        void Knapsack(double W,int n){
            cur_weight=0;
            cur_value=0;
            bestp=0;
            double sum_weight=0;
            double sum_value=0;
            for(int i=1;i<=n;i++){
                sum_weight+=w[i];
                sum_value+=v[i];
            }
            if(sum_weight<=W){
                bestp=sum_value;
                cout << "Bestp is: " << bestp << "\n";
                return;
            }
            auto start = system_clock::now();
            Backtrack(1); 
            auto end = system_clock::now();
            cout << "Bestp is: " << bestp << "\n";
            // cout << "Id of objects in the bag is: ";
            // for(int i=1;i<=n;i++){
            //     if(bestx[i]==1){
            //         cout << i << " " ;
            //     }
            // }
            auto duration = duration_cast<microseconds>(end-start);
            cout<<"\nThere is "<<n<<" objects totally."<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
        }
    public:
        int n;
        int W;
        vector<double>w;
        vector<double>v;
        vector<bool>x;
        double cur_weight;
        double cur_value;
        double bestp;
        vector<bool>bestx;
};

int main(){
    Knap k0(10,40);
    Knap k1(20,80); 
    Knap k2(40,160);
    return 0;
}