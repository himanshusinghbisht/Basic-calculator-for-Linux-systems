#include<iostream>
using namespace std;
//
//
// function to take arguments from terminal during runtime
//
//

int  runtime(char x[],char y[])
{
  int i=0;
while(x[i]!='\0')
{
  y[i]=x[i];;
  i++;
}
return i;
}
//
//  function to convert character numbers like  '1', '2' to integers  = 1, 2
//
int ToNumber(char x)
{
  switch(x)
  {
    case '1':
    return 1;
    break;
    case '2':
    return 2;
    break;
    case '3':
    return 3;
    break;
    case '4':
    return 4;
    break;
    case '5':
    return 5;
    break;
    case '6':
    return 6;
    break;
    case '7':
    return 7;
    break;
    case '8':
    return 8;
    break;
    case '9':
    return 9;
    break;
    case '0':
    return 0;
    break;

  }
return 0;
}
int main(int argc,char*argv[]){
string e;
char exp[100];
char op[10];
int num[100];
float realnum[100];
int n=0;
bool forever;
 if(argc==3)
 {
   cout << "help : calculla - h \n";
   cout << " use in 3 ways \n";
   cout << " 1. calculla\n";
   cout << " 2. calculal 2+4/2*100 ( any expression )\n";
   cout << " 3. for bash scripts as either through second way or for assigning value to any variable use - variable=$(calculla $a+$b*$c) anything !\n\n";
   return 0;
 }
if(argc>2)
{
  cout << "\nsingle argument allowed with no spaces or no aguments at all\n\n   example : sol 5*4/2\n";
  cout << "\n";
  exit(0);
}
if(argc==1)
forever=true;
do
{
////////////////////////////
// testing
////// if argument is provided
if(argc==2)
{
n = runtime(argv[1],exp);
}
// if argument is not provided
//

else if(argc==1)
{
//////////////////////////

cout << "enter expression\n"; cout << ">>> ";
cin >> e;
n=0;
int count=0;
while(e[count]!='\0')
{
  exp[n]=e[count];
  n++;
  count++;
}
}
// cout << "expression entered is ";
// for(int i=0;i<n;++i)
// {
// cout << exp[i] ;
// }
// cout << "\n\n";
//
//       for viewing all operators and numbers seperately
//

// cout << "separating operators and numbers";
int j=0,i=0;
while(exp[j]!='\0')
{
  switch(exp[j])
  {
    case '+':
    case '-':
    case '/':
    case '*':
    op[i]=exp[j];
    i++;
    break;
  }
  j++;
}
// cout << "\n\n";

///  operators

// // // cout << " all operators are - \n";
// // for(int x=0;x<i;x++)
// // {
// //   cout << op[x];
// // }
// cout << "\n\n\n";
// cout << "all numbers are \n";
j=0;
int NumLength=0;
float temp;
//
//
// converting numbers in character array to integar format
//
//
for(j=0;j<n;++j)
{
  // cout << " exp [" << j << "] = " << exp[j] << " \n";
  if((exp[j]!='*')&&(exp[j]!='/')&&(exp[j]!='+')&&(exp[j]!='-'))
  {

    temp = ToNumber(exp[j]);
    // cout << " number = " << temp << "\n";
    num[NumLength] = temp;
    NumLength++;
  }
  else
  {
    // cout << " character = " << exp[j] << "\n";
    num[NumLength]=7777;
    NumLength++;
  }
  // cout << " numlength = " << NumLength ;
// cout << "\n\n\n";

}
num[NumLength]=7777;
//cout << " numlength = " << NumLength << "\n";
// cout << " mixed num with redundant values \n";
// for(int i=0;i<=NumLength;++i)
// {
//   cout << num[i] << " ";
// }
// cout << "\n\n";
//////
int indexcount[100];
j=0;
for(int i=0;i<=NumLength;++i)
{
  if(num[i]==7777)
  {
    indexcount[j]=i;
    j++;
  }

}
// cout << " indexes where 7777 are \n\n";
// for(int i=0;i<j;++i)
// {
//   cout << indexcount[i] << " " ;
//
// }
// cout << "\n\n";
//


 int l;
 int x=0,y=0,power=1,index=0;
//
//
//   converting numbers in integar array to their real form
//
//

 for(int i=0;i<j;++i)
 {
    x = indexcount[i];
   temp=0;
   power=1;
while(y<x)
{

      temp = temp*10;
     temp = temp + num[y];
     y++;

}
realnum[index]=(float)temp;
index++;
y++;
}
/// final numbers
////
////
// cout << " all numbers are \n\n";
// index  = total numbers
// for(int i=0;i<index;++i)
// {
//   cout << realnum[i] << " ";
// }
////
//// all operators
////
// cout << "\n\n all operators are - \n";
// for(int x=0;x<i;x++)
// {
//   cout << op[x] << " ";
// }
// cout << "\n\n\n";

for(int i=0;i<index;i++)
{
  if(op[i]=='-')
  {
    realnum[i+1]=realnum[i+1]*(-1);
  }
}

// for(int i=0;i<index;i++)
// {
//   cout << realnum[i] << " " ;
// }
///
///
/// this is for calculating through BODMAS RULE with highest priority of division and multiplication
///
///
 cout << "\n";
for(int i=0;i<index;i++)
{

    if(op[i]=='*')
    {
      // cout << " realnum [i+1] = " << realnum[i+1] << " ,, realnum[i-1] = " << realnum[i-1] << "\n";
      realnum[i+1] = realnum[i] * realnum[i+1];
      temp = realnum[i+1];
      // cout << " temp = " << temp << "\n";
      realnum[i] = 0;
      op[i]='+';
    }
    if(op[i]=='/')
    {
      // cout << " realnum [i+1] = " << realnum[i+1] << " ,, realnum[i-1] = " << realnum[i-1] << "\n";
      realnum[i+1] = realnum[i] / realnum[i+1];
      temp = realnum[i+1];
      // cout << " temp = " << temp << "\n";
      realnum[i] = 0;
      op[i]='+';
    }

}
float ans=0;


// for(int i=0;i<index;i++)
// {
//   cout << realnum[i] << " " ;
// }

for(int i=0;i<index;i++)
{
  ans = ans + realnum[i];
}
// cout << "\n\n\n";
 cout << "  answer = " << ans << "\n\n";

  if(argc==2)
  {
  forever=false;
return ans;
}
  else
  forever=true;

}while(forever);
}
