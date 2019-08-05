#include <iostream>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;
struct student{
string name;
string rollno;
string branch;
};
int lbs(struct student[], int, int,string);
int rbs(struct student[], int, int,string);
//////////////////////////////MERGESORT////////////////////////////////////
void Merge(struct student arr[],int low,int mid, int high)
{
    int nL= mid-low+1;
    int nR= high-mid;

    struct student L[nL];
    struct student R[nR];
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=arr[low+i];
    }
    for(i=0;i<nR;i++)
    {
        R[i]=arr[mid+i+1];
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i].name.c_str(),R[j].name.c_str())<0){
		arr[k++]=L[i++];
	}
        else {
		arr[k++]=R[j++];
	}
    }
    while(i<nL)	arr[k++]=L[i++];
    while(j<nR)arr[k++]=R[j++];

}
void mergesort(struct student stud[],int low,int high){
if (low < high)
    {  //cout<<"hi";
        int mid = (low+high)/2;

        mergesort(stud, low, mid);

        mergesort(stud, mid+1,high);

        Merge(stud, low, mid, high);
    }

}
////////////////////////////////////SWAP FUNCTION/////////////////////
void swap(struct student* a, struct student* b)
{
    struct student t = *a;
    *a = *b;
    *b = t;
}
////////////////////////PARTITION FUNCTION///////////////////////
int partition (struct student stud[], int low, int high)
{
    string pivot = stud[high].name;
    string pivot1=stud[high].rollno;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if(stud[j].name==pivot)
        {

            if(stud[j].rollno<=pivot1)
            {
                 i++;
            swap(&stud[i], &stud[j]);

            }
        }
        else if (stud[j].name < pivot)
        {
            i++;
            swap(&stud[i], &stud[j]);
        }

    }
    swap(&stud[i + 1], &stud[high]);
    return (i + 1);
}
/////////////////////////////////////////QUICK SORT///////////////////////////////
void quicksort(struct student stud[],int low,int high){
if (low < high)
    {
        int pi = partition(stud, low, high);
        quicksort(stud, low, pi - 1);
        quicksort(stud, pi + 1, high);
    }
}
///////////////////PRINT FUNCTION///////////////////
void print(struct student stud[],int lineno)
{
    for(int i=0;i<=lineno;i++)
    {

        cout<<stud[i].name<<"\t"<<stud[i].rollno<<"\t"<<stud[i].branch<<endl;
    }

}
/////////////////////////////BINARY SEARCH//////////////////////////
/*int binarysearch(struct student stud[],int low,int high,string name)
{
    cout<<name;
 if (high >= low) {
        int mid = (low+high) / 2;
        if (stud[mid].name == name)
            return mid;
        if (stud[mid].name > name)
            return binarysearch(stud, 0, mid - 1,name);
            else
        return binarysearch(stud, mid + 1,high,name);
    }
    return -1;
}*/
////////////////////QUIT////////////////
void quit(){
cout<<"best of luck!!!!!"<<endl;
}
//////////////////////////////////////////////////////////////
int main()
{   struct student stud[20];
    int a,lineno=0,r,low=0;
    string line;
    ifstream ptr;
    ptr.open("student.txt",ios::in);
    if(ptr.fail()){
        cout<<"error in opening file"<< endl;
    }
    while(getline(ptr,line))
    {
        stringstream sp(line);
        getline(sp,stud[lineno].name,',');
        getline(sp,stud[lineno].rollno,',');
        getline(sp,stud[lineno].branch,'\n');
        lineno++;
    }
    ptr.close();
    //cout<<lineno;
  /* for(i=0;i<lineno;i++)
    {
        cout<<stud[i].name<<"\t"<<stud[i].rollno<<"\t"<<stud[i].branch<<endl;

    }
    */
    cout << "Enter the choice"<<endl;
    cout<<"1.Merge sort"<<"\n"<<"2.Quick sort"<<"\n"<<"3.Binary search"<<"\n"<<"4.Quit"<<endl;
    cin>>r;
    switch(r){
  case 1: mergesort(stud,0,lineno-1);
            print(stud,lineno);
           break;
    case 2: quicksort(stud,low,lineno-1);
            print(stud,lineno);
            break;
    case 3:{
            mergesort(stud,0,lineno-1);
            char bn[30];
            cout<<"Enter Name of the student";
            scanf(" %[^\n]",bn);
            string bname=bn;
            int p=lbs(stud,0,lineno-1,bname);
            int q=rbs(stud,0,lineno-1,bname);
            if(p==-1 && q==-1)
            {
                cout<<"No Record found!!!";
                break;
            }
           // cout<<"No of students are "<<q-p+1<<endl;
            for(int x=p,f=1;x<=q;x++,f++)
            {
                cout<<stud[x].name<<"\t";
                cout<<stud[x].rollno<<"\t";
                cout<<stud[x].branch<<endl;
            }
                 break;
           }
    case 4: quit();
            break;
    default:
        cout<<"entered the wrong choice"<<endl;
            break;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////
int lbs(struct student stud[], int i,int j,string x)
{
	int mid;
	while(i<=j)
		{
			mid=(i+j)/2;
			if (stud[mid].name==x && mid==i){return mid;}
			if(stud[mid-1].name<stud[mid].name && stud[mid].name==x){return mid;}
			if(stud[mid].name<x){i=mid+1;}
			else{j=mid-1;}
		}
	return -1;
}
int rbs(struct student stud[], int i, int j,string x)
{

	int mid;
	while(i<=j)
		{
			mid=(i+j)/2;
			if (stud[mid].name==x && mid==j){return mid;}
			if(stud[mid].name<stud[mid+1].name && stud[mid].name==x){return mid;}
			if(stud[mid].name<=x){i=mid+1;}
			else{j=mid-1;}
		}
	return -1;
}

