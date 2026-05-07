#include <stdlib.h>
#include <string.h>
char* copyString(const char* source) {
   char* dest = malloc(strlen(source));
   if (dest == NULL) {
       return NULL;
   }
   strcpy(dest, source);
   return dest;
}

