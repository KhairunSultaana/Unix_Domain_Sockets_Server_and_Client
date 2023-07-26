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

  // Connect to the server.
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "/tmp/unix_socket");
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the two integers to the server.
  int a = 10;
  int b = 20;
  write(sockfd, &a, sizeof(a));
  write(sockfd, &b, sizeof(b));

  // Receive the sum back from the server.
  int sum;
  read(sockfd, &sum, sizeof(sum));

  // Print the sum.
  printf("The sum is %d\n", sum);

  // Close the socket.
  close(sockfd);

  return 0;
}
