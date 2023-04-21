#ifndef INCLUDE_LED_CUBE_H
#define INCLUDE_LED_CUBE_H
#define CUBE_SIZE 8

typedef struct Cube_struct {
  uint8_t leds[CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3];
} Cube;
void cube_set_zero(Cube *);
void stdin_set_params();
void get_cube(Cube *);
void send_cube(const Cube *);

#endif //INCLUDE_LED_CUBE_H
