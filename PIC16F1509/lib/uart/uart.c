#include "uart.h"


void uart_setup(void)
{
    uart_tx_buff_front = uart_tx_buff;
    uart_tx_buff_back = uart_tx_buff;
    uart_rx_buff_front = uart_rx_buff;
    uart_rx_buff_back = uart_rx_buff;
    TXSTAbits.BRGH = 0b1; //high speed uart baud rate generator
    TXSTAbits.SYNC = 0b0; //uart asynchronous mode
    BAUDCONbits.BRG16 = 0b1; //16-bit uart baud rate generator
    SPBRGL = 0x44;
    SPBRGH = 0x00; //set uart baud rate generator to 68
    RCSTAbits.SPEN = 0b1; //Serial Port Enabled

    TRISBbits.TRISB7 = 0; //set Tx pin to output
    TRISBbits.TRISB5 = 1; //set Rx pin to input

    ANSELBbits.ANSB5 = 0; //set Rx pin to digital

    
    PIR1bits.TXIF = 0b0; //reset transmit interrupt flag
    PIR1bits.RCIF = 0b0; //reset receive interrupt flag
    PIE1bits.TXIE = 0b0; //keep transmit interrupts disabled until data is ready to be sent
    PIE1bits.RCIE = 0b1; //enable receive interrupts
    INTCONbits.PEIE = 0b1; //enable peripheral interrupts
    INTCONbits.GIE = 0b1; //enable global interrupts

    TXSTAbits.TXEN = 0b1; //enable transmit
    RCSTAbits.CREN = 0b1; //enable receive

}

char getch(void)
{
    char retval;
    while (uart_rx_buff_empty());
    retval = *(uart_rx_buff_front++);
    if (uart_rx_buff_front == uart_rx_buff + UART_RX_BUFF_SIZE)
    {
        uart_rx_buff_front = uart_rx_buff;
    }
    return retval;
}

char getstr(char* str, int strlen)
{
    int i = 0;
    char retval;
    char tmpchr;
    while (i < (strlen - 1))
    {
        retval = 1;
        tmpchr = getch();
        //str[i] = getch();
        if (tmpchr == 0x0D)
        { //Carriage Return
            retval = 0;
            break;
        }
        else if (tmpchr == 0x08 || tmpchr == 0x7F)
        { // backspace
            if (i > 0)
            {
                i--;
            }
            i--;
        }
        else
        {
            str[i] = tmpchr;
        }
            
        i++;
    }
    str[i] = '\0';
    return retval;
}

void putch(char c)
{
#ifdef PUTCH_WAIT
    while (uart_tx_buff_full());
#endif
    if (!uart_tx_buff_full())
    {
        *(uart_tx_buff_back++) = c;
        //uart_buff_back++;
        if (uart_tx_buff_back >= uart_tx_buff + UART_TX_BUFF_SIZE)
        {
            uart_tx_buff_back = uart_tx_buff;
        }
    }
    
    if (!PIE1bits.TXIE)
    {
        PIE1bits.TXIE = 1;
    }
}

char uart_tx_buff_full(void)
{
    if ((uart_tx_buff_front == uart_tx_buff) && (uart_tx_buff_back == uart_tx_buff + (UART_TX_BUFF_SIZE - 1)))
    {
        return 1;
    }
    else if (uart_tx_buff_front == (uart_tx_buff_back + 1))
    {
        return 1;
    }
    return 0;
}

char uart_rx_buff_full(void)
{
    if ((uart_rx_buff_front == uart_rx_buff) && (uart_rx_buff_back == uart_rx_buff + (UART_RX_BUFF_SIZE - 1)))
    {
        return 1;
    }
    else if (uart_rx_buff_front == (uart_rx_buff_back + 1))
    {
        return 1;
    }
    return 0;
}

char uart_tx_buff_empty(void)
{
    if (uart_tx_buff_front == uart_tx_buff_back)
    {
        return 1;
    }
    return 0;
}

char uart_rx_buff_empty(void)
{
    if (uart_rx_buff_front == uart_rx_buff_back)
    {
        return 1;
    }
    return 0;
}

void uart_interrupt_handler(void)
{ //call this in ISR
    if (PIR1bits.TXIF && PIE1bits.TXIE)
    {
        //PORTBbits.RB6 = toggle; toggle ^= 1;
       
        if (!uart_tx_buff_empty())
        {
            //PORTBbits.RB4 = toggle; toggle ^= 1;
            TXREG = *(uart_tx_buff_front++);
            if (uart_tx_buff_front == uart_tx_buff + UART_TX_BUFF_SIZE)
            {
                uart_tx_buff_front = uart_tx_buff;
            }
        }
        else
        {
            //PORTBbits.RB4 = toggle; toggle ^= 1;
            PIE1bits.TXIE = 0; //disable interrupts for uart
            
        }
    }

    if (PIR1bits.RCIF && PIE1bits.RCIE)
    {
        //PORTBbits.RB6 = toggle; toggle ^= 1;
        PIR1bits.RCIF = 0;
        if (!uart_rx_buff_full())
        {
            *(uart_rx_buff_back++) = RCREG;
#ifdef ECHO_RX_CHAR
            putch(*(uart_rx_buff_back - 1));
#endif

            if (uart_rx_buff_back >= uart_rx_buff + UART_RX_BUFF_SIZE)
            {
                uart_rx_buff_back = uart_rx_buff;
            }
        }
        else
        {
            dummy = RCREG;
            dummy++;
        }
    }

    
}