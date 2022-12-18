//Program to compute salary of employee
#include<iostream>
using namespace std;
typedef struct employee
{
    char name[30];
    float bs;
    float gs;
    float ns;
}emp;
int main()
{
    emp e[10];
    int n,i;
    float da,hra,it;
    cout<<"ENter how many employee details you want to store:";
    cin>>n;
    cout<<"Enter "<<n<<" employee details:\n";
    //Loop for reading employee details
    for (i=0;i<n;i++)
    {
        it=0; da=0; hra=0;
        cout<<"Enter employee name:";
        cin>>e[i].name;
        cout<<"Enter employee salary:";
        cin>>e[i].bs;
        da=(52*e[i].bs)/100;
        hra=(30*e[i].bs)/100;
        e[i].gs=e[i].bs+da+hra;
        it=(10*e[i].gs)/100;
        e[i].ns=e[i].gs-it;
        cout<<"=========="<<endl;
    }//Reading loop closed
    //Looping for printing employee details
    cout<<"Employee details:"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<"Employee name:"<<e[i].name<<endl;
        cout<<"Employee basic salary:"<<e[i].bs<<endl;
        cout<<"Employee gross salary:"<<e[i].gs<<endl;
        cout<<"Employee net salary:"<<e[i].ns<<endl;
        cout<<"=========="<<endl;
    }
    return 0;
}