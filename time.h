//Made by Keelan Brening
//Simple timer class
//Change if needed

class Timer {
	public:
		int x;
	
	Timer() {
		x = 0;
	}
	int inc_timer() {
		for (int i = 1; i <= 10; i++) {		
			if (i == 10)			
				return x++;
		}
	}
}t;
