#include "led.h"
#define GPIODEN          (1U<<3) // 0b 0000 0000 0000 0000 0000 0000 0000 1000
#define LED_PIN          (1U<<13) 

void led_init(void)
{
    /*Enable clock access to led port (Port D)*/
    RCC->AHB1ENR |= GPIODEN;
    /*Set led pin as output pin*/
    GPIOD->MODER |= (1U<<26);
    GPIOD->MODER &= ~(1U<<27);

}

void led_on(void)
{
    /*Set led pin HIGH (PD13)*/
    GPIOD->ODR |= LED_PIN;
}

void led_off(void)
{
    /*Set led pin LOW (PD13)*/
    GPIOD->ODR &= ~LED_PIN;
}