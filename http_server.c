#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "http_functions.h"

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Read failed");
        close(client_socket);
        return;
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    printf("Received request:\n%s\n", buffer);

    // Parse the request
    char method[10], path[100];
    sscanf(buffer, "%s %s", method, path);

    // Remove leading slash from path
    char *resource = path + 1; // Skip the leading '/'

    // Handle requests to the root directory
    if (strcmp(resource, "") == 0) { // Check if the requested resource is the root
        resource = "index.html"; // Default resource
    }

    // Log the method and resource
    printf("Method: %s, Resource: %s\n", method, resource);

    // Check the resource type
    struct stat statbuf;
    if (stat(resource, &statbuf) == 0) {
        if (S_ISDIR(statbuf.st_mode)) {
            list_directory(client_socket, resource); // Handle directory listing
        } else if (S_ISREG(statbuf.st_mode)) {
            send_file(client_socket, resource); // Handle file sending
        } else {
            send_response(client_socket, "400 Bad Request", "Invalid resource");
        }
    } else {
        send_response(client_socket, "404 Not Found", "Resource does not exist");
    }
}


int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}

