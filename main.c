#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void horario() {
  for(;;) {
    time_t seg = time(NULL);
    struct tm data = *localtime(&seg);
    printf("Horario: %d-%02d-%02d %02d:%02d:%02d\r", data.tm_year + 1900, data.tm_mon + 1, data.tm_mday, data.tm_hour-3, data.tm_min, data.tm_sec);
  }
}
void timer(int tempo) {
  for (int i = tempo; i >= 0; i--) {
    fflush(stdin);
    printf("Tempo: %02i\n", i);

    sleep(1);
  }
}

int cronometro(void) {
  time_t time_init = time(NULL);
  int s = 0;

  for (;;) {
    time_t current = time(NULL) - time_init;

    printf("\rTempo: %02ld:%02ld", current / 60, current % 60);
  }
  return 0;
}

int main() {
  timer(10);
  horario();
  return 0;
}
