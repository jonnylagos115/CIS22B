#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

int main()
{
    ProductionWorkers worker1("Jonny", 1243, "02/15/2018", 1, 17.50), 
    worker2("Sue", 5124, "04/14/2016", 2, 22.50), 
    worker3("Walter", 5616, "10/01/2014", 2, 30.25);

    worker1.displayWorkerInfo();
    worker2.displayWorkerInfo();
    worker3.displayWorkerInfo();

    return 0;
}