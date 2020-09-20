# Files
| File Name | Creation Date  |
|--|--|
| bisection.c | Mar 25, 2017 |
| rFalsi_nRaphson.c | Apr 8, 2017|
| gauss_seidel.c | Apr 20, 2017 |
| lagrange_gNewton.c | Jun 5, 2017 |

please use `-lm` while compilation if needed

## bisection.c

	iter, E, xL, xR:  1000 0.0001 -8 2
	coeff #4 (a4 * x^4): 4
	coeff #3 (a3 * x^3): -9
	coeff #2 (a2 * x^2): 4
	coeff #1 (a1 * x^1): 1
	coeff #0 (a0 * x^0): 0


	f(xL)=yL                         f(xM)=yM                         f(xR)=yR
	---------
	iter, E, xL, xR:  1000 0.0001 -8 2
	coeff #4 (a4 * x^4): 4
	coeff #3 (a3 * x^3): -9
	coeff #2 (a2 * x^2): 4
	coeff #1 (a1 * x^1): 1
	coeff #0 (a0 * x^0): 0


	f(xL)=yL                         f(xM)=yM                         f(xR)=yR
	---------
	f(-8.00000)=21240.00000         , f(-3.00000)=600.00000           , f(2.00000)=10.00000
	f(-3.00000)=600.00000           , f(-0.50000)=1.87500             , f(2.00000)=10.00000
	...
	f(1.00009)=-0.00018            , f(1.00024)=-0.00049
	f(0.99994)=0.00012             , f(1.00002)=-0.00003            , f(1.00009)=-0.00018

	Real Root @ 1.000015 in [-8.000000,2.000000]

## rFalsi_nRaphson.c
### Regula Falsi
    [1] Regula Falsi
    [2] Newton Raphson
    (press 1 or 2)
    1
    coeff #4 (a4 * x^4): 2
    coeff #3 (a3 * x^3): 1
    coeff #2 (a2 * x^2): 3
    coeff #1 (a1 * x^1): -5
    coeff #0 (a0 * x^0): 1
    iter, E:  10000 0.0001
    xL, xR:  0 1


    f(xL)=yL                         f(xM)=yM                         f(xR)=yR
    ----------------------------------------------------------------------------------------
    f(0.00000)=1.00000             , f(-1.00000)=10.00000            , f(1.00000)=2.00000
    f(-1.00000)=10.00000            , f(1.50000)=13.75000            , f(1.00000)=2.00000
    ...
    f(0.75176)=0.00027             , f(0.75173)=0.00012             , f(1.00000)=2.00000
    f(0.75173)=0.00012             , f(0.75172)=0.00005             , f(1.00000)=2.00000

    Real Root @ 0.751716 in [0.000000,1.000000]
### Newton Raphson
    [1] Regula Falsi
    [2] Newton Raphson
    (press 1 or 2)
    2
    coeff #4 (a4 * x^4): 5
    coeff #3 (a3 * x^3): 1
    coeff #2 (a2 * x^2): 2
    coeff #1 (a1 * x^1): -8
    coeff #0 (a0 * x^0): 1
    iter, E:  1000 0.000001
    x0:  0

    f(0.00000)=1.00000
    f(0.12500)=0.03442
    f(0.12964)=0.00006
    f(0.12965)=0.00000

    Real Root @ 0.129651

## lagrange_gNewton.c
    Number of samples: 5
    x value #0: 2
    x value #1: 4
    x value #2: 6
    x value #3: 8
    x value #4: 10
    y value #0: 6
    y value #1: 24
    y value #2: 58
    y value #3: 108
    y value #4: 174
    x value to compute: 12

    Lagrange:
        Function:
            (4.0000) * x^0 + (-3.0000) * x^1 + (2.0000) * x^2

        Result:
            256.0000

    Gregory-Newton:
        Function:
            (4.0000) * x^0 + (-3.0000) * x^1 + (2.0000) * x^2

        Result:
            256.0000

## gauss_seidel.c
    # variables: 3
    row 1, column 1: 54
    row 1, column 2: 72
    row 1, column 3: 5
    row 2, column 1: 586
    row 2, column 2: 547
    row 2, column 3: 5287
    row 3, column 1: 5468
    row 3, column 2: 8645
    row 3, column 3: 55
    value #1: 112
    value #2: 5454
    value #3: 8778

    ---------------------@

    54.00   72.00    5.00    | 112.00
    586.00  547.00 5287.00    |5454.00
    5468.00 8645.00   55.00    |8778.00

    ---------------------@

    54.00   72.00    5.00    | 112.00
    0.00 -234.33 5232.74    |4238.59
    0.00 1354.33 -451.30    |-2563.04

    ---------------------@

    54.00   72.00    5.00    | 112.00
    0.00 -234.33 5232.74    |4238.59
    0.00    0.00 29791.41    |21933.97

    ---------------------@

    x0: 4.20
    x1: -1.65
    x2: 0.74

    c0: 112.000000  c0': 111.999992
    c1: 5454.000000  c1': 5454.000000
    c2: 8778.000000  c2': 8777.999023