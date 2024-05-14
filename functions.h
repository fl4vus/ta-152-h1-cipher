void copyArray(int source[], int destination[], int size) 
{
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findCharPosition(char arr[], int size, char element) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if the element is found
        }
    }

    return -1; // Return -1 if the element is not found
}

int findMapPosition(int arr[], int size, int element) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if the element is found
        }
    }

    return -1; // Return -1 if the element is not found
}

void reverseArray(int arr[], int starter, int size) 
{
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(&arr[starter+start], &arr[starter+end]);

        start++;
        end--;
    }
}

void superShuffle(int arr[], int n, int size)
{
    if (n <= 0)
    {
        n = size;
    }
    int new_size = size - (size % n);
    int crapSize = size / n;
    int starter, ender;
    starter = 0;
    //ender = crapSize - 1;
    for (int i = 0; i < n; i++)
    {
        starter = (i  * crapSize);
        reverseArray(arr, starter, crapSize);
    } 
}

