#include <stdio.h>
#include <string.h>
#define MAX 100

int L[MAX];

int max(int num1,int num2){
  return(num1 > num2) ? num1 : num2;
}

int LIS(int num[],int i){
  int maior;
  if (L[i] != -1)
    return L[i];
  else if (i==0)
    return L[i] = 1;
  else{
    maior = 1;
    for(int j = 0;j<i;j++){
      if (num[j] < num[i]){
        maior = max(maior,LIS(num,j) + 1);
      }
    }
  }
  return L[i] = maior;
}

int subsequencia(int num[],int n){
  int maior = 1;
  for(int i =0;i<n;i++)
    maior = max(maior,LIS(num,i));
  return maior;
}

int main() {
  memset(L,-1,sizeof(L));

  int num[] = {1,3,2,5,4,8,10,16,11,20}, n = 10;
  int maior = subsequencia(num, n);
  printf("\nMaior subsequencia: %i",maior);
}