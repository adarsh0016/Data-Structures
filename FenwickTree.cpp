#include <iostream>

using namespace std;

class FencwickTree{
    long* fenwickTree;
    public:
    FencwickTree(int arr[], int n){
        fenwickTree = new long[n];
        for(int i = 0 ; i < n ; i++){
            fenwickTree[i] = arr[i];
        }
        for(int i = 0; i < n ; i++){
            int j = i + lsb(i);
            if( j <= n){
                fenwickTree[j] += fenwickTree[i];
            }
        }
    }

    long prefixSum(int i){
        long sum = 0;
        while(i != 0){
            sum += fenwickTree[i];
            i &= ~lsb(i);
        }
        return sum;
    }

    long sum(int i, int j){
        if(j >= i){
            return prefixSum(j) - prefixSum(i-1);
        }
        return -1;
    }

    //add k to index i
    void add(int i, long k){
        while(i < sizeof(fenwickTree)/sizeof(fenwickTree[0])){
            fenwickTree[i] += k;
            i += lsb(i);
        }
    }

    //set index i equal to k
    void set (int i, long k){
        long value = sum(i, i);
        add(i, k - value);
    }

    int lsb(int i){
        return i & -i;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i< n; i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    FencwickTree f(arr, size);
    int i, j;
    cin>>i>>j;
    cout<<f.sum(i, j);

    return 0;
}