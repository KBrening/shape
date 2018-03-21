//Made by Keelan Brening
//Simple timer class
//Change if needed

class TimeMilli {
	public:
		int x;
	
	TimeMilli() {
		x = 0;
	}
	int inc_timer() {
		for (int i = 1; i <= 60; i++) {		
			if (i == 60)			
				return x++;
		}
		return x;
	}
};
