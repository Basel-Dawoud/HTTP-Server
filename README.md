```markdown
# HTTP Server

Welcome to My HTTP Server!

My name is Basel Dawoud, and I created this server in C. This project serves as a simple implementation of an HTTP server that can handle various requests and is designed for educational purposes.

## Server Capabilities

This server can handle the following:

- **GET requests for static files** (e.g., HTML).
- **Directory listing** of available files in a requested directory.
- **Custom error messages** for unsupported requests or missing resources.

## Usage Instructions

You can interact with this server using a web browser or command-line tools like `curl`. Here are some examples of how to use it:

- To retrieve the main page:
  ```bash
  curl http://localhost:8080/
  ```

- To retrieve a specific file (e.g., `Hello`):
  ```bash
  curl http://localhost:8080/Hello
  ```

- To retrieve another HTML page (e.g., `about.html`):
  ```bash
  curl http://localhost:8080/about.html
  ```

- To list files in a directory (e.g., `test_directory`):
  ```bash
  curl http://localhost:8080/test_directory/
  ```

- To access a specific file in the test directory:
  ```bash
  curl http://localhost:8080/test_directory/test_file.html
  ```

- To test a nonexistent resource:
  ```bash
  curl http://localhost:8080/nonexistent.html
  ```

## Additional Information

This server is a simple implementation of an HTTP server in C, designed for educational purposes. You can find the source code and contribute to its development on my GitHub profile.

### Features

- Accepts connections from web browsers.
- Reads and parses HTTP requests.
- Processes requests based on the requested resource:
  1. **Directory**: Lists its contents.
  2. **Regular File**: Sends its contents.
  3. **CGI File**: Executes it (if applicable).
  4. **Nonexistent Resource**: Sends the proper HTTP error message.
- Constructs and sends replies to clients.

## Contact

If you have any questions or feedback, feel free to reach out to me at [baseldawoud2003@gmail.com](mailto:baseldawoud2003@gmail.com).
