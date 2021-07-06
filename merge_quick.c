#include <stdio.h>
#include <conio.h>

struct employee
{
    int id;
    char name[50];
};

void getdata(struct employee data[20], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter input for %d", i + 1);

        printf("\nEnter ID: ");
        scanf("%d", &data[i].id);

        printf("\nEnter name : ");
        fflush(stdin);
        fgets(data[i].name,30,stdin);
    }
}

void merge(struct employee list[], int low, int mid, int high)
{

    int arr1[10], arr2[10];

    int arr_length1, arr_length2, i, j, k;
    arr_length1 = mid - low + 1;
    arr_length2 = high - mid;

    for(i=0; i < arr_length1; i++)
        arr1[i] = list[low+i].id;
    for(j=0; j < arr_length2;j++)
        arr2[j] = list[mid+j+1].id;

    i = 0; j = 0;
    for(k = low; k <= high; k++)
    {
        if(arr1[i]<=arr2[j])
            list[k].id=arr1[i++];
        else
            list[k].id=arr2[j++];
    }
}

void merge_sort(struct employee list[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;

        // Partition into two
        merge_sort(list, low, mid);
        merge_sort(list, mid+1, high);

        // Merge
        merge(list, low, mid, high);
    }
}

void quicksort(struct employee list[], int low, int high)
{
    int pivot, i, j;
    struct employee temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i].id <= list[pivot].id && i <= high)
            {
                i++;
            }
            while (list[j].id > list[pivot].id && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}

void display(struct employee data[20], int s)
{
    int i;

    printf("\n\nID\tName\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t\n", data[i].id, data[i].name);
    }
}

int main()
{
    struct employee data[10];
    int n;
    int ch=0;

    printf("Total Number of records: ");
    scanf("%d", &n);
    getdata(data, n);

    printf("\nMenu: \n1.Quick sort \n2.Merge sort\n");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        quicksort(data, 0, n-1);
        printf("\nQuick Sort:");
        display(data, n);
        break;
    case 2: 
        merge_sort(data, 0, n-1);
        printf("\nMerge Sort:");
        display(data, n);
    default:
        printf("\nInvalid");
        break;
    }

    return 0;
}