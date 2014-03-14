
	//handler voor buttons. maar 5 buttons.
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			// "0.20€", "1€", "Back", "Give", "Chart"
			String action = event.getActionCommand();
			if(action.equals("0.20€"))
			{
				parkeerAutomaat.voegToeAanBetaald(20);
			}
			else if(action.equals("1€"))
			{
				parkeerAutomaat.voegToeAanBetaald(100);
			}
			else if(action.equals("Back"))
			{
				parkeerAutomaat.setBetaald(0);
			}
			else if(action.equals("Give"))
			{
				if(parkeerAutomaat.voldoendeBetaald() && kaartIsIngeworpen == true)
				{
					kaartIsIngeworpen = false;
					for(JButton button:buttons)
					{
						if(button.getText().equals("Chart"))
						{
							button.setEnabled(true);
						}
					}
					if(parkeerAutomaat.getBetaald() > parkeerAutomaat.getPrijs())
					{
						System.out.println("got here");
						parkeerAutomaat.haalAfVanBetaald(parkeerAutomaat.getPrijs());
					}
				}
			}
			else if(action.equals("Chart"))
			{
				if(kaartIsIngeworpen == false)
				{
					kaartIsIngeworpen = true; //kaart ingworpen
					parkeerAutomaat.setPrijs(teBetalenBedrag);//set het te betalen bedrag
					for(JButton button:buttons)
					{
						if(button.getText().equals("Chart"))
						{
							button.setEnabled(false); //disable de button.
						}
					}
				}
			}
			output.setText("te betalen: "+parkeerAutomaat.getPrijs()+" Cent. betaald: "+parkeerAutomaat.getBetaald()+" Cent.");
			this.printPressed(action);
		}*/
	}
	public void printPressed(String action)
	{
		System.out.println(action+" pressed");
	}
