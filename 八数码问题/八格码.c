#include<stdio.h>

void convert(int *m,int *n)
{
	int t;
	t=*m;
	*m=*n;
	*n=t;
}

void dayin(int *a)
{
	int i;
	for(i=0;i<9;i++)
	{
		if((i==3)||(i==6))
		{
			printf("\n");
		}
		
		if(a[i]==0)
		{
			printf("   ");		
		}
		else
		{
			printf("  %d",a[i]);	
		}
		
		if(i==8)
		{
			printf("\n");
		}
	}
	printf("\n");
	
}

void step1(int *a)
{

	if(a[2]==0)
	{
		if(a[1]==1)
		{
			convert(&a[2],&a[5]);
		}
		else
		{
			convert(&a[2],&a[1]);
		}
	}
	else if(a[2]==1)
	{
		if(a[1]==0)
		{
			convert(&a[2],&a[5]);
		}
		else
		{
			convert(&a[2],&a[1]);
		}
	}
	else
	{
		
	}
	dayin(a);
	printf("step1 ends\n");
	printf("=====================\n");
	
}

void lunzhuan(int f_num,int org[],int *a,int o_num,int p_num)
//f_num转停的数,o_num需要循环轮转的个数,p_num0在九宫格中的位置 1，b，8,0 
{
	int i;
	int t1=0;
	int t2=0;
	int order[o_num];
	for(i=0;i<9;i++)
	{
		if(a[i]==0)
		{
			t1=i;
			break;
			
		}

	}
	
	//printf("t1=%d\n",t1);
	//dayin(a);
	printf("\n");
	for(i=0;i<o_num;i++)
	{
		if(org[i]==t1)
		{
			t2=i;
			break;
		}		
	}
	
//	printf("t2=%d\n",t2);
//	printf("\n");
	
	for(i=0;i<o_num;i++)
	{
		if((t2+i)<o_num)
		{
			order[i]=org[t2+i];
			
		}
		else
		{
			order[i]=org[t2+i-o_num];
		}
	}
	
/*	for(i=0;i<o_num;i++)
	{
		printf("%d\n",order[i]);
	}
	printf("\n");*/
	i=0;
	while(a[p_num]!=f_num)
	{
		if((i+1)==o_num)
		{
			convert(&a[order[i]],&a[order[0]]);
			i=0;
			
		}
		else
		{
			convert(&a[order[i]],&a[order[i+1]]);
			i++;
		}
		
		dayin(a);
	}
		
}

void step2(int *a)
{
	int org[8]={0,3,6,7,8,5,4,1};	
	lunzhuan(1,org,a,8,0);
	printf(" step2 ends\n");
	printf("=====================\n");
}

void step3(int *a)
{
	int org[8]={1,4,3,6,7,8,5,2};
	lunzhuan(2,org,a,8,1);
	printf("step3 ends\n");
	printf("=====================\n");
}

void step4(int *a)
{
	int org[6]={5,4,3,6,7,8};
	lunzhuan(3,org,a,6,4);
	printf("step4 ends\n");
	printf("=====================\n");
}

void step5(int *a)
{
	int org[]={3,0,1,4,5,2,1,0,3};
	lunzhuan(3,org,a,9,2);
	convert(&a[0],&a[1]);
	dayin(a);
	convert(&a[0],&a[3]);
	dayin(a);
	printf("step5 ends\n");
	printf("=====================\n");
}

void step6(int *a)
{
	int org[]={5,4,3,6,7,8};
	lunzhuan(4,org,a,6,5);
	printf("step6 ends\n");
	printf("=====================\n");
}

void step7(int *a)
{
	int org[]={4,3,6,7};
	lunzhuan(5,org,a,4,4);
	printf("step7 ends\n");
	printf("=====================\n");
}

void step8(int *a)
{
	int org[]={0,1,2,5,4,7,8,5,2,1,0,3};
	convert(&a[0],&a[3]);
	lunzhuan(0,org,a,12,3);
	printf("step8 ends\n");
	printf("=====================\n");
}
step9(int *a)
{
	int org[]={4,3,6,7};
	lunzhuan(6,org,a,4,7);
	printf("step9 ends\n");
	printf("=====================\n");
}
void main()
{
	int *pa;
//	int a[9]={2,3,0,4,1,5,6,7,8};
//	int a[9]={3,4,5,6,7,8,1,2,0};
	int a[9]={1,4,7,5,2,8,0,6,3};
	int flag=0;

	pa=a;
	printf("the origin \n");
	dayin(pa);
	
	printf("\n");
	step1(pa);
	
	step2(pa);
	
	step3(pa);
	
	if(pa[2]==3)
	{
		printf("===from step3 to step6===\n");
		printf("\n");
	}
	else
	{
		step4(pa);
		step5(pa);

	}
	step6(pa);
	
	if(pa[8]==5)
	{
		printf("===from step6 to step 9====\n");
		
	}
	else
	{
		step7(pa);
		step8(pa);
	}
	step9(pa);
	
	if(pa[6]==7)
	{
		printf("perfect\n");
	}
	else
	{
		printf("failure\n");
	}

}
