#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f4xx_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include "stm32f4xx_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include "stm32f4xx_tim.h" 
#define Max_Strlen 24
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
	str = (unsigned char *)strlen((const char *)str1)+100;
	strcpy((char *)str,(const char *)str1);// str1 dizisini str dizisine kopyaladim.
int i,str_length = strlen((const char *)str);
int org_length = str_length;
	str[str_length] = 0x80; //8 BIT 
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
static void USART_SendString(USART_TypeDef* USARTx, char* s);
char giris[256];
int countergiris=0;
int receviekey=0;
int sayici=0;
char out[250]="";
void USART1_IRQHandler(void)
{		
		
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
		{		
				TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
				char kelime=USART_ReceiveData(USART1);				
				GPIO_SetBits(GPIOG, GPIO_Pin_13);
			
			if( (kelime != '\n') && (sayici < Max_Strlen) ) // kelime degiskenini karakter sayisi boyunca tara.
{			
				giris[sayici]=kelime; // Ekrana girilmis olan kelimeyi alinanString degiskenine ata.
				sayici++; // sayiciyi 1 arttir.				
			}
			else // kelime degiskenindeki karakter bittiyse.
			{
				giris[sayici]='\0'; // alinanString degerini sifirla.
				sayici=0;
				receviekey=1;
				USART_SendString(USART1,giris);// alinanString degiskenini ekrana yazdir.
				TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
				USART_ITConfig(USART1, USART_IT_RXNE,DISABLE);
			}
		}
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		GPIO_ResetBits(GPIOG, GPIO_Pin_13);
		
}

void TIM2_IRQHandler()
	{
	    // Checks whether the TIM2 interrupt has occurred or not

	    if (TIM_GetITStatus(TIM2, TIM_IT_Update))
	    {		 GPIO_ToggleBits(GPIOG, GPIO_Pin_13);
				
					 USART_ITConfig(USART1, USART_IT_RXNE,DISABLE);
	        // Toggle orange LED (GPIO13)
	      
	        // Clears the TIM2 interrupt pending bit
	         TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
					USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);
	    }
	}

int main(void)
{		
	  GPIO_InitTypeDef    GPIO_InitStructure;
    USART_InitTypeDef   USART_InitStrutcure;
    NVIC_InitTypeDef    NVIC_InitStructure;
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOG, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;
    GPIO_Init(GPIOG, &GPIO_InitStructure);
 
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
 
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
 
    USART_InitStrutcure.USART_BaudRate              = 115200;
    USART_InitStrutcure.USART_WordLength            = USART_WordLength_8b;
    USART_InitStrutcure.USART_Parity                = USART_Parity_No;
    USART_InitStrutcure.USART_StopBits              = USART_StopBits_1;
    USART_InitStrutcure.USART_HardwareFlowControl   = USART_HardwareFlowControl_None;
    USART_InitStrutcure.USART_Mode                  = USART_Mode_Tx | USART_Mode_Rx;
 
    USART_Init(USART1, &USART_InitStrutcure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART1, ENABLE);
 
    NVIC_InitStructure.NVIC_IRQChannel          = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd       = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority  = 0;
    NVIC_Init(&NVIC_InitStructure);
		GPIO_SetBits(GPIOG, GPIO_Pin_14);
		USART_SendString(USART1, "\nLutfen deger giriniz:(Ex:0123456789ABCEDF)\r\n");
		
	  TIM_TimeBaseInitStruct.TIM_Prescaler = 4199;
	  TIM_TimeBaseInitStruct.TIM_Period = 9999;
	  TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	  TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	 
		TIM_OCInitTypeDef        TIM_OCInitStructure;
	    // TIM2 initialize20
	  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	    // Enable TIM2 interrupt2 
	    // Start TIM2
		TIM_Cmd(TIM2, ENABLE);
	  NVIC_InitTypeDef NVIC_InitStruct;
	  NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStruct);
			
		uint64_t girilen=0;//0x9474B8E8C73BCA7D;	
		uint64_t key[3] ={0x9474B8E8C73BCA7D, 0x9474B8E8C73BCA7C, 0x9474B8E8C73BC97D};
		uint64_t sonuc=0;
		int i=0;	
		char out[128]="";
		while(1)
		{	
			if(receviekey==1)
				{
						GPIO_SetBits(GPIOG, GPIO_Pin_14);				
						for(i=0;i<16;i++)
						{
							girilen<<=4;
						
							if(giris[i]<':')
								girilen|=giris[i]-'0';
							else
								girilen|=giris[i]-'7';	
						}
				sprintf (out,"\nGirilen Anahtar)x8: %llx", girilen);//hex kod seklinde yazdirma
				USART_SendString(USART1, out);
				//DES sifreleme
				sonuc = des(girilen, key[0],'e');
				sprintf (out,"\nDES sifre Cozumlemesi(Ecrypt)x: %llx", sonuc);//hex kod seklinde yazdirma
				USART_SendString(USART1, out);
				
				sonuc = des(sonuc, key[1],'d');
				//sprintf (out,"\nDES sifre Cozumlemesi(Decrypt)x16: 		%llx", sonuc);//hex kod seklinde yazdirma
			//	USART_SendString(USART1, out);
				//3-DES sifreleme
				sonuc = des(sonuc, key[2],'e');
				sprintf (out,"\nTriple-DES sifre Cozumlemesi(Ecrypt): %llx", sonuc);//hex kod seklinde yazdirma
				USART_SendString(USART1, out);
						
				//3DES Decrypt
				
				sprintf (out,"\n 3-DES Decrypt\n");//hex kod seklinde yazdirma
				USART_SendString(USART1, out);						
				
				sonuc = des(sonuc, key[2],'d');
				sprintf (out,"\nDES sifre Cozumlemesi(Decrypt)x: %llx", sonuc);//hex kod seklinde yazdirma
				USART_SendString(USART1, out);
				
				sonuc = des(sonuc, key[1],'e');
				//sprintf (out,"\nDES sifre Cozumlemesi(Ecrypt)x16: 		%llx", sonuc);//hex kod seklinde yazdirma
				//USART_SendString(USART1, out);
				
				sonuc = des(sonuc, key[0],'d');
				sprintf (out,"\nTriple-DES sifre Cozumlemesi(Decrypt): %llx", sonuc);//hex kod seklinde yazdirma
				USART_SendString(USART1, out);
				
				receviekey=0;
				}
			GPIO_ResetBits(GPIOG, GPIO_Pin_14);

		}
			
    return (0);
}
 
static void USART_SendString(USART_TypeDef* USARTx, char* s)
{
    while(*s)
    {
        while(!USART_GetFlagStatus(USARTx, USART_FLAG_TC));
        USART_SendData(USARTx, *s);
        s++;
    }
}
