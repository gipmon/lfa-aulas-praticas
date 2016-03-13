/**
 * Say hello to given name ("World" by default)
 *
 * @author Artur Pereira
 * @version 0.1 (Fev 2014)
 */

#include <stdio.h>

/**
 * Any application must have a function called <tt>main</tt>,
 *   which is the entry point.
 *
 * @param args name to salute
 */
int main (int argc, char* argv[])
{
  switch (argc)
  {
    case 1:
      fprintf (stdout, "Hello world!\n");
      break;
    case 2:
      fprintf (stdout, "Hello %s, how are you?\n", argv[1]);
      break;
    default:
      fprintf (stderr, "Wrong number of arguments, try again!\n");
      return 1;
  }

  return 0;
}

