#include<iostream>
#define maxValue 0x3f3f3f3f
int main()
{
    int n;
    while(std::cin>>n)
    {
        int *a=new int[n];
        int *step=new int[2*n];
        for(int i=0;i<2*n;++i)
        {
            if(i<n)
                std::cin>>a[i];
            if(i==0)
                step[i]=0;
            else
                step[i]=maxValue;
        }
        for(int i=0;i<n;++i)
        {
            int w=a[i];
            if(w==0)
                continue;
            
            for(int j=1;j<=w;++j)
            {
                step[i+j]=((step[i]+1>step[i+j])?step[i+j]:step[i]+1);
            }
        }
        if(step[n]>=maxValue)
                std::cout<<-1<<std::endl;
            else
                std::cout<<step[n]<<std::endl;
            delete[] a;
            delete[] step;
    }
    return 0;
}
