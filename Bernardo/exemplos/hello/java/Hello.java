/**
 * Say hello to given name ("World" by default)
 *
 * @author Artur Pereira
 * @version 0.1 (Fev 2014)
 */

public class Hello
{
  /**
   * Any class that defines an application must have a static method called <tt>main</tt>,
   *   which is the entry point.
   *
   * @param args name to salute
   */
  public static void main (String [] args)
  {
    switch (args.length)
    {
      case 0:
        System.out.println ("Hello world!");
        break;
      case 1:
        System.out.println ("Hello " + args[0] + ", how are you?");
        break;
      default:
        System.err.println ("Wrong number of arguments, try again!");
    }
  }
}

