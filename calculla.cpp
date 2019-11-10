//   FUNCTIONS USED 
//   runtime( to convert runtime arguments to a character array for easily processing the arguments supplied )
//   ToNumber( to convert character array of arguments supplied to integers ) it returns int value

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
char exp[100];      // array for storing runtime arguments or the expression supplied for calculation
char op[10];        // for storing operators supplied ( example = 2+4/5 , op[] array will store +,/ { op['+','\'] }
int num[100];       
float realnum[100]; 
// num[] array stores the numbers with a seperator constant to distinguish between the numbers example if expression is 25+4/5+55
 // then op will store op['+','/','+'] and 
 // num array will store num[2,5,7777,4,7777,5,7777,5,5,7777]
  // 7777 is a constant which represents place of any operator in op array
 // 7777 is used to help convert the num array easily to the form as given in realnum[] 
  //
 // now num array has 1 number in each index , then realnum[] array converts the numbers to actual numbers supplied
  // realnum[] doesnt store 7777 like num , it converts the numbers into realnum[25,4,5,55] 
 // now realnum has the numbers now all that is left is calculation
 
  
  // FLOW OF PROGRAM
  // let's say i did :
  // $calculla 2+45-6*4
  // first thing that happens is all operators are stored in seperate array
  // op['+','-','*']
  // num[2,7777,4,5,7777,6,7777,4,7777]
  // then the indexes where 7777 is present is caluclated and realnum array will store the numbers without 7777
  // num[2,7777,4,5,7777,6,7777,4,7777] is copied in realnum array to give a form like realnum[2,45,6,4]
  // now there is a '-' in op[] array before so the calculation is made where the '-' sign exist and that number
  // in realnum index is made negative in this case it was 6 so now the real num array is 
  // realnum[2,45,-6,4]
  // now op[] array is used where '*' is present then this is used to calculate the product and changes are made to realnum array
  // '*' is in 3rd index in op[] so that is used so 3+1th index in realnum is multiplied with the 3-1th index of realnum array
  // realnum[2,45,-6,(4)*(-6)]
  // realnum[2,45,0,-24] , the index where multiplication is done is made = 0 so ( -6 is changed to 0 )
  // now just add the remaining number as there is no '*' sign
  // realnum[2,45,0,-24] all values are added then 
  // ans = 2+45-24 = 23
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
