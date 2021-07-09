


class insertionSort {
public:
    insertionSort(int* arr, int N, int compares, int exchanges);
    void sort(int* arr, int N,int compares, int exchanges);
    void swap(int* arr, int i, int j);
};
insertionSort::insertionSort(int* arr, int N,int compares, int exchanges) {
    sort(arr, N, compares, exchanges);
}
void insertionSort::sort(int* arr, int N,int compares, int exchanges) {
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            compares++;
            if (arr[j] < arr[j - 1])
            {
                exchanges++;
                swap(arr, j, j - 1);
                visual(arr, compares, exchanges);
            }
            else
                break;
        }
    }
}
void insertionSort::swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


