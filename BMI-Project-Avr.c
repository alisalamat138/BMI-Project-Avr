#include <mega16a.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 50

void main(void){
    char heightCm;
    float heightM;
    float heightM2;
    char weight;
    float bmi;
    
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x19;

    while (1){
        printf("Please enter your height(cm): \n\r");
        scanf("%d", &heightCm);
        heightM = heightCm/100.0;
        printf("%1.2f (m) \n\r", heightM);
        printf("Please enter your weight(kg): \n\r");
        scanf("%d", &weight);
        printf("%d (kg) \n\r", weight);
        heightM2 = heightM * heightM;
        bmi = weight / heightM2;
        printf("Your BMI is : %2.2f \n\r", bmi);
        
        if(bmi > 18.5 && bmi <= 25){
            printf("Normal \n\r");    
        }else if(bmi > 25 && bmi < 30){
            printf("Average \n\r");
        }else if(bmi >= 30 && bmi < 40){
            printf("Important \n\r");
        }else if(bmi >= 40){
            printf("Severe \n\r");
        }else{
            printf("very slim \n\r");
        }                   
    }
}
