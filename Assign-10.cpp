// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    heap(){
        arr[0]=-1;
    }
    void heapify(int arr[],int n,int i){
        int smallest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n && arr[left]<arr[smallest]){
            smallest=left;
        }
        if(right<=n && arr[right]<arr[smallest]){
            smallest=right;
        }
        if(smallest!=i){
            swap(arr[smallest],arr[i]);
            heapify(arr,n,smallest);
        }
    }
   void heapsort(int arr[], int n) {
        // Step 1: Swap the first and last nodes
        int size = n;
        while (size > 1) {
            // Step 1: Swap
            swap(arr[size], arr[1]);
            // Step 2:
            size--;
            heapify(arr, size, 1);
        }
    }
  void deletefromheap(int arr[], int& n) {
    if (n == 0) {
        cout << "Nothing to delete" << endl;
        return;
    }
    arr[1] = arr[n];
    n--;
    int i = 1; // Define and initialize i
    while (i < n) { // Correct loop condition
        heapify(arr, n, i);
        i++; // Increment i to avoid infinite loop
    }
}

        
    };
int main() {
    // Write C++ code here
    heap h;
    int arr[6]={-1,54,52,55,50,53};
    int n=5;
    for(int i=n/2;i>0;i--){
        h.heapify(arr,n,i);
    }
     for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    h.deletefromheap(arr,n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    h.heapsort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}