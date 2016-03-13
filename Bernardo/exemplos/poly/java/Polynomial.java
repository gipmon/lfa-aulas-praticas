//package polynomial;

public class Polynomial
{
    private double[] coef = new double[3];
    
    public Polynomial(double[] c)
    {
		coef[0] = c[0];
		coef[1] = c[1];
		coef[2] = c[2];
	}

    public double[] getRoots()
    {
        double s = coef[1] * coef[1] - 4 * coef[0] * coef[2];
    	if (s < 0) 
        {
	        return new double[0];
        }
        else if (s == 0)
        {
			double[] roots = new double[1];
			roots[0] = -coef[1] / (2 * coef[0]);
			return roots;
	    }
	    else
        {
			double[] roots = new double[2];
			roots[0] = (-coef[1] - Math.sqrt (s)) / (2 * coef[0]);
	    	roots[1] = (-coef[1] + Math.sqrt (s)) / (2 * coef[0]);
	    	return roots;
	    }
    }
}


