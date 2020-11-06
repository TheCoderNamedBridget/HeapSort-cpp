/******************************************************************************

Bridget Naylor
Lab 5 Max Heaps
Date:11/4/2020

*******************************************************************************/
#include <iostream>
using namespace std;

//Functions to include
//build_MaxHeap
//max_heapify
//heap_sort

//check if parent is greater than children
//if not then swap with the bigger child
void max_heapify( int a[], int size, int index )
{
    //size 2
    size = size - 1;
    bool largerThanKids = false;
    while ( !largerThanKids )
    {
        
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        // no right and left is less than index
        if ( (left > size && right > size ) || ( a[index] > a[right] && a[index] > a[left] ) || ( left <= size && right > size && a[index] > a[left] ) )
        {
            largerThanKids = true;
            return;
        }
        else if ( right <= size  && a[right] >= a[left] && a[right] >= a[index])
        {
            //swap a[right] and a[index]
            int tempRight = a[right];
            a[right] = a[index];
            a[index] = tempRight;
            
            index = right;
        }
        else if ( (left <= size && right <= size && a[left] > a[right] && a[left] > a[index]) || ( left <= size && a[left] > a[index]) )
        {
            //swap a[left] and a[index]
            int tempLeft = a[left];
            a[left] = a[index];
            a[index] = tempLeft;
            
            index = left;
        }
        
        //cout<<"heremax_heapifyloop"<<endl;
    }

}

void build_MaxHeaps( int a[], int size )
{
    //size = 2
    int end = size;
    for ( int i = size - 1; i > -1; i -- )
    {
        //cout<<"build_MaxHeaps before max_heapify seg fault?"<<endl;
        max_heapify( a, end, i );
        //cout<<"build_MaxHeaps after max_heapify seg fault?"<<endl;
        
        
    }
    
}

void heap_sort( int a[], int size )
{
    build_MaxHeaps( a, size );
    
    //size = 3
    int end = size - 1;//2
    
    
    while ( end != 0 )
    {
        //swap a[0] with a[end]
        int root = a[0];
        a[0] = a[end];
        a[end] = root;
        end--;//1
        if ( end != 0 )
        {
            max_heapify( a, end, 0 );
        }
    }
    
    
    
    
}

void selection_sort( int a[], int size )
{
    int min;
    for ( int nextIndexToFill = 0; nextIndexToFill < size; nextIndexToFill ++ )
    {
        min = a[nextIndexToFill];
        for ( int i = 0; i < size; i ++)
        {
            if ( a[i] < min )
            {
                int temp = a[i];
                a[i] = min;
                min = temp;
            }
        }
        a[nextIndexToFill] = min;
    }
    
}

int main()
{
    //Part A
    int n = 0;
    
    while ( n < 1)
    {
        cout<<"Enter a positive non zero integer: ";
        cin >> n;
    }
    int a[n];
    
    srand (time(NULL));
    for ( int i = 0; i < n; i++ )
    {
        int posOrNeg = rand() % 2 + 1;
        int posNum = rand() % 101;//0 - 100
        int negNum = rand() % 101 -100;//-100 - -1

        if ( posOrNeg == 2 )//posOrNeg = 2 +> do pos
        {
            a[i] = posNum;
        }
        else//do neg
        {
            a[i] = negNum;
        }
    }
    //print list
    cout<<"Original List"<<endl;
    for ( int i = 0; i < n; i++ )
    {
        cout<<a[i]<<endl;
    }
    heap_sort( a, n );
    //selection_sort( a, n );
    
    cout<<"Sorted list"<<endl;
    for ( int i = 0; i < n; i++ )
    {
        cout<<a[i]<<endl;
    }
    
    //determine runtime for n = 1000 and n =100
    //compare runtimes to Selection sort runtimes
    
    //Part 2
    // int sizeB = 10;
    // int b[sizeB];
    
    // for ( int i = 0; i < sizeB; i++ )
    // {
    //     int posOrNeg2 = rand() % 2 + 1;
    //     int posNum2 = rand() % 101;//0 - 100
    //     int negNum2 = rand() % 101 -100;//-100 - -1

    //     if ( posOrNeg2 == 2 )//posOrNeg = 2 +> do pos
    //     {
    //         b[i] = posNum2;
    //     }
    //     else//do neg
    //     {
    //         b[i] = negNum2;
    //     }
    // }
    // heap_sort( b, sizeB );
    // cout<<"Part 2 List B"<<endl;
    // for ( int i = 0; i < sizeB; i++ )
    // {
    //     cout<<b[i]<<endl;
    // }
    return 0;
}



