
public class ParkeerAutomaat
{
    private double prijs;
    private double betaald;

    public boolean voldoendeBetaald()
    {
	  return betaald>=prijs;
    }

    public void haalAfVanBetaald()
    {
		this.prijs -= betaald;
    }

    public void voegToeAanBetaald(int bedrag)
    {
		betaald += bedrag;
    }

    public double getBetaald()
    {
		return betaald;
    }

    public void setBetaald(double bedrag)
    {//geef beginwaarde
    }
    
    public void setPrijs(double prijs)
    {
		this.prijs = prijs;
    }

    public double getPrijs()
    {
		return prijs;
    }
}
