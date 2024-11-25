#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h> 
#include "http_functions.h"

#define BUFFER_SIZE 1024


void send_response(int client_socket, const char *status, const char *message) {
    char response[BUFFER_SIZE];

    // Construct the HTTP response
    snprintf(response, sizeof(response),
             "HTTP/1.1 %s\r\n"
             "Content-Type: text/plain\r\n"
             "Content-Length: %zu\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s", status, strlen(message), message);

    // Send the response
    write(client_socket, response, strlen(response));
    close(client_socket); // Close the connection after sending the response
}

void send_file(int client_socket, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        send_response(client_socket, "404 Not Found", "File not found");
        return;
    }

    char response[BUFFER_SIZE];
    char file_buffer[BUFFER_SIZE];
    
    // Construct the HTTP response header
    snprintf(response, sizeof(response),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "Connection: close\r\n"
             "\r\n");

    // Send the response header
    write(client_socket, response, strlen(response));

    // Read and send the file content
    while (fgets(file_buffer, sizeof(file_buffer), file)) {
        write(client_socket, file_buffer, strlen(file_buffer));
    }

    fclose(file);
    close(client_socket); // Close the connection after sending the file
}

// List the contents of a directory as an HTTP response
void list_directory(int client_socket, const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        send_response(client_socket, "404 Not Found", "Directory not found");
        return;
    }

    struct dirent *entry;
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    write(client_socket, buffer, strlen(buffer)); // Send header

    // List directory contents
    while ((entry = readdir(dir)) != NULL) {
        snprintf(buffer, sizeof(buffer), "<p>%s</p>", entry->d_name);
        write(client_socket, buffer, strlen(buffer)); // Send each entry
    }

    closedir(dir);
    close(client_socket); // Close the connection after sending directory content
}


