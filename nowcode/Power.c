class Solution {
public:
    double Power(double base, int exponent) {
    if((base-0.0>-0.00001)&&(base-0.0<0.00001))
        return 0;
    if(exponent==0)
    {
        return 1;
    }
     else if(exponent==1)
    {
        return base;
    }  
   double base1=1.0;
   int exp=exponent;
   if(exponent<0)
   {
     exp=-exponent;
   }
     for (int i=0;i<exp;i++)
     {
        base1*=base;
     }  
      if (exponent<0)
      {
           base1=1.0/base1;
      } 
   return base1;
    }
};
