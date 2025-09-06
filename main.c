#include "main.h"
#define LED_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_0
#define BTN_GPIO_Port GPIOC
#define BTN_Pin GPIO_PIN_13

// Simple LED+button demo
void SystemClock_Config(void); static void MX_GPIO_Init(void);

int main(void){
  HAL_Init(); SystemClock_Config(); MX_GPIO_Init();
  while(1){
    if(HAL_GPIO_ReadPin(BTN_GPIO_Port,BTN_Pin)==GPIO_PIN_RESET){
      // if button pressed, fast toggle
      HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
      HAL_Delay(120);
    } else {
      // otherwise slow blink
      HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
      HAL_Delay(500);
    }
  }
}

static void MX_GPIO_Init(void){
  __HAL_RCC_GPIOB_CLK_ENABLE(); __HAL_RCC_GPIOC_CLK_ENABLE();
  GPIO_InitTypeDef G={0};
  G.Pin=LED_Pin; G.Mode=GPIO_MODE_OUTPUT_PP; G.Pull=GPIO_NOPULL; G.Speed=GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port,&G);
  G.Pin=BTN_Pin; G.Mode=GPIO_MODE_INPUT; G.Pull=GPIO_PULLUP;
  HAL_GPIO_Init(BTN_GPIO_Port,&G);
}
