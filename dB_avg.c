#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
void main(int argc, char *argv[]) {
  double f;
  double tol = 0;
  char *str;
  char format[20];
  uint16_t count = 0;
  uint8_t dot_count=0;
  if (argc == 2) {
    printf("%s", argv[1]);
    return;
  }

  if (argc == 1) {
   while(1) {
     memset(format, 0, sizeof(format));
     scanf("%19s", format);
     if(format[0] == 0) break;
      str=strchr(format, '.');
      if(str){
        if(strlen(str) > dot_count)
          dot_count = strlen(str);
      }
      count++;
      sscanf(format, "%lf", &f);
      tol += pow(10, f / 10);
   }
  }else {
    for(uint16_t i = 1; i < argc; i++) {
      str=strchr(argv[i], '.');
      if(str){
        if(strlen(str) > dot_count)
          dot_count = strlen(str);
      }
      sscanf(argv[i], "%lf", &f);
      tol += pow(10, f / 10);
    }
    count = argc - 1;
  }
  dot_count --;
  if(dot_count > 9)
    dot_count = 9;

  format[0] = '%';
  sprintf(&format[1], ".%dlf", dot_count);
  printf(format, log10(tol / count) * 10);
  return;
}
