// increaser
#include <iostream>
using namespace std;
void increase (void* data, int psize)
{
    if ( psize == sizeof(char) )
    { char* pchar; pchar=(char*)data; ++(*pchar); }
    else if (psize == sizeof(int) )
    { int* pint; pint=(int*)data; ++(*pint); }
    else if (psize == sizeof(long) )
    { long* plong; plong=(long*)data; ++(*plong); }
}
int main ()
{
    char a = 'x';
    int b = 1602;
    long c = 184736;
    increase (&a,sizeof(a));
    increase (&b,sizeof(b));
    increase (&c,sizeof(c));
    cout << a << ", " << b << ", " << c << endl;
    return 0;
}