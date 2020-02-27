#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	float ZeroRate[20];
	float SwapRate[20];
	float discount[20];
	float P=100;
	float C;
	int n=7;
	
	SwapRate[0]=0.0226;
	SwapRate[1]=0.02275;
	SwapRate[2]=0.02285;
	SwapRate[4]=0.02355;
	SwapRate[3]=(SwapRate[4]-SwapRate[2])/2 +SwapRate[2]; //內插法 
	SwapRate[6]=0.0244;
	SwapRate[5]=(SwapRate[6]-SwapRate[4])/2 +SwapRate[4]; //內插法 
	for(int i=0; i<n; i++)
	{
		printf("第%d年交換利率:%f \n",i+1,SwapRate[i]);
	}
	
	ZeroRate[0]= ((P+P*SwapRate[0]) / P)-1;
	printf("第一年的零息利率:%f\n",ZeroRate[0]);
	discount[0]= 1+ZeroRate[0];
	
	ZeroRate[1]= pow( (P+P*SwapRate[1]) / (P-(P*SwapRate[1]/ discount[0])) ,0.5)-1 ;        
	printf("第二年的零息利率:%f\n",ZeroRate[1]);
	discount[1]= pow(1+ZeroRate[1],2);
	
	ZeroRate[2]=pow( (P+P*SwapRate[2]) / (P-(P*SwapRate[2]/ discount[0])-(P*SwapRate[2]/ discount[1])) ,0.333)-1;
	printf("第三年的零息利率:%f\n",ZeroRate[2]);
	discount[2]= pow(1+ZeroRate[2],3);
	
	ZeroRate[3]=pow( (P+P*SwapRate[3]) / (P-(P*SwapRate[3]/ discount[0])-(P*SwapRate[3]/ discount[1])-(P*SwapRate[3]/ discount[2])) ,0.25)-1;
	printf("第四年的零息利率:%f\n",ZeroRate[3]);
	discount[3]= pow(1+ZeroRate[3],4);
	
	ZeroRate[4]=pow( (P+P*SwapRate[4]) / (P-(P*SwapRate[4]/ discount[0])-(P*SwapRate[4]/ discount[1])-(P*SwapRate[4]/ discount[2])-(P*SwapRate[4]/ discount[3])) ,0.2)-1;
	printf("第五年的零息利率:%f\n",ZeroRate[4]);
	discount[4]= pow(1+ZeroRate[4],5);
	
	ZeroRate[5]=pow( (P+P*SwapRate[5]) / (P-(P*SwapRate[5]/ discount[0])-(P*SwapRate[5]/ discount[1])-(P*SwapRate[5]/ discount[2])-(P*SwapRate[5]/ discount[3])-(P*SwapRate[5]/ discount[4])) ,0.2)-1;
	printf("第六年的零息利率:%f\n",ZeroRate[5]);
	discount[5]= pow(1+ZeroRate[5],6);
	
	ZeroRate[6]=pow( (P+P*SwapRate[6]) / (P-(P*SwapRate[6]/ discount[0])-(P*SwapRate[6]/ discount[1])-(P*SwapRate[6]/ discount[2])-(P*SwapRate[6]/ discount[3])-(P*SwapRate[6]/ discount[4])-(P*SwapRate[6]/ discount[5])) ,0.166)-1;
	printf("第七年的零息利率:%f\n",ZeroRate[6]);
	
	return 0;
}
