#include "fft.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
//int inverse(int n,int N)
//{
//	int bit_w = 0;
//	int tmp = N;
//	while(tmp >>= 1)
//	{
//		bit_w++;
//	}
//	int *h = new int[bit_w];
//	tmp = n;
//	for(int i = 0;i < bit_w;i++)
//	{
//		h[i] = tmp & 0x1;
//		tmp >>= 1;
//	}
//	tmp = 0;
//	for(int i = 0;i < bit_w;i++)
//	{
//		tmp += h[i] << (bit_w - 1 - i);
//	}
//
//	delete[] h;
//	h = 0;
//	return tmp;
//}
int bits_inverse(int n,int N)
{
	int bit_w = 0;
	int tmp = N;
	int tmp_l = 0;
	int tmp_h = 0;
	int new_n = n;
	int xor_l = 0;
	int xor_h = 0;
	while(tmp >>= 1)
	{
		bit_w++;
	}
	tmp = n;
	for(int i = 0;i < bit_w / 2;i++)
	{
		tmp_l = (tmp & (0x1 << i)) >> i;
		tmp_h = (tmp & (0x1 << (bit_w - 1 - i))) >> (bit_w - 1 - i);
		xor_l = (N - 1) ^ (0x1 << i);
		xor_h = (N - 1) ^ (0x1 << (bit_w - 1 - i));
		tmp = (tmp & (xor_l)) & (xor_h);
		new_n = tmp | (tmp_h << i) | (tmp_l << (bit_w - 1 - i));
		tmp = new_n;
	}
	return new_n;
}
void bits_inverse(COMPLEX_STRUCT *pSrcData,int length)
{
	int NV2 = length >> 1;
	int NM1 = length - 1;
	int J = 0;
	int I = 0;
	int K = 0;
	COMPLEX_STRUCT temp = {0,0};
	while(I < NM1)
	{
		if(I < J)
		{
			temp.re = pSrcData[J].re;
			temp.im = pSrcData[J].im;

			pSrcData[J].re = pSrcData[I].re;
			pSrcData[J].im = pSrcData[I].im;

			pSrcData[I].re = temp.re;
			pSrcData[I].im = temp.im;
		}
		K = NV2;

		if(K <= J)
		{
			J -= K;
			K /= 2;
		}
		//else
		//{
			J = J + K;
		//}
		I += 1;
	}
}
void fft(int fft_nbr,COMPLEX_STRUCT *pSrcdata,int inv,COMPLEX_STRUCT *pOutdata)
{
	//注:fft_nbr必须是2的幂次方

	int fft_level = 0;
	int tmp = 0;
	int half_fft_points = fft_nbr / 2;
	int dist_betwn_butterfly = 1;
	int nbr_butterfly = 1;
	int m = 0;
	int k = 0;
	int u = 0;
	int i = 0;
	int j = 0;
	int ip = 0;
	double a = 0.0;
	double b = 0.0;
	COMPLEX_STRUCT sTemp = {0.0,0.0};
	COMPLEX_STRUCT w = {0.0,0.0};
	COMPLEX_STRUCT w1 = {0.0,0.0};
	if(0 != inv)
	{
		for(i = 0;i < fft_nbr;i++)
		{
			pSrcdata[i].im *= -1;
		}
	}
	//首先进行位倒序
	bits_inverse(pSrcdata,fft_nbr);
	//for(i = 0;i < fft_nbr;i++)
	//{
	//	printf("%d:%lf\n",i,pSrcdata[i].re);
	//}
	tmp = fft_nbr;
	while(tmp >>= 1)
	{
		fft_level++;
	}
	for(m = 1;m <= fft_level;m++)
	{
		dist_betwn_butterfly <<= m;
		nbr_butterfly <<= (m - 1);
		//w.re = 1;
		//w.im = 0;

		//w1.re = cos(2.0 * SUL_PI / (1 << m));
		//w1.im = -sin(2.0 * SUL_PI /  (1 << m));

		for(k = 0;k < nbr_butterfly;k++)
		{
			//根据清华大学出版社《数字信号处理教程》中求W的方法
			w.re = cos(2.0 * SUL_PI * (k << (fft_level - m)) / (double)(fft_nbr));
			w.im = -sin(2.0 * SUL_PI * (k << (fft_level - m)) / (double)(fft_nbr));
			for(i = k;i + nbr_butterfly < fft_nbr;i += dist_betwn_butterfly)
			{
				ip = i + nbr_butterfly;
				sTemp.re = pSrcdata[ip].re * w.re - pSrcdata[ip].im * w.im;
				sTemp.im = pSrcdata[ip].re * w.im + pSrcdata[ip].im * w.re;

				pSrcdata[ip].re = pSrcdata[i].re - sTemp.re;
				pSrcdata[ip].im = pSrcdata[i].im - sTemp.im;

				pSrcdata[i].re = pSrcdata[i].re + sTemp.re;
				pSrcdata[i].im = pSrcdata[i].im + sTemp.im;
			}
			//a = w.re * w1.re - w.im * w1.im;
			//b = w.re * w1.im + w.im * w1.re;
			//w.re = a;
			//w.im = b;
		}
		//nbr_butterfly *= 2;
	}
	if(0 != inv)
	{
		for(i = 0;i < fft_nbr;i++)
		{
			pSrcdata[i].im *= -1;
		}
	}
	if(NULL != pOutdata)
	{
		memcpy(pOutdata,pSrcdata,fft_nbr * sizeof(COMPLEX_STRUCT));
	}
}