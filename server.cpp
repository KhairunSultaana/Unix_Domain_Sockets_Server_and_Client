#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>

int main() {
  // Create a socket.
  int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Bind the socket to a name.
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "/tmp/unix_socket");
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for connections.
  listen(sockfd, 5);

  // Accept a connection.
  int connfd = accept(sockfd, NULL, NULL);
  if (connfd < 0) {
    perror("accept");
    return 1;
  }

  // Receive the two integers from the client.
  int a, b;
  read(connfd, &a, sizeof(a));
  read(connfd, &b, sizeof(b));

  // Calculate the sum of the two integers.
  int sum = a + b;

  // Send the sum back to the client.
  write(connfd, &sum, sizeof(sum));

  // Close the sockets.
  close(sockfd);
  close(connfd);

  return 0;
}
