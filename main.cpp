#include<iostream>
#include"String.h"
using namespace std;
int main()
{
    String s1{"Hello"},s2{"World"},s3{" "};
    s1+=s3;//Hello 
    s1+=s2;
    cout<<s1; //Hello World
    return 0;
}
