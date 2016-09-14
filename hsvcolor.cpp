int color_recognize(Scalar m)
{
	int h = (int)m[0];
	int s = (int)m[1];
	int v = (int)m[2];

	if ((s < 30)||(v < 46))
	{
		if (v < 46)
		{
			return V_Black;
		}

		if ((s<30)&&((v>221)&&(v<255)))
		{
			return V_White;
		}

		if ((s<43)&&((v>46)&&(v<220)))
		{
			return V_Gray;
		}
	}

	if ((s > 30)&&(v > 46))
	{
		if ((h <= 10)||(h>=156))
		{
			return V_Red;
		}

		if ((h <= 25)&&(h>=11))
		{
			return V_Orange;
		}

		if ((h <= 34)&&(h>=26))
		{
			return V_Yellow;
		}

		if ((h <= 77)&&(h>=35))
		{
			return V_Green;
		}

		if ((h <= 99)&&(h>=78))
		{
			return V_Indigo;
		}

		if ((h <= 124)&&(h>=100))
		{
			if (s<=100)
			{
				return V_Sliver;
			}
			return V_Blue;
		}

		if ((h <= 155)&&(h>=125))
		{
			return V_Purple;
		}
	}

	return -1;
}
