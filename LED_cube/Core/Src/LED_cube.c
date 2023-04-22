#include "LED_cube.h"

void cube_set_zero(uint8_t *cube_colors) {
  for (uint8_t *end = (uint8_t)cube + CUBE_MASSIVE_SIZE; cube_colors < end; ++cube_colors) {
    *cube_colors = 0;
  }
  send_cube(cube_colors);
}
void stdin_set_params() {
  //настройка stdin в режим блокирующего (ожидающего) чтения
  //настройка времени ожидания через tcgetattr
}
void get_cube(uint8_t *cube_colors) {
  //считать от питонистов данные в режиме ожидания
  //считываем данные для кубика, вбиваем их в структуру
  uint16_t j = 0;
  for (j = 0; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; j += 3) {
	  cube_colors[j] = 43;
  }
  for (j = 1; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; j += 3) {
	  cube_colors[j] = 200;
  }
  for (j = 2; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; j += 3) {
	  cube_colors[j] = 86;
  }
}
void send_cube(uint8_t const *cube_colors) {
  for (uint16_t pin = GPIO_PIN_0; pin < GPIO_PIN_7; pin *= 2) {
    send_flat(pin, cube_colors);
  }
  TIM1->CNT = 0;
  while (TIM1->CNT < 0xfff0) {};
}
void send_flat(uint16_t const pin, uint8_t const *cube_colors) {
  HAL_GPIO_SEND_FLAT(pin, cube_colors);
  HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
}
