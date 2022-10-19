#include "./cmd.h"
#include "logger/log.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache_arg {
  int argc;
  char **argv;
} cache_arg;

typedef struct cache_arg cache_arg;

static cache_arg args = {0};

int get_cache_argc() { return args.argc; }

char **get_cache_argv() { return args.argv; }

static void print_version(void) { printf("stb_demo 0.1.0\n"); }

static void print_help(void) {
  printf("Usage: stb_demo [OPTIONS | SUBCOMMAND]\n");
  printf("\n");
  printf("OPTIONS: \n");
  printf("    -h, --help     Print help information\n");
  printf("    -v, --version  Print version information\n");
  printf("\n");
  printf("SUBCOMMANDS:\n");
  printf("    resize         Generate shell completions for your shell to stdout\n");
  printf("    help           Print this message or the help of the given subcommand(s)\n");
  printf("    init           Creates the boilerplate structure and files for a new book\n");
  printf("    serve          Serves a book at http://localhost:3000, and rebuilds it on changes\n");
  printf("    test           Tests that a book's Rust code samples compile\n");
  printf("    watch          Watches a book's files and rebuilds it on changes\n");
  printf("\n");
}

int main(int argc, char **argv) {

  int ret;
  args.argc = argc;
  args.argv = argv;

  if (argc < 2) {
    print_help();
    return EXIT_FAILURE;
  }

  char *subcmd = argv[1];
  args.argc -= 2;
  args.argv += 2;
  if (strcmp(subcmd, "read") == 0) {
    if (args.argc < 1) {
      printf("参数数量太少\n");
      exit(EXIT_FAILURE);
    }
    cmd_read(args.argc, args.argv);
  } else if (strcmp(subcmd, "resize") == 0) {
    if (args.argc < 2) {
      printf("参数数量太少\n");
      exit(EXIT_FAILURE);
    }
    cmd_resize(args.argc, args.argv);
  } else if (strcmp(subcmd, "chcolor") == 0) {
    if (args.argc < 2) {
      printf("参数数量太少\n");
      exit(EXIT_FAILURE);
    }
    cmd_chcolor(args.argc, args.argv);
  } else if (strcmp(subcmd, "join") == 0) {
    if (args.argc < 2) {
      printf("参数数量太少\n");
      exit(EXIT_FAILURE);
    }
    cmd_join(args.argc, args.argv);
  } else if (strcmp(subcmd, "compress") == 0) {
    if (args.argc < 2) {
      printf("参数数量太少\n");
      exit(EXIT_FAILURE);
    }
    cmd_compress(args.argc, args.argv);
  } else if (strcmp(subcmd, "-h") == 0 || strcmp(subcmd, "--help") == 0) {
    print_version();
    print_help();
  } else if (strcmp(subcmd, "-v") == 0 || strcmp(subcmd, "--version") == 0) {
    print_version();
  } else {
    print_help();
    return EXIT_FAILURE;
  }
}
