import java.util.*;
class DierenWinkel
{
	private ArrayList<HuisDier> dieren = new ArrayList<HuisDier>();
	public DierenWinkel()
	{
		voegToe(new Kat("Minoes"));
		voegToe(new Hond("Bello"));
		voegToe(new Hamster("lassie"));
		printOverzicht();
	}
	
	public void voegToe(HuisDier dier)
	{
		dieren.add(dier);
	}
	
	public void printOverzicht()
	{
		for(HuisDier dier:dieren)
		{
			System.out.println(dier.getNaam()+" zegt "+dier.maakGeluid());
		}
	}
	
	public static void main(String args[])
	{
		DierenWinkel dierenwinkel = new DierenWinkel();
	}
}
abstract class HuisDier
{
	private String naam;
	public HuisDier(String naam)
	{
		this.naam = naam;
	}
	abstract public String maakGeluid();
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
	public String maakGeluid()
	{
		return "Mieaaauw?";
	}
}
class Hond extends HuisDier
{
	public Hond(String naam)
	{
		super(naam);
	}
	public String maakGeluid()
	{
		return "Woef Woef!";
	}
}
class Hamster extends HuisDier
{
	public Hamster(String naam)
	{
		super(naam);
	}
	public String maakGeluid()
	{
		return "squeeek";
	}
}
