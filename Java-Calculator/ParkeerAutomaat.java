public class ParkeerAutomaat
{
    private int prijs;
    private int betaald;

    public boolean voldoendeBetaald()
    {
	  return this.betaald >= this.prijs;
    }

    public void haalAfVanBetaald(int bedrag)
    {
		this.betaald -= bedrag;
    }

    public void voegToeAanBetaald(int bedrag)
    {
		this.betaald += bedrag;
    }

    public int getBetaald()
    {
		return this.betaald;
    }

    public void setBetaald(int bedrag)
    {
		this.betaald = bedrag;
    }
    
    public void setPrijs()
    {
		this.prijs = (int)(Math.random()*20);
    }

    public int getPrijs()
    {
		return this.prijs;
    }
}
