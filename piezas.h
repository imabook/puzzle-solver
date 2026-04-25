#ifndef PIEZAS_H
#define PIEZAS_H

#include <stdbool.h>

typedef struct {
  bool estructura[5][5]; // todas las figuras caben en ese espacio
  int size_x;
  int size_y;
  char representacion; // payada
  bool sim_flip;
  bool sim_rot;
} pieza_t;

void gen_piezas(pieza_t *PIEZAS);
void rotate_pieza(pieza_t *pieza);
void flip_pieza(pieza_t *pieza);
void print_pieza(pieza_t pieza);
char *char_to_color(char c);

#endif
