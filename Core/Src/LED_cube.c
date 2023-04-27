#include "LED_cube.h"

#include <string.h>

void cube_set_zero(uint8_t *cube_colors) {
	memset(cube_colors, 0, CUBE_MASSIVE_SIZE);
  //send_cube(cube_colors);
}
void stdin_set_params() {
  //настройка stdin в режим блокирующего (ожидающего) чтения
  //настройка времени ожидания через tcgetattr
}
void get_cube(uint8_t *cube_colors) {
	for (uint16_t j = 0; j < CUBE_MASSIVE_SIZE; j+=3) {
		cube_colors[j] = 10;
	}
	for (uint16_t j = 1; j < CUBE_MASSIVE_SIZE; j+=3) {
			cube_colors[j] = 128;
		}
	for (uint16_t j = 2; j < CUBE_MASSIVE_SIZE; j+=3) {
			cube_colors[j] = 100;
		}
	//HAL_Delay(1);
  //считать от питонистов данные в режиме ожидания
  //считываем данные для кубика, вбиваем их в структуру

}
void send_cube(uint8_t *cube_colors) {
  uint16_t i = 0;
  for (uint16_t pin = GPIO_PIN_0; pin < GPIO_PIN_7; pin *= 2) {
	  for (i = 0; i < CUBE_SIZE * CUBE_SIZE * 3; ++i) {
			  HAL_GPIO_SEND_BYTE(pin, cube_colors);
	  }
	  HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
  }
  TIM1->CNT = 0;
  while (TIM1->CNT < 0xff00) {};
}
