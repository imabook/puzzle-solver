#include "piezas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _append_I(int starting, pieza_t *PIEZAS);
void _append_l(int starting, pieza_t *PIEZAS);
void _append_L(int starting, pieza_t *PIEZAS);
void _append_S(int starting, pieza_t *PIEZAS);
void _append_x(int starting, pieza_t *PIEZAS);
void _append_o(int starting, pieza_t *PIEZAS);
void _append_p(int starting, pieza_t *PIEZAS);
void _append_s(int starting, pieza_t *PIEZAS);
void _append_R(int starting, pieza_t *PIEZAS);
void _append_P(int starting, pieza_t *PIEZAS);
void _append_C(int starting, pieza_t *PIEZAS);
void _append_T(int starting, pieza_t *PIEZAS);
void _append_W(int starting, pieza_t *PIEZAS);

void gen_piezas(pieza_t *PIEZAS, unsigned int seed) {
  srand(seed);
  int in[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  int selection = -1;

  // bastante feo pero es lo que hay
  for (int i = 0; i < 13; i++) {
    bool flag = true;
    while (flag) {
      flag = false;
      selection = rand() % 13;

      for (int j = 0; j < 13; j++)
        if (selection == in[j]) {
          flag = true;
          break; // el esa pieza ya esta, coge otra
        }
    }

    in[i] = selection;

    switch (selection) {
    case 0:
      _append_I(i, PIEZAS);
      break;
    case 1:
      _append_l(i, PIEZAS);
      break;
    case 2:
      _append_L(i, PIEZAS);
      break;
    case 3:
      _append_S(i, PIEZAS);
      break;
    case 4:
      _append_x(i, PIEZAS);
      break;
    case 5:
      _append_o(i, PIEZAS);
      break;
    case 6:
      _append_p(i, PIEZAS);
      break;
    case 7:
      _append_s(i, PIEZAS);
      break;
    case 8:
      _append_R(i, PIEZAS);
      break;
    case 9:
      _append_P(i, PIEZAS);
      break;
    case 10:
      _append_C(i, PIEZAS);
      break;
    case 11:
      _append_T(i, PIEZAS);
      break;
    case 12:
      _append_W(i, PIEZAS);
      break;
    }
  }
}

void rotate_pieza(pieza_t *pieza) {
  bool estructura[5][5] = {0};
  for (int y = 0; y < pieza->size_y; y++)
    for (int x = 0; x < pieza->size_x; x++)
      estructura[x][pieza->size_y - y - 1] =
          pieza->estructura[y][x]; // simplemente funciona, historico

  int temp = pieza->size_x;
  pieza->size_x = pieza->size_y;
  pieza->size_y = temp;

  memcpy(pieza->estructura, estructura, sizeof(estructura));
}

void flip_pieza(pieza_t *pieza) {
  bool estructura[5][5] = {0};
  for (int y = 0; y < pieza->size_y; y++)
    for (int x = 0; x < pieza->size_x; x++)
      estructura[y][pieza->size_x - x - 1] = pieza->estructura[y][x];

  memcpy(pieza->estructura, estructura, sizeof(estructura));
}

void print_pieza(pieza_t pieza) {

  printf("pieza: \n");
  for (int y = 0; y < pieza.size_y; y++) {
    printf("\t");
    for (int x = 0; x < pieza.size_x; x++)
      printf("%c", pieza.estructura[y][x] ? pieza.representacion : ' ');
    printf("\n");
  }
  printf("\n");
}

char *char_to_color(char c) {
  char *string = malloc(30);

  switch (c) {
  case 'S':
  case 's':
    // red
    sprintf(string, "\033[91m\033[41m%c\033[0m", c);
    break;
  case 'P':
  case 'W':
    // green
    sprintf(string, "\033[92m\033[42m%c\033[0m", c);
    break;
  case 'o':
  case 'C':
    // yellow
    sprintf(string, "\033[93m\033[43m%c\033[0m", c);
    break;
  case 'L':
  case 'T':
    // blue
    sprintf(string, "\033[94m\033[44m%c\033[0m", c);
    break;

  case 'R':
  case 'p':
    sprintf(string, "\033[95m\033[45m%c\033[0m", c);
    break;

  case 'I':
    sprintf(string, "\033[96m\033[46m%c\033[0m", c);
    break;

  case 'l':
  case 'x':
    sprintf(string, "\033[97m\033[47m%c\033[0m", c);
    break;

    // case 'x':
    //   sprintf(string, "\033[99m\033[47m%c\033[0m", c);
    //   break;

  default:
    sprintf(string, "%c", c);
    break;
  }

  return string;
}

void _append_I(int starting, pieza_t *PIEZAS) {
  // la I
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 1;
  PIEZAS[starting].size_y = 5;
  PIEZAS[starting].representacion = 'I';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = false;
}

void _append_l(int starting, pieza_t *PIEZAS) {

  // la L larga
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 2;
  PIEZAS[starting].size_y = 4;
  PIEZAS[starting].representacion = 'l';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_L(int starting, pieza_t *PIEZAS) {

  // la L corta
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'L';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = false;
}

void _append_S(int starting, pieza_t *PIEZAS) {

  // la S
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {false, true, false, false, false},
                      {false, true, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'S';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_x(int starting, pieza_t *PIEZAS) {

  // la cruz
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{false, true, false, false, false},
                      {true, true, true, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'x';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = true;
}

void _append_o(int starting, pieza_t *PIEZAS) {

  // el cuadrado
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {true, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 2;
  PIEZAS[starting].size_y = 2;
  PIEZAS[starting].representacion = 'o';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = true;
}

void _append_p(int starting, pieza_t *PIEZAS) {

  // el piton
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, true, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 2;
  PIEZAS[starting].size_y = 4;
  PIEZAS[starting].representacion = 'p';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_s(int starting, pieza_t *PIEZAS) {

  // la serpiente
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, true, false, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 2;
  PIEZAS[starting].size_y = 4;
  PIEZAS[starting].representacion = 's';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_R(int starting, pieza_t *PIEZAS) {

  // el patito
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {false, true, true, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'R';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_P(int starting, pieza_t *PIEZAS) {

  // el gordo teton
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 2;
  PIEZAS[starting].representacion = 'P';
  PIEZAS[starting].sim_flip = false;
  PIEZAS[starting].sim_rot = false;
}

void _append_C(int starting, pieza_t *PIEZAS) {

  // la c
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, false, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 2;
  PIEZAS[starting].representacion = 'C';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = false;
}

void _append_T(int starting, pieza_t *PIEZAS) {

  // la T
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {false, true, false, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'T';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = false;
}

void _append_W(int starting, pieza_t *PIEZAS) {

  // la W
  memcpy(PIEZAS[starting].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, true, false, false, false},
                      {false, true, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[starting].estructura));
  PIEZAS[starting].size_x = 3;
  PIEZAS[starting].size_y = 3;
  PIEZAS[starting].representacion = 'W';
  PIEZAS[starting].sim_flip = true;
  PIEZAS[starting].sim_rot = false;
}
