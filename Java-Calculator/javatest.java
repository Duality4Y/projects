class javatest
{
	public class Moeder
	{
		public Moeder(){}
	}
	
	public interface Vader
	{
		//public Vader(){}
	}
	
	public class Kind extends Moeder implements Vader
	{
		public Kind(){}
	}
	
	public javatest()
	{
		
	}
	public static void main()
	{
		//Moeder m = new Moeder();
		Moeder m = new Vader();
	}
}
