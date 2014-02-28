#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <limits.h>


#define PROGRAM_NAME "biotranslator"

enum
  {
    GETOPT_HELP_CHAR = (CHAR_MIN - 2), GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
  };

#define GETOPT_HELP_OPTION_DECL \
  "help", no_argument, NULL, GETOPT_HELP_CHAR
#define GETOPT_VERSION_OPTION_DECL \
  "version", no_argument, NULL, GETOPT_VERSION_CHAR

#define HELP_OPTION_DESCRIPTION \
  _("      --help     display this help and exit\n")
#define VERSION_OPTION_DESCRIPTION \
  _("      --version  output version information and exit\n")

#define case_GETOPT_HELP_CHAR                   \
  case GETOPT_HELP_CHAR:                        \
  usage (EXIT_SUCCESS);                       \
  break;

static int verbose_flag;

char* program_name = "biotranslator";

void
usage(int status)
{
  puts("Usage: biotranslator");
  exit(status);
}

int
main(int argc, char **argv)
{
  int c;

  int option_index = 0;

  static struct option long_options[] =
    {
      /* These options set a flag. */
      { "verbose", no_argument, NULL, 'v' },
      { GETOPT_HELP_OPTION_DECL },
      { GETOPT_VERSION_OPTION_DECL },
      /* These options don't set a flag.
	 We distinguish them by their indices. */
      { "from", required_argument, 0, 'f' },
      { "dialect", required_argument, 0, 'd' },
      { 0, 0, 0, 0 } };

  while ((c = getopt_long(argc, argv, "abc:d:f:", long_options, &option_index))
	 != 1)
    {

      switch (c)
        {

	case 'a':
	  puts("option -a\n");
	  break;

	case 'b':
	  puts("option -b\n");
	  break;

	case 'c':
	  printf("option -c with value `%s'\n", optarg);
	  break;

	case 'd':
	  printf("option -d with value `%s'\n", optarg);
	  break;

	case 'f':
	  printf("option -f with value `%s'\n", optarg);
	  break;

	case '?':
	  /* getopt_long already printed an error message. */
	  break;

	  case_GETOPT_HELP_CHAR;

	default:
	  usage(EXIT_FAILURE);
	  ;
	}
    }

  /* Instead of reporting ‘--verbose’
     and ‘--brief’ as they are encountered,
     we report the final status resulting from them. */
  if (verbose_flag)
    puts("verbose flag is set");

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf("non-option ARGV-elements: ");
      while (optind < argc)
        printf("%s ", argv[optind++]);
      putchar('\n');
    }

  exit(0);
  return EXIT_SUCCESS;
}
