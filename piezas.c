#include "piezas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen_piezas(pieza_t *PIEZAS) {
  // la I
  memcpy(PIEZAS[0].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false}},
         sizeof(PIEZAS[0].estructura));
  PIEZAS[0].size_x = 1;
  PIEZAS[0].size_y = 5;
  PIEZAS[0].representacion = 'I';
  PIEZAS[0].sim_flip = true;
  PIEZAS[0].sim_rot = false;

  // la L larga
  memcpy(PIEZAS[1].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[1].estructura));
  PIEZAS[1].size_x = 2;
  PIEZAS[1].size_y = 4;
  PIEZAS[1].representacion = 'l';
  PIEZAS[1].sim_flip = false;
  PIEZAS[1].sim_rot = false;

  // la L corta
  memcpy(PIEZAS[2].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[2].estructura));
  PIEZAS[2].size_x = 3;
  PIEZAS[2].size_y = 3;
  PIEZAS[2].representacion = 'L';
  PIEZAS[2].sim_flip = true;
  PIEZAS[2].sim_rot = false;

  // la S
  memcpy(PIEZAS[3].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {false, true, false, false, false},
                      {false, true, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[3].estructura));
  PIEZAS[3].size_x = 3;
  PIEZAS[3].size_y = 3;
  PIEZAS[3].representacion = 'S';
  PIEZAS[3].sim_flip = false;
  PIEZAS[3].sim_rot = false;

  // la cruz
  memcpy(PIEZAS[4].estructura,
         (bool[5][5]){{false, true, false, false, false},
                      {true, true, true, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[4].estructura));
  PIEZAS[4].size_x = 3;
  PIEZAS[4].size_y = 3;
  PIEZAS[4].representacion = 'x';
  PIEZAS[4].sim_flip = true;
  PIEZAS[4].sim_rot = true;

  // el cuadrado
  memcpy(PIEZAS[5].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {true, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[5].estructura));
  PIEZAS[5].size_x = 2;
  PIEZAS[5].size_y = 2;
  PIEZAS[5].representacion = 'o';
  PIEZAS[5].sim_flip = true;
  PIEZAS[5].sim_rot = true;

  // el piton
  memcpy(PIEZAS[6].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, true, false, false, false},
                      {true, false, false, false, false},
                      {true, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[6].estructura));
  PIEZAS[6].size_x = 2;
  PIEZAS[6].size_y = 4;
  PIEZAS[6].representacion = 'p';
  PIEZAS[6].sim_flip = false;
  PIEZAS[6].sim_rot = false;

  // la serpiente
  memcpy(PIEZAS[7].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, false, false, false, false},
                      {true, true, false, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[7].estructura));
  PIEZAS[7].size_x = 2;
  PIEZAS[7].size_y = 4;
  PIEZAS[7].representacion = 's';
  PIEZAS[7].sim_flip = false;
  PIEZAS[7].sim_rot = false;

  // el patito
  memcpy(PIEZAS[8].estructura,
         (bool[5][5]){{true, true, false, false, false},
                      {false, true, true, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[8].estructura));
  PIEZAS[8].size_x = 3;
  PIEZAS[8].size_y = 3;
  PIEZAS[8].representacion = 'R';
  PIEZAS[8].sim_flip = false;
  PIEZAS[8].sim_rot = false;

  // el gordo teton
  memcpy(PIEZAS[9].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[9].estructura));
  PIEZAS[9].size_x = 3;
  PIEZAS[9].size_y = 2;
  PIEZAS[9].representacion = 'P';
  PIEZAS[9].sim_flip = false;
  PIEZAS[9].sim_rot = false;

  // la c
  memcpy(PIEZAS[10].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {true, false, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[10].estructura));
  PIEZAS[10].size_x = 3;
  PIEZAS[10].size_y = 2;
  PIEZAS[10].representacion = 'C';
  PIEZAS[10].sim_flip = true;
  PIEZAS[10].sim_rot = false;

  // la T
  memcpy(PIEZAS[11].estructura,
         (bool[5][5]){{true, true, true, false, false},
                      {false, true, false, false, false},
                      {false, true, false, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[11].estructura));
  PIEZAS[11].size_x = 3;
  PIEZAS[11].size_y = 3;
  PIEZAS[11].representacion = 'T';
  PIEZAS[11].sim_flip = true;
  PIEZAS[11].sim_rot = false;

  // la W
  memcpy(PIEZAS[12].estructura,
         (bool[5][5]){{true, false, false, false, false},
                      {true, true, false, false, false},
                      {false, true, true, false, false},
                      {false, false, false, false, false},
                      {false, false, false, false, false}},
         sizeof(PIEZAS[12].estructura));
  PIEZAS[12].size_x = 3;
  PIEZAS[12].size_y = 3;
  PIEZAS[12].representacion = 'W';
  PIEZAS[12].sim_flip = true;
  PIEZAS[12].sim_rot = false;
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
