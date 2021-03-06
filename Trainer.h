#ifndef TRAINER_H
#define TRAINER_H

#include "Matrix.h"

class Trainer {
public:
    Trainer();
    Trainer(const Trainer& orig);
    virtual ~Trainer();
    
    int initializeWeightMatrices(int);
    int forwardPropagation();
    int backPropagation();
    int sortMeanList(float *,int);
    int train(int);
    int fillMatrixData(int);
    int writeMetaData();
    int writeWeights();
    
    int printOutputLayer();
    int printdifferenceMeanList();
    
private:
    int w,h;
    int classes,chars;
    int distinctChars;
    int inputLayerNodes,hiddenLayer1Nodes,hiddenLayer2Nodes;
    float learningRate;
    float *differenceMeanList;
    int iterationNo;
    char *targetChars;
    float *rangeData;
    char *rangeChars;
    std::string *trainingImages;
    char *trainedChars;
    
    Matrix inputMatrix, targetMatrix;
    Matrix weightMatrix1, weightMatrix2, weightMatrix3;
    Matrix hiddenLayer1Matrix, hiddenLayer2Matrix;
    Matrix outputLayerMatrix;
    Matrix w3Delta,w3Delta1,w3Delta2,w3Delta3;
    Matrix w2Delta,w2Delta1,w2Delta2,w2Delta3;
    Matrix w1Delta,w1Delta1,w1Delta2,w1Delta3;

};

#endif /* TRAINER_H */
