package grasp;

import utils.Console;
import utils.Instance;

public class Grasp {
	Instance instance = Instance.getInstance();
	public void run() {
		if(instance.instanceIsNull()) {
			return;
		}
		Console.log("Running Grasp: ");
		
	}
}
