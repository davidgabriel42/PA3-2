#include <stdio.h>
#include <math.h>    /* for pow(x, y) */
#include "type.h"
#define n_dim 5
#define bits_per_dim 10

double decode(IPTR pj, int index, int size);
double binToDec(int *chrom, int l);

double eval(POPULATION *p, IPTR pj) 
     /* Called from gen.c and init.c */
{

  double val;
  //double square = 0.0;

  val = decode(pj, 0, p->lchrom); 
  //square = val * val;

  return val;
}

double decode(IPTR pj, int index, int size)
{

  return ((double) binToDec(&(pj->chrom[0]), size));
}

double binToDec(int *chrom, int l)
{
  double x[n_dim];
  int i;
  int j = 0;
  int k = 0;
  double prod;
  double sum = 0;
  float x1, x2;
  prod = 0.0;

  for(i = 0; i < l; i++)
  {
    
    //j = i % bits_per_dim;
    if (i == 11	)
    {
      x1 = prod;
      prod = 0;
    }

    if (i == 23 )

    {
      x2 = prod;
      prod = 0;
    }

    prod += (chrom[i] == 0 ? 0.0 : pow((double)2.0, (double) j))/1024;
    printf("x1: %2.2f", x1);
    printf( "x2: %2.2f\n", x2);
  }
//  printf("sum-sqs: %2.2f ", sum);
  sum = 100*pow((pow(x1,2)-x2),2) + pow((1-x1),2);
  return sum;
}

void decToBin(int ad, int *barray, int size)
{
  int i, t;

  t = ad;
  for(i = 0; i < size; i++){
    barray[i] = t%2;
    t = t/2;

  }
}
