#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron {
public:
    double Input;
    vector<double> Weights;

    Neuron(int NumberOfInputs) {
        for(int i = 0; i < NumberOfInputs; i++) {
            Weights.push_back((double)rand() / RAND_MAX);
        }
    }

    double Activate(vector<double>& inputs) const {
	    double sum = 0.0;
	    for(int i = 0; i < inputs.size(); i++) {
	        sum += inputs[i] * Weights[i];
	    }
	    sum += Input;
	    return 1.0 / (1.0 + exp(-sum));
	}
	
};

class Layer {
public:
    vector<Neuron> neurons;

    Layer(int NumberOfNeurons, int NumberOfInputsPerNeuron) {
        for(int i = 0; i < NumberOfNeurons; i++) {
            neurons.push_back(Neuron(NumberOfInputsPerNeuron));
        }
    }
};

class NeuralNetwork {
public:
    vector<Layer> layers;

    NeuralNetwork(const vector<int>& topology) {
        for(int layerNum = 0; layerNum < topology.size(); layerNum++) {
            int numberOfOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
            layers.push_back(Layer(topology[layerNum], numberOfOutputs));
        }
    }

    void FeedForward(const vector<double>& inputValues) {
        for(int i = 0; i < inputValues.size(); i++) {
            layers[0].neurons[i].Input = inputValues[i];
        }

        for(int layerNum = 1; layerNum < layers.size(); layerNum++) {
            const Layer& previousLayer = layers[layerNum - 1];
            for(int n = 0; n < layers[layerNum].neurons.size(); n++) {
                vector<double> inputs;
                for(int p = 0; p < previousLayer.neurons.size(); p++) {
                    inputs.push_back(previousLayer.neurons[p].Activate(layers[layerNum - 1].neurons[p].Weights));
                }
                layers[layerNum].neurons[n].Input = inputs[n];
            }
        }

        // Output
        for(int i = 0; i < layers.back().neurons.size(); i++) {
            cout << "Output " << i + 1 << ": " << layers.back().neurons[i].Input << endl;
        }
    }
};

int main() {
    vector<int> topology = {3, 4, 7, 10, 15, 20, 15, 10, 7, 4, 2};
    NeuralNetwork myNetwork(topology);
    vector<double> inputValues = {1.0, 2.0, 3.0};
    myNetwork.FeedForward(inputValues);
}


            for (int i = 1; i < n_node; i++)
            {
                for (int j = 1; j < n_node; j++)
                {
                    if(i!=j){
                        edges[i][j]=rand()%80;
                    }
                }
                
            }