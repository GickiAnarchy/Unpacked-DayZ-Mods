class CameraFuncs 
{
	
	static float VIGNETTE = 0;
	static float VARGB[4] = { 0, 0, 0, 0 };
	static float m_Color[4] = { 0, 0, 0, 0 };

    // Function used to change the strength of the vignette effect.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeVignette(float intensity, float R, float G, float B) 
	{
		Material materialColors = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");
		VIGNETTE = Math.Clamp(intensity,0,0.6);
		VARGB[0] = R;
		VARGB[1] = G;
		VARGB[2] = B;
		materialColors.SetParam("Vignette", VIGNETTE);
		materialColors.SetParam("VignetteColor", VARGB);
	}
	static void SetWTF69Overlay(float r, float g, float b, float a)
	{

		Material matColors = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		
		m_Color[0] = r;
		m_Color[1] = g;
		m_Color[2] = b;
		m_Color[3] = a;
		
		matColors.SetParam("OverlayColor", m_Color);
		matColors.SetParam("OverlayFactor", a);
	}
}