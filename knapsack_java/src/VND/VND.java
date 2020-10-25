package VND;

import utils.Instance;
import utils.Solution;

public class VND {
	// Controllers
	Instance instance = Instance.getInstance();

	public void run(Solution s) {
		int k;
		double fo_s;

		k = 1;

		while (k <= 2) { //while 1
			fo_s = instance.calculateFo(s);

			switch (k) {
			case 1:
				bestNeighborN1(s);
				break;
			case 2:
				bestNeighborN2(s);
				break;
			default:
				break;
			}
			if (instance.calculateFo(s) > fo_s) {
				k = 1;
			} else
				k++;
		}
	}

	private Solution bestNeighborN1(Solution s) {
		Solution newS = new Solution();
		return newS;
	}

	private Solution bestNeighborN2(Solution s) {
		Solution newS = new Solution();
		return newS;
	}
}
