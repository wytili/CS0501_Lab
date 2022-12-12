using namespace std;
int divide(int a[], int low, int high)
{
    int n = a[low];
    do
    {
        while(low < high && a[high] >= n)--high;
        if(low < high){a[low] = a[high]; ++low;}
        while(low < high && a[low] <= n)++low;
        if(low < high){a[high] = a[low]; --high;}
    } while (low != high);
    a[low] = n;
    return low;   
}
void quicksort(int a[], int low, int high)
{
    int mid;
    if(low >= high)return;
    mid = divide(a, low, high);
    quicksort(a, low, mid-1);
    quicksort(a, mid+1, high);
}
