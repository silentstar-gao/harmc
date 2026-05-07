
#include <stdio.h>

int write_exact(FILE *file, const char *buffer, size_t n) {
   size_t bytes_written = 0;
   while (bytes_written < n) {
       size_t bytes_to_write = n - bytes_written;
       size_t bytes_written_this_time = fwrite(buffer + bytes_written, 1, bytes_to_write, file);
       if (bytes_written_this_time == 0) {
          fclose(file);
           return -1;
       }
       bytes_written += bytes_written_this_time;
   }
   return 0;
}