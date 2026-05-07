
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the HTTP request struct
struct http_request {
   char *method;
   char *url;
   char *body;
   size_t body_len;
};

// Function to build an HTTP request struct
struct http_request *build_http_request(const char *method, const char *url, const char *body, size_t body_len) {
   struct http_request *req = NULL;

   // Allocate memory for the HTTP request struct
   req = malloc(sizeof(struct http_request));
   if (req == NULL) {
       goto fail;
   }

   // Allocate memory for the method, url, and body
   req->method = malloc(strlen(method) + 1);
   req->url = malloc(strlen(url) + 1);
   req->body = malloc(body_len + 1);
   if (req->method == NULL || req->url == NULL || req->body == NULL) {
       goto fail;
   }

   // Copy the method, url, and body into the HTTP request struct
   strcpy(req->method, method);
   strcpy(req->url, url);
   strcpy(req->body, body);
   req->body_len = body_len;

   // Return the HTTP request struct
   return req;

fail:
   // Clean up any allocated memory
   if (req != NULL) {
       free(req->method);
       free(req->body);
       free(req);
   }
   return NULL;
}

int main() {
   // Build an HTTP request struct
   struct http_request *req = build_http_request("GET", "http://example.com", "Hello, world!", 13);
   if (req == NULL) {
       printf("Failed to build HTTP request\n");
       return 1;
   }

   // Use the HTTP request struct
   printf("Method: %s\n", req->method);
   printf("URL: %s\n", req->url);
   printf("Body: %s\n", req->body);
   printf("Body length: %zu\n", req->body_len);

   // Clean up the HTTP request struct
   free(req->method);
   free(req->body);
   free(req);

   return 0;
}