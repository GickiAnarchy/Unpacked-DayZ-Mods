modded class BloodBagFull extends ItemBase
{

    void BloodBagFull() 
    {
	}
    
  
   
	void RPRZ_BloodBagFullDestroy()
	{
		//delete object
		GetGame().ObjectDelete( this );
	}
}