//package polynomial;

public class Poly
{   
   public static void main(String [] args)
    {
        /* check commmand line */
        if (args.length != 3)
        {
            throw new RuntimeException("Wrong number of arguments");
        }

        /* extract coefficients from arguments */
        double [] coef = new double[3];        
        for (int i = 0; i < 3; i++)
        {
            try
            {
                coef[i] = Double.parseDouble(args[i]);
            }
            catch (Exception e)
            {
                throw new RuntimeException("Invalid argument, args[" + i + "]");
            }
        }

		/* compute roots */
        Polynomial poly = new Polynomial(coef);
        double roots[] = poly.getRoots();

        /* print results */
        System.out.print("Roots of (" + coef[0] + ", " + coef[1] + ", " + coef[2] + ") = \n");
        switch (roots.length)
        {
            case 0:
                System.out.print("  No roots\n");
                break;

            case 1:
                System.out.print ("  One root: " + roots[0] + "\n");
                break;

            case 2:
                System.out.print ("  Root 1: " + roots[0] + "\n");
                System.out.print ("  Root 2: " + roots[1] + "\n");
                break;
        }
    }
 
}

