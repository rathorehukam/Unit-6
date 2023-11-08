










#include <iostream>
#include <climits>

using namespace std;

#define MAX_DEVICES 100

int dataTransferRate[MAX_DEVICES][MAX_DEVICES];

void initialize(int numDevices) {
    for (int i = 0; i < numDevices; i++) {
        for (int j = 0; j < numDevices; j++) {
            if (i == j) {
                dataTransferRate[i][j] = 0;
            } else {
                dataTransferRate[i][j] = INT_MAX;
            }
        }
    }
}

void addConnection(int source, int destination, int capacity) {
    dataTransferRate[source][destination] = capacity;
}

void floydWarshall(int numDevices) {
    for (int k = 0; k < numDevices; k++) {
        for (int i = 0; i < numDevices; i++) {
            for (int j = 0; j < numDevices; j++) {
                if (dataTransferRate[i][k] != INT_MAX && dataTransferRate[k][j] != INT_MAX) {
                    dataTransferRate[i][j] = min(dataTransferRate[i][j], max(dataTransferRate[i][k], dataTransferRate[k][j]));
                }
            }
        }
    }
}

int main() {
    int numDevices, numConnections;
    int sourceDevice;

    cin >> numDevices;

    initialize(numDevices);

    cin >> numConnections;

    for (int i = 0; i < numConnections; i++) {
        int source, destination, capacity;
        cin >> source >> destination >> capacity;
        addConnection(source, destination, capacity);
    }

    cin >> sourceDevice;

    floydWarshall(numDevices);

    for (int i = 0; i < numDevices; i++) {
        if (i == sourceDevice) {
            cout << "Device " << i << ": Not reachable\n";
        } else if (dataTransferRate[sourceDevice][i] != INT_MAX) {
            cout << "Device " << i << ": " << dataTransferRate[sourceDevice][i] << " units\n";
        } else {
            cout << "Device " << i << ": Not reachable\n";
        }
    }

    return 0;
}
