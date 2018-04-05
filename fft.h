#ifndef _FFT_H_
#define _FFT_H_
#define SUL_PI 3.1415926535897932384626433832795
typedef struct
{
	double re;
	double im;
}COMPLEX_STRUCT;
int bits_inverse(int n,int N);
void bits_inverse(COMPLEX_STRUCT *pSrcData,int length);
void fft(int fft_nbr,COMPLEX_STRUCT *pSrcdata,int inv,COMPLEX_STRUCT *pOutdata);
#endif