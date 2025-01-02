# HTTP Server Implementation

This repository contains a simple HTTP server implemented in C. The server can handle basic HTTP GET requests for static files, directory listings, and custom error messages. It is designed for educational purposes and to demonstrate fundamental network programming concepts.

## Overview of Implementation

The server listens for incoming connections on port 8080 and processes client requests by performing the following operations:

1. **Socket Creation and Binding**: The server creates a socket, binds it to the specified port, and listens for incoming connections.

2. **Handling Client Requests**: When a client connects, the server reads the incoming HTTP request, parses it, and determines the requested resource (file or directory).

3. **Resource Management**:
   - **Static Files**: If the requested resource is a file, it reads the file and sends its contents as an HTTP response.
   - **Directories**: If the resource is a directory, it lists its contents in an HTML format.
   - **Error Handling**: If the requested resource does not exist or is of an unsupported type, the server responds with appropriate error messages.

## Code Breakdown

### Main Server Functionality

**File: `http_server.c`**

- **Socket Creation**: The server socket is created using `socket()` and configured with `bind()` and `listen()`.
- **Accepting Connections**: The server enters an infinite loop, accepting client connections and passing them to the `handle_client()` function for processing.

### Client Handling

**Function: `handle_client(int client_socket)`**

- Reads the incoming request and parses the HTTP method and requested path.
- Checks if the requested resource is a directory or a regular file using `stat()`.
- Calls `list_directory()` to handle directory requests or `send_file()` to serve files.

### Sending Responses

**Function: `send_response(int client_socket, const char *status, const char *message)`**

- Constructs and sends an HTTP response with the specified status and message.

### File Sending

**Function: `send_file(int client_socket, const char *filename)`**

- Opens the requested file and sends its content to the client as an HTTP response.
- Constructs an HTTP header indicating the response status and content type.

### Directory Listing

**Function: `list_directory(int client_socket, const char *dir_path)`**

- Opens the specified directory and reads its contents.
- Sends the list of entries back to the client in an HTML format.

## Compilation and Running

To compile and run the server, follow these steps:

1. **Compile the Server**:
   ```bash
   gcc -o http_server http_server.c http_functions.c


2. **Run the Server**:
   ```bash
   ./http_server
   ```

3. **Testing the Server**:
   You can test the server using a web browser or `curl`. For example:
   ```bash
   curl http://localhost:8080/
   ```

## Contact

If you have any questions or feedback, feel free to reach out to me at [baseldawoud2003@gmail.com](mailto:baseldawoud2003@gmail.com).
