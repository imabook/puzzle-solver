#include "piezas.h"
#include "string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 8
#define MAX_Y 8

void print_tablero(char tablero[MAX_X][MAX_Y]);
bool resolver(char tablero[MAX_X][MAX_Y], pieza_t *piezas, int piezas_len);
bool poner_pieza(char tablero[MAX_X][MAX_Y], pieza_t pieza);

unsigned int SEED;

int main(int argc, char *argv[]) {
  char tablero[MAX_X][MAX_Y];
  pieza_t PIEZAS[13];
  if (argc == 2)
    SEED = atoi(argv[1]);
  else
    SEED = time(NULL);

  for (int y = 0; y < MAX_Y; y++)
    for (int x = 0; x < MAX_X; x++)
      tablero[y][x] = ' ';

  gen_piezas(PIEZAS, SEED);

  // pieza_t p = PIEZAS[7];
  // for (int j = 0; j < 2; j++) {
  //   for (int i = 0; i < 4; i++) {
  //     rotate_pieza(&p);
  //     print_pieza(p);
  //   }
  //   flip_pieza(&p);
  //   print_pieza(p);
  //   printf("\n");
  // }
  // printf("\033[?25l");

  printf("\033[2J\033[H"); // limpia la pantalla al inicio

  resolver(tablero, PIEZAS, 13);
  print_tablero(tablero);
  // printf("\033[?25h");
}

bool resolver(char tablero[MAX_X][MAX_Y], pieza_t *piezas, int piezas_len) {
  char tablero_local[MAX_X][MAX_Y];
  pieza_t pieza_local;
  pieza_t pieza_anterior;
  bool pieza_set_flag = false;

  print_tablero(tablero);

  for (int i = 0; i < piezas_len; i++) {
    memcpy(&pieza_local, &piezas[i], sizeof(pieza_t));

    for (bool flip = false; !flip; flip = true)
      for (int rotation = 0; rotation < 4; rotation++) {
        if (!pieza_set_flag ||
            memcmp(pieza_local.estructura, pieza_anterior.estructura,
                   sizeof(pieza_t)) != 0) {
          // si es la primera rotacion, o si la anterior estructura es diferente
          // a la actual

          memcpy(tablero_local, tablero, sizeof(char) * MAX_X * MAX_Y);

          // printf("poniendo pieza %c\n", pieza_local.representacion);

          if (poner_pieza(tablero_local, pieza_local)) {
            if (piezas_len == 1) {
              memcpy(tablero, tablero_local, sizeof(char) * MAX_X * MAX_Y);

              // print_pieza(pieza_local);
              // ha conseguido poner la ultima pieza
              return true;
            }

            // printf("se ha consiguido meter la siguiente pieza:");
            // print_pieza(pieza_local);

            pieza_t *piezas_locales =
                (pieza_t *)malloc(sizeof(pieza_t) * (piezas_len - 1));

            for (int j = 0; j < piezas_len; j++) {
              if (j == i)
                continue;

              piezas_locales[j - ((j > i) ? 1 : 0)] = piezas[j];
            }

            if (resolver(tablero_local, piezas_locales, piezas_len - 1)) {
              free(piezas_locales);

              memcpy(tablero, tablero_local, sizeof(char) * MAX_X * MAX_Y);
              return true;
            }

            free(piezas_locales);
          }

          // if (pieza_local.sim_rot)
          //   break;

          memcpy(&pieza_anterior, &pieza_local, sizeof(pieza_t));
          pieza_set_flag = true;
          rotate_pieza(&pieza_local);
        }
      }

    // if (pieza_local.sim_flip)
    //   break;

    memcpy(&pieza_anterior, &pieza_local, sizeof(pieza_t));
    pieza_set_flag = true;
    flip_pieza(&pieza_local);
  }

  return false;
}

void print_tablero(char tablero[MAX_X][MAX_Y]) {
  printf("\033[H"); // mueve el cursor al principio
  printf("Tablero con semilla '%d':\n", SEED);

  printf("+--------+\n");

  for (int y = 0; y < MAX_Y; y++) {
    printf("|");
    for (int x = 0; x < MAX_X; x++) {
      char *str = char_to_color(tablero[y][x]);
      printf("%s", str);
      free(str);
    }

    printf("|\n");
  }

  printf("+--------+\n");
}

bool poner_pieza(char tablero[MAX_X][MAX_Y], pieza_t pieza) {
  // coge la pieza que se le ha dado y prueba a meterla en el primer hueco
  // libre empezando de izquierda, derecha; arriba abajo intenta rotarla y
  // luego flipearla si no lo consigue devuelve false
  int x = 0, y = 0, offset = 0;
  bool hueco = false;

  char local_tablero[MAX_X][MAX_Y];
  memcpy(local_tablero, tablero, sizeof(char) * MAX_X * MAX_Y);

  for (y = 0; y < MAX_Y; ++y) {
    for (x = 0; x < MAX_X; ++x)
      if (local_tablero[y][x] == ' ') {
        // celda vacia
        hueco = true;
        break;
      }
    if (hueco)
      break;
  }

  if (!hueco)
    return false;

  // establece un offset por si la primera posicion de la pieza es blanca
  // por asi decir ajusta la pieza
  // piensa en la cruz, que el primer elemento es vacio, para que la pegue a
  // la otra pieza
  for (offset = 0; offset < pieza.size_x; offset++)
    if (pieza.estructura[0][offset])
      break;

  // printf("poniendo pieza %c en (%d, %d)\n", pieza.representacion, x, y);

  for (int py = 0; py < 5; py++)
    for (int px = 0; px < 5; px++)

      if (pieza.estructura[py][px]) {
        if ((x + px - offset) >= MAX_X || (x + px - offset) < 0 ||
            y + py >= MAX_Y)
          return false; // no cabe

        if (local_tablero[y + py][x + px - offset] != ' ')
          return false; // se choca

        local_tablero[y + py][x + px - offset] = pieza.representacion;
      }

  memcpy(tablero, local_tablero, sizeof(char) * MAX_X * MAX_Y);
  return true;
}
