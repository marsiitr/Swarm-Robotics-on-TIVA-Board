#include"tm4c123GH6pm.h"
#include"stdbool.h"
#include<stdint.h>
#include"pll.h"

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
// Port F
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))

void  PortF_Init(void){
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x00000020;  			// enable clock at port F
delay = SYSCTL_RCGC2_R;    					
GPIO_PORTF_LOCK_R=0x4C4F434B;       // Unlock Port F 
GPIO_PORTF_CR_R=0x1F;           		
GPIO_PORTF_AMSEL_R=0x00; 
GPIO_PORTF_PCTL_R=0x00000000;      
GPIO_PORTF_AFSEL_R=0x00;
GPIO_PORTF_DIR_R=0x0E;        
GPIO_PORTF_PUR_R=0x00;
GPIO_PORTF_DEN_R=0x0E;
}


//******************************************************************************************

// Port C and D
// For LSA
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
	
#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_R      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_R        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_R       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_R      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile unsigned long *)0x4000652C))	
	

void  PortC_Init(void){
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x0000004;  			// enable clock at port C
delay = SYSCTL_RCGC2_R;    					
GPIO_PORTC_LOCK_R=0x4C4F434B;       // Unlock Port C 
GPIO_PORTC_CR_R=0xF0;           		
GPIO_PORTC_AMSEL_R=0x00; 
GPIO_PORTC_PCTL_R=0x00000000;      
GPIO_PORTC_AFSEL_R=0x00;
GPIO_PORTC_DIR_R=0x00;   // input        
GPIO_PORTC_PUR_R=0x00;
GPIO_PORTC_DEN_R=0xF0;
}
void  PortD_Init(void){
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x0000008;  			// enable clock at port D
delay = SYSCTL_RCGC2_R;    					
GPIO_PORTD_LOCK_R=0x4C4F434B;       // Unlock Port D 
GPIO_PORTD_CR_R=0x0F;           		
GPIO_PORTD_AMSEL_R=0x00; 
GPIO_PORTD_PCTL_R=0x00000000;      
GPIO_PORTD_AFSEL_R=0x00;
GPIO_PORTD_DIR_R=0x00;        
GPIO_PORTD_DEN_R=0x0F;
GPIO_PORTD_PUR_R=0x00;
}

//************************************************


// Port E for Motor digital pins    left motor PE1 and PE2 and right motor PE3 and PE4 
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

void  PortE_Init(void){
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x00000010;  			// enable clock at port E
delay = SYSCTL_RCGC2_R;    					
GPIO_PORTE_LOCK_R=0x4C4F434B;       // Unlock Port E 
GPIO_PORTE_CR_R=0x1E;           		
GPIO_PORTE_AMSEL_R=0x00; 
GPIO_PORTE_PCTL_R=0x00000000;      
GPIO_PORTE_AFSEL_R=0x00;
GPIO_PORTE_DIR_R=0x1E;        
GPIO_PORTE_PUR_R=0x00;
GPIO_PORTE_DEN_R=0x1E;
}
//************************************************

// For UART Communication between TIVA and NODE MCU

// PORT B
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

#define SYSCTL_RCGCUART_R        (*((volatile unsigned long *)0x400FE618))

// UART PINS

#define UART1_DR_R      (*((volatile unsigned long *)0x4000D000))
#define UART1_RSR_R			(*((volatile unsigned long *)0x4000D004))
#define UART1_FR_R			(*((volatile unsigned long *)0x4000D018))
#define UART1_IBRD_R		(*((volatile unsigned long *)0x4000D024))
#define UART1_FBRD_R    (*((volatile unsigned long *)0x4000D028))
#define UART1_LCRH_R    (*((volatile unsigned long *)0x4000D02C))
#define UART1_CTL_R     (*((volatile unsigned long *)0x4000D030))
	


void UART_Init(void){ // should be called only once
SYSCTL_RCGCUART_R |= 0x0002; // activate UART1
SYSCTL_RCGC2_R |= 0x0002; // activate port B
UART1_CTL_R &= ~0x0001; // disable UART
UART1_IBRD_R = 27; // IBRD=int(50000000/(16*115,200)) = int(27.1267)
UART1_FBRD_R = 8; // FBRD = round(0.1267 * 64) = 8
UART1_LCRH_R = 0x0070; // 8-bit word length, enable FIFO
UART1_CTL_R = 0x0301; // enable RXE, TXE and UART
GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011; // UART
GPIO_PORTB_AMSEL_R &= ~0x03; // disable analog function on PB1-0
GPIO_PORTB_AFSEL_R |= 0x03; // enable alt funct on PB1-0
GPIO_PORTB_DEN_R |= 0x03; // enable digital I/O on PB1-0
}

void UART_OutChar(char data){
while((UART1_FR_R&0x0020) != 0); // wait until TXFF is 0
UART1_DR_R = data;
}

//************************************




void PortF_Init(void);
void PortD_Init(void);
void PortC_Init(void);
void PortE_Init(void);

void Milli_Second_Delay(void);
void forward(void);
void backward(void);
void right(void);
void left(void);
void stop(void);
void UART_Init(void);
void UART_OutChar(char data);
void Delay(int n);
//**********************************************************Delay**************
// SYSTIC TIMER
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))	
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

void One_Milli_Second_Delay(void)
{
    NVIC_ST_CTRL_R =0;            /* disable SysTick during setup */
    NVIC_ST_RELOAD_R |= 0X00009C3F;    /* Reload Value goes here */
    NVIC_ST_CTRL_R |= 0x5;          /* enable SysTick with core clock */
    while( (NVIC_ST_CTRL_R & 0X00010000 ) == 0);     /* Monitoring bit 16 to be set */
    NVIC_ST_CTRL_R = 0;             /* Disabling SysTick Timer */
}

//void Delay(long value)
//{
//	long int l;
//	for(l = 0; l<value; l++){
//		One_Milli_Second_Delay();
//	}
//}
void Delay(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}
//******************************************************




//************************************Wheel motions*************
int sw[8];
int w[8];
int w_sum;
void forward(void){
GPIO_PORTE_DATA_R=0x14;  //    bot 10100
}

void right(void){
GPIO_PORTE_DATA_R=0x10;  // left motor in forward diection only 
}
void left(void){
	GPIO_PORTE_DATA_R=0x04;   /// right motor in move only
			}
void stop(void){
GPIO_PORTE_DATA_R=0x00;    //   stops 
}

int main(void){

  PortF_Init();
	PortE_Init();
	PortC_Init();
	PortD_Init();
//	PLL_Init();
	UART_Init();
	
	GPIO_PORTE_DATA_R=0x00;
	GPIO_PORTF_DATA_R=0x0E;
	Delay(1000);
	while(1){ 
		sw[1]= ((GPIO_PORTD_DATA_R&0x01)==0)?0:1;   // PD0
		sw[3]= ((GPIO_PORTD_DATA_R&0x02)==0)?0:1;   // PD1
		sw[5]= ((GPIO_PORTD_DATA_R&0x04)==0)?0:1;		// PD2
		sw[7]= ((GPIO_PORTD_DATA_R&0x08)==0)?0:1;		// PD3
		sw[6]= ((GPIO_PORTC_DATA_R&0x10)==0)?0:1;   // PC4
		sw[4]= ((GPIO_PORTC_DATA_R&0x20)==0)?0:1;		// PC5
		sw[2]= ((GPIO_PORTC_DATA_R&0x40)==0)?0:1;		// PC6
		sw[0]= ((GPIO_PORTC_DATA_R&0x80)==0)?0:1;		//PC7
		
		w[0]=1;
		w[1]=1;
		w[2]=1;
		w[3]=1;
		w[4]=-1;
		w[5]=-1;
		w[6]=-1;
		w[7]=-1;
		
		w_sum=w[0]*sw[0]+w[1]*sw[1]+w[2]*sw[2]+w[3]*sw[3]+w[4]*sw[4]+w[5]*sw[5]+w[6]*sw[6]+w[7]*sw[7];
		
		if(sw[0]==0 && sw[1]==0 && sw[2]==0 && sw[3]==0 && sw[4]==0 && sw[5]==0 && sw[6]==0 && sw[7]==0){
			GPIO_PORTF_DATA_R=0x08;
			UART_OutChar('4');
			stop();
		}
		else if(sw[0]==1 && sw[1]==1 && sw[2]==1 && sw[3]==1 && sw[4]==1 && sw[5]==1 && sw[6]==1 && sw[7]==1){
		  GPIO_PORTF_DATA_R=0x08;
			UART_OutChar('4');
			stop();
		}
		else if(w_sum==0){
			GPIO_PORTF_DATA_R=0x04;
			UART_OutChar('1');
			forward();
		}
		else if(w_sum>0){
			GPIO_PORTF_DATA_R=0x08;
			UART_OutChar('2');
			right();
		}
		else if(w_sum<0){
			GPIO_PORTF_DATA_R=0x08;
			UART_OutChar('3');
			left();
		}
		Delay(1);
	}
	
}


