import java.util.*;
class DierenWinkel
{
	private ArrayList<HuisDier> dieren = new ArrayList<HuisDier>();
	public DierenWinkel()
	{
		
	}
	
	public void voegToe(HuisDier dier)
	{
		dieren.add(dier);
	}
	
	public void printOverzicht()
	{
		for(HuisDier dier:dieren)
		{
			Sys
		}
	}
}
abstract class HuisDier
{
	private String naam;
	public HuisDier(String naam)
	{
		this.naam = naam;
	}
	abstract public void maakGeluid();
	public String getNaam()
	{
		return this.naam;
	}
}
class Kat extends HuisDier
{
	public Kat(String naam)
	{
		super(naam);
	}
	public void maakGeluid()
	{
		System.out.println("Mieaaauw?");
	}
}
class Hond extends HuisDier
{
	public Hond(String naam)
	{
		super(naam);
	}
	public void maakGeluid()
	{
		System.out.println("Woef Woef!");
	}
}
class Hamster extends HuisDier
{
	public Hamster(String naam)
	{
		super(naam);
	}
	public void maakGeluid()
	{
		System.out.println("squeeek");
	}
}
