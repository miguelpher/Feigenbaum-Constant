n = 30; /* number of iterations */
\p 45 /* precission  */

mu = vector(n);
a0 = 2; a1 = 1 + sqrt(5); d  = 4;
mu[1] = a0;
mu[2] = a1;


{
for(k = 3, n,
	a = a1 + (a1-a0)/d;
    for (i = 1,2,
        res = 0.5; der = 0;
        for (j = 2,2^(k-1)+1,
           der = res*(1-res) + a*(1-2*res)*der;
           res = a*res*(1-res);
        );
        a = a - (res-0.5)/der;
    );
    d = (a1-a0)/(a-a1);
    time=gettime();
	print(k," ",d,"    done in ",time," ms.");
    a0 = a1; a1 = a;
    mu[k] = a;
);
}
