/*coa_project Students-Shubham Gupta Sonali Gupta Somya Shekhar Jain Simran GUpta */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void binary_label(char s[3]);
/*function for decimal to binary*/
void dec_bin(int decimalNumber){
    int remainder,quotient,k=1;
    int binaryNumber[100],i=1,j;
    quotient = decimalNumber;
	if(quotient==0)
	{
		printf("0000000000");
	}
	
	if(quotient>0)
	{
    while(quotient!=0 )
	{
	while(i!=11){
         binaryNumber[i++]= quotient % 2;
         quotient = quotient / 2;
	}
  	}
	 for(j = i -1 ;j> 0;j--)
         printf("%c",binaryNumber[j]+ '0');
	}
	

}
void dec_bin_label(int decimalNumber){
    int remainder,quotient,k=1;
    int binaryNumber[100],i=1,j;
    quotient = decimalNumber;
	if(quotient==0)
	{
		printf("00000");
	}
	
	if(quotient>0)
	{
    while(quotient!=0 )
	{
	while(i!=6){
         binaryNumber[i++]= quotient % 2;
         quotient = quotient / 2;
	}
  	}
	 for(j = i -1 ;j> 0;j--)
         printf("%c",binaryNumber[j]+ '0');
	}
	
}
void binary(char *s);
int main()
{
	FILE *fp,*fptr;
	fptr=fopen("symbol4.txt","w");
	char a[50][15];
	char string[15];
	 char opcode[3],lab[2];
	int i=0;
	fp = fopen("digits.txt", "r");
   	if(fp == NULL)
		printf("FILE NOT FOUND\n");
	else
	{
		while(fscanf(fp, "%s", string)!=EOF)
		{
			strcpy(a[i],string);
			i++;
		}
	}
	int j,k;
	for(j=0;j<i;j++)//one pass
	{	if(strncmp(a[j],"L1",2)==0||strncmp(a[j],"L2",2)==0||strncmp(a[j],"L3",2)==0||strncmp(a[j],"L4",2)==0)
		{
			for(k=0;k<2;k++)
				fprintf(fptr,"%c",a[j][k]);
		fprintf(fptr," %d\n",j+1);
		}
		
   		
	}
	fclose(fptr);
	for(j=0;j<i;)
	{

		if(strncmp(a[j],"JMP",3)==0 || strncmp(a[j],"JEQ",3)==0 || strncmp(a[j],"JLT",3)==0 || strncmp(a[j],"JGT",3)==0)
		{
			strncpy(opcode,a[j],3);
			binary(opcode);
			char label[3];
			int l=0;
			label[0]=a[j][3];
			label[1]=a[j][4];
			label[2]='\0';

			while(strcmp(a[l],label))
			{
				l++;
			}
			l=l+2;
			 dec_bin_label(l);
			j++;
			printf("\n");
		}
		else if(strncmp(a[j],"L1",2)==0||strncmp(a[j],"L2",2)==0||strncmp(a[j],"L3",2)==0||strncmp(a[j],"L4",2)==0)
		{	
			lab[0]=a[j][0];
			lab[1]=a[j][1];
			lab[2]='\0';
			binary_label(lab);
			printf("\n");
			j++;
		}
		else
		{
			/*strncpy(opcode,a[j],3);
			printf("`%s`",opcode);
			binary(opcode);*/
			int y=0;
			int x=0;
			int flag=0;
			while(a[j][y]!='\0')
			{
				if(a[j][y]=='#')
				{
					flag=1;
					int q=(y+1);
					int d=0;
					char z[50];
					while(a[j][q]!='\0')
					{
						z[d]=a[j][q];
						q++;
						d++;
					}
					z[d]='\0';
					dec_bin(atoi(z));
					break;
				}
				opcode[x]=a[j][y];
				x++;
				y++;
				if(y==3 || y==6 || y==9 || y==12)
				{
					flag=1;
					binary(opcode);
					memset(opcode,'0',3);
					x=0;
				}
			}
		if(flag==1)
			printf("\n");

		j++;
		}
	}
}
/*function for binary of mnemonics*/
void binary(char s[4])
{
	char *m[17]={"MOV","ADD","SUB","MUL","DIV","CMP","JMP","JEQ","JLT","HLT","JGT","ADi","SUi","MUi","DIi","MOi","CMi"};
	char *r[15]={"R00","R01","R02","R03","R04","R05","R06","R07","R08","R09","R10","R11","R12","R13","R14"};
    int i;
    if(strcmp(s,m[0])==0)//mov
   	 printf("1111111111111111100000");//17-1s 5-0s
    else if(strcmp(s,m[1])==0)//add
   	 printf("00000000000000000");
   	 else if(strcmp(s,m[11])==0)//add
   	 printf("00000000000000100");
   	 else if(strcmp(s,m[12])==0)//add
   	 printf("00000000000000101");
   	 else if(strcmp(s,m[13])==0)//add
   	 printf("00000000000000110");
   	 else if(strcmp(s,m[14])==0)//add
   	 printf("00000000000000111");
   	 else if(strcmp(s,m[15])==0)//add
   	 printf("00000000000001000");
   	 else if(strcmp(s,m[16])==0)//add
   	 printf("00000000000001001");//17-0s
    else if(strcmp(s,m[2])==0)//sub
   	 printf("00000000000000001");//17-0s
    else if(strcmp(s,m[3])==0)//mul
   	 printf("00000000000000010");//17-0s
    else if(strcmp(s,m[4])==0)//div
   	 printf("00000000000000011");//17-0s
    else if(strcmp(s,m[5])==0)//cmp
   	 printf("1111111111111111100001");//17-1s
    else if(strcmp(s,m[6])==0)//jmp
   	 printf("111111111111111111111100000");//17-0s
    else if(strcmp(s,m[7])==0)//jeq
    	printf("111111111111111111111100001");
    else if(strcmp(s,m[10])==0)//JGT
   	 printf("111111111111111111111100010");//221s
    else if(strcmp(s,m[8])==0)//jlt
   	 printf("111111111111111111111100011");//22-1s
    else if(strcmp(s,m[9])==0)//hlt
   	 printf("11111111111111111111111111100000");//27-1s 5-0s
   	else if(strcmp(s,r[0])==0)
	   printf("00000");
	else if(strcmp(s,r[1])==0)
	   printf("00001");
	else if(strcmp(s,r[2])==0)
	   printf("00010");
	else if(strcmp(s,r[3])==0)
	   printf("00011");
	else if(strcmp(s,r[4])==0)
	   printf("00100");
	else if(strcmp(s,r[5])==0)
	   printf("00101");
	else if(strcmp(s,r[6])==0)
	   printf("00110");
	else if(strcmp(s,r[7])==0)
	   printf("00111");
	else if(strcmp(s,r[8])==0)
	   printf("01000");
	else if(strcmp(s,r[9])==0)
	   printf("01001");
	else if(strcmp(s,r[10])==0)
	   printf("01010");
	else if(strcmp(s,r[11])==0)
	   printf("01011");
	else if(strcmp(s,r[12])==0)
	   printf("01100");
	else if(strcmp(s,r[13])==0)
	   printf("01101");
	else if(strcmp(s,r[14])==0)
	   printf("01110");
}
void binary_label(char s[3])
{
	char *m[4]={"L1","L2","L3","L4"};
	 if(strcmp(s,m[0])==0)//L1
		printf("11111111111111111111111111100001");
	else if(strcmp(s,m[1])==0)//L2
		printf("11111111111111111111111111100010");
	else if(strcmp(s,m[2])==0)//L3
		printf("11111111111111111111111111100011");
	else if(strcmp(s,m[3])==0)//L4
		printf("11111111111111111111111111100100");
	else
		printf("ERROR 0001!!\n");
}



	

