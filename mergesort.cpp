#include<stdio.h>
#include<fstream>
#include<sstream>
struct student{
string name;
string rollno;
string branch;
};
void main(){
struct student stud[10];

cout<< "enter the data";
for(int i=0;i<4;i++)
{

    cin>>stud[i].name;
    cin>>stud[i].rollno;
    cin>>stud[i].branch;
}

}
