
public class ParkeerAutomaat
{
    private int prijs;
    private int betaald;

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

    public int getBetaald()
    {
		return betaald;
    }

    public void setBetaald(int bedrag)
    {//geef beginwaarde
    }
    
    public void setPrijs(int prijs)
    {
		this.prijs = prijs;
    }

     public int getPrijs()
    {
		return prijs;
    }
}
