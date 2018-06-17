Feigenbaum-Constant

Computation of the Feigenbaum constant delta in different lenguages. The method is bases on the computation of superstable points of f^{2^n}(mu), where mu is the parameter of the family (here we use the logistic map). To compute mu, we use the Newthon method. The objective was to compute the constant with a larger amount of digits than Feigenbaum archived in his article "Quantitative Universality for a Class of Nonlinear Transformations" , and in a "a few minutes" (as he says in that article).

The method is the same in the three codes, but it's implemented in different lenguages:

    C++: This was the first try for the computation. Computes only 7 correct digits of delta, but also saves and shows mu. It uses an unnecessary number of iterations of the Newthon method, but it was the first try, so left it that way. It's impossible to compute more digits with the default precission, so extended precission libraries are needed.

    Matlab: Used because allows the use of extended precission in a very easier way than C++, with the function "vpa". The method shows a larger amunt od correct digits, but the lenguage was to slow for the objectives we wanted to reach. The iterations of the Newthon method were changed to 2 instead of 10, because 2 iterarions were enoght to reach a convinient convergence.

    PARI/GP: This leanguage proved to be very efficient. The time of the calculation it's so much slower than the results archived with Matlab, so that allowed us to calculate more digits. At iteration 25 (f^{2^25}), we have 16 correct digits, so the objective was archived. The delta obtained at this point is 4.669201609102990




