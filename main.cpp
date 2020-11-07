
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Bridget Naylor 
SID: 025531413
*/
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <cstdio>
#include <ctime>
#include <time.h>
#include <math.h>
#include <chrono>
#include <unistd.h>
using namespace std;

void max_heapify( int a[], int size, int index )
{
    //size 2
    //cout<<"max_heapify heaps"<<endl;
    size = size - 1;
    bool largerThanKids = false;
    while ( !largerThanKids )
    {
        
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        // no right and left is less than index
//        cout<<"index "<<index<<" Value: "<<a[index]<<endl;
//        if ( left <= size )
//        {
//        	cout<<"left "<<left<<" Value: "<<a[left]<<endl;
//		}
//		else
//		{
//			cout<<"left "<<left<<" out of bounds"<<endl;
//		}
//		if ( right <= size )
//        {
//        	cout<<"right "<<right<<" Value: "<<a[right]<<endl;
//		}
//       else
//		{
//			cout<<"right "<<right<<" out of bounds"<<endl;
//		} 
//        cout<<"right "<<right<<" Value: "<<a[right]<<endl;
        
		//cout<<"( left<= size && right > size && a[left] > a[right] && a[left] == a[index]) "<<( left<= size && right > size && a[left] > a[right] && a[left] == a[index])<<endl;
		//cout<<" ( left<= size && right <= size && a[left] >= a[right] && a[left] == a[right]) "<< ( left<= size && right <= size && a[left] >= a[right] && a[left] == a[right])<<endl;
//		cout<<"( left <= size && right > size && a[index] >= a[left] ) "<<( left <= size && right > size && a[index] >= a[left] )<<endl;
//		cout<<"( left <= size && right <= size && a[left] >= a[right] && a[index] >= a[left] ) "<<( left <= size && right <= size && a[left] >= a[right] && a[index] >= a[left] )<<endl;
//		cout<<"left<= size "<<(left<= size)<<endl;
	    //cout<<"right > size "<<(right > size)<<endl;
//	    cout<<"right <= size "<<(right <= size)<<endl;
//	    if ( (left<= size) && (right <= size) )
//	    {
//	    	cout<<"a[left] >= a[right] "<<(a[left] >= a[right])<<endl;
//        	cout<<"a[left] == a[index] "<<(a[left] == a[index])<<endl;
//		}
//		cout<<"Everything else "<<endl;
//		cout<<"( (left > size && right > size ) || ( a[index] > a[right] && a[index] > a[left] ) || ( left <= size && right > size && a[index] > a[left] ) "<<( (left > size && right > size ) || ( a[index] > a[right] && a[index] > a[left] ) || ( left <= size && right > size && a[index] > a[left] ))<<endl;
        if ( (left > size && right > size ) || ( a[index] > a[right] && a[index] > a[left] ) || ( left <= size && right > size && a[index] >= a[left] ) 
		|| ( left <= size && right <= size && a[left] >= a[right] && a[index] >= a[left] ) )
		//||( left<= size && right > size && a[left] == a[right]) || ( left<= size && right <= size && a[left] >= a[right] && a[left] == a[right]) )
        {
        	//cout<<"ended"<<endl;
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
    //cout<<"buildmax heaps"<<endl;
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

int main(int argc, char** argv)
{
	
	//Part A
	cout<<"Part A: ";
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
    
    cout<<"Sorted list"<<endl;
    for ( int i = 0; i < n; i++ )
    {
        cout<<a[i]<<endl;
    }
    
    //construct lst of n = 1000
    int k = 1000;
    int c[k];
    for ( int i = 0; i < k; i++ )
    {
        int posOrNeg1 = rand() % 2 + 1;
        int posNum1 = rand() % 101;//0 - 100
        int negNum1 = rand() % 101 -100;//-100 - -1
		//cout<<posNum1<<endl;
		//cout<<negNum1<<endl;
        if ( posOrNeg1 == 2 )//posOrNeg = 2 +> do pos
        {
            c[i] = posNum1;
        }
        else//do neg
        {
            c[i] = negNum1;
        }
        //cout<<"c[i] "<<c[i]<<endl;
    }
    

 //calculates average time of heapsort search over 100 runs
 	double averageTimeOfHeap;
	auto start = chrono::steady_clock::now();
	for ( int i = 0; i < 100; i++ )
	{
//run heap sort
		heap_sort( c, k );
		//selection_sort( c, k );

	}
	auto end = chrono::steady_clock::now();
		
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//	cout<<"nanoseconds "<<nanoseconds<<endl;
//	cout << "Elapsed time in nanoseconds : "
//		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
//		<< " ns" << endl;
		
	averageTimeOfHeap = nanoseconds * 0.01;
	cout<<"Average Heapsort 100x "<<averageTimeOfHeap<<endl;
	
	int p = 1000;
    int d[p];
    for ( int i = 0; i < p; i++ )
    {
        int posOrNeg1 = rand() % 2 + 1;
        int posNum1 = rand() % 101;//0 - 100
        int negNum1 = rand() % 101 -100;//-100 - -1
		//cout<<posNum1<<endl;
		//cout<<negNum1<<endl;
        if ( posOrNeg1 == 2 )//posOrNeg = 2 +> do pos
        {
            d[i] = posNum1;
        }
        else//do neg
        {
            d[i] = negNum1;
        }
        //cout<<"c[i] "<<c[i]<<endl;
    }
	
//	 //calculates average time of selectiion search over 100 runs
 	double averageTimeOfSelect;
	auto start1 = chrono::steady_clock::now();
	for ( int i = 0; i < 100; i++ )
	{
//run heap sort
		selection_sort( d, p );

	}
	auto end1 = chrono::steady_clock::now();
		
	auto nanoseconds1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
//	cout<<"nanoseconds "<<nanoseconds1<<endl;
//	cout << "Elapsed time in nanoseconds : "
//		<< chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count()
//		<< " ns" << endl;
		
	averageTimeOfSelect = nanoseconds1 * 0.01;
	cout<<"Average Select 100x "<<averageTimeOfSelect<<endl;
	
	
	
	
//Part 2
    int sizeB = 10;
    int b[sizeB];
    
    for ( int i = 0; i < sizeB; i++ )
    {
        int posOrNeg2 = rand() % 2 + 1;
        int posNum2 = rand() % 101;//0 - 100
        int negNum2 = rand() % 101 -100;//-100 - -1

        if ( posOrNeg2 == 2 )//posOrNeg = 2 +> do pos
        {
            b[i] = posNum2;
        }
        else//do neg
        {
            b[i] = negNum2;
        }
    }
    heap_sort( b, sizeB );
    cout<<"Part B"<<endl;
    for ( int i = 0; i < sizeB; i++ )
    {
        cout<<b[i]<<endl;
    }
    return 0;
}
