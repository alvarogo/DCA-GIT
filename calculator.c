#include <stdio.h>

void add ();
void sub ();
void mul ();
void div ();
void sqr ();
void prime_factorization ();
void factorial ();
void sel_func (int);

// Pureba del hook prepare-commit-msg
int main (void)
{
        int s;
    
        Input:
           printf("Introduce un número [ +(1), -(2), *(3), /(4), ^(5), factirización primos(6), !(7)] : ");
           scanf("%d",&s);
         
           if ((s > 7) | (s < 1)){
                  printf("Por favor, introduzca una opción válida\n");
                  goto Input;
           }
           sel_func (s);
    
           goto Input;
}

void sel_func (int s)
{
        void (*fptr)(void);
        switch (s){
        case 1:
                fptr = add;
                break;
        case 2:
                fptr = sub;
                break;
        case 3:
                fptr = mul;
                break;
        case 4:
                fptr = div;
                break;
        case 5:
                fptr = sqr;
                break;
        case 6:
                fptr = prime_factorization;
                break;
        case 7:
                fptr = factorial;
                break;        
        }
    
        fptr();
}

void add ()
{
        int a, b;
        
        printf("Introduce dos números : ");
        scanf("%d%d", &a,&b);
        printf("Result = %d\n", a + b);
}

void sub ()
{
        int a, b;
        
        printf("Introduce dos números : ");
        scanf("%d%d", &a,&b);
        printf("Result = %d\n" , a - b);
}

void mul ()
{
        int a, b;
      
        printf("Introduce dos números : ");
        scanf("%d%d", &a,&b);
        printf("Result = %d\n", a * b);
}

void div ()
{
        int a, b;
        
        printf("Introduce dos números : ");
        scanf("%d%d", &a,&b);
        printf("Result = %d\n", a / b);
}

void sqr (){
        int exp, base, i;
        int result = 1;
    
        printf("Introduce base : ");
        scanf("%d",&base);
        printf("Introduce exp : ");
        scanf("%d",&exp);
    
        for (i = 0; i < exp; ++i)
                result *= base;
            
        printf("%d^%d = %d\n",
                    base,exp,result);
}

void prime_factorization ()
{
        int n; 
        while (1){ 
                printf("Introduce un número : "); 
                scanf("%d",&n); 
       
             if(n < 2)
                    return; 
        }
        
        int p = 2; 
        int primes[20]; 
        int index = 0; 
        int i; 
        
        while (1 != n){ 
                if (0 == (n%p)){ 
                        n = n/p; 
                        primes[index] = p; 
                        ++index; 
                        p = 2; 
                } else {
                    ++p;
                }
        } 
        
        if(1 == index){
                printf("Número primo\n"); 
        } else { 
                for (i = 0; i < index - 1; ++i)
                        printf("%d*", primes[i]);

                printf("%d\n", primes[i]);
          }  
        
          return;    
        
}

void factorial ()
{
        int a, b;
        int sum = 1;
    
        printf("Introduce un número : ");
        scanf("%d", &b);
    
        for (a = 1; a <= b; ++a)
                    sum *= a;
        
        printf("%d!=%d\n",b,sum);
}
