// http_functions.h

#ifndef HTTP_FUNCTIONS_H
#define HTTP_FUNCTIONS_H

void send_response(int client_socket, const char *status, const char *message);
void send_file(int client_socket, const char *file_path);
void list_directory(int client_socket, const char *dir_path);
void handle_client(int client_socket);

#endif

