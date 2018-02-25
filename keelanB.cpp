//Project: Shape
//Name: Keelan Brening
//Last Modified: 2/25/18

#include "time.h"

class kb_set_time {
	public:
		int sec_count;
		int min_count;
		int holder;	
	kb_set_time() {
		sec_count = 0;
		min_count = 0;
		holder = 0;
	}
	int kb_sec() {
		if (sec_count > 59)
			return sec_count + 1;		
		else if (sec_count == 59) {
			sec_count = 0;
			min_count =+ 1;
		}
	}
	int kb_min() {
		return min_count;
	}
}
