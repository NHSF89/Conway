
#include <iostream>
#include <unistd.h>
#include "ConwayCell.h"
#include "ConwayWorld.h"
#include "AlwaysAliveCell.h"
#include "NeverAliveCell.h"

using namespace std;

bool userWantsAnotherGeneration() {
    char response;
    
    cout << "Another? (y/n): ";
    cin >> response;
    
    return response == 'y';
}

int main () {
    ConwayWorld world(15, 15);
    
    world.setIsAlive(1, 1, true);
    world.setIsAlive(1, 2, true);
    world.setIsAlive(2, 2, true);
    world.setIsAlive(2, 3, true);
    world.setIsAlive(3, 3, true);
    world.setIsAlive(3, 4, true);
    
    world.replaceCell(new AlwaysAliveCell(), 5, 5, false);
    world.replaceCell(new NeverAliveCell(), 9, 9, false);
    world.display();
    
	int x = 4;

    while (x==4) {
        world.nextGeneration();
        world.display();
		usleep(300000);
    }
}

