 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <hiredis/hiredis.h>
 #include <stdbool.h>
 #include <unistd.h>

int main (int argc, char **argv) {
  extern char *optarg;
  extern int optind, optopt, opterr;
  redisReply *reply;
  redisContext *ctx;
  int c, err = 0;
  char *host = "localhost";
  int port = 6379;
  char *pwd;

  while ((c = getopt(argc, argv, "h:p:a:")) != -1) {
    switch(c) {
      case 'h':
        host = optarg;
        break;
      case 'p':
        port = atoi(optarg);
        break;
      case 'a':
        pwd = optarg;
        break;
      case '?':
        err += 1;
        break;
    }
  }

  if (err > 0) {
    return 1;
  }

  ctx = redisConnect(host, port);

  if (ctx->err) {
    printf("error: %s\n", ctx->errstr);
    return 1;
  }

  if (strlen(pwd) > 0) {
    redisCommand(ctx, "AUTH %s", pwd);
  }

  while (true) {
    reply = redisCommand(ctx,"ECHO %s", "Still Connected");
    if (reply) {
      printf("RESPONSE: %s\n", reply->str);
      freeReplyObject(reply);
    }
    else {
      printf("error: %s\n", ctx->errstr);
    }
    sleep(5);
  }
}