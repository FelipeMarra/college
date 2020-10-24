package grasp;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import utils.Console;
import utils.Instance;
import utils.KnapsackObject;
import utils.Solution;

public class Grasp {
	// Controllers
	Instance instance = Instance.getInstance();

	// Methods
	public void run() {
		if (instance.instanceIsNull()) {
			return;
		}
		Console.log("Running Grasp: ");

		// Auxiliary solution
		Solution sl = new Solution();
		double fo_star = -Double.MAX_VALUE;

		// Till stopping criteria (max of iterations)
		for (int i = 0; i < instance.iter_max; i++) {

			// Build partially greedy solution
			sl = buildGraspSolution();
			Console.log("solucao construida: " + sl.calculateFo());

			//Apply local search to the built solution
			//VND(n, sl, p, w, b);
			Console.log("solucao refinada: " + sl.calculateFo());

			//Update best solution
			if (sl.calculateFo() > fo_star) {

				//Change s to the best solution
				instance.setS(sl);

				//update fo
				fo_star = sl.calculateFo();
			}
		}
	}

	private Solution buildGraspSolution() {
		double peso = 0;
		int j;
		int restrictSize;
		double value;

		Solution s = new Solution(instance.getN());
		
		//Create list of ordered objects
		ArrayList<KnapsackObject> sortedObjs = instance.getSortedObjects();
	
		//imprime_lista(objetosOrd);

		//Build a solution element by element, checking if each object fits in the residual capacity of the backpack 
		while(sortedObjs.size() > 0 && peso < instance.getB()) {
			restrictSize = 0;

			//Defines the size of the restricted list

			KnapsackObject bestObj = sortedObjs.get(0);
			KnapsackObject worstObj = sortedObjs.get(sortedObjs.size() - 1);
			
			value = bestObj.getProfit() - instance.alfa * (bestObj.getProfit() - worstObj.getProfit());
			Console.log("Reference value " + value);

			for (int i = 0; i < sortedObjs.size(); i++){
				KnapsackObject o = sortedObjs.get(i);
				if (o.getProfit() >= value)
					restrictSize++;
				else
					break;
			}

			//Sort random position from residual list
			j = ThreadLocalRandom.current().nextInt(0, (int) restrictSize + 1);

			KnapsackObject randObj = sortedObjs.get(j);

			//If object is not yet in the backpack and fits in it, add object to the backpack
			if (s.getIndex(randObj.getId()) != 1 && peso + randObj.getWeight() <= instance.getB()){
				s.setIndex(randObj.getId(), 1);
				peso += randObj.getWeight();
			}

			//Remove object from list as it has already been tested
			sortedObjs.remove(j);
		}
		return s;
	}
}
