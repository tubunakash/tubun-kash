    #include <stdio.h>
    #include <math.h>
    int main ()
     {
        int t,p,s;
        float v,x;
        scanf ("%u", &t);
        for(;t>0;t--)
         {
            scanf ("%u %u", &p,&s);
            x = (float)p/12 - sqrt(p*p-24*s)/12;
            v = x*(x*x-(x*p/4)+s/2);
            printf ("%.2f\n", v);
         }
        return 0;
     }
