#include <bits/stdc++.h>
using namespace std;

int main(){

/*EXPLANATION
i is octal. 

j is hexadecimal;

k=i|j->
1 0 0 0 0 0
1 0 0 0 0 0
-----------
1 0 0 0 0 0

l=i&j
1 0 0 0 0 0
1 0 0 0 0 0
-----------
1 0 0 0 0 0

m=i^j
1 0 0 0 0 0
1 0 0 0 0 0
-----------
0 0 0 0 0 0
*/
    // int i=040, j=0x20, k,l,m;
    // k=i|j; //bitwise or
    // l=i&j; // bitwise and
    // m=k^l; // bitwise xor
    // printf("%d %d %d %d %d\n\n",i,j,k,l,m);
 

/* BINARY CONVERSION
64 32 16 8 4 2 1 -> the places have how much value
0  1  0  0 0 0 0  = 32
*/

/* BIT MANIPULATION
1. getBit()
2. setBit()-- denotes if the bit on that place is 1
3. resetBit() denotes if the bit on that place is 0

ques- getBit()
example- check whether the 3rd position of the given number (in binary) is 1 or 0.
given_number= 1 1 1 1
solution- mask_number= 0 0 0 0 1
pos=3
shift_by_pos=pos-1 // 2
mask_number=mask_number<<shift_by_pos
mask_number&given_number
if(3rd position of number is 1 then its set. therefore the entire number will be anything but 0.) cout<<1;
else cout<<0;
*/
    //method 1
//----------------
    // int given_number= 11;
    // int mask_number=1 ;
    // int pos=3;
    // int shift_by_pos=pos-1; // 2
    // mask_number=mask_number<<shift_by_pos;
    // int checker=mask_number&given_number;
    // if(checker==0){
    //     cout<<0;
    // }
    // else{
    //     cout<<1;
    // }
//------------------
    //method 2= this wouldn't work for big integers
    // given_number=257;
    // int given=257;
    // given>>2;
    // checker=given&given_number;
    // if(checker==0)
    //     cout<<0;
    // else
    //     cout<<1;

    /* Check if a number is even or odd without %
    Explanation: 
    All the even numbers have 0 as LSB. and odd numbers have 1 as LSB.
    15= 1 1 1 1 
  mask=&0 0 0 1
  -------------
       =0 0 0 1 

    4= 1 0 0
mask= &0 0 1
-------------
     = 0 0 0

    Therefore if the ans is 0, its even. If answer is 1, its odd.
    */
//------------------
//    given=15;
//    mask=1;
//    if((given&mask)==0) cout<<"even";
//    else cout<<"odd";

/*
Ques- setBit()
example-set the 4th bit of 10001 as 1.
*/
// int given=17;
// int mask=1;
// int pos=4;
// int shift_by_pos= pos-1;
// mask = mask<<shift_by_pos;
// given=given|mask;
// cout<<given;

/*
Ques- resetBit()
example- set the 4th bit of 1111 as 0.
*/
// int given = 16;
// int mask=1;
// int pos=3;
// int shift_by_pos=pos-1;
// mask=mask<<shift_by_pos;
// given=given^mask;
// cout<<given;

/*
Convert decimal number into octal, hexidecimal, binary.
*/
    int dec=500;
    int remainder, octal=0, i=1, hex=0, bin=0;
    //Octal
     while(dec != 0) {
        remainder = dec%8;
        dec = dec/8;
        octal = octal + (remainder*i);
        i = i*10;
    }
    cout<<octal<<endl;

    //Hexadecimal
    i=1;
    dec=500;
     while(dec != 0) {
        remainder = dec%16;
        dec = dec/16;
        hex = hex + (remainder*i);
        i = i*10;
    }
    cout<<hex<<endl;

    //Binary
    i=1;
    dec=500;
     while(dec != 0) {
        remainder = dec%2;
        dec = dec/2;
        bin = bin + (remainder*i);
        i = i*10;
    }
    cout<<bin<<endl;
   return 0;
}