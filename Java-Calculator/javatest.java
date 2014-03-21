class Moeder
{
	public Moeder(){}
}
interface Vader
{
	//public Vader(){}
}
	
class Kind extends Moeder implements Vader
{
	public Kind(){}
	//public void vader(){int i = 0;}
}
	
class javatest
{
	public javatest()
	{
		
	}
	public static void main(String args[])
	{
		Moeder m = new Moeder();
		Moeder m2 = new Kind();
		Vader v = new Kind();
		Kind k = new Moeder();
	}
}
