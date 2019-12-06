//hadeer ashraf elnaggar  20160278
//hashem khaled said  20160273
//mariam jafaar elnakeeb  20160359

#include <iostream>
#include<stack>
using namespace std;

void printarr(int *arr,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
class functiontype
{
public:
    int type; //0 for merge sort function and 1 for merge function
    int start;
    int middle;
    int endd;
    functiontype(int type,int start,int middle,int endd)
    {
        this->type=type;
        this->start=start;
        this->middle=middle;
        this->endd=endd;
    }

};
void merge(int arr[], int start, int middle, int endd)
{
    int i, j, k;
	//size of first half
    int n1 = middle - start + 1;
	//size of second half
    int n2 =  endd - middle;
	//temp arrays for first and second halves 
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (true)
    {
        if(!i < n1 || !j < n2) break;
		//put less value first
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
	//complete left array
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
	//complete right array
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int *a,int start,int endd)
{
	//put the first mergesort function which is all the array in the stack
    functiontype firstmerge(0,start,0,endd);
    stack<functiontype>mystack;
    mystack.push(firstmerge);
    while(true)
    {
		//breaks when stack is empty
        if(mystack.empty()) break;
		//pop top element in stack
        functiontype temp=mystack.top();
        mystack.pop();
		//if top element is mergesort function
        if(temp.type==0)
        {
             
            if(!(temp.endd-temp.start==1))
            {
				//get middle element
                int middle=(temp.start+temp.endd)/2;
				//each mergesort function is poped and replaced with 1 merge and 2 mergesorts 1 for each half
                functiontype mergee(1,temp.start,middle,temp.endd);
                functiontype mergesortleft(0,temp.start,0,middle);
                functiontype mergeesortright(0,middle,0,temp.endd);
                mystack.push(mergee);
                mystack.push(mergesortleft);
                mystack.push(mergeesortright);

            }
			//if the difference between start and end is 1 no further mergesort
            else
            {
                merge(a,temp.start,temp.start,temp.endd);
            }
        }
		//for merge function type
        else if(temp.type==1)
        {
            merge(a,temp.start,temp.middle,temp.endd);
        }
    }

}

int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;
    int *arr=new int[n];
    cout<<"please enter the array values"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"merged"<<endl;
    printarr(arr,n);
    delete[] arr;

    return 0;
}

