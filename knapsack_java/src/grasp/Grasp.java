package grasp;

import utils.Console;
import utils.Instance;

public class Grasp {
	//Controllers
	Instance instance = Instance.getInstance();
	
	//Methods
	public void run() {
		if(instance.instanceIsNull()) {
			return;
		}
		Console.log("Running Grasp: ");
		
	}
}
