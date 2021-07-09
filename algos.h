


class insertionSort {
public:
    insertionSort(int* arr, int N);
    void sort(int* arr, int N);
    void swap(int* arr, int i, int j);
};
insertionSort::insertionSort(int* arr, int N) {
    sort(arr, N);
}
void insertionSort::sort(int* arr, int N) {
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            compares++;
            if (arr[j] < arr[j - 1])
            {
                exchanges++;
                swap(arr, j, j - 1);
                visual(arr,"Insertion Sort");
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






class selectionSort {
public:
    selectionSort(int* arr, int N);
    void sort(int* arr, int N);
    void swap(int* arr, int i, int j);
};
selectionSort::selectionSort(int* arr, int N) {
    sort(arr, N);
}
void selectionSort::sort(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int ind = i;
        for (int j = i + 1; j < N; j++)
        {
            compares++;
            if (arr[j] < arr[ind])
                ind = j;
        }
        exchanges++;
        swap(arr, i, ind);
        visual(arr,"Selection Sort");
    }
}
void selectionSort::swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
