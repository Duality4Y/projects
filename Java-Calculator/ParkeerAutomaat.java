public class ParkeerAutomaat
{
    private double prijs;
    private double betaald;

    public boolean voldoendeBetaald()
    {
	  return this.betaald >= this.prijs;
    }

    public void haalAfVanBetaald(double bedrag)
    {
		this.betaald -= bedrag;
    }

    public void voegToeAanBetaald(double bedrag)
    {
		this.betaald += bedrag;
    }

    public double getBetaald()
    {
		return this.betaald;
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
		return this.prijs;
    }
}
