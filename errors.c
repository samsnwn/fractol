#include "fractol.h"

void  free_exit(void *mlx, char *message)
{
  perror(message);
  free(mlx);
  exit(EXIT_FAILURE);
}