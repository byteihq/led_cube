#ifndef INCLUDE_LED_CUBE_H
#define INCLUDE_LED_CUBE_H

#include "main.h"
#define CUBE_SIZE 8
#define CUBE_MASSIVE_SIZE CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3

#define HAL_GPIO_SEND_BIT(PIN, BIT, COLORS)          \
  {                                                  \
    if ((*COLORS) & (1 << BIT)) {                    \
      HAL_GPIO_WritePin(GPIOA, PIN, GPIO_PIN_SET);   \
      TIM1->CNT = 0;                                 \
      while (TIM1->CNT < 52) {};                     \
      TIM1->CNT = 0;                                 \
      HAL_GPIO_WritePin(GPIOA, PIN, GPIO_PIN_RESET); \
      TIM1->CNT = 0;                                 \
      while (TIM1->CNT < 2) {};                      \
      TIM1->CNT = 0;                                 \
    } else {                                         \
      HAL_GPIO_WritePin(GPIOA, PIN, GPIO_PIN_SET);   \
      TIM1->CNT = 0;                                 \
      while (TIM1->CNT < 2) {};                      \
      HAL_GPIO_WritePin(GPIOA, PIN, GPIO_PIN_RESET); \
      TIM1->CNT = 0;                                 \
      while (TIM1->CNT < 52) {};                     \
      TIM1->CNT = 0;                                 \
    }                                                \
  }
#define HAL_GPIO_SEND_BITE(PIN, COLORS) \
  {                                     \
    HAL_GPIO_SEND_BIT(PIN, 0, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 1, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 2, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 3, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 4, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 5, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 6, COLORS);  \
    HAL_GPIO_SEND_BIT(PIN, 7, COLORS);  \
    ++COLORS;                           \
  }
#define HAL_GPIO_SEND_LED(PIN, COLORS) \
  {                                    \
    HAL_GPIO_SEND_BITE(PIN, COLORS);   \
    HAL_GPIO_SEND_BITE(PIN, COLORS);   \
    HAL_GPIO_SEND_BITE(PIN, COLORS);   \
  }
#define HAL_GPIO_SEND_LINE(PIN, COLORS) \
  {                                     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
    HAL_GPIO_SEND_LED(PIN, COLORS);     \
  }
#define HAL_GPIO_SEND_FLAT(PIN, COLORS)  \
  {                                      \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
    HAL_GPIO_SEND_LINE(PIN, COLORS);     \
  }

void cube_set_zero(uint8_t *);
void stdin_set_params();
void get_cube(uint8_t *);
void send_cube(uint8_t const *);
void send_flat(uint16_t const, uint8_t const *) {

#endif //INCLUDE_LED_CUBE_H
