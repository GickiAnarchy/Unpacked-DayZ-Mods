class Cure_Petridish extends ItemBase
{

    void Cure_Petridish() 
    {
	}
    
  
   
	void RPRZ_Cure_PetridishDestroy()
	{
		//delete object
		GetGame().ObjectDelete( this );
	}
}