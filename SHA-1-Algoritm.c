#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>



 unsigned long int rotateleft(unsigned long int x, int n){
 	return (x<<n | x>>(32-n));
 }
 /*unsigned long int rotateright(unsigned long int x, int n){
 	return ((x>>n) | x<<(32-n));
 }
*/
void SHA1(unsigned char * str1)
{
unsigned long int H0,H1,H2,H3,H4,A,B,C,D,E,f,k,temp;
	H0 = 0x67452301;
	H1 = 0xEFCDAB89;
	H2 = 0x98BADCFE;
	H3 = 0x10325476;
	H4 = 0xC3D2E1F0;
unsigned char * str;
	str = (unsigned char *)malloc(strlen((const char *)str1)+100);
	strcpy((char *)str,(const char *)str1);// str1 dizisini str dizisine kopyaladým.
int i,str_length = strlen((const char *)str);
int org_length = str_length;
	str[str_length] = 0x80; //8 BÝT 
	str[str_length + 1] = '\0';

	for(i=0;i <str_length+1;i++)
	{
	printf("%c",str[i]);
	
			
	}

//char ic = str[str_length];
	str_length++;
int iB = str_length % 64;
	
	if(iB<56)
		iB = 56-iB;
	else
		iB = 120 - iB;
	printf("\n- %d tane Bit eklendi(hex)toBit:",str_length*8);
	for(i=0;i < iB;i++)
	{
		str[str_length]=0x00;
		str_length++;
	
	}
	str[str_length + 1]='\0';		
	printf("\n- %d tane sifir eklendi.Toplam",iB*8);	
	printf("\n- %d tane toplam Bit",str_length*8);	
	printf("\n- 64 Bit yer kaldi.");
	for(i=0;i<6;i++)
	{
		str[str_length]=0x0;		
		str_length++;	
	}
	printf("\n- 40 Bit yer kaldi.");
	
str[str_length] = (org_length * 8) / 0x100 ; //256 1000
printf("\n- 4 tane Bit eklendi:%x",str[str_length]);
	str_length++;
str[str_length] = (org_length * 8) % 0x100;
printf("\n- 36 tane Bit eklendi:000000%x",str[str_length]);
	str_length++;
str[str_length+i]='\0';
printf("\n- %d tane toplam Bit",str_length*8);	
int j,m,sayi_obegi = str_length/64;
printf("\n- %d tane 512 Bit oBek var",sayi_obegi);
unsigned long int word[80];
	for(i=0;i<sayi_obegi;i++)
	{
			for(j=0;j<16;j++)
			{
			word[j] = str[i*64 + j*4 + 0] * 0x1000000 + str[i*64 + j*4 + 1] * 0x10000 + str[i*64 + j*4 + 2] * 0x100 + str[i*64 + j*4 + 3];
			printf("\n- %d\\32-Bit eklendi:%c,%c,%c,%c",j,str[i*64 + j*4 + 0],str[i*64 + j*4 + 1],str[i*64 + j*4 + 2],str[i*64 + j*4 + 3]);
			}
			
			for(j=16;j<80;j++)
			{
			word[j] = rotateleft((word[j-3] ^ word[j-8] ^ word[j-14] ^ word[j-16]),1);
			//printf("\n- %llu ",(word[j-3] ^ word[j-8] ^ word[j-14] ^ word[j-16]));	
			}
		A = H0;
		B = H1;
		C = H2;
		D = H3;
		E = H4;
		for(m=0;m<80;m++)// f(t;B,C,D)
			{
					if(m<=19){
					f=(B & C) | ((~B) & D);
					k=0x5A827999;				
				}
				else if(m<=39){
					f=(B ^ C ^ D);
					k=0x6ED9EBA1;				
				}
				else if(m<=59){
					f=(B & C) | (B & D) | (C & D);
					k=0x8F1BBCDC;				
				}
				else if(m<=79){
					f=(B ^ C ^ D);
					k=0xCA62C1D6;				
				}
				printf("\n-f:%x-k:%x",f,k);
			temp = (rotateleft(A,5) + f + E + word[m] + k);// & 0xFFFFFFFF;
			printf("\n-TEMP:%x",temp);
			E = D;
			D = C;
			C = rotateleft(B,30);
			B = A;
			A = temp;
		}
			H0 = H0 + A;
			printf("\n-H0:%x",H0);
			H1 = H1 + B;
			printf("\n-H1:%x",H1);
			H2 = H2 + C;
			printf("\n-H2:%x",H2);
			H3 = H3 + D;
			printf("\n-H3:%x",H3);
			H4 = H4 + E;
			printf("\n-H4:%x",H4);
	}
printf("\n\n");
printf("SHA-1 SIFRE: %x%x%x%x%x",H0, H1, H2, H3, H4);

}
void main()
{
	unsigned char* input="parsarge";
	SHA1(input);
}
