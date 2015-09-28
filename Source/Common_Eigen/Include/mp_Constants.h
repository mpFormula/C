
#define mp_const_log2 1
#define mp_const_pi 2
#define mp_const_euler 3
#define mp_const_catalan 4

#define mp_get_DefaultRoundingMode 1
#define mp_put_DefaultRoundingMode 2
#define mp_get_Emin 3
#define mp_put_Emin 4
#define mp_get_Emax 5
#define mp_put_Emax 6
#define mp_get_EminMin 7
#define mp_get_EminMax 8
#define mp_get_EmaxMin 9
#define mp_get_EmaxMax 10

#define mp_get_UnderflowFlag 11
#define mp_put_UnderflowFlag 12
#define mp_get_OverflowFlag 13
#define mp_put_OverflowFlag 14
#define mp_get_NanFlag 15
#define mp_put_NanFlag 16
#define mp_get_InexactFlag 17
#define mp_put_InexactFlag 18
#define mp_get_ErangeFlag 19
#define mp_put_ErangeFlag 20
#define mp_mpfr_clear_flags 21

#define mp_get_Prec2 31
#define mp_put_Prec2 32
#define mp_get_Prec10 33
#define mp_put_Prec10 34

#define mp_setZero 1
#define mp_setOnes 2
#define mp_setIdentity 3
#define mp_setRandom 4
#define mp_transposeInPlace 5
#define mp_reverseInPlace 6
#define mp_Resize 7
#define mp_conservativeResize 8
#define mp_setRandom_nm 9
#define mp_FillLinear 10
#define mp_setNan 11
#define mp_setInfinity 12
#define mp_setMinusInfinity 13
#define mp_setMinusZero 14
#define mp_setRandomSymmetric 15

#define mp_asDiagonal 1
#define mp_adjoint 2
#define mp_conjugate 3
#define mp_transpose 4
#define mp_reverse 5
#define mp_replicate 6
#define mp_ResizeLike 7
#define mp_RandomMatrix 8
#define mp_RandomSymmetricMatrix 9

#define mp_const_mpType_Single 1
#define mp_const_mpType_Double 2
#define mp_const_mpType_LongDouble 3
#define mp_const_mpType_Mpfr 4
#define mp_const_mpType_Mpfi 5
#define mp_const_mpType_Mpdec 6
#define mp_const_mpType_Mpq 7
#define mp_const_mpType_Arb 8
#define mp_const_mpType_Fmpz 9
#define mp_const_mpType_Mpascii 10


#define mp_const_mpType_cplx_Single -1
#define mp_const_mpType_cplx_Double -2
#define mp_const_mpType_cplx_LongDouble -3
#define mp_const_mpType_cplx_Mpfr -4
#define mp_const_mpType_cplx_Mpfi -5
#define mp_const_mpType_cplx_Mpdec -6
#define mp_const_mpType_cplx_Arb -7
#define mp_const_mpType_cplx_Mpq -8
#define mp_const_mpType_cplx_Fmpz -9
#define mp_const_mpType_cplx_Mpascii -10


#define mp_const_plus 1
#define mp_const_minus 2
#define mp_const_cwiseProduct 3
#define mp_const_cwiseQuotient 4
#define mp_const_MatrixProduct 5
#define mp_const_DotProduct 6

#define mp_const_plus_scalar 7
#define mp_const_minus_scalar 8
#define mp_const_times_scalar 9
#define mp_const_div_scalar 10

#define mp_const_op_pow 11
#define mp_const_op_Mod 12
#define mp_const_op_IntDiv 13
#define mp_const_op_AND 14
#define mp_const_op_OR 15
#define mp_const_op_XOR 16



#define mp_const_plus_i 1
#define mp_const_minus_i 2
#define mp_const_minus_i_neg 3
#define mp_const_times_i 4
#define mp_const_div_i 5
#define mp_const_div_i_inv 6
#define mp_const_op_pow_i 7
#define mp_const_op_RSH 8
#define mp_const_op_LSH 9





#define mp_const_minCoeff_Index 1
#define mp_const_maxCoeff_Index 2


#define mp_const_sum 1
#define mp_const_prod 2
#define mp_const_mean 3
#define mp_const_minCoeff 4
#define mp_const_maxCoeff 5
#define mp_const_squaredNorm 6
#define mp_const_Norm 7
#define mp_const_stableNorm 8
#define mp_const_lpNorm1 9
#define mp_const_lpNormInf 10


#define mp_const_full_matrix 1
#define mp_const_rowwise 2
#define mp_const_colwise 3

#define mp_const_All 1
#define mp_const_Any 2
#define mp_const_Count 3

#define mp_const_GT 1
#define mp_const_LT 2
#define mp_const_LE 3
#define mp_const_GE 4
#define mp_const_EQ 5
#define mp_const_NE 6


#define mp_const_block 1
#define mp_const_topLeftCorner 2
#define mp_const_bottomLeftCorner 3
#define mp_const_topRightCorner 4
#define mp_const_bottomRightCorner 5
#define mp_const_topRows 6
#define mp_const_bottomRows 7
#define mp_const_leftCols 8
#define mp_const_rightCols 9
#define mp_const_diagonal 10
#define mp_const_middleRows 11
#define mp_const_middleCols 12
#define mp_const_triangularView 13

#define mp_const_Upper 1
#define mp_const_Lower 2
#define mp_const_StrictlyUpper 3
#define mp_const_StrictlyLower 4
#define mp_const_UnitUpper 5
#define mp_const_UnitLower 6



#define mp_const_pdf 1
#define mp_const_cdf_P 2
#define mp_const_cdf_Q 3
#define mp_const_cdf_Pinv 4
#define mp_const_cdf_Qinv 5



#define mp_const_cxsc_Sgn 1
#define mp_const_cxsc_Neg 2
#define mp_const_cxsc_Inv 3
#define mp_const_cxsc_Abs 4
#define mp_const_cxsc_Abs2 5
#define mp_const_cxsc_Sqrt 6
#define mp_const_cxsc_Exp 7
#define mp_const_cxsc_Exp2 8
#define mp_const_cxsc_Exp10 9
#define mp_const_cxsc_Log 10
#define mp_const_cxsc_Log2 11
#define mp_const_cxsc_Log10 12
#define mp_const_cxsc_Sin 13
#define mp_const_cxsc_Cos 14
#define mp_const_cxsc_Tan 15
#define mp_const_cxsc_Sinh 16
#define mp_const_cxsc_Cosh 17
#define mp_const_cxsc_Tanh 18
#define mp_const_cxsc_Asin 19
#define mp_const_cxsc_Acos 20
#define mp_const_cxsc_Atan 21
#define mp_const_cxsc_Asinh 22
#define mp_const_cxsc_Acosh 23
#define mp_const_cxsc_Atanh 24
#define mp_const_cxsc_Ceil 25
#define mp_const_cxsc_Floor 26
#define mp_const_cxsc_Trunc 27
#define mp_const_cxsc_Round 28
#define mp_const_cxsc_Log1p 29
#define mp_const_cxsc_Expm1 30
#define mp_const_cxsc_Cbrt 31
#define mp_const_cxsc_Sqrt1pm1 32
#define mp_const_cxsc_Sinc_pi 33
#define mp_const_cxsc_Sinhc_pi 34
#define mp_const_cxsc_Erf 35
#define mp_const_cxsc_Erf_inv 36
#define mp_const_cxsc_Erfc 37
#define mp_const_cxsc_Erfc_inv 38
#define mp_const_cxsc_Tgamma 39
#define mp_const_cxsc_LGamma 40

#define mp_const_cxsc_sqr 41
#define mp_const_cxsc_x2py2 42
#define mp_const_cxsc_x2my2 43
#define mp_const_cxsc_Sqrt_n 44
#define mp_const_cxsc_Sqrt_r 45
#define mp_const_cxsc_nth_root 46
#define mp_const_cxsc_sqrt1px2 47
#define mp_const_cxsc_sqrt1mx2 48
#define mp_const_cxsc_sqrtx2m1 49
#define mp_const_cxsc_Atan2 50
#define mp_const_cxsc_acot 51
#define mp_const_cxsc_sinh 52
#define mp_const_cxsc_cosh 53
#define mp_const_cxsc_Hypot 54
#define mp_const_cxsc_Power 55
#define mp_const_cxsc_Pow 56
#define mp_const_cxsc_Agm 57
#define mp_const_cxsc_lnHypot 58
#define mp_const_cxsc_ln_Sin 59
#define mp_const_cxsc_ln_Cos 60
#define mp_const_cxsc_Cot 61
#define mp_const_cxsc_expx2m1 62
#define mp_const_cxsc_expmx2 63
#define mp_const_cxsc_expmx2m1 64
#define mp_const_cxsc_gamma_D 65
#define mp_const_cxsc_acoth 66
#define mp_const_cxsc_coth 67
#define mp_const_cxsc_acoshp1 68
#define mp_const_cxsc_csc 69
#define mp_const_cxsc_sec 70
#define mp_const_cxsc_csch 71
#define mp_const_cxsc_sech 72
#define mp_const_cxsc_ln_sqrtxp1_2y2 73
#define mp_const_cxsc_gamma_reci 74
#define mp_const_cxsc_digamma 75
#define mp_const_cxsc_lngamma 76
#define mp_const_cxsc_factorial 77
#define mp_const_cxsc_zeta 78
#define mp_const_cxsc_Ei 79
#define mp_const_cxsc_Li2 80
#define mp_const_cxsc_J0 81
#define mp_const_cxsc_J1 82
#define mp_const_cxsc_Jn 83
#define mp_const_cxsc_Y0 84
#define mp_const_cxsc_Y1 85
#define mp_const_cxsc_Yn 86

#define mp_const_cxsc_Conj 87
#define mp_const_cxsc_Real 88
#define mp_const_cxsc_Imag 89
#define mp_const_cxsc_Arg 90
#define mp_const_cxsc_Sqrt_all 91
#define mp_const_cxsc_nth_root_all 92
#define mp_const_cxsc_pow_r 93
#define mp_const_cxsc_pow_c 94

#define mp_const_cxsc_add 95
#define mp_const_cxsc_sub 96
#define mp_const_cxsc_mul 97
#define mp_const_cxsc_div 98
#define mp_const_cxsc_expx2 99

#define mp_const_mpz_Sqrt 1
#define mp_const_mpz_Abs 2
#define mp_const_mpz_Complement 3
#define mp_const_mpz_Neg 4
#define mp_const_mpz_Sgn 5
#define mp_const_mpz_Urandomb 6
#define mp_const_mpz_Urandomm 7
#define mp_const_mpz_Nextprime 8
#define mp_const_mpz_Rrandomb 9
#define mp_const_mpz_Factorial 10
#define mp_const_mpz_Fibonacci 11
#define mp_const_mpz_Lucas 12
#define mp_const_mpz_PopCount 13

#define mp_const_mpz_Gcd 14
#define mp_const_mpz_SqrtRem 15
#define mp_const_mpz_AND 16
#define mp_const_mpz_IOR 17
#define mp_const_mpz_XOR 18
#define mp_const_mpz_Mod 19
#define mp_const_mpz_Lcm 20
#define mp_const_mpz_BinCoeff 21
#define mp_const_mpz_Fibonacci2 22
#define mp_const_mpz_Lucas2 23
#define mp_const_mpz_Pow 24
#define mp_const_mpz_Root 25
#define mp_const_mpz_LSH 26
#define mp_const_mpz_RSH 27
#define mp_const_mpz_Scan0 28
#define mp_const_mpz_Scan1 29
#define mp_const_mpz_TestBit 30
#define mp_const_mpz_ComBit 31
#define mp_const_mpz_HamDist 32
#define mp_const_mpz_Jacobi 33
#define mp_const_mpz_Kronecker 34
#define mp_const_mpz_Legendre 35

#define mp_const_mpz_PowMod 36
#define mp_const_mpz_RootRem 37
#define mp_const_mpz_RemoveFactor 38
#define mp_const_mpz_InvertMod 39

#define mp_const_mpz_GcdExt 40

#define mp_const_mpz_cdiv_q 41
#define mp_const_mpz_cdiv_r 42
#define mp_const_mpz_cdiv_q_2exp 43
#define mp_const_mpz_cdiv_r_2exp 44
#define mp_const_mpz_cdiv_qr 45


#define mp_const_mpz_fdiv_q 46
#define mp_const_mpz_fdiv_r 47
#define mp_const_mpz_fdiv_q_2exp 48
#define mp_const_mpz_fdiv_r_2exp 49
#define mp_const_mpz_fdiv_qr 50


#define mp_const_mpz_tdiv_q 51
#define mp_const_mpz_tdiv_r 52
#define mp_const_mpz_tdiv_q_2exp 53
#define mp_const_mpz_tdiv_r_2exp 54
#define mp_const_mpz_tdiv_qr 55


// mpz
#define mp_const_IsOdd 1
#define mp_const_IsEven 2
#define mp_const_IsPerfectPower 3
#define mp_const_IsPerfectSquare 4
#define mp_const_fits_ulong 5
#define mp_const_fits_slong 6
#define mp_const_fits_uint 7
#define mp_const_fits_sint 8
#define mp_const_fits_ushort 9
#define mp_const_fits_sshort 10
// mpfr
#define mp_const_isInf 11
#define mp_const_isNan 12
#define mp_const_isNumber 13
#define mp_const_isZero 14
#define mp_const_isRegular 15
#define mp_const_isInteger 16
// mpfi
#define mp_const_IsPos 17
#define mp_const_IsStrictlyPos 18
#define mp_const_IsNonNeg 19
#define mp_const_IsNeg 20
#define mp_const_IsStrictlyNeg 21
#define mp_const_IsNonPos 22
#define mp_const_HasZero 23
//#define mp_const_IsBounded 24
#define mp_const_IsEmpty 25


// mpz
#define mp_const_IsDivisible 1
#define mp_const_IsDivisible_2exp 2
#define mp_const_IsDefinitelyComposite 3
#define mp_const_IsDefinitelyPrime 4
#define mp_const_IsProbablyPrime 5
// mpfr
#define mp_const_IsUnordered 6
// mpfi
#define mp_const_IsInside 7
#define mp_const_IsStrictlyInside 8

// mpz
#define mp_const_IsCongruent 1
#define mp_const_IsCongruent_2exp 2





#define mp_const_Sgn 1
#define mp_const_Neg 2
#define mp_const_Inv 3
#define mp_const_Abs 4
#define mp_const_Abs2 5
#define mp_const_Sqrt 6
#define mp_const_Exp 7
#define mp_const_Exp2 8
#define mp_const_Exp10 9
#define mp_const_Log 10
#define mp_const_Log2 11
#define mp_const_Log10 12
#define mp_const_Sin 13
#define mp_const_Cos 14
#define mp_const_Tan 15
#define mp_const_Sinh 16
#define mp_const_Cosh 17
#define mp_const_Tanh 18
#define mp_const_Asin 19
#define mp_const_Acos 20
#define mp_const_Atan 21
#define mp_const_Asinh 22
#define mp_const_Acosh 23
#define mp_const_Atanh 24
#define mp_const_Ceil 25
#define mp_const_Floor 26
#define mp_const_Trunc 27
#define mp_const_Round 28
#define mp_const_Log1p 29
#define mp_const_Expm1 30
#define mp_const_Cbrt 31
#define mp_const_Sqrt1pm1 32
#define mp_const_Sinc_pi 33
#define mp_const_Sinhc_pi 34
#define mp_const_Erf 35
#define mp_const_Erf_inv 36
#define mp_const_Erfc 37
#define mp_const_Erfc_inv 38
#define mp_const_Tgamma 39
#define mp_const_LGamma 40



// Note: Tgamm1pm1 to Ellint are missing !!!
// Except in Double !!!

#define mp_const_Tgamma1pm1 41
#define mp_const_Digamma 42
#define mp_const_Factorial 43
#define mp_const_Unchecked_Factorial 44
#define mp_const_Double_Factorial 45
#define mp_const_Expint_ei 46
#define mp_const_Zeta 47
#define mp_const_Ellint2 48
#define mp_const_Ellint_1_K 49





#define mp_const_Powm1 50
#define mp_const_Hypot 51
#define mp_const_Ldexp 52
#define mp_const_Frexp 53
#define mp_const_Modf 54
#define mp_const_Pow 55
#define mp_const_Fmod 56
#define mp_const_Atan2 57
#define mp_const_Copysign 58
#define mp_const_Max 59
#define mp_const_Min 60
#define mp_const_Tgamma_ratio 61
#define mp_const_Tgamma_delta_ratio 62
#define mp_const_Gamma_p 63
#define mp_const_Gamma_q 64
#define mp_const_Tgamma_lower 65
#define mp_const_Tgamma_upper 66
#define mp_const_Gamma_p_inv 67
#define mp_const_Gamma_q_inv 68
#define mp_const_Gamma_p_inva 69
#define mp_const_Gamma_q_inva 70
#define mp_const_Gamma_p_derivative 71
#define mp_const_Legendre_q 72
#define mp_const_Laguerre 73
#define mp_const_Hermite 74
#define mp_const_Rising_Factorial 75
#define mp_const_Falling_Factorial 76
#define mp_const_Binomial_Coefficient 78
#define mp_const_Beta 79
#define mp_const_Expint_n 80
#define mp_const_Ellint_3_K 81
#define mp_const_Ellint_2_F 82
#define mp_const_Ellint_1_F 83
#define mp_const_Ellint_rc 84
#define mp_const_Cyl_bessel_j 85
#define mp_const_Cyl_neumann 86
#define mp_const_Cyl_bessel_i 87
#define mp_const_Cyl_bessel_k 88
#define mp_const_Sph_bessel 89
#define mp_const_Sph_neumann 90
#define mp_const_Legendre_p 91

#define mp_const_Ibeta 92
#define mp_const_Ibetac 93
#define mp_const_IBeta_non_normalized 94
#define mp_const_IBetac_non_normalized 95
#define mp_const_Ibeta_inv 96
#define mp_const_Ibetac_inv 97
#define mp_const_Ibeta_inva 98
#define mp_const_Ibetac_inva 99
#define mp_const_Ibeta_invb 100
#define mp_const_Ibetac_invb 101
#define mp_const_IBeta_derivative 102
#define mp_const_Legendre_p_m 103
#define mp_const_Legendre_m 104
#define mp_const_Ellint_rf 105
#define mp_const_Ellint_rd 106
#define mp_const_Ellint_3_F 107

#define mp_const_Ellint_rj 108
#define mp_const_Spherical_harmonic_r 109
#define mp_const_Spherical_harmonic_i 110
#define mp_const_Hermite_next 111
#define mp_const_Laguerre_next 112
#define mp_const_Legendre_next 113


#define mp_const_Bernoullidist 114
#define mp_const_Cdist 115
#define mp_const_Exponentialdist 116
#define mp_const_Poissondist 117
#define mp_const_Raleighdist 118
#define mp_const_Tdist 119
#define mp_const_Betadist 120
#define mp_const_Binomialdist 121
#define mp_const_Cauchydist 122
#define mp_const_Extreme_valuedist 123
#define mp_const_Fdist 124
#define mp_const_Gammadist 125
#define mp_const_Laplacedist 126
#define mp_const_Logisticdist 127
#define mp_const_Lognormaldist 128
#define mp_const_Negative_binomialdist 129
#define mp_const_Cdistn 130
#define mp_const_Tdistn 131
#define mp_const_Ndist 132
#define mp_const_Paretodist 133
#define mp_const_Weibulldist 134
#define mp_const_Uniformdist 135
#define mp_const_Hypergeometricdist 136
#define mp_const_Fdistn 137
#define mp_const_Betadistn 138
#define mp_const_Triangulardist 139

#define mp_const_Dim 140
#define mp_const_Ilogb 141
#define mp_const_Logb 142
#define mp_const_Scalbn 143
#define mp_const_Scalbln 144

#define mp_const_Lround 145
#define mp_const_Llround 146
#define mp_const_Rint 147
#define mp_const_Lrint 148
#define mp_const_Llrint 149
#define mp_const_Nearbyint 150
#define mp_const_Remainder 151
#define mp_const_Fabs 152
#define mp_const_Nextafter 153
#define mp_const_Nexttoward 154
#define mp_const_Remquo 155
#define mp_const_Fma 156

#define mp_const_Real 157
#define mp_const_Imag 158
#define mp_const_Arg 159
#define mp_const_cplx_Norm 160

#define mp_const_Conj 161
#define mp_const_Polar 162
#define mp_const_Proj 163



